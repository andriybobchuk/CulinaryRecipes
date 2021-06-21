//
// Created by Andriy on 17-Jun-21.
//

#ifndef CULINARYRECIPS_RECIPEBOOK_H
#define CULINARYRECIPS_RECIPEBOOK_H


#include "Recipe.h"
#include "BakeryRecipe.h"
#include "PremiumRecipe.h"
#include "CakeRecipe.h"
#include <vector>

class RecipeBook {

    std::vector<Recipe> recipes;
//    std::vector<BakeryRecipe> bakeryRecipes;
//    std::vector<PremiumRecipe> premiumRecipes;
//    std::vector<CakeRecipe> cakeRecipes;

public:

//    RecipeBook();
//    ~RecipeBook();

    void addNew(Recipe recipe);
//    void addNew(BakeryRecipe recipe);
//    void addNew(PremiumRecipe recipe);
//    void addNew(CakeRecipe recipe);

    void addUserRecipe();

    void listRecipes();
    void listRecipes(std::vector<std::string> ingredients);

    // TODO: + operator


    // Getters
    const std::vector<Recipe> &getRecipes() const;
//    const std::vector<BakeryRecipe> &getBakeryRecipes() const;
//    const std::vector<PremiumRecipe> &getPremiumRecipes() const;
//    const std::vector<CakeRecipe> &getCakeRecipes() const;
};


#endif //CULINARYRECIPS_RECIPEBOOK_H
