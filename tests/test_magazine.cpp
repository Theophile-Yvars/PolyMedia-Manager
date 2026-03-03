#include <gtest/gtest.h>
#include "entities/Magazines.hpp"
#include "entities/Genre.hpp"
#include <memory>

// Groupe de test pour les magazines
TEST(MagazineTest, ConstructorInitializesMembers) {
    // Arrange
    std::string expectedTitle = "Inception";
    Genre expectedGenre = Genre::ScienceFiction;
    float expectedPrice = 14.99f;

    // Act
    Magazines myMagazine(expectedTitle, expectedGenre, expectedPrice);

    // Assert
    EXPECT_EQ(myMagazine.getTitle(), expectedTitle);
    EXPECT_EQ(myMagazine.getGenre(), expectedGenre);
    EXPECT_FLOAT_EQ(myMagazine.getPrice(), expectedPrice);
}

// Test de la cohérence avec l'interface IMedia
TEST(MagazineTest, PolymorphicBehavior) {
    // Act
    std::unique_ptr<IMedia> media = std::make_unique<Magazines>("The Godfather", Genre::Drama, 19.99f);

    // Assert
    EXPECT_EQ(media->getTitle(), "The Godfather");
    EXPECT_EQ(media->getGenre(), Genre::Drama);
    EXPECT_FLOAT_EQ(media->getPrice(), 19.99f);
}