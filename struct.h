#pragma once


struct studentas {
    string vardas, pavarde;
    vector<float> nd = { 0 };
    float egz;
    float galvid;
    float galmed;
};


void spausdinimas(vector<studentas> Eil, int pazymiu_sk);
void skaitymas(vector<studentas>& Eil, int* pazymiu_sk);

