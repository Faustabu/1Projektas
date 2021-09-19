#include <iostream>
#include <iomanip>
#include<string>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::swap;
using std::vector;

struct studentas
{
	string vardas, pavarde;
	vector <float> nd;
	float egz;
	float galvid;
	float galmed;
};

void pildymas(studentas& kint);
void spausdinimas(studentas& k);

int main()
{
	//studentas st1{};
	//studentas st2{ "Vardenis2", "Pavardenis2",5,8,9,9,7,6,5,4,10,0,8,0 };

	studentas stud[10];
	for (int i = 0; i < 2; i++)
	{
		pildymas(stud[i]);
		spausdinimas(stud[i]);
	};
	return 0;
}

void pildymas(studentas& kint) {
	vector<studentas>grupe;
	int n;
	float laik;
	cout << "iveskite studento varda ir pavarde: "; cin >> kint.vardas >> kint.pavarde;
	//cout << "iveskite namu darbu skaiciu(1-10): "; cin >> n;
	cout << "iveskite pazymius: " << endl;

	while (cin>>n) {
		kint.nd.push_back(n);
	}
	cin.clear();
	cin.ignore(10000, '\n');

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

	cout << "mediana = " << mediana << endl;
	vidurkis = std::accumulate(kint.nd.begin(), kint.nd.end(), 0.0) / kint.nd.size();
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
	cout << "galutinis rez(vid): " << fixed << setprecision(2) << k.galvid << endl;
	cout << "galutinis rez(med):  " << fixed << setprecision(2) << k.galmed << endl;
}
