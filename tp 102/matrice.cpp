#include <iostream>
using namespace std;

const int LIGNES = 3;
const int COLONNES = 3;

// Remplir une matrice avec des valeurs saisies par l'utilisateur
void remplirMatrice(int matrice[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            cout << "Entrez l'élément [" << i << "][" << j << "] : ";
            cin >> matrice[i][j];
        }
    }
}

// Afficher une matrice
void afficherMatrice(int matrice[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            cout << matrice[i][j] << "\t";
        }
        cout << endl;
    }
}

// Additionner deux matrices
void additionnerMatrices(int A[LIGNES][COLONNES], int B[LIGNES][COLONNES], int resultat[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            resultat[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int matriceA[LIGNES][COLONNES];
    int matriceB[LIGNES][COLONNES];
    int matriceResultat[LIGNES][COLONNES];

    cout << "Remplissage de la matrice A :" << endl;
    remplirMatrice(matriceA);

    cout << "Remplissage de la matrice B :" << endl;
    remplirMatrice(matriceB);

    additionnerMatrices(matriceA, matriceB, matriceResultat);

    cout << "\nMatrice A :" << endl;
    afficherMatrice(matriceA);

    cout << "\nMatrice B :" << endl;
    afficherMatrice(matriceB);

    cout << "\nMatrice Resultat (A + B) :" << endl;
    afficherMatrice(matriceResultat);

    return 0;
}
