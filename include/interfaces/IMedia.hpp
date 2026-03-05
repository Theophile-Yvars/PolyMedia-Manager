#pragma once
#include <string>
#include "entities/Genre.hpp"

class IMedia {
public:
    virtual ~IMedia() = default;
    virtual std::string getTitle() const = 0;
    virtual Genre getGenre() const = 0;
    virtual float getPrice() const = 0;
};