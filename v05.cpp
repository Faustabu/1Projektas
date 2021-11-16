#include "studentas.h"

studentas get(list<studentas> lst, int d) {
    list<studentas>::iterator itr = lst.begin();
    for (int i = 0; i < d; i++) ++itr;
    return *itr;
}

int random_generatorius()
{
    // srand(time(NULL));
    int r = rand() % 10 + 1;
    return r;
}

vector<int> auto_skaiciai(int pazymiu_kiekis)
{
    vector<int> sk;
    for (int i = 0; i < pazymiu_kiekis; i++) {
        sk.push_back(random_generatorius());
    }
    return sk;
}

float galutinis_balas(vector<int>skaiciai)
{
    studentas eile;
    eile.gal = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * random_generatorius();
    return eile.gal;
}


int generavimas(vector<int> nd_skc) {
    int kiek;
    cout << "iveskite studentu skaiciu: "; cin >> kiek;

    //auto start = std::chrono::high_resolution_clock::now();

    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";
    std::ofstream isvedimas(pavadinimas);
    vector<int> skaiciai;
    studentas eile;
    isvedimas << std::setw(20) << std::left << "Vardas" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Gal.(vid)" << endl;

    for (int i = 1; i <= kiek; i++)
    {
        skaiciai = auto_skaiciai(5);
        isvedimas << std::setw(20) << "Vardas" + std::to_string(i) <<
            std::setw(20) << "Pavarde" + std::to_string(i) <<
            std::setw(18) << galutinis_balas(skaiciai) << std::endl;
        skaiciai.clear();

    }

    // auto end = std::chrono::high_resolution_clock::now();
     //std::chrono::duration<double> diff = end - start;
     //cout << "studentų failo sukūrimas užtruko: " << diff.count() << endl;

    return kiek;
}


void failo_skaitymas(list<studentas>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";


    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            //kint.resize(kint.size() + 1);
            studentas student;
            skaitymas >> student.vardas;
            skaitymas >> student.pavarde;
            skaitymas >> student.gal;
            kint.push_back(student);
            stud += 1;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "nuskaitymas uztruko: " << diff.count() << endl;
    }

}


int main()
{
    int paz;
    cout << "iveskite pazymiu kieki: ";
    cin >> paz;
    float balas = 5.00;
    auto_skaiciai(paz);
    vector<int> skaiciai;

    int kiek = generavimas(skaiciai);
    cout << kiek << endl;
    list <studentas> duom;
    failo_skaitymas(duom, kiek);
    list<studentas> galvociai;
    list<studentas> nuskriaustukai;
    int galvoc = 0;
    int nuskr = 0;
    string pavad1, pavad2;

    auto start1 = std::chrono::high_resolution_clock::now();


   for (const auto& laik : duom) {
        if (laik.gal < balas) {
            nuskriaustukai.push_back(laik);
        }
        else {
            galvociai.push_back(laik);
        }
   }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;
    cout << "Studentu rusiavimas i dvi grupes uztruko:  " << diff1.count() << endl;

    auto start2 = std::chrono::high_resolution_clock::now();


    pavad1 = "nuskriaustukai_" + std::to_string(kiek) + ".txt";
    std::ofstream nuskr_failas(pavad1);

    for (int l = 0; l < kiek; l++)
    {
        if (get(duom, l).gal < balas) {

            nuskr_failas << get(duom, l).vardas << std::setw(20) << get(duom, l).pavarde << std::setw(20) << get(duom, l).gal << endl;
        }
    }
    

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    //cout << "Surūšiuotų studentų išvedimas į failą - nuskriaustukai:  " << diff2.count() << endl;



    auto start3 = std::chrono::high_resolution_clock::now();

    pavad2 = "galvociai_" + std::to_string(kiek) + ".txt";
    std::ofstream galvoc_failas(pavad2);

    for (int k = 0; k < kiek; k++)
    {
        if (get(duom, k).gal >= balas) {

            galvoc_failas << get(duom, k).vardas << std::setw(20) << get(duom, k).pavarde << std::setw(20) << get(duom, k).gal << endl;
        }
    }
    duom.clear();
    galvociai.clear();
    nuskriaustukai.clear();
    
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff3 = end3 - start3;
    //cout << "Surūšiuotų studentų išvedimas į failą - galvočiai:  " << diff3.count() << endl;
}
