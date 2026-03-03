#include "entities/Dvd.hpp"

Dvd::Dvd(const std::string& title, Genre genre, float price)
    : _title(title), _genre(genre), _price(price) {}

std::string Dvd::getTitle() const {
    return _title;
}

Genre Dvd::getGenre() const {
    return _genre;
}

float Dvd::getPrice() const {
    return _price;
}