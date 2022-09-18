#include "Druga.h"
#include<vector>
#include"Ucenik.h"
#include<iostream>
#include<string>
#include<istream>
#include<fstream>


Druga::Druga() {
	Set_Type(2);
}

Druga::Druga(int u_id, string ime, string pol, int godina, int mesec, int dan, double Matematika, double Srpski, double Engleski, double Istorija, double Geografija, double Fizika, double Hemija) 
    :Ucenik(u_id, ime, pol, godina, mesec, dan, Matematika, Srpski, Engleski, Istorija, Geografija) {
	this->Hemija = Hemija;
	this->Fizika = Fizika;
}

double Druga::getFizika()
{
	return Fizika;
}

void Druga::setFizika(double Fizika)
{
	this->Fizika = Fizika;
}

double Druga::getHemija()
{
	return Hemija;
}

void Druga::setHemija(double Hemija){
	this->Hemija = Hemija;
}

void Druga::upis(){
    Druga stu;
    char temp[50];

    while (1) {
        cout << "Unesite ID ucenika druge godine: (4 BROJA)" << endl;
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

        cout << "Ocena iz fizike: ";
        cin >> temp;
        stu.setFizika(atof(temp));

        cout << "Ocena iz hemije: ";
        cin >> temp;
        stu.setHemija(atof(temp));

        drugaVector.push_back(stu);
        break;
    }
}

void Druga::ispis(){
    ifstream fin;
    fin.open("razred2.txt");
    if (!fin) {
        cerr << "Error in opening the file" << endl;
    }
    Druga druga;
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
    double fiz;
    double hem;
    ostream_iterator<Druga> output(cout, "");
    drugaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> fiz >> hem) {

        druga.setId(id_st);
        druga.setIme(ime);
        druga.setPol(pol);
        druga.setGodina(dina);
        druga.setMesec(mjesec);
        druga.setDan(day);
        druga.setMatematika(mat);
        druga.setSrpski(srp);
        druga.setEngleski(eng);
        druga.setIstorija(ist);
        druga.setGeografija(geo);
        druga.setFizika(fiz);
        druga.setHemija(hem);

        drugaVector.push_back(druga);
    }
    cout << "Rezultat pretrage: " << endl;
    copy(drugaVector.begin(), drugaVector.end(), output);

    fin.close();

}

void Druga::obrisi(){
    ifstream fin;
    fin.open("razred2.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Druga a;
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
    double fiz;
    double hem;
    cout << "Unesite redni broj ucenika prve godine koje zelite da izbrisete:  ";
    cin >> id;
    drugaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> fiz >> hem) {
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
        a.setFizika(fiz);
        a.setHemija(hem);
        drugaVector.push_back(a);
    }
    for (auto it = drugaVector.begin(); it != drugaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << " OBRISANO: " << *it << endl;
            drugaVector.erase(it);
            break;
        }
    }
    upisUfajl();
}

void Druga::izmeni(){
    ifstream fin;
    fin.open("razred2.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Druga a;
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
    double fiz;
    double hem;
    ostream_iterator<Druga> output(cout, "");
    cout << "Unesite redni broj ucenika koje zelite da izmenite:  ";
    cin >> id;
    drugaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> fiz >> hem) {
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
        a.setFizika(fiz);
        a.setHemija(hem);
        drugaVector.push_back(a);
    }
    for (auto it = drugaVector.begin(); it != drugaVector.end(); ++it) {
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
            cout << "Ocena iz fizike: ";
            cin >> fiz;
            cout << "Ocena iz hemija: ";
            cin >> hem;
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
            it->setFizika(fiz);
            it->setHemija(hem);
            break;
        }
    }
    upisUfajl();
}

void Druga::pretraga(){
    ifstream fin;
    fin.open("razred2.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    int id;
    Druga a;
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
    double fiz; double hem;
    ostream_iterator<Druga> output(cout, " ");
    cout << "Unesite indeks ucenika druge godine kog zelite naci:" << endl;
    cin >> id;
    drugaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> fiz >> hem) {

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
        a.setFizika(fiz); 
        a.setHemija(hem);

        drugaVector.push_back(a);
    }

    for (auto it = drugaVector.begin(); it != drugaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << *it << endl;
        }
    }
    fin.close();

}

void Druga::upisUfajl(){
    Druga a;
    ofstream out("razred2.txt");

    for (auto it = drugaVector.begin(); it != drugaVector.end(); ++it) {

        out << it->getId() << " " << it->getIme() << " " << it->getPol() << " " << it->getGodina()
            << " " << it->getMesec() << " " << it->getDan() << " " << it->getMatematika() << " "
            << it->getSrpski() << " " << it->getEngleski() << " " <<
            it->getIstorija() << " " << it->getGeografija() << " " << it->getFizika() << " " << it->getHemija() << endl;
    }
    out.close();
}

istream& operator>>(istream& is, Druga& ucenik) {

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
    is >> ucenik.Fizika;
    is >> ucenik.Hemija;

    return is;

}

ostream& operator<<(ostream& out, const Druga& druga) {

    out << druga.u_id << ", " << druga.ime << ", " << druga.pol << ", "
        << druga.godina << ", " << druga.mesec << ", " << druga.dan << ", "
        << druga.Matematika << ", " << druga.Srpski << ", " << druga.Engleski
        << ", " << druga.Istorija << ", " << druga.Geografija << ", " << druga.Fizika << ", " << druga.Hemija << endl;
    return out;

}

bool operator==(Druga const& druga1, Druga const& druga2)
{
    if (druga1.u_id == druga2.u_id) {

        cout << "Objekat je pronadjen!" << endl;
        return true;
    }
    else {
        cout << "Objekat nije pronadjen!" << endl;
        return false;
    }

}


