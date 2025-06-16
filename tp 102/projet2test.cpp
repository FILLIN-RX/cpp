#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class Vecteur2D
{
private:
    double x;
    double y;
    static int nombreVecteurs;

public:
    Vecteur2D();
    Vecteur2D(double x, double y);
    Vecteur2D(const Vecteur2D &other);

    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

    static int getNombreVecteurs();

    std::string ToString() const;
    bool Equals(const Vecteur2D &other) const;
    virtual double Norme() const;
};

int Vecteur2D::nombreVecteurs = 0;

Vecteur2D::Vecteur2D() : x(0.0), y(0.0)
{
    nombreVecteurs++;
}

Vecteur2D::Vecteur2D(double x, double y) : x(x), y(y)
{
    nombreVecteurs++;
}

Vecteur2D::Vecteur2D(const Vecteur2D &other) : x(other.x), y(other.y)
{
    nombreVecteurs++;
}

double Vecteur2D::getX() const
{
    return x;
}

void Vecteur2D::setX(double x)
{
    this->x = x;
}

double Vecteur2D::getY() const
{
    return y;
}

void Vecteur2D::setY(double y)
{
    this->y = y;
}

int Vecteur2D::getNombreVecteurs()
{
    return nombreVecteurs;
}

std::string Vecteur2D::ToString() const
{
    std::stringstream ss;
    ss << "X = " << x << " - Y = " << y;
    return ss.str();
}

bool Vecteur2D::Equals(const Vecteur2D &other) const
{
    return (x == other.x && y == other.y);
}

double Vecteur2D::Norme() const
{
    return std::sqrt(x * x + y * y);
}

class Vecteur3D : public Vecteur2D
{
private:
    double z;

public:
    // Constructors
    Vecteur3D();
    Vecteur3D(double x, double y, double z);
    Vecteur3D(const Vecteur3D &other);

    // Accessors
    double getZ() const;
    void setZ(double z);

    // Methods
    std::string ToString() const;              // Removed override
    bool Equals(const Vecteur3D &other) const; // Removed override
    double Norme() const override;
};

Vecteur3D::Vecteur3D() : Vecteur2D(), z(0.0) {}

Vecteur3D::Vecteur3D(double x, double y, double z) : Vecteur2D(x, y), z(z) {}

Vecteur3D::Vecteur3D(const Vecteur3D &other) : Vecteur2D(other), z(other.z) {}

double Vecteur3D::getZ() const
{
    return z;
}

void Vecteur3D::setZ(double z)
{
    this->z = z;
}

std::string Vecteur3D::ToString() const
{
    std::stringstream ss;
    ss << "X = " << getX() << " - Y = " << getY() << " - Z = " << z;
    return ss.str();
}

bool Vecteur3D::Equals(const Vecteur3D &other) const
{
    return (getX() == other.getX() && getY() == other.getY() && z == other.z);
}

double Vecteur3D::Norme() const
{
    return std::sqrt(getX() * getX() + getY() * getY() + z * z);
}

int main()
{
    Vecteur2D vecteur2D_1(1.5, 2.0);
    Vecteur2D vecteur2D_2(1.5, 2.0);

    Vecteur3D vecteur3D_1(1.0, 2.0, 3.0);
    Vecteur3D vecteur3D_2(1.0, 2.0, 4.0);

    std::cout << "Vecteur 2D 1: " << vecteur2D_1.ToString() << std::endl;
    std::cout << "Vecteur 2D 2: " << vecteur2D_2.ToString() << std::endl;
    std::cout << "Vecteur 3D 1: " << vecteur3D_1.ToString() << std::endl;
    std::cout << "Vecteur 3D 2: " << vecteur3D_2.ToString() << std::endl;

    std::cout << "Vecteur 2D 1 Equals Vecteur 2D 2: " << vecteur2D_1.Equals(vecteur2D_2) << std::endl;
    std::cout << "Vecteur 3D 1 Equals Vecteur 3D 2: " << vecteur3D_1.Equals(vecteur3D_2) << std::endl;

    std::cout << "Norme Vecteur 2D 1: " << vecteur2D_1.Norme() << std::endl;
    std::cout << "Norme Vecteur 3D 1: " << vecteur3D_1.Norme() << std::endl;

    std::cout << "Nombre de vecteurs crées: " << Vecteur2D::getNombreVecteurs() << std::endl;

    return 0;
}
