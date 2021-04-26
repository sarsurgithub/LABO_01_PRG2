/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Jallon Sarah, Louis Hadrien, Martins Tenorio Richard V.
 Date creation  : 26.04.2021

 Description    : Programme testant le bon fonctionnnement des fonctions de la
                  librairie listes_dynamiques.h

 Remarque(s)    : -

 Compilateur    : Mingw-w64 g++ 8.1.0
                  Apple clang version 12.0.0 (clang-1200.0.32.29)
 -----------------------------------------------------------------------------------
*/

#include "listes_dynamiques.h"
#include <stdio.h>

bool elEstTrois(size_t position, const Info *info);
bool elEstPair(size_t position, const Info *info);


int main() {
   //-------------------------------------------------------------------------------
   //création des variables infos

   const Info info1 = 1;
   const Info info2 = 2;
   const Info info3 = 3;
   const Info info4 = 4;
   const Info info5;       // servira pour la fonction de suppression

   //-------------------------------------------------------------------------------
   //initialisation listes

   Liste *liste1Ptr = initialiser();
   Liste *liste2Ptr = initialiser();


   printf("Initialisation liste1 : ");
   afficher(liste1Ptr, FORWARD);

   printf("Initialisation liste2 : ");
   afficher(liste2Ptr, FORWARD);

   //-------------------------------------------------------------------------------
   //remplissage des listes

   printf("\nInsertion de 4 elements en tete de liste2  : ");
   insererEnTete(liste2Ptr, &info1);
   insererEnTete(liste2Ptr, &info2);
   insererEnTete(liste2Ptr, &info3);
   insererEnTete(liste2Ptr, &info4);

   afficher(liste2Ptr,FORWARD);

   printf("Insertion de 3 elements en queue de liste2 : ");
   insererEnQueue(liste2Ptr, &info4);
   insererEnQueue(liste2Ptr, &info3);
   insererEnQueue(liste2Ptr, &info2);

   afficher(liste2Ptr,FORWARD);

   //-------------------------------------------------------------------------------
   //tests vide et longueur

   printf("\nLa liste1 est-elle vide ? : %s, elle a une longueur de %zu\n",
          estVide(liste1Ptr) ? "oui" : "non",
          longueur(liste1Ptr));
   printf("La liste2 est-elle vide ? : %s, elle a une longueur de %zu\n",
          estVide(liste2Ptr) ? "oui" : "non",
          longueur(liste2Ptr));

   //-------------------------------------------------------------------------------
   //tests fonctions d'affichage

   printf("\nListe2 en mode FORWARD  : ");
   afficher(liste2Ptr,FORWARD);

   printf("Liste2 en mode BACKWARD : ");
   afficher(liste2Ptr,BACKWARD);

   //-------------------------------------------------------------------------------
   //test fonctions de supression

   printf("\nListe2 etat acutel : ");
   afficher(liste2Ptr,FORWARD);

   supprimerEnTete(liste2Ptr,&info5);

   printf("\nListe2 apres supression en tete : ");
   afficher(liste2Ptr,FORWARD);
   printf("Info supprimee: %d\n", info5);

   supprimerEnQueue(liste2Ptr, &info5);

   printf("\nListe2 apres supression en queue : ");
   afficher(liste2Ptr,FORWARD);
   printf("Info supprimee: %d\n", info5);

   supprimerSelonCritere(liste2Ptr,elEstTrois);
   printf("\nListe2 apres supression des occurences de 3 : ");
   afficher(liste2Ptr,FORWARD);

   supprimerSelonCritere(liste2Ptr,elEstPair);
   printf("Liste2 apres supression des nombres pairs : ");
   afficher(liste2Ptr,FORWARD);

   //-------------------------------------------------------------------------------
   //test vidage + égalité

   vider(liste2Ptr,0);
   printf("Liste2 apres avoir ete videe depuis la position 0 : ");
   afficher(liste2Ptr,FORWARD);

   printf("\nEtat actuel de Liste1 : ");
   afficher(liste1Ptr,FORWARD);
   printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
          sontEgales(liste2Ptr,liste1Ptr) ? "oui" : "non");


   insererEnTete(liste2Ptr, &info1);
   insererEnTete(liste2Ptr, &info2);
   insererEnTete(liste2Ptr, &info3);
   insererEnTete(liste2Ptr, &info4);
   insererEnTete(liste2Ptr, &info1);
   insererEnTete(liste2Ptr, &info2);
   insererEnTete(liste2Ptr, &info3);
   insererEnTete(liste2Ptr, &info4);

   insererEnTete(liste1Ptr, &info1);
   insererEnTete(liste1Ptr, &info2);
   insererEnTete(liste1Ptr, &info3);
   insererEnTete(liste1Ptr, &info4);
   insererEnTete(liste1Ptr, &info1);
   insererEnTete(liste1Ptr, &info2);
   insererEnTete(liste1Ptr, &info3);
   insererEnTete(liste1Ptr, &info4);

   printf("\nEtat actuel de liste1 : ");
   afficher(liste1Ptr,FORWARD);

   printf("Etat actuel de liste2 : ");
   afficher(liste2Ptr,FORWARD);

   printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
          sontEgales(liste2Ptr,liste1Ptr) ? "oui" : "non");

   printf("\nVidage de liste2 depuis la position 5: ");
   vider(liste2Ptr, 5);
   afficher(liste2Ptr,FORWARD);

   printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
          sontEgales(liste2Ptr,liste1Ptr) ? "oui" : "non");

   printf("\nVidage complet de liste1 et liste2 : ");
   vider(liste2Ptr,0);
   vider(liste1Ptr,0);

   printf("\nEtat actuel de liste1 : ");
   afficher(liste1Ptr,FORWARD);

   printf("Etat actuel de liste2 : ");
   afficher(liste2Ptr,FORWARD);

   printf("\nFin de programme");


   return 0;
}

bool elEstTrois(size_t position, const Info *info) {
   if (*info == 3) return true;
   return false;
}
bool elEstPair(size_t position, const Info *info) {
   if (*info % 2 == 0) return true;
   return false;
}

