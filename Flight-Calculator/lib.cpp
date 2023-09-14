#include "lib.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>


double haversine(double lat1, double long1, double lat2, double long2, double RADIUS){
    
    double dLat = (lat2-lat1)*M_PI/180; 
    double dLon = (long2-long1)*M_PI/180;
    lat1 = (lat1) * M_PI / 180; 
    lat2 = (lat2) * M_PI / 180;
    
    double area = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    
    double distMI = RADIUS * (2 * asin(sqrt(area)));
    
    return distMI;
}

double getFlightTime(double lat1, double long1, double lat2, double long2, double distMI){
    
    int flightSpeed = 500;
    double flightTime = distMI / flightSpeed;
    
    return flightTime;
}

void displayLocations(std::vector<std::string>& locations){
    for(int i = 0; i < locations.size(); i++){
        std::cout <<" (" << (i+1) << ") " << locations.at(i) << std::endl;
    }
}

void removeEntry(std::vector<std::string>& locations,std::vector<double>& lat,std::vector<double>& longitude, int inputInt){
    for(int i = 0; i < locations.size(); i++){
        if(inputInt == (i+1)){
            locations.erase(locations.begin()+i);
            lat.erase(lat.begin()+i);
            longitude.erase(longitude.begin()+i);
        }

    }
}

void userInput(std::vector<std::string>& locations,std::vector<double>& lat,std::vector<double>& longitude, double &tempLat, double &tempLong){
    std::string input;
    int inputInt;
    bool loop = true;
    
    //Loop until user selects a destination (prevents crash on invalid input)
    while(loop == true){
        //Display destinations
        displayLocations(locations);
        std::cout << "Select a Location: ";
        std::cin >> input;
        std::cout << std::endl;
        
        //Check to see if Input is valid
        inputInt = atoi(input.c_str());;
        if(inputInt == 0 || inputInt > locations.size()){
            std::cout << "Invalid Input, Try again..." << std::endl;
        }else{
            loop == false;
            tempLat = lat.at((inputInt-1));
            tempLong = longitude.at((inputInt-1));
            
            removeEntry(locations, lat, longitude, inputInt);
            break;
        }
    }
    
}

