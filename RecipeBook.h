//
// Created by Andriy on 17-Jun-21.
//

#ifndef CULINARYRECIPS_RECIPEBOOK_H
#define CULINARYRECIPS_RECIPEBOOK_H

#include "Recipe.h"
#include "BakeryRecipe.h"
#include <vector>

/**
 * Class which represents a book of recipes containing two chapters: chapter with basic recipes and bakery ones.
 * Should have only one instance throughout the app execution.
 */

class RecipeBook {

    std::vector<Recipe> recipes;    /**< A chapter of a recipe book which stores basic recipes */
    std::vector<BakeryRecipe> bakeryRecipes;    /**< A chapter of a book which stores bakery recipes */

public:

    RecipeBook();    //!< Default constructor (Not in use)
    ~RecipeBook();   //!< Destructor

    /**
     * Takes input from user and adds new generated recipe to a book
     */
    void addUserRecipe();

    /**
     * Lists ALL the recipes
     */
    void listRecipes();

    /**
     * Lists ONLY recipes containing ingredients keywords
     * @param ingredients a vector of keywords
     */
    void listRecipes(std::vector<std::string> ingredients);


    // Getters
    const std::vector<Recipe> &getRecipes() const;      //!< gets vector of basic recipes
    const std::vector<BakeryRecipe> &getBakeryRecipes() const;      //!< gets vector of bakery recipes

    // Setters (add elements to vectors)
    void addNew(Recipe recipe);    //!< pushes back to vector of basic recipes
    void addNew(BakeryRecipe recipe);    //!< pushes back to vector of bakery recipes

    // Operators
    void operator + (Recipe recipe);    //!< Same as addNew
    void operator + (BakeryRecipe recipe);  //!< Same as addNew
};


#endif //CULINARYRECIPS_RECIPEBOOK_H
