#include "entities/Book.hpp"
#include <stdexcept>
#include <chrono>

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
        _borrowDate = std::chrono::system_clock::now();
    } else {
        throw std::runtime_error("Book is already borrowed.");
    }
}

void Book::returnItem() {
    if(_isBorrowed) {
        _isBorrowed = false;
        _borrowDate = std::chrono::system_clock::time_point(); // Reset borrow date
    } else {
        throw std::runtime_error("Book is not borrowed.");
    }
}

bool Book::isBorrowed() const {
    return _isBorrowed;
}