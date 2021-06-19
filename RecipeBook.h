//
// Created by Andriy on 17-Jun-21.
//

#ifndef CULINARYRECIPS_RECIPEBOOK_H
#define CULINARYRECIPS_RECIPEBOOK_H


#include "Recipe.h"
#include "BakeryRecipe.h"
#include <vector>

class RecipeBook {

    std::vector<Recipe> recipes;
    std::vector<BakeryRecipe> specialRecipes;

public:

//    RecipeBook();
//    ~RecipeBook();

    void addNew(Recipe recipe);
    void addNew(BakeryRecipe recipe);
    void listRecipes();
    void listRecipes(std::vector<std::string> ingredients);

    // TODO: + operator

};


#endif //CULINARYRECIPS_RECIPEBOOK_H
