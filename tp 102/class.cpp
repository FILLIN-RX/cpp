#include <iostream>
using namespace std;
#include<string.h>
#include  <list>
#include <vector>
class  Personne
{
private:
    string nom;
    string prenom;
    string DOB;
public:
    Personne(string n, string p,string  d):nom(n),prenom(p),DOB(d){};
    void afficher(){
        cout << "Nom:" << nom << endl;
        cout << "prenom:" << prenom << endl;
        cout << "age :" << DOB <<   endl;

    };
 
};

class  Employer: public Personne
{
private:

protected:
    int salaire;
public:
   Employer(string n,string p , string d ,int s):Personne( n, p, d ),  salaire(s){};
   void afficher(){
        Personne::afficher();
        
        cout << "Salaire :" << salaire <<   endl;
   };
};

class Chef: public Employer{
protected:
    string Service;

public:
    Chef(string n,string p, string d,int s ,string service):Employer(n,p,d,s), Service(service){};
    void afficher(){
        Employer::afficher();
        cout << "Service:" << Service << endl ;
    };
};
class Directeur: public Chef{
protected:
    string Societer;

public:
    Directeur(string n,string p, string d,int s ,string service, string societer):Chef(n,p,d,s,service), Societer(societer){};
    void afficher(){
    
        Employer::afficher();
        cout << "Societer:" << Societer << endl ;
    };
};
 
int main() {
    vector<Personne*>personnes;
    personnes.push_back(new Employer("Dupont", "Jean", "01/01/1980", 2500));
    personnes.push_back(new Employer("Martin", "Claire", "12/05/1985", 2700));
    personnes.push_back(new Employer("Durand", "Paul", "23/08/1975", 3000));
    personnes.push_back(new Employer("Bernard", "Sophie", "04/11/1990", 2900));
    personnes.push_back(new Employer("Moreau", "Luc", "18/03/1982", 2600));
    
    personnes.push_back(new Chef("Leclerc", "Julie", "11/06/1978", 3500, "Informatique"));
    personnes.push_back(new Chef("Garcia", "Michel", "21/09/1973", 3600, "Marketing"));

    personnes.push_back(new Directeur("Dubois", "Alice", "02/02/1970", 5000, "Direction", "TechCorp"));

    for ( const auto& p :personnes)
    {
        p->afficher();
        cout << "_________________________________" << endl;
    }
    



    return 0;
}