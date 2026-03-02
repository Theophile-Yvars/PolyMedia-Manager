#include "CatalogManagement.hpp"
#include "IMedia.hpp"

CatalogManagement::CatalogManagement() {
    // Constructeur
}

CatalogManagement::~CatalogManagement() {
    // Destructeur
}

void CatalogManagement::addMedia(IMedia* media) {
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