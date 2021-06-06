//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"
#include "json.hpp"
#include "Recipe.h"

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



void mainMenu () {
    std::cout << "======================================================                \n";
    std::cout << "MAIN MENU                                                             \n";
    std::cout << "Type a switch:                                                        \n";
    std::cout << "-a    to add new recipe                                              \n";
    std::cout << "-s    to search for the recipe by ingredient                         \n";
    std::cout << "-l    to list names of all known recipes                             \n";

    std::string choice;
    std::cin >> choice;

    if (choice == "-a") {
        inputToObject();
    } else if (choice == "-s") {
        searchAndList();
    } else if (choice == "-l") {
        listRecipes();
    } else {
        std::cerr << "Wrong switch\n";
        mainMenu();
    }
}

void searchAndList () {
    // Read users ingredients one by one to vector
    std::cout << "ENTER INGREDIENTS TO SEARCH: ";
    std::string line;
    getline(std::cin.ignore(), line); // ignore because of a newline char contained in cin
    std::istringstream iss(line);
    std::vector<std::string> inputStrings;
    for (std::string s; iss >> s; inputStrings.push_back(s));


    // TODO: correct finding words with commas
    // Print matching recipes
    std::cout << "RECIPES MATCHING SEARCH REQUEST:\n";
    bool matchesSearchRequest = true;
    for (int i = 0; i <= objectsFromFile().size() - 1; i++) {
        for (int j = 0; j <= inputStrings.size() - 1; j++) {
            if (objectsFromFile()[i].getIngredients().find(inputStrings[j]) == std::string::npos) {
                matchesSearchRequest = false;
            }
        }
        if (matchesSearchRequest) objectsFromFile()[i].printRecipe();
    }

    std::cout << "BACK TO MENU (0) \n";
    int choice;
    std::cin >> choice;
    if (choice == 0) {
        mainMenu();
    }
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
        mainMenu();
    }
}

