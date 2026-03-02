#include "Dvd.hpp"

Dvd::Dvd(const std::string& title, Genre genre, float price)
    : IMedia(title, genre, price) {}

std::string Dvd::getTitle() const {
    return IMedia::getTitle();
}

Genre Dvd::getGenre() const {
    return IMedia::getGenre();
}

float Dvd::getPrice() const {
    return IMedia::getPrice();
}