//
// Created by Andriy on 17-Jun-21.
//

#ifndef CULINARYRECIPS_FILEHANDLER3000_H
#define CULINARYRECIPS_FILEHANDLER3000_H


#include <fstream>
#include "RecipeBook.h"

class FileHandler3000 {

    std::string recipeBookFile;

public:
    FileHandler3000(std::string recipeBookFile);

    void readFile(RecipeBook &recipeBook);
    void writeFile();


};


#endif //CULINARYRECIPS_FILEHANDLER3000_H
