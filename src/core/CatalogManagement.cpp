#include "core/CatalogManagement.hpp"
#include "interfaces/IMedia.hpp"
#include <iostream>

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