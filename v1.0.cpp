#include "studentas.h"
using std::cout;
using std::cin;
using std::endl;

template<class C>
void antra_strategija(C& studentai, C& v, double& balas);
template<class C>
void pirma_strategija(C& studentai, C& v, C& n, double& balas);

int main()
{
    int kiek;
    // cout << "iveskite pazymiu kieki: ";
     //cin >> paz;
    double balas = 5.00;
    //auto_skaiciai(paz);
    vector<int> skaiciai;

    //int kiek = generavimas(skaiciai);
    cout << "kiek studentu " << endl; cin >> kiek;

    list <studentas> duom;
    list<studentas> galvociai;
    list<studentas> nuskriaustukai;
    vector<studentas> duomvec;
    vector<studentas> galvociaivec;
    vector<studentas> nuskriaustukaivec;
    deque<studentas> duomdeq;
    deque<studentas> nuskriaustukaideq;
    deque<studentas> galvociaideq;

    int galvoc = 0;
    int nuskr = 0;
    string pavad1, pavad2;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << std::fixed;
    //------------------------------------------------LIST----------------------------------------
    failo_skaitymas(duom, kiek);

    start = std::chrono::high_resolution_clock::now();

   /* for (const auto& laik : duom) {
        if (laik.gal < balas) {
            nuskriaustukai.push_back(laik);
        }
        else {
            galvociai.push_back(laik);
        }
    }*/
    pirma_strategija(duom, galvociai, nuskriaustukai, balas);

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su list uztruko( su pirma strategija):  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
     pavad1 = "nuskriaustukai_" + std::to_string(kiek) + ".txt";
     std::ofstream nuskr_failas(pavad1);


     for (const auto& laik : duom)
     {
         if (laik.gal < balas) {
             nuskr_failas << laik.vardas << std::setw(20) << laik.pavarde << std::setw(20) << laik.gal << endl;
         }
     }
   

     end = std::chrono::high_resolution_clock::now();
     diff = end - start;
     //cout << "Surūšiuotų studentų išvedimas į failą - nuskriaustukai:  " << diff.count() << endl;



     start = std::chrono::high_resolution_clock::now();

     pavad2 = "galvociai_" + std::to_string(kiek) + ".txt";
     std::ofstream galvoc_failas(pavad2);


     for (const auto& laik : duom)
     {
         if (laik.gal >= balas) {
             galvoc_failas << laik.vardas << std::setw(20) << laik.pavarde << std::setw(20) << laik.gal << endl;
         }
     }

     
     using std::remove;
     using std::rename;
     string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";
     //remove(pavadinimas);
    

     
     galvociai.clear();
     nuskriaustukai.clear();

     end = std::chrono::high_resolution_clock::now();
     diff = end - start;
     //cout << "Surūšiuotų studentų išvedimas į failą - galvočiai:  " << diff.count() << endl;


     start = std::chrono::high_resolution_clock::now();
     antra_strategija(duom, nuskriaustukai, balas);
     end = std::chrono::high_resolution_clock::now();
     diff = end - start;
     cout << "Studentu rusiavimas i dvi grupes su list uztruko( su antra strategija):  " << diff.count() << endl;
    
     
     //---------------------------------------VECTOR-----------------------------------------
    failo_skaitymas(duomvec, kiek);

    start = std::chrono::high_resolution_clock::now();

    pirma_strategija(duomvec, galvociaivec, nuskriaustukaivec, balas);


    
    galvociaivec.clear();
    nuskriaustukaivec.clear();
    
    galvociaivec.shrink_to_fit();
    nuskriaustukaivec.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector uztruko:  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    antra_strategija(duomvec, nuskriaustukaivec, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector uztruko( su antra strategija):  " << diff.count() << endl;
    //--------------------DEQUE----------------------------------------------
    failo_skaitymas(duomdeq, kiek);
    start = std::chrono::high_resolution_clock::now();

    pirma_strategija(duomdeq, galvociaideq, nuskriaustukaideq, balas);
    
    galvociaideq.clear();
    nuskriaustukaideq.clear();
    
    galvociaideq.shrink_to_fit();
    nuskriaustukaideq.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su deque uztruko:  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    antra_strategija(duomdeq, nuskriaustukaideq, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su deque uztruko( su antra strategija):  " << diff.count() << endl;
}

studentas get(list<studentas> lst, int d) {
    list<studentas>::iterator itr = lst.begin();
    for (int i = 0; i < d; i++) ++itr;

    return *itr;
}


template<class C>
void antra_strategija(C & studentai, C & v, double& balas) {
    for (auto it = studentai.begin(); it != studentai.end();) {
        if (it->gal < balas){
            v.push_back(*it);
           it = studentai.erase(it);
        }
        else { it++; }
    }

}

template<class C>
void pirma_strategija (C& studentai, C& v, C& n, double& balas) {
    for (auto it = studentai.begin(); it != studentai.end(); it++) {
        if (it->gal >= balas) {
            v.push_back(*it);
            
        }
        else { 
            n.push_back(*it); }

    }

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
        cout << "nuskaitymas su listu uztruko: " << diff.count() << endl;
    }

}
void failo_skaitymas(vector<studentas>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now();
    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            kint.resize(kint.size() + 1);

            skaitymas >> kint.at(stud).vardas;
            skaitymas >> kint.at(stud).pavarde;
            skaitymas >> kint.at(stud).gal;
            stud += 1;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "nuskaitymas su vectoriumi uztruko: " << diff.count() << endl;
}


void failo_skaitymas(deque<studentas>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now();
    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            kint.resize(kint.size() + 1);

            skaitymas >> kint.at(stud).vardas;
            skaitymas >> kint.at(stud).pavarde;
            skaitymas >> kint.at(stud).gal;
            stud += 1;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "nuskaitymas su deque uztruko: " << diff.count() << endl;
}
