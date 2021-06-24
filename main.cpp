//
// Created by Andriy on 13-Jun-21.
//

#include <iostream>
#include <sstream>
#include "functions.h"
#include "FileHandler3000.h"


int main() {

    // Objects
    RecipeBook recipeBook; // As agreed, only ONE recipe book
    FileHandler3000 FH3K("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json"); // and only 1 FH3K

    // As agreed, at first we read everything to recipe book
    FH3K.readFile(recipeBook); // Read to recipeBook

    // Now user can choose what to do
    std::string choice;
    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == "-a") {
            recipeBook.addUserRecipe();

        } else if (choice == "-s") {
            // Getting keywords to search from the keyboard
            std::cout << "ENTER INGREDIENTS TO SEARCH: "; std::string line; getline(std::cin.ignore(), line);
            std::istringstream iss(line); std::vector<std::string> ingredients;
            for (std::string s; iss >> s; ingredients.push_back(s));

            // And list recipes by those keywords
            recipeBook.listRecipes(ingredients);

        } else if (choice == "-l") {
            recipeBook.listRecipes();

        } else if (choice == "-e") {
            // Saving recipe book instance to file
            FH3K.writeFile(recipeBook);
            return 0;

        } else {
            std::cerr << "Wrong switch\n";
        }
    }

}

