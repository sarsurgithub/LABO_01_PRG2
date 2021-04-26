/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.c
 Auteur(s)      : Jallon Sarah, Louis Hadrien, Martins Tenorio Richard V.
 Date creation  : 26.04.2021

 Description    : Implémentation des diverses fonctions permettant la création
                  et l'édition d'une liste doublement chainée non circulaire

 Remarque(s)    : 1) Nous ne tenons pas compte du cas où le paramètre "liste" serait
                  passé en tant que pointeur NULL.
                  2) La fonction vider() a été implémentée de telle sorte que nous
                  ne restituons pas la mémoire lorsqu'une liste est vidée entièrement
                  afin de pouvoir la re-remplir si besoin. Il faut donc s'assurer
                  de libérer la mémoire d'une liste en fin de programme.

 Compilateur    : Mingw-w64 g++ 8.1.0
                  Apple clang version 12.0.0 (clang-1200.0.32.29)
 -----------------------------------------------------------------------------------
*/

#include "listes_dynamiques.h"
#include <stdio.h>
#include "stdlib.h"

Liste *initialiser() {
   Liste *nouvelleListe = (Liste *) calloc(1, sizeof(Liste));
   return nouvelleListe;
}

bool estVide(const Liste *liste) {
   return liste->queue == NULL && liste->tete == NULL;
}

size_t longueur(const Liste *liste) {
   Element *actuel = liste->tete;
   size_t compteur = 0;

   while (actuel != NULL) {
      compteur++;
      actuel = actuel->suivant;
   }

   return compteur;
}

void afficher(const Liste *liste, Mode mode) {
   Element *actuel;

   printf("[");
   if (mode == FORWARD) {
      actuel = liste->tete;
      while (actuel != NULL) {
         printf("%d", actuel->info);
         if (actuel != liste->queue) printf(", ");
         actuel = actuel->suivant;
      }
   } else if (mode == BACKWARD) {   //nous précisons la condition au cas où un
      actuel = liste->queue;        // nouveau mode serait ajouté
      while (actuel != NULL) {
         printf("%d", actuel->info);
         if (actuel != liste->tete) printf(", ");
         actuel = actuel->precedent;
      }
   }
   printf("]\n");

}

Status insererEnTete(Liste *liste, const Info *info) {
   Element *el = (Element *) malloc(sizeof(Element));
   if (el == NULL) return MEMOIRE_INSUFFISANTE;

   *el = (Element) {
      .info = *info,
      .suivant = liste->tete,
      .precedent = NULL
   };

   if (!estVide(liste)) {
      liste->tete->precedent = el;
   } else {
      // Liste vide
      liste->queue = el;
   }

   liste->tete = el;

   return OK;
}

Status insererEnQueue(Liste *liste, const Info *info) {
   Element *el = (Element *) malloc(sizeof(Element));
   if (el == NULL) return MEMOIRE_INSUFFISANTE;

   *el = (Element) {
      .info = *info,
      .precedent = liste->queue,
      .suivant = NULL
   };

   if (!estVide(liste)) {
      liste->queue->suivant = el;
   } else {
      liste->tete = el;
   }
   liste->queue = el;

   return OK;
}

Status supprimerEnTete(Liste *liste, Info *info) {
   if (estVide(liste)) return LISTE_VIDE;
   Element *ancienneTete = liste->tete;
   *info = ancienneTete->info;

   if (longueur(liste) == 1) {
      liste->tete = liste->queue = NULL;
   } else {
      liste->tete = liste->tete->suivant;
      liste->tete->precedent = NULL;
   }

   free(ancienneTete);

   return OK;
}

Status supprimerEnQueue(Liste *liste, Info *info) {
   if (estVide(liste)) return LISTE_VIDE;
   Element *ancienneQueue = liste->queue;
   *info = ancienneQueue->info;

   if (longueur(liste) == 1) {
      liste->tete = liste->queue = NULL;
   } else {
      liste->queue = liste->queue->precedent;
      liste->queue->suivant = NULL;
   }

   free(ancienneQueue);

   return OK;
}

void supprimerSelonCritere(Liste *liste,
                           bool (*critere)(size_t position, const Info *info)) {
   if (estVide(liste)) return;

   Element *actuel = liste->tete;
   size_t pos = 0;
   while (actuel != NULL) {
      Element *suivant = actuel->suivant;
      if (critere(pos++, &actuel->info)) {
         // delete current
         Info tmpInfo;
         if (actuel == liste->tete) {
            supprimerEnTete(liste, &tmpInfo);
         } else if (actuel == liste->queue) {
            supprimerEnQueue(liste, &tmpInfo);
         } else {
            actuel->suivant->precedent = actuel->precedent;
            actuel->precedent->suivant = actuel->suivant;

            free(actuel);
         }
      }
      actuel = suivant;
   }
}


void vider(Liste *liste, size_t position) {
   if (longueur(liste) <= position) return;

   Element *actuel = liste->tete;
   size_t compteur = 0;

   while (compteur < position) {
      actuel = actuel->suivant;
      compteur++;
   }

   while (liste->queue != actuel->precedent) {
      Info tmpInfo;
      supprimerEnQueue(liste, &tmpInfo);
   }
}

bool sontEgales(const Liste *liste1, const Liste *liste2) {
   if (longueur(liste1) != longueur(liste2)) return false;
   if (estVide(liste1)) return true;

   Element *actuel1 = liste1->tete;
   Element *actuel2 = liste2->tete;
   while (actuel1 != NULL) {
      if (actuel1->info != actuel2->info) return false;

      actuel1 = actuel1->suivant;
      actuel2 = actuel2->suivant;
   }

   return true;
}
