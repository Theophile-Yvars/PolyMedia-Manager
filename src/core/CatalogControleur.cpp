#include "core/CatalogControleur.hpp"
#include "interfaces/IMedia.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <sstream>


#include "core/CatalogManagement.hpp"
#include "entities/Book.hpp"
#include "entities/Dvd.hpp"
#include "entities/Genre.hpp"
#include "entities/Magazines.hpp"

using namespace std;

namespace { // anonymous namespace for helper functions
struct MediaInput {
    string title;
    Genre genre;
    float price;
};

MediaInput readMediaInput(const string& mediaName) {
    MediaInput input;
    cout << "Entrez le titre du " << mediaName << ": ";
    getline(cin >> ws, input.title);

    cout << "Entrez le genre du " << mediaName << ": ";
    printGenreOptions();
    int genreInput;
    cin >> genreInput;
    input.genre = intToGenre(genreInput);

    cout << "Entrez le prix du " << mediaName << ": ";
    cin >> input.price;

    return input;
}

unique_ptr<IMedia> createMediaFromType(const string& mediaType, const MediaInput& input) {
    if (mediaType == "book") {
        return std::make_unique<Book>(input.title, input.genre, input.price);
    }
    if (mediaType == "dvd") {
        return std::make_unique<Dvd>(input.title, input.genre, input.price);
    }
    if (mediaType == "magazine") {
        return std::make_unique<Magazines>(input.title, input.genre, input.price);
    }
    return nullptr;
}

IMedia* findMediaByTitle(const vector<IMedia*>& mediaList, const string& title) {
    for (const auto& media : mediaList) {
        if (media->getTitle() == title) {
            return media;
        }
    }
    return nullptr;
}

void printBasicMediaLine(const IMedia* media, bool includePrice) {
    cout << "- " << media->getTitle() << endl;
    cout << "  Genre: " << genreToString(media->getGenre()) << endl;
    if (includePrice) {
        cout << "  Price: $" << media->getPrice() << endl;
    }
}
} // namespace

CatalogControleur::CatalogControleur() {
    // Constructeur
}

CatalogControleur::~CatalogControleur() {
    // Destructeur
}

bool CatalogControleur::addMedia() {
    cout << "Quel type de média souhaitez-vous ajouter ? (book, dvd, magazine): ";
    string mediaType;
    cin >> mediaType;

    string mediaName;
    if (mediaType == "book") {
        mediaName = "livre";
    } else if (mediaType == "dvd") {
        mediaName = "DVD";
    } else if (mediaType == "magazine") {
        mediaName = "magazine";
    } else {
        cout << "Type de média inconnu. Veuillez réessayer." << endl;
        return false;
    }

    const MediaInput input = readMediaInput(mediaName);
    unique_ptr<IMedia> media = createMediaFromType(mediaType, input);
    _catalogManagement.addMedia(move(media));

    return true;
}

bool CatalogControleur::removeMedia() {
    vector<IMedia*> mediaList = _catalogManagement.listMedia();
    if (mediaList.empty()) {
        cout << "Aucun média à supprimer." << endl;
        return false;
    }

    cout << "Médias disponibles:" << endl;
    for (const auto& media : mediaList) {
        printBasicMediaLine(media, false);
    }

    cout << "Entrez le titre du média à supprimer: ";
    string title;
    getline(cin >> ws, title);

    IMedia* media = findMediaByTitle(mediaList, title);
    if (!media) {
        cout << "Média non trouvé: " << title << endl;
        return false;
    }

    _catalogManagement.removeMedia(move(media));
    cout << "Média supprimé: " << title << endl;
    return true;
}

void CatalogControleur::listMedia() {
    auto mediaList = _catalogManagement.listMedia();
    if (mediaList.empty()) {
        cout << "Aucun média dans le catalogue." << endl;
        return;
    }
    cout << "Médias dans le catalogue:" << endl;
    for (const auto& media : mediaList) {
        cout << "- " << media->getTitle() << endl;
        cout << "  Genre: " << genreToString(media->getGenre()) << endl;
        cout << "  Price: $" << media->getPrice() << endl;
        if (auto* borrowable = dynamic_cast<IBorrowable*>(media)) {
            cout << "  Status: " << (borrowable->isBorrowed() ? "Borrowed" : "Available") << endl;
        } else {
            cout << "  Status: Not borrowable" << endl;
        }
    }
}

bool CatalogControleur::borrowMedia() {
    auto mediaList = _catalogManagement.listMedia();
    cout << "Médias disponibles pour emprunt:" << endl;
    for (const auto& media : mediaList) {
        printBasicMediaLine(media, true);
    }

    cout << "Entrez le titre du média à emprunter: ";
    string title;
    getline(cin >> ws, title);

    IMedia* media = findMediaByTitle(mediaList, title);
    if (!media) {
        cout << "Média non trouvé : " << title << endl;
        return false;
    }

    try {
        _catalogManagement.borrowMedia(move(media));
        cout << "Média emprunté avec succès : " << media->getTitle() << endl;
        return true;
    } catch (const std::exception& e) {
        cerr << "Erreur lors de l'emprunt : " << e.what() << endl;
        return false;
    }
}

bool CatalogControleur::returnMedia() {
    auto mediaList = _catalogManagement.listMedia();
    cout << "Médias empruntés:" << endl;
    for (const auto& media : mediaList) {
        if (auto* borrowable = dynamic_cast<IBorrowable*>(media)) {
            if (borrowable->isBorrowed()) {
                printBasicMediaLine(media, true);
            }
        }
    }

    cout << "Entrez le titre du média à retourner: ";
    string title;
    getline(cin >> ws, title);

    IMedia* media = findMediaByTitle(mediaList, title);
    if (!media) {
        cout << "Média non trouvé : " << title << endl;
        return false;
    }

    try {
        _catalogManagement.returnMedia(move(media));
        cout << "Média retourné avec succès : " << media->getTitle() << endl;
        return true;
    } catch (const std::exception& e) {
        cerr << "Erreur lors du retour : " << e.what() << endl;
        return false;
    }
}

void CatalogControleur::initMedia() {
    // Livres
    _catalogManagement.addMedia(make_unique<Book>("1984", Genre::ScienceFiction, 8.50f));
    _catalogManagement.addMedia(make_unique<Book>("Le Seigneur des Anneaux", Genre::Fantasy, 25.00f));
    _catalogManagement.addMedia(make_unique<Book>("Le Petit Prince", Genre::Drama, 6.90f));
    _catalogManagement.addMedia(make_unique<Book>("Dune", Genre::ScienceFiction, 12.00f));
    _catalogManagement.addMedia(make_unique<Book>("Foundation", Genre::ScienceFiction, 9.99f));
    _catalogManagement.addMedia(make_unique<Book>("L'Alchimiste", Genre::Fantasy, 7.50f));
    _catalogManagement.addMedia(make_unique<Book>("Les Misérables", Genre::Drama, 15.50f));

    // DVDs
    _catalogManagement.addMedia(make_unique<Dvd>("The Dark Knight", Genre::Action, 12.99f));
    _catalogManagement.addMedia(make_unique<Dvd>("Interstellar", Genre::ScienceFiction, 14.99f));
    _catalogManagement.addMedia(make_unique<Dvd>("Inception", Genre::ScienceFiction, 10.99f));
    _catalogManagement.addMedia(make_unique<Dvd>("Pulp Fiction", Genre::Action, 9.99f));
    _catalogManagement.addMedia(make_unique<Dvd>("The Godfather", Genre::Drama, 19.99f));
    _catalogManagement.addMedia(make_unique<Dvd>("Princess Mononoke", Genre::Action, 18.00f));

    // Magazines
    _catalogManagement.addMedia(make_unique<Magazines>("Wired", Genre::Documentary, 6.00f));
    _catalogManagement.addMedia(make_unique<Magazines>("National Geographic", Genre::Documentary, 5.99f));
    _catalogManagement.addMedia(make_unique<Magazines>("Vogue", Genre::Action, 4.50f));
    _catalogManagement.addMedia(make_unique<Magazines>("New Scientist", Genre::Documentary, 7.20f));
}

std::string CatalogControleur::formatTimePoint(std::chrono::system_clock::time_point tp) {
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm* local_tm = std::localtime(&tt);
    std::stringstream ss;
    ss << std::put_time(local_tm, "%d/%m/%Y %H:%M:%S");
    return ss.str();
}