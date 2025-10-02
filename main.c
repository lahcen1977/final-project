#include <stdio.h>
#include <string.h>

typedef struct {
    int idClient;
    char nom[30];
    char prenom[30];
    char email[50];
    float solde;
} Client;

typedef struct {
    int idProduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;

Client client;
Produit produits[100];
int nbProduits = 0;

int produitChoisi = -1;
int quantiteAchetee = 0;

// ==== Déclarations des fonctions (prototypes) ====
void afficherMenuPrincipal();
void gererChoixPrincipal();
void gererProfilClient();
    void afficherMenuClient();
        void creerUnProfil();
        void modificationProfil();
        void consulterLeProfil();
void gererSoldeVirtuel();
    void afficherMenuSolde();
        void consulterSolde();
        void deposerArgent();
void afficherProduitsDisponibles();
    void afficherMenuProduit();
        void afficherCatalogue();
        void rechercherProduitParNom();
        void rechercherProduitParCategorie();
        void trierProduitsParPrix();
void effectuerAchat();
        void selectProduit();
        int verification();
        void paiement();
        void miseAjour();
        void confirmation();
void afficherStatistiquesClient();





//initille des 5 produit
void ajouterProduitDefault(char nom[], char categorie[], float prix, int stock, char description[]) {
    if (nbProduits < 100) {
        produits[nbProduits].idProduit = nbProduits + 1;
        strcpy(produits[nbProduits].nom, nom);
        strcpy(produits[nbProduits].categorie, categorie);
        produits[nbProduits].prix = prix;
        produits[nbProduits].stock = stock;
        strcpy(produits[nbProduits].description, description);
        nbProduits++;
    }
}

void initCatalogue() {
    ajouterProduitDefault("Ordinateur", "Electronique", 799, 5, "Laptop 14'' - CPU i5 - 8GB RAM");
    ajouterProduitDefault("Smartphone", "Electronique", 499, 10, "Smartphone 6.5'' - 128GB");
    ajouterProduitDefault("Casque Audio", "Audio", 89, 15, "Casque circum-aural");
    ajouterProduitDefault("Souris", "Peripherique", 25, 20, "Souris optique USB");
    ajouterProduitDefault("Clavier", "Peripherique", 45, 12, "Clavier AZERTY filaire");
}



int main() {



    initCatalogue();
    afficherMenuPrincipal();
    gererChoixPrincipal();
    return 0;
}

void afficherMenuPrincipal() {
    printf("\n=====  SYSTEME DACHAT CLIENT ======\n");
    printf("1. Gestion du profil client\n");
    printf("2. Gestion du solde virtuel\n");
    printf("3. Consultation des produits\n");
    printf("4. Effectuer un achat\n");
    printf("5. Mes statistiques\n");
    printf("0. Quitter lapplication\n");
    printf("======================================\n");
}

void gererChoixPrincipal() {
    int choix;
    printf("\n Entrez votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            gererProfilClient();
            break;
        case 2:
            gererSoldeVirtuel();
            break;
        case 3:
            afficherProduitsDisponibles();
            break;
        case 4:
            effectuerAchat();
            break;
        case 5:
            afficherStatistiquesClient();
            break;
        case 0:
            printf("Merci d'avoir utilisé notre système. À bientôt !\n");
            break;
        default:
            printf("hoix invalide. Veuillez réessayer.\n");
    }
}

//esapace de cliante
void afficherMenuClient() {
    printf("\n=====  GESTION DU PROFIL CLIENT =====\n");
    printf("1. creer un profil\n");
    printf("2. Modifier le profil\n");
    printf("3. Consulter le profil\n");
    printf("0. Retour au menu principal\n");
    printf("=======================================\n");

    int choix;
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            creerUnProfil();
            break;
        case 2:
            modificationProfil();
            break;
        case 3:
            consulterLeProfil();
            break;
        case 0:
            printf("Retour au menu principal...\n");
            afficherMenuPrincipal();
            gererChoixPrincipal();
            break;
        default:
            printf("hoix invalide. Veuillez reessayer.\n");
            afficherMenuClient();
    }
}

void creerUnProfil() {
    printf("Creation du profil client\n");
    printf("-----------------------------------------\n");
    client.idClient = 1;
    printf("Prenom : ");
    scanf("%s", client.prenom);
    printf("Nom : ");
    scanf("%s", client.nom);
    sprintf(client.email, "%s.%s@gmail.com", client.prenom, client.nom);
    client.solde = 0.0;
    printf("rofil cree avec succes !\n");
    printf("ID : %d\n", client.idClient);
    printf("Email: %s\n", client.email);
    printf("Solde initial : %.2f MAD\n", client.solde);
     printf("profile create avec secsse!\n");
    afficherMenuClient();
}

void modificationProfil() {
    printf("\n Modification du profil client\n");
    printf("=====================================\n");

    printf(" Informations actuelles :\n");
    printf("    Prenom : %s\n", client.prenom);
    printf("    Nom    : %s\n", client.nom);
    printf("    Email  : %s\n", client.email);
    printf("-------------------------------------\n");


    printf(" Entrez le nouveau prenom : ");
    scanf("%s", client.prenom);
    printf(" Entrez le nouveau nom : ");
    scanf("%s", client.nom);
    sprintf(client.email, "%s.%s@gmail.com", client.prenom, client.nom);

    printf("\nrofil mis à jour avec succès !\n");
    printf("ID client      : %d\n", client.idClient);
    printf("Nouveau nom    : %s %s\n", client.prenom, client.nom);
    printf("Nouvel email   : %s\n", client.email);
    printf("Solde actuel   : %.2f MAD\n", client.solde);

    printf("profile misajeure avec secsse!\n");

    afficherMenuClient();
}

void consulterLeProfil() {
    printf("\n=========  VOTRE PROFIL CLIENT =========\n");

    if (client.idClient != 0) {
        printf(" ID Client        : %d\n", client.idClient);
        printf(" Nom Complet      : %s %s\n", client.prenom, client.nom);
        printf(" Adresse Email    : %s\n", client.email);
        printf(" Solde Disponible : %.2f MAD\n", client.solde);
        printf("==========================================\n");
    } else {
        printf(" Aucun profil trouve !\n");
        printf(" Veuillez dabord creer un profil pour acceder aux fonctionnalites.\n");
        printf("------------------------------------------\n");
        int choix;
        printf("1.Creer un profil\n");
        printf("0.Retour au menu\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            creerUnProfil();
        } else if (choix == 0) {
            afficherMenuClient();
            return;
        } else {
            printf(" Choix invalide. Retour au menu...\n");
            afficherMenuClient();
            return;
        }
    }

    afficherMenuClient();
}

void gererProfilClient() {
    afficherMenuClient();
}

//espace de solde

void gererSoldeVirtuel() {
    if (client.idClient != 0){
        afficherMenuSolde();
    }else {
        printf(" Aucun profil trouve !\n");
        printf(" Veuillez dabord creer un profil pour acceder aux fonctionnalites.\n");
        printf("------------------------------------------\n");
        int choix;
        printf("1.Creer un profil\n");
        printf("0.Retour au menu\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            creerUnProfil();
        } else if (choix == 0) {
            afficherMenuClient();
            return;
        } else {
            printf(" Choix invalide. Retour au menu...\n");
            afficherMenuClient();
            return;
        }
    }

}

void afficherMenuSolde(){
    int choix;
    printf("=== GESTION DU SOLDE VIRTUEL ===\n");
    printf("1. Consulter mon solde\n");
    printf("2. Deposer de largent\n");
    printf("0. Retour au menu principal\n");
    printf("================================\n\n");

    printf("Votre choix:");
    scanf("%d",&choix);

    switch(choix){
        case 1:
            consulterSolde();
            break;
        case 2:
            deposerArgent();
            break;
        case 0:
            afficherMenuPrincipal();
            gererChoixPrincipal();
            return;
    }

}

void consulterSolde(){
    printf("Votr solde et: %f",client.solde);
    afficherMenuSolde();

}
void deposerArgent() {
    float montant;
    printf("Votre solde actuellement: %.2f DH\n", client.solde);
    printf("Entrez le montant a deposer: ");
    scanf("%f", &montant);

    client.solde += montant;

    printf("Le montant depose avec succes.\n");
    printf("Le nouveau solde est: %.2f DH\n", client.solde);
    afficherMenuSolde();
}




//esapac de produit

void afficherProduitsDisponibles() {
    afficherMenuProduit();
}


void afficherMenuProduit() {
    int choix;
    char recherche[50];
    int id;

        printf("\n=== GESTION DES PRODUITS ===\n");
        printf("1. Afficher le catalogue\n");
        printf("2. Rechercher produit\n");
        printf("3. Trier produits par\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherCatalogue();
                break;

            case 2:
                int choix;
                skip:
                printf("---------------------------------------------\n");
                printf("Espace de Recherche...\n");
                printf("---------------------------------------------\n");
                printf("1. Recherche par nom\n");
                printf("2. Recherche par categorie\n");

                printf("Entre un choix:");
                scanf("%d",&choix);
                switch(choix){
                case 1:
                    rechercherProduitParNom();
                    break;
                case 2:
                    rechercherProduitParCategorie();
                    break;
                 default:
                    printf("hoix invalide. Veuillez reessayer.\n");
                    goto skip;
                }
                break;

            case 3:
                trierProduitsParPrix();
                afficherCatalogue();

                break;
            case 0:
                printf("Retour au menu principal...\n");
                afficherMenuPrincipal();
                break;
            default:
                printf("Choix invalide!\n");
                afficherMenuPrincipal();
        }
}


void afficherCatalogue() {
    printf("\n CATALOGUE DES PRODUITS \n");
    for (int i = 0; i < nbProduits; i++) {
        printf("ID: %d\n", produits[i].idProduit);
        printf("Nom: %s\n", produits[i].nom);
        printf("Categorie: %s\n", produits[i].categorie);
        printf("Prix: %.2f MAD\n", produits[i].prix);
        printf("Stock: %d\n", produits[i].stock);
        printf("Description: %s\n", produits[i].description);
        printf("--------------------------------------\n");
    }
    afficherMenuProduit();

}

void rechercherProduitParNom() {
    printf("---------------------------------------------\n");
    printf(" Recherche de produit par nom\n");
    printf("---------------------------------------------\n");
    char nomRecherche[50];
    printf("Entrez le nom du produit : ");
    scanf("%s", nomRecherche);
    int trouve = 0;
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(nomRecherche, produits[i].nom) == 0) {
            printf("Produit trouve:\n");
            printf("ID        : %d\n", produits[i].idProduit);
            printf("Nom       : %s\n", produits[i].nom);
            printf("Catégorie : %s\n", produits[i].categorie);
            printf("Prix      : %.2f MAD\n", produits[i].prix);
            printf("Stock     : %d unités\n", produits[i].stock);
            printf("Description : %s\n", produits[i].description);
            trouve = 1;
            break;
        }
    }
    if(trouve ==0){
        printf(" Aucun produit ne correspond au nom \"%s\".\n", nomRecherche);
    }

}
void rechercherProduitParCategorie() {
    printf("---------------------------------------------\n");
    printf(" Recherche de produit par categorie\n");
    printf("---------------------------------------------\n");
    char nomRecherche[50];
    printf("Entrez le categorie du produit : ");
    scanf("%s", nomRecherche);
    int trouve = 0;
    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(nomRecherche, produits[i].categorie) == 0) {
            printf("Produit trouve:\n");
            printf("ID        : %d\n", produits[i].idProduit);
            printf("Nom       : %s\n", produits[i].nom);
            printf("Catégorie : %s\n", produits[i].categorie);
            printf("Prix      : %.2f MAD\n", produits[i].prix);
            printf("Stock     : %d unités\n", produits[i].stock);
            printf("Description : %s\n", produits[i].description);
            trouve = 1;
            printf("---------------------------------------------\n");
        }
    }
    if(trouve ==0){
        printf(" Aucun produit ne correspond au categorie \"%s\".\n", nomRecherche);
    }

}

void trierProduitsParPrix() {
    printf("---------------------------------------------\n");
    printf("Liste des produits triés par prix\n");
    printf("---------------------------------------------\n");

    Produit tmp;
    for(int i = 0; i < nbProduits - 1; i++) {

        for(int j = 0; j < nbProduits - 1; j++) {
            if(produits[j].prix > produits[j+1].prix) {
                tmp = produits[j];
                produits[j] = produits[j+1];
                produits[j+1] = tmp;
            }
        }
    }
}


void menuAchat(){
printf("=======ESPACE MRNU ACHAT=======\n\n");
printf("1 : select_produite ::::\n");
printf("2 : verification ::::\n");
printf("3 : paiement ::::\n");
printf("4 : mise_a_jour ::::\n");
printf("5 : comfirmation ::::\n");

int choix ;
printf("size un choix : ");
scanf("%d",&choix);
switch(choix){

            case 1:
                selectProduit();
                break;

            case 2:
                verification();
                break;

            case 3:
                paiement();
                break;
            case 4:
                miseAjour();
                break;
            case 0:
                afficherMenuPrincipal();
                gererChoixPrincipal();
                break;
            default:
                printf("eroor !!!!\n");
                afficherMenuPrincipal();
                gererChoixPrincipal();

}

}


void selectProduit(){
  printf("\n CATALOGUE DES PRODUITS \n");
    for (int i = 0; i < nbProduits; i++) {
        printf("ID: %d\n", produits[i].idProduit);
        printf("Nom: %s\n", produits[i].nom);
        printf("Categorie: %s\n", produits[i].categorie);
        printf("Prix: %.2f MAD\n", produits[i].prix);
        printf("Stock: %d\n", produits[i].stock);
        printf("Description: %s\n", produits[i].description);
        printf("--------------------------------------\n");
    }
    int idSelectionne;
    printf("Entrez ID du produit q acheter : ");
    scanf("%d", &idSelectionne);

    produitChoisi = -1;
    for (int i = 0; i < nbProduits; i++) {
        if (produits[i].idProduit == idSelectionne) {
            produitChoisi = i;
            break;
        }
    }

    if (produitChoisi == -1) {
        printf("Produit non trouve.\n");
        return;
    }

    printf("Quantite q acheter : ");
    scanf("%d", &quantiteAchetee);
    if (quantiteAchetee <= 0) {
        printf("Quantite invalide.\n");
        produitChoisi = -1;
        }
        return;
    }



int verification(){
if (produitChoisi == -1) {
        printf("Aucun produit selectionne.\n");
        return 0;
    }

    if (produits[produitChoisi].stock < quantiteAchetee) {
        printf("Stock insuffisant. Stock disponible: %d\n", produits[produitChoisi].stock);
        return 0;
    }

    float total = produits[produitChoisi].prix * quantiteAchetee;
    if (client.solde < total) {
        printf("Solde insuffisant. Votre solde: %.2f MAD, Total achat: %.2f MAD\n", client.solde, total);
        return 0;
    }

    return 1;
}

void paiement() {
    float total = produits[produitChoisi].prix * quantiteAchetee;
    client.solde -= total;
    printf("Paiement effectue avec succes. Montant debite : %.2f DH\n", total);
    menuAchat();
}

void miseAjour(){

produits[produitChoisi].stock -= quantiteAchetee;
    printf("Stock mis à jour. Stock restant de %s : %d\n",
        produits[produitChoisi].nom,
        produits[produitChoisi].stock);
        menuAchat();

}






void effectuerAchat() {
    menuAchat();

}


void afficherStatistiquesClient() {
    printf("Module Statistiques en développement...\n");
}

