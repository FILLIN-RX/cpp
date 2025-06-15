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
    string getReference(){
        return reference;
    };
    string getDesignation(){
        return designation;
    };
    double getPrix(){
        return prix;
    };

    void setReference(string ref){
        reference = ref;
    };
    void setDesignation(string des){
        designation = des;
    };
    void setPrix(double prix){
        this->prix = prix;
    };
    Article():reference("N/A"),designation("N/A"),prix(0.0){};
    Article(string ref,string des,double prix){
        
    }
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


