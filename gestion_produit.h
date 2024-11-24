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
        //nom, catégorie, prix et quantité.
        string nom;
        string categorie;
        double prix;
        int quantite;
        list<string> loggeur;

        //Creation de la class d'ajout de produit
        /*Ici ma logique est que chaque donné aura un fichier specifique a lui*/

        //ajouterProduit();
        void gestion_prod(){
            string donner;
            cout<<"Entrer le nom du produit\n";
            cin>>nom;
            cout<<"Entrer la categorie du produit\n";
            cin>>categorie;
            cout<<"Entrez le prix du produit\n";
            cin>>prix;
            cout<<"Entrer la quantitee du produit\n";
            cin>>quantite;
            donner="Ajout produit"+nom+" "+categorie+" "+to_string(prix)+" "+" "+to_string(quantite);
            loggeur.push_back(donner);
            //Enregistrement des donnée dans leur fichier respectifs
            //Enregistrement du nom du produit
            ofstream Produit("produit.txt",ios::app);
            if(Produit.is_open()){

                Produit<<nom<<"\t"<<categorie<<"\t"<<prix<<"\t"<<quantite<<"\n";
                cout<<"Produit ajouter avec succes\n";
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
    cout << "Choisissez l'article a modifier en entrant le numero correspondant: ";
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
    cout << "Entrez le nouveau nom (ou appuyez sur Entree pour garder le meme) : ";
    string nouveauNom;
    cin.ignore();  // Pour ignorer le caractère de fin de ligne
    getline(cin, nouveauNom);
    if (!nouveauNom.empty()) nomProduit = nouveauNom;  // Si l'utilisateur entre un nouveau nom

    cout << "Entrez la nouvelle catégorie (ou appuyez sur Entrée pour garder la meme) : ";
    string nouvelleCategorie;
    getline(cin, nouvelleCategorie);
    if (!nouvelleCategorie.empty()) categorieProduit = nouvelleCategorie;  // Si l'utilisateur entre une nouvelle catégorie

    cout << "Entrez le nouveau prix (ou appuyez sur Entree pour garder le meme) : ";
    double nouveauPrix;
    string prixInput;
    getline(cin, prixInput);
    if (!prixInput.empty()) {
        stringstream(prixInput) >> nouveauPrix;
        prixProduit = nouveauPrix;  // Si l'utilisateur entre un nouveau prix
    }

    cout << "Entrez la nouvelle quantite (ou appuyez sur Entree pour garder la meme) : ";
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

        cout << "Modification effectuee avec succes.\n";
    } else {
        cerr << "Erreur lors de l'ouverture du fichier temporaire.\n";
    }
}

    //Mise en place de la fonctionnalité de suppression de produit
    void supprimerProduit(){
        string donner;
        vector<string> produits;
        int reponse;
        string ligne;
        int i=1;
        ifstream Produit("Sauvegarde.txt");

        if (Produit.is_open()) {
            // Lire chaque ligne du fichier et stocker dans le vecteur
            while (getline(Produit, ligne)) {
                produits.push_back(ligne);
                cout << i << "  " << ligne << "\n";  // Afficher chaque produit avec un numéro
                i++;
            }
            Produit.close();  // Fermer le fichier une fois la lecture terminée
        } else {
            cerr << "Erreur lors de l'ouverture du fichier Sauvegarde.txt\n";
            return;
        }

        // Demander à l'utilisateur quel produit il veut modifier
        cout << "Choisissez l'article a modifier en entrant le numero correspondant: ";
        cin >> reponse;

        if(reponse<1||reponse>produits.size()){
            cout<<"Numero choisi non valide\n";
            return;
        }
        donner = "suppression de produit: " + produits[reponse - 1];

        loggeur.push_back(donner);
        produits.erase(produits.begin()+reponse-1);

        //Ecriture des donnés restant dans le fichier
        ofstream ProduitSortie("produit.txt",ios::trunc);

        if(ProduitSortie.is_open()){
            for(const string & produit: produits){
                ProduitSortie<<produit<<"\n";
            }
            ProduitSortie.close();
            cout<<"Produit supprimer avec succès\n";
        }else{
           cerr<<"Erreur lors de l'ouverture du fichier produit.txt\n";
        }
    }


    //Afficher les articles disponibles
    void produitAffichage(){
        // Extraire la ligne de l'article choisi
        int i=1;
        vector<string>produits;
        //string article;

        string nomProduit, categorieProduit;
        double prixProduit;
        int quantiteProduit;


        string ligne;
        ifstream ProduitAffichage("Sauvegarde.txt");
        if(ProduitAffichage.is_open()){
            while(getline(ProduitAffichage,ligne)){
                produits.push_back(ligne);
            }

        }
        else{
            cout<<"Rien a afficher pour l instant\n";
        }


        if(ProduitAffichage.is_open()){
            cout<<"Nom produits\tQuantitee Produit\n";
            for(int i=1;i<=produits.size();i++){
                string article = produits[i - 1];
                stringstream ss(article);
                ss >> nomProduit >> categorieProduit >> prixProduit >> quantiteProduit;
                if(quantiteProduit>0){
                    cout<<nomProduit<<"\t\t\t"<<quantiteProduit<<"\n";
                }
            }
            cout<<"Lecture terminer\n";
            ProduitAffichage.close();
        }
        else{
            cerr<<"Erreur lors de l'ouverture du fichier";
        }

    }

    //FONCTION DE RECHERCHE
    void rechercheProduit(){
        string nom;
        cout<<"Veuillez entrer le nom rechercher\n"<<endl;
        cin>>nom;
        ifstream fichierProduit("Sauvegarde.txt");
        if(fichierProduit.is_open()){
            string ligne;
            while(getline(fichierProduit,ligne)){
                if(ligne.find(nom)!=string::npos){
                    cout<<"produit trouver"<<endl;
                    cout<<ligne<<endl;
                }
                else{
                    cout<<"Oups!Aucun resultat trouver"<<endl;
                }
            }
            fichierProduit.close();
        }
        else{
            cerr<<"Erreur lors de l'ouverture du fichier"<<endl;
        }

    }

    //Fonction de enregistrement de transaction
    void enregistrerTransaction() {
    cout << "Enregistrement des transactions en cours..." << endl;

    // Ouvrir le fichier en mode ajout (appending)
    ofstream sortiFichier("loggeur.txt", ios::app);

    if (sortiFichier.is_open()) {
        // Écrire chaque transaction dans le fichier
        for (const string& transaction : loggeur) {
            sortiFichier << transaction << endl;
        }

        sortiFichier.close();  // Fermer le fichier après écriture
        cout << "Enregistrement terminé." << endl;
    } else {
        cerr << "Erreur lors de l'ouverture du fichier loggeur.txt" << endl;
    }
}

    //Fonction de sauvegarde de donnée
    void sauvegarde(){
        ifstream entrerFichier("produit.txt", ios::app);
        ofstream sortiFichier("Sauvegarde.txt",ios::trunc);

        string ligne;
        if(entrerFichier.is_open()){
            while(getline(entrerFichier,ligne)){
                sortiFichier<<ligne<<"\n";
            }
        }
        cout<<"Sauvegarde terminer avec succes\n";
        sortiFichier.close();
        entrerFichier.close();
    }
        //virtual ~gestion_produit();

    protected:

    private:
};

#endif // GESTION_PRODUIT_H
