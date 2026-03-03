#pragma
#include <vector>
#include <memory>
#include "interfaces/IMedia.hpp"
#include "core/CatalogManagement.hpp"

class CatalogControleur {
public:
    CatalogControleur();
    ~CatalogControleur();
    bool addMedia();
    bool removeMedia();
    void listMedia();
private:
    CatalogManagement catalogManagement;
};