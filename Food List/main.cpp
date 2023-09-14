#include "class.h"
#include "function.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<Foods> foodList
    {
        //Food(Names, Calories, Fat, Sugar, Protein, Sodium)
            {
            {Foods("Apple", 80, 0, 16, 0, 0)},
            {Foods("Frozen Pizza", 410, 20, 5, 15, 810)},
            {Foods("Chunky Peanut Butter", 188, 16, 3, 8, 5)},
            {Foods("White Rice", 100, 0, 0, 2, 3)},
            {Foods("Protein Bar", 110, 4, 11, 4, 60)},
            {Foods("Chicken Breast", 110, 2.5, 0, 20, 250)},
            {Foods("Greek Yogurt", 300, 23, 7, 15, 65)},
            {Foods("Instant Ramen", 187, 7, 1, 4, 861)},
            {Foods("Whopper Hamburger", 510, 23, 11, 28, 840)},
            {Foods("Wendys Frosty", 342, 6, 53, 8, 214)}
            }
    };
    
    userInput(foodList);
    
    
    return 0;
}
