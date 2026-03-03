#pragma once
#include "interfaces/IMedia.hpp"

class Dvd : public IMedia {
public:
    Dvd(const std::string& title, Genre genre, float price);
    ~Dvd() = default;
    std::string getTitle() const override;
    Genre getGenre() const override;
    float getPrice() const override;
private:   
    std::string _title;
    Genre _genre;
    float _price;
};