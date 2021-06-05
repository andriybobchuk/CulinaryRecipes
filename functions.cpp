//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"
#include "json.hpp"
#include "Recipe.h"

void writeJSON () {
    nlohmann::json j =
            {
                    {
                            "recipes",
                            {
                                    {
                                            {"title", "Varenyky"},
                                            {"description", "take water, put varenyky inside"},
                                            {"ingredients", "flour, water, that's all"}
                                    },
                                    {
                                            {"title", "Hot Dog"},
                                            {"description", "description of my hot dog"},
                                            {"ingredients", "sausage, ketchup, that's all"}
                                    },
                                    {
                                            {"title", "Borsch"},
                                            {"description", "kurwa"},
                                            {"ingredients", "beetroot, water, that's all"}
                                    }
                            }
                    }
            };


    // Adding one more recipe
    j["recipes"][3] = {{"title","A"},{"description","B"},{"ingredients","C"}};


    // Saving to file
    std::ofstream o("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\CulinaryBook.json");
    o << std::setw(4) << j << std::endl;


    //nlohmann::json::iterator c = j.find("recipes");
    std::cout << j["recipes"][2]["title"];
    j["recipes"][3]["title"] = "kawa";
    j["recipes"][3] = {{"title","A"},{"description","B"},{"ingredients","C"}};









    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
}




std::vector<Recipe> jsonToObjects () {
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

