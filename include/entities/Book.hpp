#pragma once
#include "interfaces/IMedia.hpp"   
#include "interfaces/IBorrowable.hpp"
#include "entities/Genre.hpp"

class Book : public IMedia, public IBorrowable
{
public:
    Book(const std::string& title, Genre genre, float price);
    ~Book() = default;
    std::string getTitle() const override;
    Genre getGenre() const override;
    float getPrice() const override;
    void borrow() override;
    void returnItem() override;
    bool isBorrowed() const override;
    std::chrono::system_clock::time_point getBorrowDate() const override;
private:   
    std::string _title;
    Genre _genre;
    float _price;
    bool _isBorrowed = false;
    std::chrono::system_clock::time_point _borrowDate;
};