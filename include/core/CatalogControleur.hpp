#pragma
#include <vector>
#include <memory>
#include <string>
#include <chrono>
#include "interfaces/IMedia.hpp"
#include "core/CatalogManagement.hpp"

class CatalogControleur {
public:
    CatalogControleur();
    ~CatalogControleur();
    bool addMedia();
    bool removeMedia();
    void listMedia();
    bool borrowMedia();
    bool returnMedia();
    void initMedia();
private:
    CatalogManagement _catalogManagement;
    std::string formatTimePoint(std::chrono::system_clock::time_point tp);
};