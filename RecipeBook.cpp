//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include "RecipeBook.h"

void RecipeBook::addNew(Recipe recipe) {
    recipes.push_back(recipe);
}

void RecipeBook::addNew(BakeryRecipe recipe) {
    this->specialRecipes.push_back(recipe);
}

void RecipeBook::listRecipes() {

    // We have two recipe vectors to print so I use 2 loops to do it


    // For normal Recipe
    for(int i=0; i<recipes.size(); ++i) {
        recipes[i].printRecipe();
    }

    // For special recipe
    for (BakeryRecipe recipe : specialRecipes) {
        recipe.printRecipe();
    }
}

// TODO: Implement
void RecipeBook::listRecipes(std::vector<std::string> ingredients) {}
