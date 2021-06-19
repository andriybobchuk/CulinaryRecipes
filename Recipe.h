//
// Created by Andriy on 04-Jun-21.
//

#ifndef CULINARYRECIPS_RECIPE_H
#define CULINARYRECIPS_RECIPE_H


#include <string>

class Recipe {

    std::string title;
    std::string description;
    std::string ingredients;

    static int counter;

public:
    // Triple argument constructor
    Recipe(std::string title, std::string description, std::string ingredients);

    // Destructor
    ~Recipe();

    // Getters
    const std::string &getIngredients() const;
    const std::string &getTitle() const;
    const std::string &getDescription() const;

    // Print functions
    void printRecipe();
    void printRecipeTitle();
};


#endif //CULINARYRECIPS_RECIPE_H
