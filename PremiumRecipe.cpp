//
// Created by Andriy on 18-Jun-21.
//

#include <iostream>
#include "PremiumRecipe.h"

int PremiumRecipe :: counter = 0;

PremiumRecipe::PremiumRecipe(std::string title, std::string description, std::string ingredients, double price)
        : Recipe(title, description, ingredients) {
    this -> price = price;
    counter++;
}

PremiumRecipe::~PremiumRecipe() {
    counter--;
}

void PremiumRecipe::printRecipe() {
    std::cout << "======================================================\n";
    std::cout << "TITLE: \n" << getTitle() << "\n\nDESCRIPTION: \n" << getDescription()
              << "\n\nINGREDIENTS: \n" << getIngredients() << "\n\nPRICE: \n" << getPrice() << "\n\n";
}

void PremiumRecipe::printRecipeTitle() {
    std::cout << this->getTitle();
}

// Getters
const double &PremiumRecipe::getPrice() const {
    return price;
}