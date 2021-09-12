// v01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

struct studentas
{
	string vardas, pavarde;
	float nd[10]{};
	float egz;
	float gal;
};

void pildymas(studentas &kint);
void spausdinimas(studentas &k);

int main()
{
	studentas st1;
	studentas st2{ "Vardenis2", "Pavardenis2",5,8,9,9,7,6,5,4,10,0,8,0 };
	
	//pildymas(st1);
	//spausdinimas(st1);
	studentas stud[10];
	for (int i = 0; i < 2; i++)
	{
		pildymas(stud[i]);
	};
	for (int i = 0; i < 2; i++) {
		spausdinimas(stud[i]);
	};
	return 0;
}

void pildymas(studentas& kint) {
	int n;
	float suma, vidurkis;
	cout << "iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
	cout << "iveskite namu darbu skaiciu(1-10): "; cin >> n;
	cout << "iveskite pazymius: " << endl;
	suma = 0;
	vidurkis = 0;
	 
		for (int i = 0; i < n; i++) {
			cin >> kint.nd[i];
			suma += kint.nd[i];
		}
		vidurkis = suma / n;
		cout << "iveskite egzamino rezultata: "; cin >> kint.egz;
		kint.gal = vidurkis * 0.4 + kint.egz * 0.6;
	
	
}
void spausdinimas(studentas& k) {
	cout << k.vardas << " " << k.pavarde<<" " << endl;
	cout << "Pazymiai: ";
	for (int i = 0; i < sizeof(k.nd) / sizeof(k.nd[0]); i++)
	{
		cout << k.nd[i] << ", ";
	}
	cout << " " << endl;
	cout << "egzamino rez: "<< fixed << setprecision(2)<< k.egz<<endl;
	cout << "galutinis rez: " << fixed << setprecision(2)<< k.gal<<endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
