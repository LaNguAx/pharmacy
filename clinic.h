#pragma once
#include "Main.h"
#include "Patient.h"

class Clinic
{
	char m_clinicName[20];
	char m_clinicAddress[20];

	int m_numOfPatients;
	Patient** m_patients;



public:

	Clinic(const char* clinicName, const char* clinicAddress);
	Clinic(const Clinic& c);
	Clinic& operator=(const Clinic& c);

	void init(const char* clinicName, const char* clinicAddress);


public:
	void setName(const char* name);
	void setAddress(const char* Address);


public:
	const char* getName() const;
	const char* getAddress() const;
	int getNumOfPatients() const;


public:
	bool addPatient(const Patient& p);
	void deletePatients();
	Patient** copyPatients() const;
	void printClinic() const;
};

