#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Classe Vecteurs2D
class Vecteurs2D {
protected:
    double x, y;
    static int compteur;

public:
    // Constructeur par défaut
    Vecteurs2D() : x(0), y(0) {
        compteur++;
    }

    // Constructeur d'initialisation
    Vecteurs2D(double x_, double y_) : x(x_), y(y_) {
        compteur++;
    }

    // Constructeur de recopie
    Vecteurs2D(const Vecteurs2D& v) : x(v.x), y(v.y) {
        compteur++;
    }

    // Accesseurs
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double val) { x = val; }
    void setY(double val) { y = val; }

    // Méthode ToString
    virtual string ToString() const {
        return "X = " + to_string(x) + " - Y = " + to_string(y);
    }

    // Méthode Equals
    virtual bool Equals(const Vecteurs2D& v) const {
        return x == v.x && y == v.y;
    }

    // Méthode Norme
    virtual double Norme() const {
        return sqrt(x * x + y * y);
    }

    // Méthode statique pour accéder au compteur
    static int getCompteur() {
        return compteur;
    }
};

// Initialisation du compteur
int Vecteurs2D::compteur = 0;

// Classe dérivée Vecteurs3D
class Vecteurs3D : public Vecteurs2D {
private:
    double z;

public:
    // Constructeur par défaut
    Vecteurs3D() : Vecteurs2D(), z(0) {}
    
    // Constructeur d'initialisation
    Vecteurs3D(double x_, double y_, double z_) : Vecteurs2D(x_, y_), z(z_) {}

    // Constructeur de recopie
    Vecteurs3D(const Vecteurs3D& v) : Vecteurs2D(v), z(v.z) {}

    // Accesseurs
    double getZ() const { return z; }
    void setZ(double val) { z = val; }

    // Redéfinir ToString
    string ToString() const override {
        return "X = " + to_string(x) + " - Y = " + to_string(y) + " - Z = " + to_string(z);
    }

    // Redéfinir Equals
    bool Equals(const Vecteurs2D& v) const override {
        const Vecteurs3D* v3 = dynamic_cast<const Vecteurs3D*>(&v);
        if (v3)
            return x == v3->x && y == v3->y && z == v3->z;
        return false;
    }

    // Redéfinir Norme
    double Norme() const override {
        return sqrt(x * x + y * y + z * z);
    }
};

// Programme de test
int main() {
    // Objets Vecteurs2D
    Vecteurs2D v1(3.0, 4.0);
    Vecteurs2D v2(3.0, 4.0);

    // Objets Vecteurs3D
    Vecteurs3D v3(1.0, 2.0, 2.0);
    Vecteurs3D v4(5.0, 1.0, 3.0);

    // Affichage
    cout << "Vecteur 2D v1 : " << v1.ToString() << endl;
    cout << "Vecteur 2D v2 : " << v2.ToString() << endl;
    cout << "v1.Equals(v2) : " << (v1.Equals(v2) ? "Oui" : "Non") << endl;
    cout << "Norme de v1 : " << v1.Norme() << endl;

    cout << "\nVecteur 3D v3 : " << v3.ToString() << endl;
    cout << "Vecteur 3D v4 : " << v4.ToString() << endl;
    cout << "v3.Equals(v4) : " << (v3.Equals(v4) ? "Oui" : "Non") << endl;
    cout << "Norme de v3 : " << v3.Norme() << endl;

    cout << "\nNombre total d’objets créés : " << Vecteurs2D::getCompteur() << endl;

    return 0;
}
