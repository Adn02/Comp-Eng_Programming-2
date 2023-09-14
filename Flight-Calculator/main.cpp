#include "lib.h"
#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;

int main(){
    
    vector<string> locations(10);
    vector<double> lat(10);
    vector<double> longitude(10);
    
    string input;
    
    int inputInt;
    double lat1, lat2, long1, long2, tempLat, tempLong;
    double RADIUS = 3958.8;
    
    locations = {"Miami Beach, FL","Fargo, ND", "Idaho City, ID","Bloomington, IN","Saint Augustine, FL","Detroit, MI","Charlotte, NC","Ontario, CA","Las Vegas, NV", "New York City, NY"};
    lat = {25.793449, 46.877186,  43.828850, 39.168804, 29.908072, 42.331429, 35.227085, 34.068871, 36.114647, 40.730610};
    longitude = {-80.139198, -96.789803, -115.837860, -86.536659, -81.324791, -83.045753, -80.843124, -117.651215, -115.172813, -73.935242};
    
    cout << "Choose a Departure Location:" << endl;
    //Gathers user Input as well as removing the selected destination
    userInput(locations,lat,longitude, tempLat, tempLong);
    
    //Set latitude 1 and longitude 1 to departure location chosen
    lat1 = tempLat;
    long1 = tempLong;
    
    cout << "Choose a Destination Location:" << endl;
    //Gathers user Input as well as removing the selected destination
    userInput(locations,lat,longitude, tempLat, tempLong);
    
    //Set latitude 2 and longitude 2 to destination
    lat2 = tempLat;
    long2 = tempLong;
    
    //Calculates and displays the distance between locations
    cout << "The Distance between the two destinations is: " << haversine(lat1,long1,lat2,long2,RADIUS) << " miles" << endl;;
    double distMI = haversine(lat1,long1,lat2,long2,RADIUS);
    //Calculates and displays the flight time between locations
    cout << "The Travel time between the two destinations is: " << getFlightTime(lat1,long1,lat2,long2,distMI) << " hours" << endl;
    
    
    
    
    return 0;
}
