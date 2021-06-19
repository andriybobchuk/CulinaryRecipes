//
// Created by Andriy on 13-Jun-21.
//

#include <iostream>
#include "functions.h"
#include "FileHandler3000.h"
#include "RecipeBook.h"


int main() {

    // Objects
    RecipeBook recipeBook; // As agreed, only ONE recipe book
    FileHandler3000 FH3K("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json"); // and only 1 FH3K

    // As agreed, at first we reed everything to recipe book
    FH3K.readFile(recipeBook); // Read to recipeBook

    printMenu();
    std::string choice; std::cin >> choice;
    if (choice == "-a") {
        //TODO:
    } else if (choice == "-s") {
        //TODO
    } else if (choice == "-l") {
        recipeBook.listRecipes();
    } else if (choice == "-e") {
        return 0;
    } else {
        std::cerr << "Wrong switch\n";
        printMenu();
    }




    return 0;
}

