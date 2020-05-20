#include "bejegyzes.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;

int bejegyzes::sorszam = 0;

bejegyzes::bejegyzes(): vezeteknev(""), keresztnev(""), szam(""), becenev(""){}

maganszam::maganszam(): lakcim(""){}

munkahelyi::munkahelyi(): cegnev(""){}

bejegyzes::~bejegyzes(){}


void bejegyzes::setvez(string vez){
    vezeteknev = vez;
}

void bejegyzes::setker(string ker){
    keresztnev = ker;
}

void bejegyzes::setbec(string bec){
    becenev = bec;
}

void bejegyzes::setszam(string telefonszam){
    szam = telefonszam;
}

void maganszam::setlakcim(string cim){
    lakcim = cim;
}

void munkahelyi::setcegnev(string ceg){
    cegnev = ceg;
}

void maganszam::kiir() {
    cout <<" ["<< getindex() <<"] : "<< getvez() <<"  "<< getker()
    <<"  "<< getszam() <<"  "<< getbecenev() <<"  "<< getcim()<<"  "<<endl;
}

void munkahelyi::kiir() {
    cout <<" ["<< getindex() <<"] : "<< getvez() <<" "<< getker()
    <<" "<< getszam() <<" "<< getbecenev() <<" "<< getceg()<<" "<<std::endl;
}

lista::lista(const lista & src):eleje(nullptr)
		{
		listaelem* tempelem = src.eleje;
		while (tempelem != nullptr)
		{
			hozzaad(tempelem->elem);
			tempelem = tempelem->kov;
		}
	}


void lista::hozzaad(bejegyzes* vmi){

    string vezeteknev = vmi->getvez();
    if(islower(vezeteknev[0])){
         vezeteknev[0] = toupper(vezeteknev[0]);
        vmi->setvez(vezeteknev);
    }

    string keresztnev = vmi->getker();
    if(islower(keresztnev[0])){
       keresztnev[0] = toupper(keresztnev[0]);
        vmi->setker(keresztnev);
    }

    listaelem* uj = new listaelem;
    uj->elem = vmi;
    uj->kov = nullptr;


    if (eleje == nullptr){
        eleje = uj;
    }
    else{
        listaelem* mozgo = eleje;
        while(mozgo->kov!= nullptr){
            mozgo = mozgo->kov;
            }
        mozgo->kov = uj;
    }
}

void lista::elemtorol(){
    int x;
    cout << endl<< "Hanyas indexu bejegyzest szeretned kitorolni?" <<endl;
    std::cin >> x;

    listaelem* lemarado = nullptr;  //keresés
    listaelem* mozgo = eleje;
    while(mozgo != nullptr && mozgo->elem->getindex() != x){
        lemarado = mozgo;
        mozgo = mozgo->kov;
    }

    if(mozgo == nullptr){}
    else if (lemarado == nullptr){
            listaelem* ujeleje = mozgo->kov;
            delete mozgo;
            eleje = ujeleje;
        }
    else{
            lemarado->kov = mozgo->kov;
            delete mozgo;
        }
    std::cout << std::endl<< "Nevjegy sikeresen torolve." << std::endl;
}


void lista::fajlbair(){
    std::ofstream fout("adatbazis.txt");
    for(listaelem* mozgo = eleje; mozgo != nullptr; mozgo = mozgo->kov){
        fout << "#" <<endl<< mozgo->elem->tipus()
            <<endl<<mozgo->elem->getvez()
            <<endl<< mozgo->elem->getker()
            <<endl<< mozgo->elem->getszam()
            <<endl<< mozgo->elem->getbecenev()
            <<endl<< mozgo->elem->getspecialadat()
            <<endl << "#" << endl;
    }
    fout.close();
}

void lista::adatbazis_kiiras( ){

         for(listaelem* mozgo = eleje; mozgo != nullptr; mozgo = mozgo->kov){
            if( mozgo != nullptr){
                cout << mozgo->elem->getindex() << "index" << endl;
                if(mozgo->kov != nullptr)
                cout << mozgo->kov->elem->getindex() << "kov. index" << endl;
            }
            mozgo->elem->kiir();
            cout <<std::endl;
        }
    }

void lista::kereses(){
    string keresett_nev;

    cout << endl << "Kereses keresztnev  VAGY vezeteknev alapjan: " << endl;
    cin >> keresett_nev;
    cout << "Keresesi talalatok " << keresett_nev <<" eseten:" << endl;

    for(listaelem* mozgo = eleje; mozgo!=nullptr; mozgo = mozgo->kov){
        string teljesnev = "";
        teljesnev = mozgo->elem->getvez() + " " + mozgo->elem->getker();
         if (teljesnev.find(keresett_nev) != std::string::npos){
                mozgo->elem->kiir();
            }
    }
}


void lista::adatbazis_beolvasas(){
    ifstream fin("adatbazis.txt");
    string sor;
    string vezeteknev;
    string keresztnev;
    string telefonszam;
    string becenev;
    string specialadat;
    string tipus;

    int sorszamlalo = 0;
    while(!fin.eof()){
        sorszamlalo++;
        getline(fin, sor);
        switch (sorszamlalo) {
        case 1:
            break;

        case 2:
            tipus = sor;
            break;

        case 3:
            vezeteknev = sor;
            break;

        case 4:
            keresztnev = sor;
            break;

        case 5:
            telefonszam = sor;
            break;

        case 6:
            becenev = sor;
            break;

        case 7:
            specialadat = sor;
            break;

        case 8:
            if(tipus == "munkahelyi"){
                hozzaad(new munkahelyi(vezeteknev,keresztnev,telefonszam,becenev,specialadat));
            }
            else{
                hozzaad(new maganszam(vezeteknev,keresztnev,telefonszam,becenev,specialadat));
            }
            sorszamlalo = 0;
            break;
        }
    }
    fin.close();
}



void lista::nevjegyfelvetel(){

    cout <<"Milyen tipusu bejegyzest szeretnel?" << endl <<
           "1 - maganszam" << endl << "2 - munkahelyi szam" << endl;
    string a;
    getline(cin, a);
    if(a[0] == '1'){

    cout<<"Kerlek add meg az adatokat!" << endl;

        cout << endl << "Vezeteknev:" << endl;   string vezeteknev;  getline(cin, vezeteknev);
        cout << endl << "Keresztnev:" << endl;   string keresztnev;  getline(cin,keresztnev);
        cout << endl << "Telefonszam:" << endl;  string telefonszam;  getline(cin,telefonszam);
        cout << endl << "Becenev" << endl;       string becenev;  getline(cin,becenev);
        cout << endl << "Lakcim:" << endl;       string lakcim;  getline(cin,lakcim);

        string x;

        cout << endl << "Ez igy  jo lesz?(i(igen)/n(nem)" << endl;
        getline(cin, x);
        cout <<endl;

        if(x[0] != 'i' && x[0] != 'I'){
            cout<<endl;
         return;
        }
        else {
            cout<<endl;

            hozzaad(new maganszam(vezeteknev, keresztnev, telefonszam, becenev, lakcim));
            fajlbair();
            cout << this;

            cout << endl << "Nevjegy sikeresen hozzaadva" << endl;
            return;
        }
    }

    else{
        cout<<"Kerlek add meg az adatokat!" << endl;

        cout << endl << "Vezeteknev:"  << endl;  string vezeteknev;  getline(cin,vezeteknev);
        cout << endl << "Keresztnev:" << endl;  string keresztnev;  getline(cin,keresztnev);
        cout << endl << "Telefonszam:" << endl; string telefonszam;  getline(cin,telefonszam);
        cout << endl << "Becenev" << endl;      string becenev;  getline(cin,becenev);
        cout << endl << "Cegnev:" << endl;      string cegnev;  getline(cin,cegnev);

        string x;
        cout << endl << "Ez igy  jo lesz?(i(igen)/n(nem)" << endl;

        getline(cin, x);
        cout <<endl;

        if(x[0] != 'i' && x[0] != 'I'){
            cout<<endl;
            return;
        }
        else {
            cout<<endl;
            hozzaad(new munkahelyi(vezeteknev, keresztnev, telefonszam, becenev, cegnev));
            fajlbair();
            cout << this;
            cout << endl << "Nevjegy sikeresen hozzaadva" << endl;
            return;
        }
    }
}

lista::~lista(){
    listaelem* iter = eleje;
    while (iter != nullptr) {
        listaelem*kov = iter->kov;
        delete iter;
        iter = kov;
    }
}
