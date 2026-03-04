#pragma once
#include "interfaces/IMedia.hpp"
#include <vector>
#include <memory>

class CatalogManagement {
public:
    CatalogManagement();
    ~CatalogManagement();
    void addMedia(IMedia* media); 
    void removeMedia(IMedia* media);  
    std::vector<IMedia*> listMedia() const;
    bool borrowMedia(IMedia* media);
    bool returnMedia(IMedia* media);
private:
    std::vector<std::unique_ptr<IMedia>> mediaList;
};
