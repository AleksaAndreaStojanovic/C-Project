#include "Cetvrta.h"
#include<vector>
#include"Ucenik.h"
#include<iostream>
#include<string>
#include<istream>
#include<fstream>

Cetvrta::Cetvrta()
{
}

Cetvrta::Cetvrta(int u_id, string ime, string pol, int godina, int mesec, int dan, double Matematika, double Srpski, double Engleski, double Istorija, double Geografija, double Ustav, double Sociologija)
    :Ucenik(u_id, ime, pol, godina, mesec, dan, Matematika, Srpski, Engleski, Istorija, Geografija) {
    this->Ustav = Ustav;
    this->Sociologija = Sociologija;
}

double Cetvrta::getUstav()
{
    return Ustav;
}


void Cetvrta::setUstav(double Ustav)
{
    this->Ustav = Ustav;
}

double Cetvrta::getSociologija()
{
    return Sociologija;
}

void Cetvrta::setSociologija(double Sociologija)
{
    this->Sociologija = Sociologija;
}


void Cetvrta::upis() {
    Cetvrta stu;
    char temp[50];

    while (1) {
        cout << "Unesite ID ucenika cetvrte godine: (4 BROJA)" << endl;
        cin >> temp;
        stu.setId(atoi(temp));
        cout << "Unesite ime ucenika:" << endl;
        cin >> temp;
        stu.setIme(temp);
        cout << "Unesite pol: (M/Z)" << endl;
        cin >> temp;
        if (!strcmp(temp, "M") || !strcmp(temp, "Z")) {

        }
        else {
            //  cout << "Unet je pogresan format!" << endl;
        }
        stu.setPol(temp);
        cout << "--Datum rodjenja--" << endl;
        cout << endl;
        cout << "Unesite godinu:";
        cin >> temp;
        stu.setGodina(atoi(temp));
        cout << "Unesite mesec:";
        cin >> temp;
        stu.setMesec(atoi(temp));
        cout << "Unesite dan:";
        cin >> temp;
        stu.setDan(atoi(temp));
        cout << "Ocene iz predmeta:" << endl;
        cout << endl;
        cout << " Ocena iz matematike: ";
        cin >> temp;
        stu.setMatematika(atof(temp));
        cout << "Ocena iz srpskog: ";
        cin >> temp;
        stu.setSrpski(atof(temp));
        cout << "Ocena iz engleskog: ";
        cin >> temp;
        stu.setEngleski(atof(temp));
        cout << "Ocena iz istorije: ";
        cin >> temp;
        stu.setIstorija(atof(temp));
        cout << "Ocena iz geografije: ";
        cin >> temp;
        stu.setGeografija(atof(temp));

        cout << "Ocena iz ustava: ";
        cin >> temp;
        stu.setUstav(atof(temp));

        cout << "Ocena iz sociologije: ";
        cin >> temp;
        stu.setSociologija(atof(temp));

        cetvrtaVector.push_back(stu);
        break;
    }
}

void Cetvrta::ispis() {
    ifstream fin;
    fin.open("razred3.txt");
    if (!fin) {
        cerr << "Error in opening the file" << endl;
    }
    Cetvrta a;
    int id_st;
    string ime;
    string pol;
    int dina;
    int mjesec;
    int day;
    double mat;
    double srp;
    double eng;
    double ist;
    double geo;
    double ust;
    double soc;
    ostream_iterator<Cetvrta> output(cout, "");
    cetvrtaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> ust >> soc) {

        a.setId(id_st);
        a.setIme(ime);
        a.setPol(pol);
        a.setGodina(dina);
        a.setMesec(mjesec);
        a.setDan(day);
        a.setMatematika(mat);
        a.setSrpski(srp);
        a.setEngleski(eng);
        a.setIstorija(ist);
        a.setGeografija(geo);
        a.setUstav(ust);
        a.setSociologija(soc);

        cetvrtaVector.push_back(a);
    }
    cout << "Rezultat pretrage: " << endl;
    copy(cetvrtaVector.begin(), cetvrtaVector.end(), output);

    fin.close();

}

void Cetvrta::obrisi() {
    ifstream fin;
    fin.open("razred4.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Cetvrta a;
    int id;
    int id_st;
    string ime;
    string pol;
    int dina;
    int mjesec;
    int day;
    double mat;
    double srp;
    double eng;
    double ist;
    double geo;
    double ust;
    double soc;
    cout << "Unesite redni broj ucenika cetvrte godine koje zelite da izbrisete:  ";
    cin >> id;
    cetvrtaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> ust >> soc) {
        a.setId(id_st);
        a.setIme(ime);
        a.setPol(pol);
        a.setGodina(dina);
        a.setMesec(mjesec);
        a.setDan(day);
        a.setMatematika(mat);
        a.setSrpski(srp);
        a.setEngleski(eng);
        a.setIstorija(ist);
        a.setGeografija(geo);
        a.setUstav(ust);
        a.setSociologija(soc);
        cetvrtaVector.push_back(a);
    }
    for (auto it = cetvrtaVector.begin(); it != cetvrtaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << " OBRISANO: " << *it << endl;
            cetvrtaVector.erase(it);
            break;
        }
    }
    upisUfajl();
}

void Cetvrta::izmeni() {
    ifstream fin;
    fin.open("razred4.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Cetvrta a;
    //Prva izmena;
    int id;
    int id_st;
    string ime;
    string pol;
    int dina;
    int mjesec;
    int day;
    double mat;
    double srp;
    double eng;
    double ist;
    double geo;
    double ust;
    double soc;
    ostream_iterator<Cetvrta> output(cout, "");
    cout << "Unesite redni broj ucenika cetvrte godine koje zelite da izmenite:  ";
    cin >> id;
    cetvrtaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> ust >> soc) {
        a.setId(id_st);
        a.setIme(ime);
        a.setPol(pol);
        a.setGodina(dina);
        a.setMesec(mjesec);
        a.setDan(day);
        a.setMatematika(mat);
        a.setSrpski(srp);
        a.setEngleski(eng);
        a.setIstorija(ist);
        a.setGeografija(geo);
        a.setUstav(ust);
        a.setSociologija(soc);
        cetvrtaVector.push_back(a);
    }
    for (auto it = cetvrtaVector.begin(); it != cetvrtaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << "Unesite ime ucenika:" << endl;
            cin >> ime;
            cout << "Unesite pol: (M/Z)" << endl;
            cin >> pol;
            cout << "--Datum rodjenja--" << endl;
            cout << endl;
            cout << "Unesite godinu:";
            cin >> dina;
            cout << "Unesite mesec:";
            cin >> mjesec;
            cout << "Unesite dan:";
            cin >> day;
            cout << "Ocene iz predmeta:" << endl;
            cout << endl;
            cout << "Ocena iz matematike: ";
            cin >> mat;
            cout << "Ocena iz srpskog: ";
            cin >> srp;
            cout << "Ocena iz engleskog: ";
            cin >> eng;
            cout << "Ocena iz istorije: ";
            cin >> ist;
            cout << "Ocena iz geografije: ";
            cin >> geo;
            cout << "Ocena iz ustava: ";
            cin >> ust;
            cout << "Ocena iz sociologije: ";
            cin >> soc;
            it->setIme(ime);
            it->setPol(pol);
            it->setGodina(dina);
            it->setMesec(mjesec);
            it->setDan(day);
            it->setMatematika(mat);
            it->setSrpski(srp);
            it->setEngleski(eng);
            it->setIstorija(ist);
            it->setGeografija(geo);
            it->setUstav(ust);
            it->setSociologija(soc);
            break;
        }
    }
    upisUfajl();
}

void Cetvrta::pretraga() {
    ifstream fin;
    fin.open("razred4.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    int id;
    Cetvrta a;
    int id_st;
    string ime;
    string pol;
    int dina;
    int mjesec;
    int day;
    double mat;
    double srp;
    double eng;
    double ist;
    double geo;
    double ust; double soc;
    ostream_iterator<Cetvrta> output(cout, " ");
    cout << "Unesite id ucenika cetvrte godine kog zelite naci:" << endl;
    cin >> id;
    cetvrtaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> ust >> soc) {

        a.setId(id_st);
        a.setIme(ime);
        a.setPol(pol);
        a.setGodina(dina);
        a.setMesec(mjesec);
        a.setDan(day);
        a.setMatematika(mat);
        a.setSrpski(srp);
        a.setEngleski(eng);
        a.setIstorija(ist);
        a.setGeografija(geo);
        a.setUstav(ust);
        a.setSociologija(soc);

        cetvrtaVector.push_back(a);
    }

    for (auto it = cetvrtaVector.begin(); it != cetvrtaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << *it << endl;
        }
    }
    fin.close();

}

void Cetvrta::upisUfajl() {
    Cetvrta a;
    ofstream out("razred4.txt");

    for (auto it = cetvrtaVector.begin(); it != cetvrtaVector.end(); ++it) {

        out << it->getId() << " " << it->getIme() << " " << it->getPol() << " " << it->getGodina()
            << " " << it->getMesec() << " " << it->getDan() << " " << it->getMatematika() << " "
            << it->getSrpski() << " " << it->getEngleski() << " " <<
            it->getIstorija() << " " << it->getGeografija() << " " << it->getUstav() << " " << it->getSociologija() << endl;
    }
    out.close();
}

bool operator==(Cetvrta const& cetvrta1, Cetvrta const& cetvrta2) {
    if (cetvrta1.u_id == cetvrta2.u_id) {

        cout << "Objekat je pronadjen!" << endl;
        return true;
    }
    else {
        cout << "Objekat nije pronadjen!" << endl;
        return false;

    }
}

istream& operator>>(istream& is, Cetvrta& ucenik) {

    is >> ucenik.u_id;
    is >> ucenik.ime;
    is >> ucenik.pol;
    is >> ucenik.godina;
    is >> ucenik.mesec;
    is >> ucenik.dan;
    is >> ucenik.Matematika;
    is >> ucenik.Srpski;
    is >> ucenik.Engleski;
    is >> ucenik.Istorija;
    is >> ucenik.Geografija;
    is >> ucenik.Ustav;
    is >> ucenik.Sociologija;

    return is;

}

ostream& operator<<(ostream& out, const Cetvrta& cetvrta) {

    out << cetvrta.u_id << ", " << cetvrta.ime << ", " << cetvrta.pol << ", "
        << cetvrta.godina << ", " << cetvrta.mesec << ", " << cetvrta.dan << ", "
        << cetvrta.Matematika << ", " << cetvrta.Srpski << ", " << cetvrta.Engleski
        << ", " << cetvrta.Istorija << ", " << cetvrta.Geografija << ", " << cetvrta.Ustav << ", " << cetvrta.Sociologija << endl;
    return out;

}


