#include <gtest/gtest.h>
#include "entities/Book.hpp"
#include "entities/Genre.hpp"


// Test de construction simple
TEST(BookTest, ConstructorInitializesMembers) {
    // Arrange
    std::string expectedTitle = "Le Mythe de Sisyphe";
    Genre expectedGenre = Genre::Drama;
    float expectedPrice = 7.50f;

    // Act
    Book myBook(expectedTitle, expectedGenre, expectedPrice);

    // Assert
    EXPECT_EQ(myBook.getTitle(), expectedTitle);
    EXPECT_EQ(myBook.getGenre(), expectedGenre);
    // Pour les nombres à virgule (float/double), on utilise FLOAT_EQ à cause de la précision
    EXPECT_FLOAT_EQ(myBook.getPrice(), expectedPrice);
}

// Test du polymorphisme via l'interface IMedia
TEST(BookTest, WorksAsIMediaInterface) {
    // On utilise un pointeur vers l'interface
    std::unique_ptr<IMedia> media = std::make_unique<Book>("1984", Genre::ScienceFiction, 10.0f);

    EXPECT_STREQ(media->getTitle().c_str(), "1984");
    EXPECT_EQ(media->getGenre(), Genre::ScienceFiction);
}