#pragma once
#include "Main.h"
#include "Patient.h"
#include "Clinic.h"

using namespace std;
int main(void) {

	Patient p1("Moshe", "Amar");

	p1.setId(123123123);

	p1.addDiagnose("abc");
	p1.addDiagnose("efg");
	p1.addDiagnose("hij");

	//p1.printPatient();


	//std::cout << " ******************** " << std::endl;

	//p1.deleteDiagnose("abc");
	//p1.deleteDiagnose("asofkpasf");
	//p1.deleteDiagnose("efg");
	//p1.deleteDiagnose("hij");
	//p1.deleteDiagnose("foapksf");


	p1.setId(455315112);

	//p1.printPatient();

	Patient p2 = p1;
	p2.setName("Yuda", "Baba");
	p2.setId(1223555);

	p2.addDiagnose("aosfpkasf");

	//p2.printPatient();


	//std::cout << "******************" << std::endl;

	Patient p3("Dod", "Yakar", 5123123);

	Patient p4 = p3;

	//p4.printPatient();


	p1 = p2;

	//std::cout << "******************" << std::endl;

	//p1.deleteDiagnose("abc");
	p1.addDiagnose("testing");
	//p1.printPatient();


	p2 = p1;


	//p2.deleteDiagnose("testing");
	p2.setName("Hi", "There");
	//p2.printPatient();



	// Clinic
	Clinic c("Klien Clinic", "TLV");
	//c.printClinic();

	c.addPatient(p1);
	c.addPatient(p2);
	c.addPatient(p3);
	c.printClinic();



	return 0;
}