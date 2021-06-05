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
    Recipe(std::string title, std::string description, std::string ingredients);

    ~Recipe();

    void printRecipe();

    void printRecipeTitle();

    const std::string &getIngredients() const;


};


#endif //CULINARYRECIPS_RECIPE_H
