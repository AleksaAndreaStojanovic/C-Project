#include "Treca.h"
#include<vector>
#include"Ucenik.h"
#include<iostream>
#include<string>
#include<istream>
#include<fstream>


Treca::Treca()
{
}

Treca::Treca(int u_id, string ime, string pol, int godina, int mesec, int dan, double Matematika, double Srpski, double Engleski, double Istorija, double Geografija, double Filozofija, double Programiranje)
	:Ucenik(u_id, ime, pol, godina, mesec, dan, Matematika, Srpski, Engleski, Istorija, Geografija) {
	this->Filozofija = Filozofija;
	this->Programiranje = Programiranje;
}

double Treca::getFilozofija()
{
    return Filozofija;
}


void Treca::setFilozofija(double Filozofija)
{
	this->Filozofija = Filozofija;
}

double Treca::getProgramiranje()
{
	return Programiranje;
}

void Treca::setProgramiranje(double Programiranje)
{
	this->Programiranje = Programiranje;
}


void Treca::upis() {
    Treca stu;
    char temp[50];

    while (1) {
        cout << "Unesite ID ucenika trece godine: (4 BROJA)" << endl;
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

        cout << "Ocena iz filozofije: ";
        cin >> temp;
        stu.setFilozofija(atof(temp));

        cout << "Ocena iz programiranja: ";
        cin >> temp;
        stu.setProgramiranje(atof(temp));

        trecaVector.push_back(stu);
        break;
    }
}

void Treca::ispis() {
    ifstream fin;
    fin.open("razred3.txt");
    if (!fin) {
        cerr << "Error in opening the file" << endl;
    }
    Treca a;
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
    double filo;
    double prog;
    ostream_iterator<Treca> output(cout, "");
    trecaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> filo >> prog) {

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
        a.setFilozofija(filo);
        a.setProgramiranje(prog);

        trecaVector.push_back(a);
    }
    cout << "Rezultat pretrage: " << endl;
    copy(trecaVector.begin(), trecaVector.end(), output);

    fin.close();

}

void Treca::obrisi() {
    ifstream fin;
    fin.open("razred3.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Treca a;
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
    double filo;
    double prog;
    cout << "Unesite redni broj ucenika trece godine koje zelite da izbrisete:  ";
    cin >> id;
    trecaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> filo >> prog) {
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
        a.setFilozofija(filo);
        a.setProgramiranje(prog);
        trecaVector.push_back(a);
    }
    for (auto it = trecaVector.begin(); it != trecaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << " OBRISANO: " << *it << endl;
            trecaVector.erase(it);
            break;
        }
    }
    upisUfajl();
}

void Treca::izmeni() {
    ifstream fin;
    fin.open("razred3.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Treca a;
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
    double filo;
    double prog;
    ostream_iterator<Treca> output(cout, "");
    cout << "Unesite redni broj ucenika trece godine koje zelite da izmenite:  ";
    cin >> id;
    trecaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> filo >> prog) {
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
        a.setFilozofija(filo);
        a.setProgramiranje(prog);
      trecaVector.push_back(a);
    }
    for (auto it = trecaVector.begin(); it != trecaVector.end(); ++it) {
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
            cout << "Ocena iz filozofija: ";
            cin >> filo;
            cout << "Ocena iz programiranje: ";
            cin >> prog;
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
            it->setFilozofija(filo);
            it->setProgramiranje(prog);
            break;
        }
    }
    upisUfajl();
}

void Treca::pretraga() {
    ifstream fin;
    fin.open("razred3.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    int id;
    Treca a;
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
    double filo; double prog;
    ostream_iterator<Treca> output(cout, " ");
    cout << "Unesite id ucenika trece godine kog zelite naci:" << endl;
    cin >> id;
    trecaVector.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> filo >> prog) {

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
        a.setFilozofija(filo);
        a.setProgramiranje(prog);

        trecaVector.push_back(a);
    }

    for (auto it = trecaVector.begin(); it != trecaVector.end(); ++it) {
        if (id == it->getId()) {
            cout << *it << endl;
        }
    }
    fin.close();

}

void Treca::upisUfajl() {
    Treca a;
    ofstream out("razred3.txt");

    for (auto it = trecaVector.begin(); it != trecaVector.end(); ++it) {

        out << it->getId() << " " << it->getIme() << " " << it->getPol() << " " << it->getGodina()
            << " " << it->getMesec() << " " << it->getDan() << " " << it->getMatematika() << " "
            << it->getSrpski() << " " << it->getEngleski() << " " <<
            it->getIstorija() << " " << it->getGeografija() << " " << it->getFilozofija() << " " << it->getProgramiranje() << endl;
    }
    out.close();
}

istream& operator>>(istream& is, Treca& ucenik) {

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
    is >> ucenik.Filozofija;
    is >> ucenik.Programiranje;

    return is;

}

ostream& operator<<(ostream& out, const Treca& treca) {

    out << treca.u_id << ", " << treca.ime << ", " << treca.pol << ", "
        << treca.godina << ", " << treca.mesec << ", " << treca.dan << ", "
        << treca.Matematika << ", " << treca.Srpski << ", " << treca.Engleski
        << ", " << treca.Istorija << ", " << treca.Geografija << ", " << treca.Filozofija << ", " << treca.Programiranje << endl;
    return out;

}

bool operator==(Treca const& treca1, Treca const& treca2)
{
    if (treca1.u_id == treca2.u_id) {

        cout << "Objekat je pronadjen!" << endl;
        return true;
    }
    else {
        cout << "Objekat nije pronadjen!" << endl;
        return false;
    }

}
