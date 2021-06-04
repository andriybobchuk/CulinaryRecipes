//
// Created by Andriy on 04-Jun-21.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.h"
#include "json.hpp"

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




//    if (c.key() == "recipes")
//    {
//        std::cout << c.key().at(0);
//    }




    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
}


void readFile() {


    std::ifstream inFile;
    inFile.open("C:\\Users\\Andriy\\CLionProjects\\CulinaryRecips\\input.txt");

    if (!inFile) {
        std::cerr << "Unable to open file to read recipes from";
        exit(1);   // call system to stop
    }

    char character;
    std::string word;
    std::string sLine;
    while (!inFile.eof())//While Not end of file
    {
        character = inFile.get();//reading file with spaces
        word += character;
        if (word == "TITLE:") {

            while (!inFile.eof())//While Not end of file
            {
                getline(inFile, sLine);
            }

            std::cout << sLine << std::endl;

            word = "";
        }



        //std::cout << sLine << std::endl;

    }
    inFile.close();

}

void writeXML () {

}

