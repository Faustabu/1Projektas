// v01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::swap;

struct studentas
{
	string vardas, pavarde;
	float nd[10]{};
	float egz;
	float galvid;
	float galmed;
};

void pildymas(studentas& kint);
void spausdinimas(studentas& k);

int main()
{
	studentas st1{};
	//studentas st2{ "Vardenis2", "Pavardenis2",5,8,9,9,7,6,5,4,10,0,8,0 };

	pildymas(st1);
	spausdinimas(st1);
	/*studentas stud[10];
	for (int i = 0; i < 2; i++)
	{
		pildymas(stud[i]);
	};
	for (int i = 0; i < 2; i++)
	{
		skaiciavimai(stud[i]);
	}
	for (int i = 0; i < 2; i++) {
		spausdinimas(stud[i]);
	};*/
	return 0;
}

void pildymas(studentas& kint) {
	int n;
	cout << "iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
	cout << "iveskite namu darbu skaiciu(1-10): "; cin >> n;
	cout << "iveskite pazymius: " << endl;

	for (int i = 0; i < n; i++) {
		cin >> kint.nd[i];
	}

	cout << "iveskite egzamino rezultata: "; cin >> kint.egz;

	float suma, vidurkis, mediana;
	suma = 0;
	vidurkis = 0;
	mediana = 0;
	for (int i = 0; i < n; i++) {
		suma += kint.nd[i];
		for (int j = i + 1; j < n; j++) {
			if (kint.nd[i] > kint.nd[j]) {
				swap(kint.nd[i], kint.nd[j]);
			}
		}
		cout << kint.nd[i] << ", ";

	}
	if (n % 2 != 0)
	{
		mediana = kint.nd[n / 2];
	}
	else {
		mediana = ((kint.nd[(n - 1) / 2]) + kint.nd[n / 2]) / 2;
	}

	cout << "m=" << mediana << endl;
	vidurkis = suma / n;
	kint.galvid = vidurkis * 0.4 + kint.egz * 0.6;
	kint.galmed = mediana * 0.4 + kint.egz * 0.6;




}



void spausdinimas(studentas& k) {
	cout << k.vardas << " " << k.pavarde << " " << endl;
	cout << "Pazymiai: ";
	for (int i = 0; i < sizeof(k.nd) / sizeof(k.nd[0]); i++)
	{
		cout << k.nd[i] << ", ";
	}
	cout << " " << endl;

	cout << "egzamino rez: " << fixed << setprecision(2) << k.egz << endl;
	cout << "galutinis rez(vid): " << fixed << setprecision(2)<< k.galvid<<endl;
	cout << "galutinis rez(med):  " << fixed << setprecision(2) << k.galmed << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
