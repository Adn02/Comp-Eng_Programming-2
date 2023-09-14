#include "class.h"
#include <iostream>
#include <iomanip>
#include <vector>

void Hospital::fillDatabase() {
    bool loop = true;
    std::string userInput;
    int idInput;


    int i = 0;

    while (loop == true) {
        Patient temp;
        patientList.push_back(temp);

        std::cout << std::endl << "Please enter your name: ";
        std::cin >> userInput;
        patientList.at(i).setName(userInput);

        std::cout << "Please enter your DOB: ";
        std::cin >> userInput;
        patientList.at(i).setDOB(userInput);

        std::cout << "Please enter your ID: ";
        std::cin >> idInput;
        patientList.at(i).setID(idInput);

        std::cout << std::endl << "Continue? Y/N ";
        std::cin >> userInput;
        if (userInput == "N") {
            loop = false;
            break;
        }
        else {
            i++;
        }
    }
}




Patient::Patient() {
	name = "";
	dateOfBirth = "";
	id = 0;
}


Patient::Patient(std::string name, std::string dateOfBirth, int id){
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->id = id;
}
Patient::~Patient(){}

void Patient::setName(std::string name) {
	this->name = name;
}
void Patient::setDOB(std::string dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}
void Patient::setID(int id) {
	this->id = id;
}
void Patient::printData() {
	
	std::cout << std::setw(10) << name << "\t |    " << dateOfBirth << "\t |     " << id << std::endl;
}

std::string Patient::getName() const {
	return name;
}
std::string Patient::getDOB() const {
	return dateOfBirth;
}
int Patient::getID() const {
	return id;
}

void Hospital::displayDatabase() {
	std::cout << std::setw(9) << "Name" << "\t | \t" << std::setw(3) << "DOB" << "\t | \t" << "ID" << std::endl;
	std::cout << std::string(48, '-') << std::endl;
	for (unsigned int i = 0; i < patientList.size(); i++) {
		patientList.at(i).printData();
	}
}
