//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include "FileHandler3000.h"
#include "json.hpp"
#include "Recipe.h"
#include "RecipeBook.h"
#include "BakeryRecipe.h"


// Constructor
FileHandler3000::FileHandler3000(std::string recipeBookFile) {
    this->recipeBookFile = recipeBookFile;
}

void FileHandler3000::readFile(RecipeBook &recipeBook) {


    std::ifstream file("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json"); // Input file stream for our file path

    try {
        nlohmann::json j = nlohmann::json::parse(file); // Object to read JSON file

        // Reading JSON
        // Looking for array called "RECIPES"
        nlohmann::json::iterator c = j.find("recipes");
        if (c.key() == "recipes") // If we found an array called "RECIPES"
        {
            // From each element of JSON array we compose a Recipe object
            for (int i = 0; i <= c.value().size()-1; i++)
            {
                // If statement for different recipes
                if(j["recipes"][i].size() == 3) {
                    // Construct Recipe object filling the appropriate fields
                    Recipe currentRecipe(j["recipes"][i]["title"],
                                         j["recipes"][i]["description"],
                                         j["recipes"][i]["ingredients"]);
                    // Adding this Recipe object to recipe book
                    recipeBook.addNew(currentRecipe);
                } else {
                    // Construct Recipe object filling the appropriate fields
                    BakeryRecipe currentRecipe(j["recipes"][i]["title"],
                                         j["recipes"][i]["description"],
                                         j["recipes"][i]["ingredients"],
                                         j["recipes"][i]["ultraSpecialFeature"]);
                    // Adding this Recipe object to recipe book
                    recipeBook.addNew(currentRecipe);
                }
            }
        }
    } catch (const std::exception &e) {
        std::cout << ":(" << e.what() << '\n';
        throw;
    }


}

//void FileHandler3000::writeFile() {
//    std::ifstream inFile(this->recipeBookFile); // Input file stream for our file path
//    std::ofstream outFile(this->recipeBookFile); // Output file stream for our file path
//
//    nlohmann::json j = nlohmann::json::parse(inFile);
//
//
//
//    // Adding one more recipe as the next JSON array's object
//    j["recipes"][objectsFromFile().size()] = {{"title", recipe.getTitle()},
//                                              {"description", recipe.getDescription()},
//                                              {"ingredients", recipe.getIngredients()}};
//
//    // Saving to file
//    std::ofstream o("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
//    o << std::setw(4) << j << std::endl;
//}


