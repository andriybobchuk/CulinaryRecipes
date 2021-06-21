//
// Created by Andriy on 17-Jun-21.
//

#include <iostream>
#include <iomanip>
#include "FileHandler3000.h"
#include "json.hpp"
#include "Recipe.h"
#include "RecipeBook.h"
#include "BakeryRecipe.h"
#include "PremiumRecipe.h"
#include "CakeRecipe.h"


// Constructor
FileHandler3000::FileHandler3000(std::string recipeBookFile) {
    this->recipeBookFile = recipeBookFile;
}

void FileHandler3000::readFile(RecipeBook &recipeBook) {

    std::ifstream file(recipeBookFile); // Input file stream for our file path

    // this try is for the case when file does not exist or whatever
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
                /**
                 * Now attention!
                 * There are various (4) types of recipes in book.
                 * Depending on the input (NUmber of field in each recipe in particular) we receive, the appropriate
                 * recipe class constructor is called:
                 */
                /// For normal recipe
                if(j["recipes"][i].size() == 3) {
                    // Construct Recipe object filling the appropriate fields
                    Recipe currentRecipe(j["recipes"][i]["title"],
                                         j["recipes"][i]["description"],
                                         j["recipes"][i]["ingredients"]);
                    // Adding this Recipe object to recipe book
                    recipeBook.addNew(currentRecipe);

                /// For bakery recipe
                /// Attention#2: Bakery recipe has the same number of fields as a premium recipe (Which could be
                /// a problem choosing which type of recipe we need to create), BUT(!) they have different field types,
                /// so here I am just trying to call each of two constructors(if not one then another will work)
                /// + Not to crash the program after every unlucky try I surround code with try/catch
                } else if (j["recipes"][i].size() == 4) {

                    try {
                        // Construct Recipe object filling the appropriate fields
                        BakeryRecipe currentRecipe(j["recipes"][i]["title"],
                                                   j["recipes"][i]["description"],
                                                   j["recipes"][i]["ingredients"],
                                                   j["recipes"][i]["doughNotes"]);
                        // Adding this Recipe object to recipe book
                        recipeBook.addNew(currentRecipe);
                    } catch (const std::exception &e) {
                        //std::cout << "Haha, I'm not gonna catch anything xD\n";
                    }
                    try {
                        // Construct Recipe object filling the appropriate fields
                        PremiumRecipe currentRecipe(j["recipes"][i]["title"],
                                                   j["recipes"][i]["description"],
                                                   j["recipes"][i]["ingredients"],
                                                   j["recipes"][i]["price"]);
                        // Adding this Recipe object to recipe book
                        recipeBook.addNew(currentRecipe);
                    } catch (const std::exception &e) {}

                /// Now for CookieRecipe
                } else {
                    // Construct Recipe object filling the appropriate fields
                    CakeRecipe currentRecipe(j["recipes"][i]["title"],
                                                j["recipes"][i]["description"],
                                                j["recipes"][i]["ingredients"],
                                                j["recipes"][i]["doughNotes"],
                                             j["recipes"][i]["price"],
                                             j["recipes"][i]["cakeType"]);
                    // Adding this Recipe object to recipe book
                    recipeBook.addNew(currentRecipe);
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

    // Fo all four vectors from 0 to end print recipes to recipe book
    // print contents of 1 vector to file

    int continuity = 0;
    for (int i = 0; i <= recipeBook.getRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
        j["recipes"][i] = {{"titleNEW", recipeBook.getRecipes()[i].getTitle()},
                           {"description", recipeBook.getRecipes()[i].getDescription()},
                           {"ingredients", recipeBook.getRecipes()[i].getIngredients()}};
    }

    for (int i = 0; i <= recipeBook.getBakeryRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
            j["recipes"][continuity] =
                                 {{"titleNEW", recipeBook.getBakeryRecipes()[i].getTitle()},
                                 {"description", recipeBook.getBakeryRecipes()[i].getDescription()},
                                 {"ingredients", recipeBook.getBakeryRecipes()[i].getIngredients()},
                                 {"doughNotes", recipeBook.getBakeryRecipes()[i].getDoughNotes()}};
    }

    for (int i = 0; i <= recipeBook.getPremiumRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
            j["recipes"][continuity] = {{"titleNEW", recipeBook.getPremiumRecipes()[i].getTitle()},
                               {"description", recipeBook.getPremiumRecipes()[i].getDescription()},
                               {"ingredients", recipeBook.getPremiumRecipes()[i].getIngredients()},
                               {"price", recipeBook.getPremiumRecipes()[i].getPrice()}};
    }

    for (int i = 0; i <= recipeBook.getCakeRecipes().size()-1; i++, continuity++) {
        nlohmann::json::iterator c = j.find("recipes");

        if (c.key() == "recipes") // If we found an array called "RECIPES"
            j["recipes"][continuity] = {{"titleNEW", recipeBook.getCakeRecipes()[i].getTitle()},
                               {"description", recipeBook.getCakeRecipes()[i].getDescription()},
                               {"ingredients", recipeBook.getCakeRecipes()[i].getIngredients()},
                               {"doughNotes", recipeBook.getCakeRecipes()[i].getDoughNotes()},
                               {"price", recipeBook.getCakeRecipes()[i].getTitle()},
                               {"cakeType", recipeBook.getCakeRecipes()[i].getCakeType()}};
    }


        // Saving to file
        std::ofstream o(recipeBookFile);
        o << std::setw(4) << j << std::endl;

}
//    nlohmann::json::iterator c = j.find("recipes");
//    if (c.key() == "recipes") // If we found an array called "RECIPES"
//    {
//        // From each element of JSON array we compose a Recipe object
//        for (int i = 0; i <= c.value().size() - 1; i++) {
//
//
//        }
//    }
//    j["recipes"][]



//    // Adding one more recipe as the next JSON array's object
//    j["recipes"][objectsFromFile().size()] = {{"title", recipe.getTitle()},
//                                              {"description", recipe.getDescription()},
//                                              {"ingredients", recipe.getIngredients()}};
//
//    // Saving to file
//    std::ofstream o("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
//    o << std::setw(4) << j << std::endl;
//}


