//
// Created by Andriy on 18-Jun-21.
//

#include <iostream>
#include "CakeRecipe.h"

int CakeRecipe :: counter = 0;

CakeRecipe:: CakeRecipe(std::string title, std::string description, std::string ingredients,
                        std::string doughNotes, double price, std::string cakeType)
                        : Recipe(title, description, ingredients),
                        PremiumRecipe(title, description, ingredients, price),
                        BakeryRecipe(title, description, ingredients, doughNotes)
                         {
    this -> cakeType = cakeType;
    counter++;
}

CakeRecipe::~CakeRecipe() {
    counter--;
}

void CakeRecipe::printRecipe() {
    std::cout << "======================================================\n";
    std::cout << "TITLE: \n" << this->getTitle() << "\n\nDESCRIPTION: \n" << getDescription()
              << "\n\nINGREDIENTS: \n" << getIngredients() << "\n\nPRICE: \n" << getPrice()
              << "\n\nNOTES: \n" << getDoughNotes() << "\n\nCAKE TYPE: \n" << getCakeType()<< "\n\n";
}

void CakeRecipe::printRecipeTitle() {
    std::cout << this->getTitle();
}

// Getters
const std::string &CakeRecipe::getCakeType() const {
    return cakeType;
}