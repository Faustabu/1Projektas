#pragma once
#ifndef Funkcijos
#define Funkcijos
#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include<chrono> 
#include <random>
#include<list>
#include<deque>

using std::string;
using std::vector;
using std::list;
using std::deque;

struct studentas {
    string vardas, pavarde;
    vector<float> paz = {};
    //int egz;
    float gal = 0;
};

studentas get(list<studentas> lst, int d);
//int random_generatorius();
//vector<int> auto_skaiciai(int pazymiu_kiekis);
//float galutinis_balas(vector<int>skaiciai);
//int generavimas(vector<int> nd_skc);
void failo_skaitymas(list<studentas>& kint, int kiek);
void failo_skaitymas(deque<studentas>& kint, int kiek);
void failo_skaitymas(vector<studentas>& kint, int kiek);
#endif