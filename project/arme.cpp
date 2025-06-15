#include "arme.hpp"

using namespace std;

Arme::Arme():m_nom("Epee rouillee"), m_degats(5)
{
    // Constructeur par défaut
}
void Arme::changer(string nom, int degats){
    m_nom = nom;
    m_degats = degats;
    // Change le nom et les dégâts de l'arme
}
Arme::Arme(string nom, int degats):m_nom(nom), m_degats(degats)
{
    // Constructeur avec paramètres
    // Initialise l'arme avec un nom et des dégâts spécifiques
}
void Arme::afficher() const
{
    cout << "Arme: " << m_nom << ", Dégâts: " << m_degats << endl;
    // Affiche le nom et les dégâts de l'arme
}
int Arme::getDegats() const
{
    return m_degats;
}