#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;


class gestion_produit
{
    public:
        //declaration des variables
        //nom, cat�gorie, prix et quantit�.
        string nom;
        string categorie;
        double prix;
        int quantite;
        list<string> loggeur;

        //Mise en place de methode

        //Creation de la class d'ajout de produit
        /*Ici ma logique est que chaque donn� aura un fichier specifique a lui*/

        //ajouterProduit();
        void gestion_prod();


        //Implementation de la methode de modification d'un article



    void modifieArticle();
    //Mise en place de la fonctionnalit� de suppression de produit

    void supprimerProduit();


    //Afficher les articles disponibles
    void produitAffichage();

    //FONCTION DE RECHERCHE
    void rechercheProduit();

    //Fonction de enregistrement de transaction
    void enregistrerTransaction();

    //Fonction de sauvegarde de donn�e
    void sauvegarde();
        //virtual ~gestion_produit();

    protected:

    private:
};

#endif // GESTION_PRODUIT_H
