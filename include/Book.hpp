#pragma once
#include "IMedia.hpp"   

class Book : public IMedia {
public:
    Book(const std::string& title, Genre genre, float price);
    ~Book() = default;
    std::string getTitle() const override;
    Genre getGenre() const override;
    float getPrice() const override;
};