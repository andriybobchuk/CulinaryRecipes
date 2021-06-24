//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include <iomanip>
#include "FileHandler3000.h"
#include "json.hpp"


// Constructor
FileHandler3000::FileHandler3000(std::string recipeBookFile) {
    this->recipeBookFile = recipeBookFile;
}

void FileHandler3000::readFile(RecipeBook &recipeBook) {

    std::ifstream file(recipeBookFile); // Input file stream for our file path

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
                if(j["recipes"][i].size() == 3) {
                    // Construct Recipe object filling the appropriate fields
                    Recipe currentRecipe(j["recipes"][i]["title"],
                                         j["recipes"][i]["description"],
                                         j["recipes"][i]["ingredients"]);
                    // Adding this Recipe object to recipe book
                    //recipeBook.addNew(currentRecipe);
                    recipeBook + currentRecipe;

                } else if (j["recipes"][i].size() == 4) {

                    if(j["recipes"][i].size() == 4) {
                        // Construct Recipe object filling the appropriate fields
                        BakeryRecipe currentRecipe(j["recipes"][i]["title"],
                                                   j["recipes"][i]["description"],
                                                   j["recipes"][i]["ingredients"],
                                                   j["recipes"][i]["doughNotes"]);
                        // Adding this Recipe object to recipe book
                        recipeBook.addNew(currentRecipe);
                        //recipeBook + currentRecipe;
                    }
                }
            }
        }
    } catch (const std::exception &e) {
        std::cout << "Smth's wrong with your file :(" << e.what() << '\n';
        throw;
    }
}

void FileHandler3000::writeFile(RecipeBook &recipeBook) {

    std::ifstream file(recipeBookFile); // Input file stream for our file path
    nlohmann::json j = nlohmann::json::parse(file);


    int continuity = 0;
    for (int i = 0; i <= recipeBook.getRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
        j["recipes"][i] = {{"title", recipeBook.getRecipes()[i].getTitle()},
                           {"description", recipeBook.getRecipes()[i].getDescription()},
                           {"ingredients", recipeBook.getRecipes()[i].getIngredients()}};
    }
    for (int i = 0; i <= recipeBook.getBakeryRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
            j["recipes"][continuity] =
                    {{"title", recipeBook.getBakeryRecipes()[i].getTitle()},
                     {"description", recipeBook.getBakeryRecipes()[i].getDescription()},
                     {"ingredients", recipeBook.getBakeryRecipes()[i].getIngredients()},
                     {"doughNotes", recipeBook.getBakeryRecipes()[i].getDoughNotes()}};
    }



        // Saving to file
        std::ofstream o(recipeBookFile);
        o << std::setw(4) << j << std::endl;

}