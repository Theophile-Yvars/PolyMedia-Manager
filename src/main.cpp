#include <cstdlib>
#include <iostream>
#include "core/CatalogControleur.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    cout << "PolyMedia-Manager is running!" << endl;

    bool running = true;
    CatalogControleur catalogControleur;
    catalogControleur.initMedia(); // Initialisation du catalogue avec des médias de test

    while (running)
    {
        cout << "Enter a command (add, remove, list, exit, borrow, return): ";
        string command;
        cin >> command;

        if (command == "add") {
            cout << "Adding media..." << endl;
            catalogControleur.addMedia();
        } else if (command == "remove") {
            cout << "Removing media..." << endl;
            catalogControleur.removeMedia();
        } else if (command == "list") {
            cout << "Listing media..." << endl;
            catalogControleur.listMedia();
        } else if (command == "borrow") {
            cout << "Borrowing media..." << endl;
            catalogControleur.borrowMedia(); 
        } else if (command == "return") {
            cout << "Returning media..." << endl;   
            catalogControleur.returnMedia(); 
        }
        else if (command == "exit") {
            running = false;
            cout << "Exiting PolyMedia-Manager. Goodbye!" << endl;
        } else {
            cout << "Unknown command. Please try again." << endl;
        }
    }
    

    return EXIT_SUCCESS;
}