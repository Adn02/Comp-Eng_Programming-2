#include "class.h"
#include "function.h"
#include <vector>
#include <string>
#include <iostream>

Foods::Foods(std::string currName, double currCalories, double currFat, double currSugar, double currProtein, double currSodium) 
: foodName{currName}, foodCalories{currCalories}, foodFat{currFat}, foodSugar{currSugar},foodProtein{currProtein}, foodSodium{currSodium}{};

Foods::Foods(double currCalories, double currFat, double currSugar, double currProtein, double currSodium)
: foodCalories{currCalories}, foodFat{currFat}, foodSugar{currSugar},foodProtein{currProtein}, foodSodium{currSodium}{};

Foods Foods::operator+(Foods& selectedIntake) {
    
    selectedIntake.foodCalories  = selectedIntake.foodCalories + foodCalories;
    selectedIntake.foodFat = selectedIntake.foodFat + foodFat;
    selectedIntake.foodSugar = selectedIntake.foodSugar + foodSugar;
    selectedIntake.foodProtein = selectedIntake.foodProtein + foodProtein;
    selectedIntake.foodSodium = selectedIntake.foodSodium + foodSodium;
    
    return selectedIntake;
}

void Foods::compareIntake(Foods& recommendedIntake){
    // Compares Object Class Calories to Recommended Intake
    if(foodCalories > recommendedIntake.foodCalories){
        std::cout << std::endl <<"Energy: " << foodCalories << "/" << recommendedIntake.foodCalories << "g... You exceed the recommended intake" << std::endl;
    }
    // Compares Object Class Fat to Recommended Intake
    if(foodFat > recommendedIntake.foodFat){
        std::cout << "Total fat: " << foodFat << "/" << recommendedIntake.foodFat << "g... You exceed the recommended intake" << std::endl;
    }
    // Compares Object Class Sugars to Recommended Intake
    if(foodSugar > recommendedIntake.foodSugar){
        std::cout << "Total sugars: " << foodSugar << "/" << recommendedIntake.foodSugar << "g... You exceed the recommended intake" << std::endl;
    }
    if(foodProtein > recommendedIntake.foodProtein){
        std::cout << "Total Protein: " << foodProtein << "/" << recommendedIntake.foodProtein << "g... You exceed the recommended intake" << std::endl;
    }
    if(foodSodium > recommendedIntake.foodSodium){
        std::cout << "Total Sodium: " << foodSodium << "/" << recommendedIntake.foodSodium << "g... You exceed the recommended intake" << std::endl;
    }
}

//Print Function
void Foods::Print() const {
    std::cout << std::endl
              << "Energy: "       << foodCalories << " cal. " << std::endl 
              << "Total fat: "    << foodFat << "g." <<  std::endl 
              << "Total Sugars: " << foodSugar << "g." << std::endl 
              << "Protein: "      << foodProtein << "g."  << std::endl 
              << "Sodium: "       << foodSodium << "mg." <<  std::endl;
}

//Mutators

/*
void Foods::setName(std::string currName){
    foodName = currName;
}
void Foods::setCalories(int currCalories){
    foodCalories = currCalories;
}
void Foods::setFat(int currFat){
    foodFat = currFat;
}
void Foods::setSugar(int currSugar){
    foodSugar = currSugar;
}
void Foods::setProtein(int currProtein){
    foodProtein = currProtein;
}
void Foods::setSodium(int currSodium){
    foodSodium = currSodium;
}
*/

//Accesors
std::string Foods::getName() const {
    return foodName;
}
/*
double Foods::getCalories() const {
    return foodCalories;
}
double Foods::getFat() const {
    return foodFat;
}
double Foods::getSugar() const {
    return foodSugar;
}
double Foods::getProtein() const {
    return foodProtein;
}
double Foods::getSodium() const {
    return foodSodium;
}
*/
 
