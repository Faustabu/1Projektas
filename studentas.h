#pragma once
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

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::list;

struct studentas {
    string vardas, pavarde;
    vector<float> paz = {};
    //int egz;
    double gal = 0;
};