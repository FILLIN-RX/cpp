#ifndef DEF_ARME
#define DEF_ARME
#include <string>
#include <iostream>

class Arme
{
private:
    std::string m_nom;
    int m_degats;
    // Attributs privés pour le nom de l'arme et les dégâts qu'elle inflige
public:
    Arme(std::string nom, int degats);
    Arme();
    void changer(std::string nom, int degats);
    void afficher() const;
    int getDegats() const;
};

#endif