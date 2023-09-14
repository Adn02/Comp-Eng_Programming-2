#include "class.h"
#include "function.h"
#include <vector>
#include <string>
#include <iostream>

void displayFoods(std::vector<Foods>& foodList){
    for(int i = 0; i < foodList.size(); i++){
            std::cout << "("<< i+1 << ") "  << foodList.at(i).getName() << std::endl;
    }
}

void userInput(std::vector<Foods>& foodList){
    
    Foods selectedIntake{0,0,0,0,0};
    Foods recommendedIntake{2000,70,30,50,2300};
    
    std::string input;
    
    int inputInt;
    
    bool loop = true;
    
    //Display Food List
    displayFoods(foodList);
    std::cout << "(11) Exit" << std::endl <<"Select a Food: ";
    
    //Loop until user enters 11 (Exit)
    while(loop == true){
        std::cin >> input;
        //Check to see if Input is valid
        inputInt = atoi(input.c_str());
        if(inputInt == 11){
            loop == false;
            break;
        }else if(inputInt == 0 || inputInt > foodList.size()){
            std::cout << "Invalid Input, Try again..." << std::endl;
        }else{
            selectedIntake = selectedIntake + foodList.at(inputInt-1);
            std::cout << "Select another food: ";
        }
    }
    
    selectedIntake.compareIntake(recommendedIntake);
    selectedIntake.Print();
}

