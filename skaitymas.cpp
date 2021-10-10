#include "inc.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;
using std::vector;
using std::setw;

#include "struct.h"


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
