//
// Created by Andriy on 04-Jun-21.
//

#ifndef CULINARYRECIPS_RECIPE_H
#define CULINARYRECIPS_RECIPE_H


#include <string>

class Recipe {

    std::string title;
    std::string description;
    std::string ingredients;

    static int numOfRecipes;

public:
    Recipe(std::string title, std::string description, std::string ingredients);

    ~Recipe();

    void toString();

};


#endif //CULINARYRECIPS_RECIPE_H
