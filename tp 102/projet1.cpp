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
    double getTva(){
        return tva;
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
    void setTva(double Tva){
        tva = Tva;
    };
    Article():reference("N/A"),designation("N/A"),prix(0.0){};
    Article(string ref,string des,double prix):reference(ref),designation(des),prix(prix){
        
    }
    Article(string ref,string des):reference(ref),designation(des),prix(0.0){
        
        
    }
    Article(const Article& autre)
    : reference(autre.reference), designation(autre.designation), prix(autre.prix) {}

    double calculerPrixTTC(){
        double prixTTC = prix + (prix * tva / 100);
        return prixTTC;
    }
    void afficher(){
        cout << "Détails de l'article :" << endl;
        cout << "------------------------" << endl;
        cout << "Reference:" << reference << endl;
        cout << "Designation:" << designation << endl;
        cout << "Prix HT:" << prix << endl;
        cout << "TVA:"<<tva<<"%"<<endl;
        cout << "Prix TTC de l'article : " << calculerPrixTTC() << "fcfa" << endl;
    }
};
double Article::tva = 18.0; 
int main(){
    Article a1("A001", "Article 1", 100.0);
    Article a2("A002", "Article 2");

    a1.afficher();
    a2.afficher();
    a1.setTva(50);
    a1.afficher();
    a2.setTva(50);
    a2.afficher();
    a2.setPrix(200.0);
    a2.afficher();
    Article a3 = a1; 
    cout << "Détails de l'article copié :" << endl;
    a3.afficher();
    return 0;
}