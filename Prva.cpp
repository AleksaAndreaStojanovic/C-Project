#include "Prva.h"
#include<vector>
#include"Ucenik.h"
#include<iostream>
#include<string>
#include<istream>
#include<fstream>
#include<algorithm>
#include "Izuzetak.h"

Izuzetak izuzetak;

Prva::Prva(int u_id, string ime, string pol, int godina, int mesec, int dan, double Matematika, double Srpski, double Engleski, double Istorija, double Geografija,double Latinski)
    :Ucenik(u_id,  ime,  pol,  godina,  mesec,  dan,  Matematika,  Srpski,  Engleski,  Istorija,  Geografija) {
    this->Latinski = Latinski;
}

Prva::Prva() {
    Set_Type(1);
}

double Prva::getLatinski()
{
    return Latinski;
}

void Prva::setLatinski(double Latinski)
{
    if (Latinski > 5 || Latinski < 1) {
        cout << izuzetak.ocena() << endl;

    }
    this->Latinski = Latinski;
}

void Prva::ispis(){

    ifstream fin;
    fin.open("razred1.txt");
    if (!fin) {
        cerr << "Error in opening the file" << endl;
    }
    Prva prvaa;
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
    double lat;
    ostream_iterator<Prva> output(cout, "");
    prva.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> lat) {

        prvaa.setId(id_st);
        prvaa.setIme(ime);
        prvaa.setPol(pol);
        prvaa.setGodina(dina);
        prvaa.setMesec(mjesec);
        prvaa.setDan(day);
        prvaa.setMatematika(mat);
        prvaa.setSrpski(srp);
        prvaa.setEngleski(eng);
        prvaa.setIstorija(ist);
        prvaa.setGeografija(geo);
        prvaa.setLatinski(lat);

        prva.push_back(prvaa);
    }
    cout << "Rezultat pretrage: " << endl;
    copy(prva.begin(), prva.end(), output);
  
    fin.close();
   
}

void Prva::upisUfajl(){
    Prva stu;
    ofstream out("razred1.txt");
    
    for (auto it = prva.begin(); it != prva.end(); ++it) {

        out << it->getId() << " " << it->getIme() << " " << it->getPol() << " " << it->getGodina()
            << " " << it->getMesec() << " " << it->getDan()<< " " << it->getMatematika() << " " 
            << it->getSrpski() << " " << it->getEngleski() << " " <<
            it->getIstorija() << " " << it->getGeografija() << " "<< it->getLatinski()<< endl;
    }
    out.close();

}

void Prva::pretraga(){
       
    ifstream fin;
    fin.open("razred1.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    int id;
    Prva prvaa;
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
    double lat;
    ostream_iterator<Prva> output(cout, " ");
    cout << "Unesite indeks ucenika kog zelite naci:" << endl;
    cin >> id;
    prva.clear();  
        while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> lat) {
           
            prvaa.setId(id_st);
            prvaa.setIme(ime);
            prvaa.setPol(pol);
            prvaa.setGodina(dina);
            prvaa.setMesec(mjesec);
            prvaa.setDan(day);
            prvaa.setMatematika(mat);
            prvaa.setSrpski(srp);
            prvaa.setEngleski(eng);
            prvaa.setIstorija(ist);
            prvaa.setGeografija(geo);
            prvaa.setLatinski(lat);
           
            prva.push_back(prvaa);      
        }
            
        for (auto it = prva.begin(); it != prva.end(); ++it) {
            if (id == it->getId()) {
                cout << *it << endl;
            }
        }
    fin.close();
    
}

void Prva::obrisi(){
    ifstream fin;
    fin.open("razred1.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Prva a;
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
    double lat;
    cout << "Unesite redni broj ucenika prve godine koje zelite da izbrisete:  ";
    cin >> id;
    prva.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> lat) {
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
        a.setLatinski(lat);
        prva.push_back(a);      
    }
    for (auto it = prva.begin(); it != prva.end(); ++it) {
        if (id == it->getId()) {
            cout << " OBRISANO: " << *it << endl;
            prva.erase(it);
            break;
        }
    }
    upisUfajl();
}

void Prva::izmeni(){
    ifstream fin;
    fin.open("razred1.txt");
    if (!fin) {
        cerr << "Greska pri otvaranju fajla." << endl;
    }
    Prva a;
    Prva izmena;
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
    double lat;
    ostream_iterator<Prva> output(cout, "");
    cout << "Unesite redni broj ucenika koje zelite da izmenite:  ";
    cin >> id;
    prva.clear();
    while (fin >> id_st >> ime >> pol >> dina >> mjesec >> day >> mat >> srp >> eng >> ist >> geo >> lat) {
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
        a.setLatinski(lat);
        prva.push_back(a);
    }
    for (auto it = prva.begin(); it != prva.end(); ++it) {
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
            cout << "Ocena iz latinskog: ";
            cin >> lat;                      
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
          it->setLatinski(lat);         
            break;
        }
    }
    upisUfajl();
}

void Prva::upis() {
    Prva stu;
    char temp[50];
    
    while (1) {       
        cout << "Unesite ID ucenika: (4 BROJA)" << endl;
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
        cout << "Ocena iz latinskog: ";
        cin >> temp;
        stu.setLatinski(atof(temp));

        prva.push_back(stu);
        break;       
    }
       
}

istream& operator>>(istream& is, Prva& ucenik){

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
    is >> ucenik.Latinski;
    return is;

}

ostream& operator<<(ostream& out,const Prva& prva){

    out << prva.u_id << ", " << prva.ime << ", " << prva.pol << ", "
        << prva.godina << ", " << prva.mesec << ", " << prva.dan << ", "
        << prva.Matematika << ", " << prva.Srpski << ", " << prva.Engleski
        << ", " << prva.Istorija << ", " << prva.Geografija << ", " << prva.Latinski << endl;
    return out;
   
}

bool operator==(Prva const& prva1, Prva const& prva2)
{
    if (prva1.u_id == prva2.u_id) {

        cout << "Objekat je pronadjen!" << endl;
        return true;
    }
    else {
        cout << "Objekat nije pronadjen!" << endl;
        return false;
    }

}
