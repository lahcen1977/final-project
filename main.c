#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int idProduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];

}produit;

typedef struct{
 int id_client;
 char nom[30];
 char prenom[30];
 char email[50];
 float solde;
}client;

produit prod[100];
client cli[100];

void creer_client(){
    int id_client = 0;
  printf("====espace de profil client====\n");
  printf("====                       ====\n");

  printf(" entrer nom :  ");
  scanf("%s",cli.nom);
  printf("entrer prenom :  ");
  scanf("%s",&cli.prenom);
  printf("entrer email :  ");
  scanf("%s",cli.email);
  printf("entrer sold : ");
  scanf("%f",cli.solde);
  printf("id _client : %d",id_client);

}

void Gestion_solde(){





}


void afficher_produit(){
    printf("===espace les produit===\n\n");
    printf("-----------------------------------------------\n");
    printf("nom_produit        prix(MAD)                stock\n");
    printf("-------------------------------------------------\n");
    printf("%s       799.00                     5   \n");
    printf("Smartphone         489.00                     10  \n");
    printf("Casque Audio        89.00                     15  \n");
    printf("Souris              25.00                     20  \n");
    printf("Clavier             45.00                     12  \n");
    printf("---------------------------------------------------\n");




}

void effectuer_achat(){
}

void statistique(){
}


void menu(){
printf("=======SUSTEME D'ACHAT CLIENT========\n\n");
printf(" 1 :: Gestion du profil client <>\n");
printf(" 2 :: Gestion du solde virtuel <>\n");
printf(" 3 :: Consultation des produits <>\n");
printf(" 4 :: Effectuer un achat <>\n");
printf(" 5 :: Mes statistique <>\n");
printf(" 0 :: Quitter l'application <>\n\n");
printf("======================================\n");





}




int main()
{
     menu();
     int choix;
     printf("entrer un choix ::  ");
     scanf("%d",&choix);
     switch(choix)
     {
     case 1:
         creer_client();
         break;
     case 2:
        Gestion_solde();
        break;
     case 3:
        afficher_produit();
        break;
     case 4:
        effectuer_achat();
        break;
     case 5:
        statistique();
        break;
     case 0:
         break;
     default:
        printf("error >!!<");

     }while(choix != 0);
     printf("merci pour visite \n");


    return 0;
}
