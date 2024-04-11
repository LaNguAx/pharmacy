#pragma once
#include "Main.h"

class Patient
{
private:
	static const int NAME_LENGTH = 20;
	char m_firstName[NAME_LENGTH];
	char m_lastName[NAME_LENGTH];
	long m_id = 0 ;
	int m_diagnoses_count = 0;
	char** m_diagnoses = nullptr;

public:
	Patient(const char* firstName = "undefined", const char* lastName = "undefined", long id = 0) {
		this->init(firstName, lastName, id);
	}

	Patient(const Patient& p) ;

	~Patient();

	//helpers
public:
	
	void init(const char* firstName, const char* lastName, long id);

	bool isValidName(const char* name) const;

	void printPatient() const;

	void printDiagnoses() const;

	int searchDiagnose(const char* diagnose) const;

	void deleteDiagnose(const char* diagnose);

	// setters
public:

	 void setName(const char* name, const char* lastName);

	 void setId(long id) { this->m_id = id; };

	 void addDiagnose(const char* diagnose);

	 void deleteDiagnose(int i) { delete[] this->m_diagnoses[i]; this->m_diagnoses_count--; };
	 void deleteDiagnosis();

	 //getters 
public:
	const char* getFirstName() const { return this->m_firstName; };

	const char* getLastName() const { return this->m_lastName; };

	int getId() const { return this->m_id; };

	int getDiagnosesCount() const {
			return this->m_diagnoses_count; 
	};

	const char* getDiagnose(int i) const { return this->m_diagnoses[i]; };
	

	Patient& operator=(const Patient& p);

};

