#pragma once
#include <string>
#include <iostream>

enum class Genre {
    Action,
    Comedy,
    Drama,
    Horror,
    ScienceFiction,
    Romance,
    Thriller,
    Fantasy,
    Animation,
    Documentary
};

inline std::string genreToString(Genre g) {
    switch (g) {
        case Genre::Action:         return "Action";
        case Genre::Comedy:         return "Comedy";
        case Genre::Drama:          return "Drama";
        case Genre::ScienceFiction: return "Science Fiction";
        case Genre::Romance:        return "Romance";
        case Genre::Thriller:       return "Thriller";
        case Genre::Fantasy:        return "Fantasy";
        case Genre::Animation:      return "Animation";
        case Genre::Documentary:    return "Documentary";
        default:                    return "Unknown";
    }
}

inline Genre intToGenre(const int genreInput) {
    switch (genreInput) {
        case 0: return Genre::Action;
        case 1: return Genre::Comedy;
        case 2: return Genre::Drama;
        case 3: return Genre::ScienceFiction;
        case 4: return Genre::Romance;
        case 5: return Genre::Thriller;
        case 6: return Genre::Fantasy;
        case 7: return Genre::Animation;
        case 8: return Genre::Documentary;
        default: throw std::invalid_argument("Invalid genre input: " + std::to_string(genreInput));
    }
}

inline void printGenreOptions() {
    std::cout << "Available genres:" << std::endl;
    std::cout << "0: Action" << std::endl;
    std::cout << "1: Comedy" << std::endl;
    std::cout << "2: Drama" << std::endl;
    std::cout << "3: Science Fiction" << std::endl;
    std::cout << "4: Romance" << std::endl;
    std::cout << "5: Thriller" << std::endl;
    std::cout << "6: Fantasy" << std::endl;
    std::cout << "7: Animation" << std::endl;
    std::cout << "8: Documentary" << std::endl;
}