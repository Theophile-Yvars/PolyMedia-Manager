#include "entities/Book.hpp"
#include <stdexcept>

Book::Book(const std::string& title, Genre genre, float price)
    : _title(title), _genre(genre), _price(price), _isBorrowed(false) {}

std::string Book::getTitle() const {
    return _title;
}

Genre Book::getGenre() const {
    return _genre;
}

float Book::getPrice() const {
    return _price;
}

void Book::borrow() {
    if(!_isBorrowed) {
        _isBorrowed = true;
    } else {
        throw std::runtime_error("Book is already borrowed.");
    }
}

void Book::returnItem() {
    if(_isBorrowed) {
        _isBorrowed = false;
    } else {
        throw std::runtime_error("Book is not borrowed.");
    }
}

bool Book::isBorrowed() const {
    return _isBorrowed;
}