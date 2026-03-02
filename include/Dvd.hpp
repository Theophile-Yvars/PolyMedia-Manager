#pragma once
#include "IMedia.hpp"

class Dvd : public IMedia {
public:
    Dvd(const std::string& title, Genre genre, float price);
    ~Dvd() = default;
    std::string getTitle() const override;
    Genre getGenre() const override;
    float getPrice() const override;
};