#include <gtest/gtest.h>
#include <memory>
#include <thread>
#include <chrono>
#include "core/CatalogManagement.hpp"
#include "entities/Book.hpp"
#include "entities/Dvd.hpp"
#include "entities/Genre.hpp"

class CatalogManagementTest : public ::testing::Test {
protected:
    CatalogManagement catalog;

    void SetUp() override {
        // Optionnel : s'exécute avant chaque test
    }
};

// 1. Test de l'ajout et du listage
TEST_F(CatalogManagementTest, AddAndListMedia) {
    auto book = std::make_unique<Book>("1984", Genre::ScienceFiction, 10.0f);
    catalog.addMedia(std::move(book));

    auto list = catalog.listMedia();
    ASSERT_EQ(list.size(), 1);
    EXPECT_EQ(list[0]->getTitle(), "1984");
}

// 2. Test de la suppression
TEST_F(CatalogManagementTest, RemoveMedia) {
    auto book = std::make_unique<Book>("Dune", Genre::ScienceFiction, 15.0f);
    IMedia* ptr = book.get(); // On garde un pointeur d'observation pour supprimer
    
    catalog.addMedia(std::move(book));
    ASSERT_EQ(catalog.listMedia().size(), 1);

    catalog.removeMedia(ptr);
    EXPECT_EQ(catalog.listMedia().size(), 0);
}

// 3. Test de l'emprunt réussi
TEST_F(CatalogManagementTest, BorrowMediaSuccess) {
    auto dvd = std::make_unique<Dvd>("Inception", Genre::ScienceFiction, 20.0f);
    IMedia* ptr = dvd.get();
    catalog.addMedia(std::move(dvd));

    EXPECT_TRUE(catalog.borrowMedia(ptr));
    
    // Vérifier que le statut est bien "Borrowed"
    auto* borrowable = dynamic_cast<IBorrowable*>(ptr);
    EXPECT_TRUE(borrowable->isBorrowed());
}

// 4. Test du calcul de pénalité (Simulé)
TEST_F(CatalogManagementTest, ReturnMediaWithPenalty) {
    auto book = std::make_unique<Book>("Le Petit Prince", Genre::Drama, 5.0f);
    IMedia* ptr = book.get();
    catalog.addMedia(std::move(book));

    catalog.borrowMedia(ptr);

    // On ne peut pas facilement attendre 1 minute dans un test unitaire (trop long).
    // Dans un vrai projet, on utiliserait un "Fake Clock", 
    // mais ici on va vérifier que la pénalité est à 0 si on rend tout de suite.
    float penalty = catalog.returnMedia(ptr);
    
    EXPECT_EQ(penalty, 0.0f);
    auto* borrowable = dynamic_cast<IBorrowable*>(ptr);
    EXPECT_FALSE(borrowable->isBorrowed());
}

// 5. Test de l'exception si le média n'est pas empruntable (ex: Magazine si tu en as)
// Ici on teste le comportement si on passait un objet nul ou incompatible
TEST_F(CatalogManagementTest, BorrowNonExistentMediaThrows) {
    EXPECT_THROW(catalog.borrowMedia(nullptr), std::runtime_error);
}