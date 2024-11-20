#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H
#include <fstream>
#include <iostream>
using namespace std;


class gestion_produit
{
    public:
        //declaration des variables
        //nom, catégorie, prix et quantité.
        string nom;
        string categorie;
        double prix;
        int quantite;

        //Creation de la class d'ajout de produit
        /*Ici ma logique est que chaque donné aura un fichier specifique a lui*/

        //ajouterProduit();
        void gestion_prod(){

            cout<<"Entrer le nom du produit\n";
            cin>>nom;
            cout<<"Entrer la categorie du produit\n";
            cin>>categorie;
            cout<<"Entrez le prix du produit\n";
            cin>>prix;
            cout<<"Entrer la quantitee du produit\n";
            cin>>quantite;

            //Enregistrement des donnée dans leur fichier respectifs
            //Enregistrement du nom du produit
            ofstream nomProduit("nomproduit.txt",ios::app);
            if(nomProduit.is_open()){
                cout<<"Ouverture du fichier nomProduit.txt reussi\n";
                nomProduit<<nom<<"\n";
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier nomProduit.txt\n";
            }

            //Enregistrement des categories
            ofstream categorieProduit("categorieproduit.txt",ios::app);
            if(categorieProduit.is_open()){
                cout<<"Ouverture du fichier categorieProduit.txt reussi\n";
                categorieProduit<<categorie<<"\n";
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier categorieProduit\n";
            }


            //Enregistrement des prix
            ofstream prixProduit("prixproduit.txt",ios::app);
            if(prixProduit.is_open()){
                cout<<"Ouverture du fichier prixProduit.txt reussi\n";
                prixProduit<<prix<<"\n";
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier prixProduit\n";
            }

            //Enregistrement de la quantité
            ofstream quantiteProduit("quantiteProduit.txt",ios::app);
            if(quantiteProduit.is_open()){
                cout<<"Ouverture du fichier quantiteProduit.txt reussi\n";
                quantiteProduit<<quantite<<"\n";
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier prixProduit\n";
            }



        };
        //virtual ~gestion_produit();

    protected:

    private:
};

#endif // GESTION_PRODUIT_H
