#pragma once
#include <string>

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