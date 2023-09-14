#ifndef LIB_H
#define LIB_H

#include <vector>
#include <string>

double haversine(double lat1, double long1, double lat2, double long2, double RADIUS);
double getFlightTime(double lat1, double long1, double lat2, double long2, double distMI);
void displayLocations(std::vector<std::string>& locations);
void userInput(std::vector<std::string>& locations,std::vector<double>& lat,std::vector<double>& longitude, double &tempLat, double &tempLong);
void removeEntry(std::vector<std::string>& locations,std::vector<double>& lat,std::vector<double>& longitude, int intInput);

#endif
