#include <iostream>
#include <string>
#include "personnage.hpp"
using namespace std;


int main()
{


    //Création des personnages
    Personnage david, goliath("Epee aiguisee", 20);
    cout << "David" << endl;
    david.afficherEtat();
    cout << "goliath" << endl;
    goliath.afficherEtat() ;
    cout << "" << endl;
 
    //Au combat !
    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);
 
    //Temps mort ! Voyons voir la vie de chacun…
    cout << "David" << endl;
    david.afficherEtat();
    cout << endl << "Goliath" << endl;
    goliath.afficherEtat();
 

 
    // Création de 2 objets de type Personnage : david et goliath
    david.afficherEtat();
   

    return 0;
}