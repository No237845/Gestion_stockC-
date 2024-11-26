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
        //nom, cat�gorie, prix et quantit�.
        string nom;
        string categorie;
        double prix;
        int quantite;

        //Creation de la class d'ajout de produit
        /*Ici ma logique est que chaque donn� aura un fichier specifique a lui*/

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

            //Enregistrement des donn�e dans leur fichier respectifs
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
    vector<string> produits;  // Utilis� pour stocker toutes les lignes du fichier

    // Ouvrir le fichier produit.txt pour lecture
    ifstream Produit("produit.txt");

    if (Produit.is_open()) {
        // Lire chaque ligne du fichier et stocker dans le vecteur
        while (getline(Produit, ligne)) {
            produits.push_back(ligne);
            cout << i << "  " << ligne << "\n";  // Afficher chaque produit avec un num�ro
            i++;
        }
        Produit.close();  // Fermer le fichier une fois la lecture termin�e
    } else {
        cerr << "Erreur lors de l'ouverture du fichier produit.txt\n";
        return;
    }

    // Demander � l'utilisateur quel produit il veut modifier
    cout << "Choisissez l'article � modifier en entrant le num�ro correspondant: ";
    cin >> choix;

    // V�rifier que le choix est valide
    if (choix < 1 || choix >= i) {
        cerr << "Num�ro invalide. Retour au menu.\n";
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
    cout << "Article s�lectionn� : " << nomProduit << " | " << categorieProduit << " | " << prixProduit << " | " << quantiteProduit << "\n";

    // Demander les nouvelles informations
    cout << "Entrez le nouveau nom (ou appuyez sur Entr�e pour garder le m�me) : ";
    string nouveauNom;
    cin.ignore();  // Pour ignorer le caract�re de fin de ligne
    getline(cin, nouveauNom);
    if (!nouveauNom.empty()) nomProduit = nouveauNom;  // Si l'utilisateur entre un nouveau nom

    cout << "Entrez la nouvelle cat�gorie (ou appuyez sur Entr�e pour garder la m�me) : ";
    string nouvelleCategorie;
    getline(cin, nouvelleCategorie);
    if (!nouvelleCategorie.empty()) categorieProduit = nouvelleCategorie;  // Si l'utilisateur entre une nouvelle cat�gorie

    cout << "Entrez le nouveau prix (ou appuyez sur Entr�e pour garder le m�me) : ";
    double nouveauPrix;
    string prixInput;
    getline(cin, prixInput);
    if (!prixInput.empty()) {
        stringstream(prixInput) >> nouveauPrix;
        prixProduit = nouveauPrix;  // Si l'utilisateur entre un nouveau prix
    }

    cout << "Entrez la nouvelle quantit� (ou appuyez sur Entr�e pour garder la m�me) : ";
    int nouvelleQuantite;
    string quantiteInput;
    getline(cin, quantiteInput);
    if (!quantiteInput.empty()) {
        stringstream(quantiteInput) >> nouvelleQuantite;
        quantiteProduit = nouvelleQuantite;  // Si l'utilisateur entre une nouvelle quantit�
    }

    // R��crire le fichier avec les nouvelles donn�es
    ofstream fichierTemp("produit_temp.txt");  // Cr�er un fichier temporaire

    if (fichierTemp.is_open()) {
        // R��crire chaque ligne du fichier, en modifiant la ligne de l'article choisi
        for (int j = 0; j < produits.size(); j++) {
            if (j == choix - 1) {
                // R��crire l'article modifi�
                fichierTemp << nomProduit << "\t" << categorieProduit << "\t" << prixProduit << "\t" << quantiteProduit << "\n";
            } else {
                // R��crire les autres articles sans modification
                fichierTemp << produits[j] << "\n";
            }
        }
        fichierTemp.close();  // Fermer le fichier temporaire

        // Supprimer l'ancien fichier et renommer le fichier temporaire
        remove("produit.txt");
        rename("produit_temp.txt", "produit.txt");

        cout << "Modification effectu�e avec succ�s.\n";
    } else {
        cerr << "Erreur lors de l'ouverture du fichier temporaire.\n";
    }
}

        //virtual ~gestion_produit();

    protected:

    private:
};

#endif // GESTION_PRODUIT_H
