#ifndef GESTION_PRODUIT_H
#define GESTION_PRODUIT_H
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
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
            ofstream Produit("produit.txt",ios::app);
            if(Produit.is_open()){
                cout<<"Ouverture du fichier Produit.txt reussi\n";
                Produit<<nom<<"\t"<<categorie<<"\t"<<prix<<"\t"<<quantite<<"\n";
                Produit.close();
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier Produit.txt\n";
            }
        }


        //Implementation de la methode de modification d'un article

        /*void modifieArticle(){
            int choix;
            int i=1;
            ifstream Produit("produit.txt");
            //Verification le fichier est bien ouvert
            if(Produit.is_open()){
                string ligne;
                while(getline(Produit,ligne)){
                    cout<<i<<"  "<<ligne<<"\n";
                    i++;
                }
                Produit.close();
            }
            else{
                cerr<<"Erreur lors de l'ouverture du fichier produit.txt\n";
            }
            cout<<"Choisiser l'article a modifier"<<endl;
            //cin>>choix;

        }*/

        void modifieArticle() {
    int choix;
    int i = 1;
    string ligne;
    vector<string> produits;  // Utilisé pour stocker toutes les lignes du fichier

    // Ouvrir le fichier produit.txt pour lecture
    ifstream Produit("produit.txt");

    if (Produit.is_open()) {
        // Lire chaque ligne du fichier et stocker dans le vecteur
        while (getline(Produit, ligne)) {
            produits.push_back(ligne);
            cout << i << "  " << ligne << "\n";  // Afficher chaque produit avec un numéro
            i++;
        }
        Produit.close();  // Fermer le fichier une fois la lecture terminée
    } else {
        cerr << "Erreur lors de l'ouverture du fichier produit.txt\n";
        return;
    }

    // Demander à l'utilisateur quel produit il veut modifier
    cout << "Choisissez l'article à modifier en entrant le numéro correspondant: ";
    cin >> choix;

    // Vérifier que le choix est valide
    if (choix < 1 || choix >= i) {
        cerr << "Numéro invalide. Retour au menu.\n";
        return;
    }

    // Extraire la ligne de l'article choisi
    string article = produits[choix - 1];
    stringstream ss(article);
    string nomProduit, categorieProduit;
    double prixProduit;
    int quantiteProduit;

    // Extraire les informations de l'article
    ss >> nomProduit >> categorieProduit >> prixProduit >> quantiteProduit;

    // Afficher les informations actuelles de l'article
    cout << "Article sélectionné : " << nomProduit << " | " << categorieProduit << " | " << prixProduit << " | " << quantiteProduit << "\n";

    // Demander les nouvelles informations
    cout << "Entrez le nouveau nom (ou appuyez sur Entrée pour garder le même) : ";
    string nouveauNom;
    cin.ignore();  // Pour ignorer le caractère de fin de ligne
    getline(cin, nouveauNom);
    if (!nouveauNom.empty()) nomProduit = nouveauNom;  // Si l'utilisateur entre un nouveau nom

    cout << "Entrez la nouvelle catégorie (ou appuyez sur Entrée pour garder la même) : ";
    string nouvelleCategorie;
    getline(cin, nouvelleCategorie);
    if (!nouvelleCategorie.empty()) categorieProduit = nouvelleCategorie;  // Si l'utilisateur entre une nouvelle catégorie

    cout << "Entrez le nouveau prix (ou appuyez sur Entrée pour garder le même) : ";
    double nouveauPrix;
    string prixInput;
    getline(cin, prixInput);
    if (!prixInput.empty()) {
        stringstream(prixInput) >> nouveauPrix;
        prixProduit = nouveauPrix;  // Si l'utilisateur entre un nouveau prix
    }

    cout << "Entrez la nouvelle quantité (ou appuyez sur Entrée pour garder la même) : ";
    int nouvelleQuantite;
    string quantiteInput;
    getline(cin, quantiteInput);
    if (!quantiteInput.empty()) {
        stringstream(quantiteInput) >> nouvelleQuantite;
        quantiteProduit = nouvelleQuantite;  // Si l'utilisateur entre une nouvelle quantité
    }

    // Réécrire le fichier avec les nouvelles données
    ofstream fichierTemp("produit_temp.txt");  // Créer un fichier temporaire

    if (fichierTemp.is_open()) {
        // Réécrire chaque ligne du fichier, en modifiant la ligne de l'article choisi
        for (int j = 0; j < produits.size(); j++) {
            if (j == choix - 1) {
                // Réécrire l'article modifié
                fichierTemp << nomProduit << "\t" << categorieProduit << "\t" << prixProduit << "\t" << quantiteProduit << "\n";
            } else {
                // Réécrire les autres articles sans modification
                fichierTemp << produits[j] << "\n";
            }
        }
        fichierTemp.close();  // Fermer le fichier temporaire

        // Supprimer l'ancien fichier et renommer le fichier temporaire
        remove("produit.txt");
        rename("produit_temp.txt", "produit.txt");

        cout << "Modification effectuée avec succès.\n";
    } else {
        cerr << "Erreur lors de l'ouverture du fichier temporaire.\n";
    }
}

        //virtual ~gestion_produit();

    protected:

    private:
};

#endif // GESTION_PRODUIT_H
