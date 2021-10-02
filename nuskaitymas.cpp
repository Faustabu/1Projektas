#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::vector;
using std::setw;

struct studentas {
    string vardas, pavarde;
    vector<float> nd = { 0 };
    float egz;
    float galvid;
    float galmed;
};

void skaitymas(vector<studentas>& Eil, int* pazymiu_sk);
void spausdinimas(vector<studentas> Eil, int pazymiu_sk);

int main()
{
    int pazymiu_sk;
    char temp;
    vector<studentas> Eil;
    skaitymas(Eil, &pazymiu_sk);
    //spausdinimas(Eil, pazymiu_sk);
    //system("pause");
    cout << setw(20) << std::left << "Vardas"
        << setw(20) << std::left << "Pavarde"
        << setw(18) << std::left << "Galutinis(vid.)" << "\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
         for (int j = i + 1; j < Eil.size(); j++) {
            if (Eil[i].vardas > Eil[j].vardas) {
                std::swap(Eil[i].vardas, Eil[j].vardas);
                std::swap(Eil[i].pavarde, Eil[j].pavarde);
                std::swap(Eil[i].galvid, Eil[j].galvid);
                }
         }
        cout << setw(20) << std::left<< Eil[i].vardas
            << setw(20) << std::left << Eil[i].pavarde
            << setw(18) << std::left <<fixed << setprecision(2)<< Eil[i].galvid << endl;

    }
    cout << "\n\n";
    return 0;
}


unsigned int countWordsInString(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}




void skaitymas(vector<studentas>& Eil, int* pazymiu_sk)
{
    int student_counter = 0;
    float temp, s ;
    std::ifstream fileRead;
    string buff;
    fileRead.open("kursiokai.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> std::ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            Eil.resize(Eil.size() + 1);
            fileRead >> Eil.at(student_counter).vardas;
            if (fileRead.eof()) { Eil.pop_back(); break; }
            fileRead >> Eil.at(student_counter).pavarde;
            s=0;
            for (int i = 0; i < *pazymiu_sk; i++)
          
            {
                fileRead >> temp;
                Eil.at(student_counter).nd.push_back(temp);
                s+=temp;
                
            }
           // std::sort(Eil.at(student_counter).nd, );

            fileRead >> Eil.at(student_counter).egz;

            Eil.at(student_counter).galvid = s / *pazymiu_sk;
            
            Eil.at(student_counter).galvid = Eil.at(student_counter).galvid * 0.4 + 0.6 * Eil.at(student_counter).egz;

           // Eil.at(student_counter).galmed = 

            student_counter++;
        }
    }
    else { cout << "-\n"; }
}





/*void spausdinimas(vector<studentas> Eil, int pazymiu_sk)
{
    std::ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << std::left << "Vardas"
        << setw(20) << std::left << "Pavarde"
        << setw(18) << std::left << "Galutinis(vid.)" << "\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < Eil.size(); i++)
    {
         for (int j = i + 1; j < Eil.size(); j++) {
            if (Eil[i].vardas > Eil[j].vardas) {
                std::swap(Eil[i].vardas, Eil[j].vardas);}
         }
        output << setw(20) << std::left << Eil[i].vardas
            << setw(20) << std::left << Eil[i].pavarde
            << setw(18) << std::left << Eil[i].galvid << endl;

    }
    output << "\n\n";
}*/
