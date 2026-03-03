#include "entities/Book.hpp"

Book::Book(const std::string& title, Genre genre, float price)
    : _title(title), _genre(genre), _price(price) {}

std::string Book::getTitle() const {
    return _title;
}

Genre Book::getGenre() const {
    return _genre;
}

float Book::getPrice() const {
    return _price;
}