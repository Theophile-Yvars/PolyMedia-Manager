#include "core/CatalogManagement.hpp"
#include "interfaces/IMedia.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include "interfaces/IBorrowable.hpp"

using namespace std;

CatalogManagement::CatalogManagement() {
    // Constructeur
}

CatalogManagement::~CatalogManagement() {
    // Destructeur
}

void CatalogManagement::addMedia(IMedia* media) {
    cout << "Adding media: " << media->getTitle() << endl;
    mediaList.emplace_back(media);
}

void CatalogManagement::removeMedia(IMedia* media) {
    for (auto it = mediaList.begin(); it != mediaList.end(); ++it) {
        if (it->get() == media) {
            mediaList.erase(it);
            break;
        }
    }
}

std::vector<IMedia*> CatalogManagement::listMedia() const {
    std::vector<IMedia*> result;
    result.reserve(mediaList.size());

    for (const auto& media : mediaList) {
        result.push_back(media.get());
    }
    
    return result;
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

bool CatalogManagement::returnMedia(IMedia* media) {
    auto* borrowable = dynamic_cast<IBorrowable*>(media);
    
    if (!borrowable) {
        throw std::runtime_error("Media is not returnable: " + media->getTitle());
    }

    try {
        borrowable->returnItem();
        return true; 
    } catch (const std::exception& e) {
        throw std::runtime_error("Error returning media: " + std::string(e.what()));
    }
}