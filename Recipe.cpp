//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include "Recipe.h"

int Recipe :: counter = 0;

Recipe::Recipe(std::string title, std::string description, std::string ingredients) {
    this -> title = title;
    this -> description = description;
    this -> ingredients = ingredients;
    //std::cerr << "Object was created.\n";
    counter++;
}

Recipe::~Recipe() {
    //std::cerr << "Object was destroyed.\n";
    counter--;
}

void Recipe::printRecipe() const {
    std::cout << "======================================================\n";
    std::cout << "TITLE: \n" << this->title << "\n\nDESCRIPTION: \n" << this->description << "\n\nINGREDIENTS: \n" << this->ingredients << "\n\n";
}

void Recipe::printRecipeTitle() {
    std::cout << this->title;
}

// Getters
const std::string &Recipe::getIngredients() const {
    return ingredients;
}

const std::string &Recipe::getTitle() const {
    return title;
}

const std::string &Recipe::getDescription() const {
    return description;
}
