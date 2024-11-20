#include <iostream>
using namespace std;
#include "gestion_produit.h"



//Project
/*
1. Système de Gestion d'Inventaire pour un Magasin
Ajouter un nouvel article avec nom, catégorie, prix et quantité.
Modifier les informations d'un article existant.
Supprimer un article du stock.
Rechercher des articles par nom
Afficher tous les articles disponibles en stock avec leur quantité actuelle.
Enregistrer les transactions (ajout et retrait d'inventaire) dans un fichier de log.
Sauvegarder et charger l'état de l'inventaire dans un fichier pour maintenir la persistance
des données.
*/
int main()
{
    //Realisattion du menu
    gestion_produit gestion;
    while(true){
                cout << "***************************************Bienvenue au système de gestion de stock**************************************" << endl;
                cout <<"\n";
                cout << "           1-Ajouter un nouvel article" << endl;
                cout << "           2-Modifier les informations d'un article existant" << endl;
                cout << "           3-Supprimer un article du stock" << endl;
                cout << "           4-Rechercher des articles par nom" << endl;
                cout << "           5-Afficher les articles disponibles en stock avec leur quantité" << endl;
                cout << "           6-Enregistrer les transactions dans un fichier log" << endl;
                cout << "           7-Sauvegarder et charger l'etat de l'invetaire dans un fichier pour persistance"<<endl;
                cout << "           8-Quitter le programme"<<endl;
                cout <<"\n";
                cout << "***************************************Bienvenue au système de gestion de stock**************************************" << endl;
                cout <<"\n";
                cout <<"Veuillez entrez votre choix\n";

                try{
                    int reponse;
                    //Recuperation de la reponse de l'utilisateur
                    cin>>reponse;
                    //variable de recuperation de la reponse
                    //gestion_produit gestion;
                    //throw runtime_error("Une erreur s'est produite !");

                    switch(reponse){
                        case(1):
                            cout<<"Ajout d'un nouveau article"<<endl;

                            //gestion.gestion_produit();
                            //gestion = gestion_produit();

                            gestion.gestion_prod(); // Assurez-vous que cette méthode existe dans votre classe gestion_produit.

                            break;

                        case(2):
                            cout<<"Modification des articles d'un produit existant"<<endl;
                            gestion.modifieArticle();
                            break;

                        case(3):
                            cout<<"Supprimer un article du stock"<<endl;
                            break;

                        case(4):
                            cout<<"Rechercher des articles par nom"<<endl;
                            break;

                        case(5):
                            cout<<"Afficher les articles disponibles en stock avec leur quantité"<<endl;
                            break;

                        case(6):
                            cout<<"Enregistrer les modification dans un fichier log"<<endl;
                            break;

                        case(7):
                            cout<<"Sauvegarder et charger l'etat de l'invetaire dans un fichier pour persistance"<<endl;
                            break;

                        case(8):
                            cout<<"Quitter le programme"<<endl;
                            return 0;
                            break;
                        default:
                            cout<<"Veuillez revoir votre entrer";
                            break;

                    }

                }catch (const exception& e) {
                    cerr << "Une Erreur c'est produite : ";
                }
        }

        return 0;
}
