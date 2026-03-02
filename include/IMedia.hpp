#pragma once
#include <string>
#include "Genre.hpp"

class IMedia
{
private:
    std::string title;
    Genre genre;
    float price;
public:
    IMedia(const std::string& title, Genre genre, float price);
    ~IMedia() = default;
    virtual std::string getTitle() const = 0;
    virtual Genre getGenre() const = 0;
    virtual float getPrice() const = 0;
};