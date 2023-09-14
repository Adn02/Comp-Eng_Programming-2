#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <vector>


class Patient{
public:
	Patient();
	Patient(std::string name, std::string dateOfBirth, int id);
	~Patient();

	void setName(std::string name);
	void setDOB(std::string dateOfBirth);
	void setID(int id);

	std::string getName() const;
	std::string getDOB() const;
	int getID() const;

	void printData();
	

private:
	std::string name;
	std::string dateOfBirth;
	int id;
};


class Hospital {
public:
	void fillDatabase();
	void displayDatabase();

private:
	std::vector<Patient> patientList;
};


#endif