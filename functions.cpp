//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"
#include "json.hpp"
#include "Recipe.h"
#include "RecipeBook.h"


void inputToObject () {

    std::cout << "\tADD NEW RECIPE:\n";
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

    // Make an object and save it to file
    Recipe recipe(title, description, ingredients);
    objectToFile(recipe);
}


void objectToFile (Recipe &recipe) {
    std::ifstream file("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
    nlohmann::json j = nlohmann::json::parse(file);

    // Adding one more recipe as the next JSON array's object
    j["recipes"][objectsFromFile().size()] = {{"title", recipe.getTitle()},
                                              {"description", recipe.getDescription()},
                                              {"ingredients", recipe.getIngredients()}};

    // Saving to file
    std::ofstream o("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
    o << std::setw(4) << j << std::endl;

}








std::vector<Recipe> objectsFromFile () {
    std::ifstream file("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
    nlohmann::json j = nlohmann::json::parse(file);

    // Vector of RECIPE objects which we will fill using JSON objects
    std::vector<Recipe> recipes;

    // Reading JSON
    nlohmann::json::iterator c = j.find("recipes");
    if (c.key() == "recipes")
    {
        // From each element of JSON array we compose a Recipe object
        for (int i = 0; i <= c.value().size()-1; i++)
        {
            // Construct Recipe object filling the appropriate fields
            Recipe currentRecipe(j["recipes"][i]["title"],
                     j["recipes"][i]["description"],
                     j["recipes"][i]["ingredients"]);

            // Adding this Recipe object to vector of objects
            recipes.push_back(currentRecipe);

        }
    }
    return recipes;
}



void printMenu () {
    std::cout << "\n                               CULINARY E-BOOK                             \n";
    std::cout << " _____________________________________Menu_________________________________  \n";
    std::cout << "| Type a switch:                                                           | \n";
    std::cout << "|  -a    to add new recipe                                                 | \n";
    std::cout << "|  -s    to search for the recipe by ingredient                            | \n";
    std::cout << "|  -l    to list names of all known recipes                                | \n";
    std::cout << "|  -e    to finish session                                                 | \n";
    std::cout << "|                                                                          | \n";
    std::cout << "|                                                                          | \n";
    std::cout << "|                                                                          | \n";
    std::cout << "|__________________________________________________________________________| \n";
    std::cout << "What do you want to do?: ";

}

void searchAndList () {

}

void listRecipes () {
    std::cout << "FOUND " << objectsFromFile().size() << " RECIPES:\n";

    for (int i = 0; i <= objectsFromFile().size() - 1; i ++) {
        objectsFromFile()[i].printRecipe();
    }

    std::cout << "BACK TO MENU (0) \n";
    int choice;
    std::cin >> choice;
    if (choice == 0) {
        printMenu();
    }
}

