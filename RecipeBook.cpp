//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include "RecipeBook.h"

void RecipeBook::addNew(Recipe recipe) {
    recipes.push_back(recipe);
}

void RecipeBook::addNew(BakeryRecipe recipe) {
    this->bakeryRecipes.push_back(recipe);
}

void RecipeBook::addNew(PremiumRecipe recipe) {
    this->premiumRecipes.push_back(recipe);
}

void RecipeBook::addNew(CakeRecipe recipe) {
    this->cakeRecipes.push_back(recipe);
}

void RecipeBook::addUserRecipe() {
    std::cout << "Which type of recipe do you want to add? (Pick one):\n";
    std::cout << "normal\n";
    std::cout << "bakery\n";
    std::cout << "premium\n";
    std::cout << "cake\n";
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
        getline(std::cin.ignore(), doughNotes);
        BakeryRecipe recipe(title, description, ingredients, doughNotes);
        bakeryRecipes.push_back(recipe);
    } else if (choice == "premium") {
        std::cout << "PRICE: ";
        std::string price;
        getline(std::cin.ignore(), price);
        PremiumRecipe recipe(title, description, ingredients, stod(price));
        premiumRecipes.push_back(recipe);
    } else if (choice == "cake") {
        std::cout << "DOUGH NOTES: ";
        std::string doughNotes;
        getline(std::cin.ignore(), doughNotes);
        std::cout << "PRICE: ";
        std::string price;
        getline(std::cin.ignore(), price);
        std::cout << "CAKE TYPE: ";
        std::string cakeType;
        getline(std::cin.ignore(), cakeType);
        // Make an object and save it to file
        CakeRecipe recipe(title, description, ingredients, doughNotes, stod(price), cakeType);
        cakeRecipes.push_back(recipe);
    } else {
        // Make an object and save it to file
        Recipe recipe(title, description, ingredients);
        recipes.push_back(recipe);
    }



}

//void RecipeBook::addUserNormal() {
//
//    std::cout << "\tADD NEW RECIPE:\n";
//    std::cout << "TITLE: ";
//    std::string title;
//    getline(std::cin.ignore(), title);
//
//    std::cout << "\nINGREDIENTS: \n";
//    std::string ingredient;
//    std::string ingredients;
//    while (ingredient != "-n") {
//        ingredients += (ingredient + "\n");
//        getline(std::cin, ingredient);
//    }
//
//    std::cout << "\nDESCRIPTION: \n";
//    std::string line;
//    std::string description;
//    while (line != "-n") {
//        description += (line + "\n");
//        getline(std::cin, line);
//    }
//
//    // Make an object and save it to file
//    Recipe recipe(title, description, ingredients);
//    recipes.push_back(recipe);
//}
//void RecipeBook::addUserBakery() {
//
//    std::cout << "\tADD NEW RECIPE:\n";
//    std::cout << "TITLE: ";
//    std::string title;
//    getline(std::cin.ignore(), title);
//
//    std::cout << "\nINGREDIENTS: \n";
//    std::string ingredient;
//    std::string ingredients;
//    while (ingredient != "-n") {
//        ingredients += (ingredient + "\n");
//        getline(std::cin, ingredient);
//    }
//
//    std::cout << "\nDESCRIPTION: \n";
//    std::string line;
//    std::string description;
//    while (line != "-n") {
//        description += (line + "\n");
//        getline(std::cin, line);
//    }
//
//    // Make an object and save it to file
//    Recipe recipe(title, description, ingredients);
//    recipes.push_back(recipe);
//}

void RecipeBook::listRecipes() {

    // For normal Recipe
    for(int i=0; i<recipes.size(); ++i) {
        recipes[i].printRecipe();
    }

    // For bakery recipe
    for (BakeryRecipe recipe : bakeryRecipes) {
        recipe.printRecipe();
    }

    // For prime recipe
    for (PremiumRecipe recipe : premiumRecipes) {
        recipe.printRecipe();
    }

    // For cake recipe
    for (CakeRecipe recipe : cakeRecipes) {
        recipe.printRecipe();
    }

}

// TODO: Implement
void RecipeBook::listRecipes(std::vector<std::string> ingredients) {}


// Getters
const std::vector<Recipe> &RecipeBook::getRecipes() const {
    return recipes;
}

const std::vector<BakeryRecipe> &RecipeBook::getBakeryRecipes() const {
    return bakeryRecipes;
}

const std::vector<PremiumRecipe> &RecipeBook::getPremiumRecipes() const {
    return premiumRecipes;
}

const std::vector<CakeRecipe> &RecipeBook::getCakeRecipes() const {
    return cakeRecipes;
}
