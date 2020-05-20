#ifndef BEJEGYZES_HPP_INCLUDED
#define BEJEGYZES_HPP_INCLUDED
#include <iostream>
#include <string>
#include <fstream>


using std::ostream;
using std::string;
using std::cout;
using std::endl;

class bejegyzes{
 protected: string vezeteknev, keresztnev, szam, becenev;
           static int sorszam;
 public:
    bejegyzes();
    bejegyzes(string vezeteknev, string keresztnev, string szam, string becenev):vezeteknev(vezeteknev),keresztnev(keresztnev), szam(szam), becenev(becenev){
        sorszam++;
    };

    string getvez(){return vezeteknev;}
    string getker(){return keresztnev;}
    string getszam(){return szam;}
    string getbecenev(){return becenev;}

    virtual int getindex() = 0;
    virtual string tipus() = 0;

    void setvez(string vez);
    void setker(string ker);
    void setszam(string telefonszam);
    void setbec(string bec);
    virtual string getspecialadat() = 0;

    virtual void kiir()  = 0;

    ~bejegyzes();
};

class maganszam:public bejegyzes{
    protected: string lakcim;
                int index;
    public:
        maganszam();
        maganszam(string vezeteknev, string keresztnev, string szam, string becenev, string lakcim):bejegyzes(vezeteknev,keresztnev,szam,becenev),lakcim(lakcim){
            index = sorszam;
        }
        string tipus(){return "maganszam";}
        string getcim(){return lakcim;}
        void setlakcim(string cim);
        int getindex(){return index;}
        void kiir();
        string getspecialadat(){
            return lakcim;
        }
};


class munkahelyi:public bejegyzes{
    protected: string cegnev;
                int index;
    public:
        munkahelyi();
        munkahelyi(string vezeteknev, string keresztnev,string szam,string becenev,string cegnev):bejegyzes(vezeteknev,keresztnev,szam,becenev),cegnev(cegnev){
            index = sorszam;
        }
        void setcegnev(string ceg);
        int getindex(){return index;}
        string getceg(){return cegnev;}
        string tipus(){return "munkahelyi";}
        void kiir();
        string getspecialadat(){
            return cegnev;
        }
};


struct listaelem{
    bejegyzes* elem;
    listaelem* kov;
};

class lista{


public:
    listaelem* eleje;

    lista(){eleje = nullptr;}

    lista& operator= (const lista& masik){
    eleje = masik.eleje;
        return *this;
    }

    lista(const lista & src);

    void hozzaad(bejegyzes* vmi);

    void elemtorol();

    void fajlbair();

    void adatbazis_kiiras();

    void kereses();

    void nevjegyfelvetel();

    void adatbazis_beolvasas();

    ~lista();

};

#endif
