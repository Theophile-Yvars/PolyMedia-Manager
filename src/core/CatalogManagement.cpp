#include "core/CatalogManagement.hpp"
#include "interfaces/IMedia.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "interfaces/IBorrowable.hpp"
#include "entities/Book.hpp"
#include "entities/Dvd.hpp"

using namespace std;

CatalogManagement::CatalogManagement() {
    // Constructeur
}

CatalogManagement::~CatalogManagement() {
    // Destructeur
}

void CatalogManagement::addMedia(unique_ptr<IMedia> media) {
    _mediaList.emplace_back(std::move(media));
}

void CatalogManagement::removeMedia(IMedia* media) {
    for (auto it = _mediaList.begin(); it != _mediaList.end(); ++it) {
        if (it->get() == media) {
            _mediaList.erase(it);
            break;
        }
    }
}

std::vector<IMedia*> CatalogManagement::listMedia() const {
    vector<IMedia*> mediaPointers;
    mediaPointers.reserve(_mediaList.size());
    for (const auto& media : _mediaList) {
        mediaPointers.push_back(media.get());
    }
    return mediaPointers;
}


bool CatalogManagement::borrowMedia(IMedia* media) {
    IBorrowable* borrowable = dynamic_cast<IBorrowable*>(media);
    
    if (!borrowable) {
        throw std::runtime_error("Media is not borrowable: " + media->getTitle());
    }
    try {
        borrowable->borrow();
        return true;
    } catch (const std::exception& e) {
        throw std::runtime_error("Error borrowing media: " + std::string(e.what()));
    }
}

float CatalogManagement::returnMedia(IMedia* media) {
    auto* borrowable = dynamic_cast<IBorrowable*>(media);
    float finalPenalty = 0.0f;
    
    if (!borrowable) {
        throw std::runtime_error("Media is not returnable: " + media->getTitle());
    }

    if (borrowable->isBorrowed()) {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<float, std::ratio<60>> durationMin = now - borrowable->getBorrowDate();
        float minutes = durationMin.count();

        if (minutes > 1.0f) {
            float rate = 0.0f;
            if (dynamic_cast<Book*>(media)) rate = 0.50f;
            else if (dynamic_cast<Dvd*>(media)) rate = 1.50f;
            
            finalPenalty = static_cast<int>(minutes) * rate;
        }
    }

    try {
        borrowable->returnItem();
        return finalPenalty; 
    } catch (const std::exception& e) {
        throw std::runtime_error("Error returning media: " + std::string(e.what()));
    }
}