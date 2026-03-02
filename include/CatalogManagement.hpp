#pragma once
#include "IMedia.hpp"
#include <vector>
#include <memory>

class CatalogManagement {
public:
    CatalogManagement();
    ~CatalogManagement();  
private:
    void addMedia(IMedia* media); 
    void removeMedia(IMedia* media);
    std::vector<std::unique_ptr<IMedia>> mediaList;
};
