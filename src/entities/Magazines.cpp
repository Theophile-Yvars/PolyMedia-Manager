#include "entities/Magazines.hpp"

Magazines::Magazines(const std::string& title, Genre genre, float price)
    : _title(title), _genre(genre), _price(price) {}

std::string Magazines::getTitle() const {
    return _title;
}

Genre Magazines::getGenre() const {
    return _genre;
}

float Magazines::getPrice() const {
    return _price;
}