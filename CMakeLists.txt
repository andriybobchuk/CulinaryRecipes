cmake_minimum_required(VERSION 3.16.3)
project(CulinaryRecips)

set(CMAKE_CXX_STANDARD 14)

add_executable(CulinaryRecips Recipe.cpp Recipe.h functions.cpp functions.h main.cpp FileHandler3000.cpp FileHandler3000.h RecipeBook.cpp RecipeBook.h BakeryRecipe.cpp BakeryRecipe.h PremiumRecipe.cpp PremiumRecipe.h CakeRecipe.cpp CakeRecipe.h)