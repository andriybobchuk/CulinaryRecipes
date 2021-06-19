//
// Created by Andriy on 18-Jun-21.
//

#ifndef CULINARYRECIPS_CAKERECIPE_H
#define CULINARYRECIPS_CAKERECIPE_H


#include "PremiumRecipe.h"
#include "BakeryRecipe.h"

class CakeRecipe : public BakeryRecipe, public PremiumRecipe {

    std::string cakeType;

    static int counter;

public:
    // Four arg constructor
    CakeRecipe(std::string title, std::string description, std::string ingredients,
                 std::string doughNotes, double price, std::string cakeType);

    // Destructor
    ~CakeRecipe();

    // Getters
    const std::string &getCakeType() const;

    // Print functions
    void printRecipe();
    void printRecipeTitle();
};


#endif //CULINARYRECIPS_CAKERECIPE_H
