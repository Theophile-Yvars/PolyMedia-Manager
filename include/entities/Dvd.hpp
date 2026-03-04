#pragma once
#include "interfaces/IMedia.hpp"
#include "interfaces/IBorrowable.hpp"

class Dvd : public IMedia, public IBorrowable
{
public:
    Dvd(const std::string& title, Genre genre, float price);
    ~Dvd() = default;
    std::string getTitle() const override;
    Genre getGenre() const override;
    float getPrice() const override;
    void borrow() override;
    void returnItem() override;
    bool isBorrowed() const override;
private:   
    std::string _title;
    Genre _genre;
    float _price;
    bool _isBorrowed = false;
};