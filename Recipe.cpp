//
// Created by Andriy on 04-Jun-21.
//

#include "Recipe.h"

int Recipe::numOfRecipes{};

Recipe::Recipe(std::string title, std::string description, std::map<std::string, std::string> ingredients) {
    this -> title = title;
    this -> description = description;
    this -> ingredients = ingredients;
    numOfRecipes++;
}

Recipe::~Recipe() {
    numOfRecipes--;
}