#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <string>

class Foods{
    
    public:
    
    //Constructor
    Foods(std::string currName, double currCalories, double currFat, double currSugar, double currProtein, double currSodium);
    //Constructor for Totals
    Foods(double currCalories, double currFat, double currSugar, double currProtein, double currSodium);
    //Overloading Operator
    Foods operator+(Foods& selectedIntake);
    //Compare Selected Intake to Recommended Intake
    void compareIntake(Foods& recommendedIntake);
    
    /*
    //Mutators
    void setName(std::string currName);
    void setCalories(int currCalories);
    void setFat(int currFat);
    void setSugar(int currSugar);
    void setProtein(int currProtein);
    void setSodium(int currSodium);
    */
    
    //Accessors
    std::string getName() const;
    /*
    double getCalories() const;
    double getFat() const;
    double getSugar() const;
    double getProtein() const;
    double getSodium() const;
    */
    void Print() const;
    
    
    private:
    std::string foodName;
    double foodCalories{}, foodFat{}, foodSugar{}, foodProtein{}, foodSodium{};
    double totalCal{}, totalFat{}, totalSugar{}, totalProtein{}, totalSodium{};
};


#endif
