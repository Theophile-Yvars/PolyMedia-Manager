#include "core/CatalogControleur.hpp"
#include "interfaces/IMedia.hpp"
#include <iostream>
#include <vector>
#include <memory>

#include "core/CatalogManagement.hpp"
#include "entities/Book.hpp"
#include "entities/Dvd.hpp"
#include "entities/Magazines.hpp"

#include <iostream>

using namespace std;

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
    cin.ignore(); // Ignore le caractère de nouvelle ligne restant dans le flux

    if(mediaType == "book") {
        string title;
        Genre genre;
        float price;

        cout << "Entrez le titre du livre: ";
        getline(cin, title);
        cout << "Entrez le genre du livre (0: Fiction, 1: Non-Fiction, 2: Science, 3: History): ";
        int genreInput;
        cin >> genreInput;
        genre = static_cast<Genre>(genreInput);
        cout << "Entrez le prix du livre: ";
        cin >> price;

        Book* newBook = new Book(title, genre, price);
        catalogManagement.addMedia(newBook);
    } else if (mediaType == "dvd") {
        string title;
        Genre genre;
        float price;

        cout << "Entrez le titre du DVD: ";
        getline(cin, title);
        cout << "Entrez le genre du DVD (0: Action, 1: Comedy, 2: Drama, 3: Horror): ";
        int genreInput;
        cin >> genreInput;
        genre = static_cast<Genre>(genreInput);
        cout << "Entrez le prix du DVD: ";
        cin >> price;

        Dvd* newDvd = new Dvd(title, genre, price);
        catalogManagement.addMedia(newDvd);
    } else if (mediaType == "magazine") {
        string title;
        Genre genre;
        float price;

        cout << "Entrez le titre du magazine: ";
        getline(cin, title);
        cout << "Entrez le genre du magazine (0: Fashion, 1: Technology, 2: Sports, 3: Health): ";
        int genreInput;
        cin >> genreInput;
        genre = static_cast<Genre>(genreInput);
        cout << "Entrez le prix du magazine: ";
        cin >> price;

        Magazines* newMagazine = new Magazines(title, genre, price);
        catalogManagement.addMedia(newMagazine);
    } else {
        cout << "Type de média inconnu. Veuillez réessayer." << endl;
        return false;
    }

    return true; 
}

bool CatalogControleur::removeMedia() {
    std::vector<IMedia*>  mediaList = catalogManagement.listMedia();
    if (mediaList.empty()) {
        cout << "Aucun média à supprimer." << endl;
        return false;
    }

    cout << "Médias disponibles:" << endl;
    for (const auto& media : mediaList) {
        cout << "- " << media->getTitle() << endl;
        cout << "  Genre: " << genreToString(media->getGenre()) << endl;
    }

    cout << "Entrez le titre du média à supprimer: ";
    string title;
    cin.ignore(); // Ignore le caractère de nouvelle ligne restant dans le flux
    getline(cin, title);

    for (const auto& media : mediaList) {
        if (media->getTitle() == title) {
            catalogManagement.removeMedia(media);
            cout << "Média supprimé: " << title << endl;    
            return true;
        }
    }

    cout << "Média non trouvé: " << title << endl;
    return false;
}

void CatalogControleur::listMedia() {
    auto mediaList = catalogManagement.listMedia();
    if (mediaList.empty()) {
        cout << "Aucun média dans le catalogue." << endl;
        return;
    }
    cout << "Médias dans le catalogue:" << endl;
    for (const auto& media : mediaList) {
        cout << "- " << media->getTitle() << endl;
        cout << "  Genre: " << genreToString(media->getGenre()) << endl;
        cout << "  Price: $" << media->getPrice() << endl;
    }
}

