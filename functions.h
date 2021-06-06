//
// Created by Andriy on 04-Jun-21.
//

#ifndef CULINARYRECIPS_FUNCTIONS_H
#define CULINARYRECIPS_FUNCTIONS_H

#include <vector>
#include "Recipe.h"

/**
 * Reads JSON file and returns vector of Recipe objects
 * @return vector of Recipe objects
 */
std::vector<Recipe> objectsFromFile ();

void inputToObject ();

void mainMenu ();

void listRecipes ();

void searchAndList ();

void objectToFile (Recipe &recipe);

#endif //CULINARYRECIPS_FUNCTIONS_H
