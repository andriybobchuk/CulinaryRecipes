//
// Created by Andriy on 18-Jun-21.
//

#ifndef CULINARYRECIPS_BAKERYRECIPE_H
#define CULINARYRECIPS_BAKERYRECIPE_H

#include <string>
#include "Recipe.h"

class BakeryRecipe : public virtual Recipe {

    std::string doughNotes;

    static int counter;

public:
    // Four arg constructor
    BakeryRecipe(std::string title, std::string description, std::string ingredients, std::string doughNotes);

    // Destructor
    ~BakeryRecipe();

    // Getters
    const std::string &getDoughNotes() const;

    // Print functions
    void printRecipe() const;
    void printRecipeTitle();
};


#endif //CULINARYRECIPS_BAKERYRECIPE_H
