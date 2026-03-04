#include "entities/Dvd.hpp"
#include <stdexcept>

Dvd::Dvd(const std::string& title, Genre genre, float price)
    : _title(title), _genre(genre), _price(price), _isBorrowed(false) {}

std::string Dvd::getTitle() const {
    return _title;
}

Genre Dvd::getGenre() const {
    return _genre;
}

float Dvd::getPrice() const {
    return _price;
}

void Dvd::borrow() {
    if(!_isBorrowed) {
        _isBorrowed = true;
    } else {
        throw std::runtime_error("DVD is already borrowed.");
    }
}

void Dvd::returnItem() {
    if(_isBorrowed) {
        _isBorrowed = false;
    } else {
        throw std::runtime_error("DVD is not borrowed.");
    }
}

bool Dvd::isBorrowed() const {
    return _isBorrowed;
}

