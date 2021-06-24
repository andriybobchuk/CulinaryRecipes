//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include <sstream>
#include "RecipeBook.h"


void RecipeBook::addUserRecipe() {
    std::cout << "Which type of recipe do you want to add? (Pick one):\n";
    std::cout << "  'normal'\n";
    std::cout << "  'bakery'\n";
    std::string choice; std::cin >> choice;
    
    std::cout << "\tADD NEW RECIPE: (-n to go next)\n";
    std::cout << "TITLE: ";
    std::string title;
    getline(std::cin.ignore(), title);

    std::cout << "\nINGREDIENTS: \n";
    std::string ingredient;
    std::string ingredients;
    while (ingredient != "-n") {
        ingredients += (ingredient + "\n");
        getline(std::cin, ingredient);
    }

    std::cout << "\nDESCRIPTION: \n";
    std::string line;
    std::string description;
    while (line != "-n") {
        description += (line + "\n");
        getline(std::cin, line);
    }

    if (choice == "bakery") {
        std::cout << "DOUGH NOTES: ";
        std::string doughNotes;
        getline(std::cin, doughNotes);
        BakeryRecipe recipe(title, description, ingredients, doughNotes);
        bakeryRecipes.push_back(recipe);
    } else {
        // Make an object and save it to file
        Recipe recipe(title, description, ingredients);
        recipes.push_back(recipe);
    }
}

// Normal list function
void RecipeBook::listRecipes() {

    // For normal Recipe
    for(int i=0; i<recipes.size(); ++i) {
        recipes[i].printRecipe();
    }

    // For bakery recipe
    for (BakeryRecipe recipe : bakeryRecipes) {
        recipe.printRecipe();
    }
}

// List function for given keywords
void RecipeBook::listRecipes(std::vector<std::string> ingredients) {

    // Print matching recipes
    // Working currently on AND logic. If you want OR then just change o to 1 and vice versa
    std::cout << "RECIPES MATCHING SEARCH REQUEST:\n";
    bool matchesSearchRequest = true;
    for (int i = 0; i <= getRecipes().size() - 1; i++) {
        for (int j = 0; j <= ingredients.size() - 1; j++) {
            if (getRecipes()[i].getIngredients().find(ingredients[j]) == -1) {
                matchesSearchRequest = false;
            }
        }
        if (matchesSearchRequest) getRecipes()[i].printRecipe();
        matchesSearchRequest = true;
    }

    matchesSearchRequest = true;
    for (int i = 0; i <= getBakeryRecipes().size() - 1; i++) {
        for (int j = 0; j <= ingredients.size() - 1; j++) {
            if (getBakeryRecipes()[i].getIngredients().find(ingredients[j]) == -1) {
                matchesSearchRequest = false;
            }
        }
        if (matchesSearchRequest) getBakeryRecipes()[i].printRecipe();
        matchesSearchRequest = true;
    }
}


// Getters
const std::vector<Recipe> &RecipeBook::getRecipes() const {
    return recipes;
}

const std::vector<BakeryRecipe> &RecipeBook::getBakeryRecipes() const {
    return bakeryRecipes;
}

// Setters for adding elements to vectors
void RecipeBook::addNew(Recipe recipe) {
    recipes.push_back(recipe);
}

void RecipeBook::addNew(BakeryRecipe recipe) {
    this->bakeryRecipes.push_back(recipe);
}

void RecipeBook::operator+(Recipe recipe) {
    recipes.push_back(recipe);
}

void RecipeBook::operator+(BakeryRecipe recipe) {
    recipes.push_back(recipe);
}

RecipeBook::RecipeBook() {}

RecipeBook::~RecipeBook() {}
