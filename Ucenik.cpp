#include "Ucenik.h"
#include "Izuzetak.h"

Izuzetak izuzetakk;

Ucenik::Ucenik( int u_id, string ime, string pol, int godina, int mesec, int dan, double Matematika, double Srpski, double Engleski, double Istorija, double Geografija)
{
}

Ucenik::Ucenik() {
}


 int Ucenik::getId() {
    return this->u_id;
}

void Ucenik::setId( int u_id) {
    this->u_id = u_id;
}

string Ucenik::getIme() {
    return this->ime;
}

void Ucenik::setIme(string ime) {
    this->ime = ime;
}

string Ucenik::getPol() {
    return this->pol;
}

void Ucenik::setPol(string pol) {

    if (pol != "M" || pol != "Z") {
        cout << izuzetakk.pol();
    }
    this->pol = pol;
}

int Ucenik::Get_Type() {
    return this->type;
}

void Ucenik::Set_Type(int type) {
    this->type = type;
}

int Ucenik::getGodina(){
    return godina;
}

void Ucenik::setGodina(int godina){
    this->godina = godina;
}

int Ucenik::getMesec(){
    return mesec;
}

void Ucenik::setMesec(int mesec){
    this->mesec = mesec;
}

int Ucenik::getDan(){
    return dan;
}

void Ucenik::setDan(int dan){
    this->dan = dan;
}

double Ucenik::getMatematika(){
    return Matematika;
}

void Ucenik::setMatematika(double Matematika){
    if (Matematika > 5 || Matematika < 1) {
        cout << izuzetakk.ocena() << endl;

    }
    this->Matematika = Matematika;
}

double Ucenik::getIstorija(){
    return Istorija;
}

void Ucenik::setIstorija(double Istorija){
    if (Istorija > 5 || Istorija < 1) {
        cout << izuzetakk.ocena() << endl;

    }
    this->Istorija = Istorija;
}

double Ucenik::getGeografija(){
    return Geografija;
}

void Ucenik::setGeografija(double Geografija){
    this->Geografija = Geografija;
}


double Ucenik::getSrpski(){
    return Srpski;
}

void Ucenik::setSrpski(double Srpski){
    this->Srpski = Srpski;

}

double Ucenik::getEngleski(){
    return Engleski;
}

void Ucenik::setEngleski(double Engleski){
    this->Engleski = Engleski;
}

bool operator==(Ucenik const& ucenik1, Ucenik const& ucenik2){
    if (ucenik1.u_id == ucenik2.u_id && ucenik1.ime == ucenik2.ime && ucenik1.pol == ucenik2.pol
        && ucenik1.godina == ucenik2.godina && ucenik1.mesec == ucenik2.mesec && ucenik1.dan == ucenik2.dan
        && ucenik1.Engleski == ucenik2.Engleski && ucenik1.Srpski == ucenik2.Srpski && ucenik1.Matematika == ucenik2.Matematika
        && ucenik1.Geografija == ucenik2.Geografija && ucenik1.Istorija == ucenik2.Istorija) {

        cout << "Objekat je pronadjen!" << endl;
        return true;
    }
    else {
        cout << "Objekat nije pronadjen!" << endl;
        return false;
    }

}

ostream& operator<<(ostream& out, const Ucenik& ucenik){
    out << ucenik.u_id << ", " << ucenik.ime << ", " << ucenik.pol << ", "
        << ucenik.godina << ", " << ucenik.mesec << ", " << ucenik.dan << ", " 
        << ucenik.Matematika << ", " << ucenik.Srpski << ", " << ucenik.Engleski 
        << ", " << ucenik.Istorija << ", " << ucenik.Geografija << endl;
    return out;
}

istream& operator>>(istream& is, Ucenik& ucenik){
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
   
    return is;

}

