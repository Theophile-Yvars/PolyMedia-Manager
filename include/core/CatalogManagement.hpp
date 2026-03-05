#pragma once
#include "interfaces/IMedia.hpp"
#include <vector>
#include <memory>

class CatalogManagement {
public:
    CatalogManagement();
    ~CatalogManagement();
    void addMedia(std::unique_ptr<IMedia> media); 
    void removeMedia(IMedia* media);  
    std::vector<IMedia*> listMedia() const;
    bool borrowMedia(IMedia* media);
    float returnMedia(IMedia* media);
private:
    std::vector<std::unique_ptr<IMedia>> _mediaList;
};
