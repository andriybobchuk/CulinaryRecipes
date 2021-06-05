//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include "Recipe.h"

int Recipe::numOfRecipes{};

Recipe::Recipe(std::string title, std::string description, std::string ingredients) {
    this -> title = title;
    this -> description = description;
    this -> ingredients = ingredients;
    numOfRecipes++;
}

Recipe::~Recipe() {
    numOfRecipes--;
}

void Recipe::toString() {
    std::cout << "======================================================\n";
    std::cout << "TITLE: \n" << this->title << "\n\nDESCRIPTION: \n" << this->description << "\n\nINGREDIENTS: \n" << this->ingredients << "\n\n";
}