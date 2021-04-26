#include "listes_dynamiques.h"
#include <stdio.h>

bool elPair(size_t position, const Info *info);

int main() {
   //-------------------------------------------------------
   //création des variables infos

   const Info info1 = 1;
   const Info info2 = 2;
   const Info info3 = 3;
   const Info info4 = 4;
   const Info info5;       // servira pour la fonction de suppression

   //-------------------------------------------------------
   //initialisation listes

   Liste *liste1Ptr = initialiser();
   Liste *liste2Ptr = initialiser();

   printf("Initialisation liste1 : ");
   afficher(liste1Ptr, FORWARD);

   printf("Initialisation liste2 : ");
   afficher(liste2Ptr, FORWARD);

   //-------------------------------------------------------
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

   //-------------------------------------------------------
   //tests vide et longueur

   printf("\nLa liste1 est-elle vide ? : %s, elle a une longueur de %zu\n",
          estVide(liste1Ptr) ? "oui" : "non",longueur(liste1Ptr));
   printf("La liste2 est-elle vide ? : %s, elle a une longueur de %zu\n",
          estVide(liste2Ptr) ? "oui" : "non",longueur(liste2Ptr));

   //-------------------------------------------------------
   //tests fonctions d'affichage

   printf("\nListe2 en mode FORWARD  : ");
   afficher(liste2Ptr,FORWARD);

   printf("Liste2 en mode BACKWARD : ");
   afficher(liste2Ptr,BACKWARD);

   //test fonctions de vidage


   return 0;
}

bool elPair(size_t position, const Info *info) {
   if (*info == 3) return true;
   return false;
}
