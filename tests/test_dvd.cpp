#include <gtest/gtest.h>
#include "entities/Dvd.hpp"
#include "entities/Genre.hpp"
#include <memory>

// Groupe de test pour les DVD
TEST(DvdTest, ConstructorInitializesMembers) {
    // Arrange
    std::string expectedTitle = "Inception";
    Genre expectedGenre = Genre::ScienceFiction;
    float expectedPrice = 14.99f;

    // Act
    Dvd myDvd(expectedTitle, expectedGenre, expectedPrice);

    // Assert
    EXPECT_EQ(myDvd.getTitle(), expectedTitle);
    EXPECT_EQ(myDvd.getGenre(), expectedGenre);
    EXPECT_FLOAT_EQ(myDvd.getPrice(), expectedPrice);
}

// Test de la cohérence avec l'interface IMedia
TEST(DvdTest, PolymorphicBehavior) {
    // Act
    std::unique_ptr<IMedia> media = std::make_unique<Dvd>("The Godfather", Genre::Drama, 19.99f);

    // Assert
    EXPECT_EQ(media->getTitle(), "The Godfather");
    EXPECT_EQ(media->getGenre(), Genre::Drama);
    EXPECT_FLOAT_EQ(media->getPrice(), 19.99f);
}