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


int main()
{
    int pazymiu_sk;
    char temp;
    vector<studentas> Eil;
    skaitymas(Eil, &pazymiu_sk);
    
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
