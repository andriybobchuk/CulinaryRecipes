//
// Created by Andriy on 18-Jun-21.
//

#include <iostream>
#include "BakeryRecipe.h"

int BakeryRecipe :: counter = 0;

// Constructor
BakeryRecipe::BakeryRecipe(std::string title, std::string description, std::string ingredients, std::string doughNotes)
: Recipe(title, description, ingredients) {
    this -> doughNotes = doughNotes;
    counter++;
}

// Destructor
BakeryRecipe::~BakeryRecipe() {
    //std::cerr << "Object was destroyed.\n";
    counter--;
}


// Print functions
void BakeryRecipe::printRecipe() const {
    std::cout << "======================================================\n";
    std::cout << "TITLE: \n" << getTitle() << "\n\nDESCRIPTION: \n" << getDescription()
    << "\n\nINGREDIENTS: \n" << getIngredients() << "\n\nNOTES: \n" << getDoughNotes() << "\n\n";
}
void BakeryRecipe::printRecipeTitle() {
    std::cout << this->getTitle();
}


// Getters
const std::string &BakeryRecipe::getDoughNotes() const {
    return doughNotes;
}