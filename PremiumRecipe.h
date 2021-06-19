//
// Created by Andriy on 18-Jun-21.
//

#ifndef CULINARYRECIPS_PREMIUMRECIPE_H
#define CULINARYRECIPS_PREMIUMRECIPE_H


#include "Recipe.h"

class PremiumRecipe : public virtual Recipe {

    double price;

    static int counter;

public:
    // Four arg constructor
    PremiumRecipe(std::string title, std::string description, std::string ingredients, double price);

    // Destructor
    ~PremiumRecipe();

    // Getters
    const double &getPrice() const;

    // Print functions
    void printRecipe();
    void printRecipeTitle();
};


#endif //CULINARYRECIPS_PREMIUMRECIPE_H
