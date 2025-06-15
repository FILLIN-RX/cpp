#include <iostream>
#include <string>
using namespace std;

class Article
{
private:
    string reference;
    string designation;
    double prix;
    static double tva;
public:
    Article(string ref,string des, double prix):reference(ref),designation(des),prix(prix){};
    void calculerPrixTTC(){
        double prixTTC = prix + (prix * tva / 100);
        

    }
    void afficher(double prixTTC){
        cout << "Détails de l'article :" << endl;
        cout << "------------------------" << endl;
        cout << "Reference:" << reference << endl;
        cout << "Designation:" << designation << endl;
        cout << "Prix HT:" << prix << endl;
        cout << "TVA:"<<tva<<"%"<<endl;
        cout << "Prix TTC de l'article " << designation << " (Réf: " << reference << ") : " << prixTTC << endl;
    }
};


