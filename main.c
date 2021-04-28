/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Jallon Sarah, Louis Hadrien, Martins Tenorio Richard V.
 Date creation  : 26.04.2021

 Description    : Programme testant le bon fonctionnnement des fonctions de la
                  librairie listes_dynamiques.h

 Remarque(s)    : 1) Il reste des warnings concernant l'affichage du type size_t par
                  printf. Nous avons choisi d'implémenter la solution vue en cours,
                  à savoir d'utiliser PRIu64 pour afficher des size_t.

 Compilateur    : Mingw-w64 g++ 8.1.0
                  Apple clang version 12.0.0 (clang-1200.0.32.29)
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "listes_dynamiques.h"
#include "conditions_suppression.h"


int main() {
	//création des variables infos
	const Info info1 = 1;
	const Info info2 = 2;
	const Info info3 = 3;
	const Info info4 = 4;
	Info info5;       // servira pour la fonction de suppression

	printf("\n------------------------------------------------------------\n");
	printf("Initialisation des listes");
	printf("\n------------------------------------------------------------\n");

	Liste *liste1Ptr = initialiser();
	Liste *liste2Ptr = initialiser();

	printf("\nInitialisation Liste1 ...\nListe1 : ");
	afficher(liste1Ptr, FORWARD);

	printf("Initialisation Liste2 ...\nListe2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests remplissage de listes");
	printf("\n------------------------------------------------------------\n");

	printf("\nInsertion de 4 elements en tete de Liste2  ...");
	insererEnTete(liste2Ptr, &info1);
	insererEnTete(liste2Ptr, &info2);
	insererEnTete(liste2Ptr, &info3);
	insererEnTete(liste2Ptr, &info4);

	printf("\nListe2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("Insertion de 3 elements en queue de Liste2 ...");
	insererEnQueue(liste2Ptr, &info4);
	insererEnQueue(liste2Ptr, &info3);
	insererEnQueue(liste2Ptr, &info2);

    printf("\nListe2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests estVide() et longueur()");
	printf("\n------------------------------------------------------------\n");

	printf("\nLa Liste1 est-elle vide ? : %s, elle a une longueur de %" PRIu64
	       "\n",estVide(liste1Ptr) ? "oui" : "non", longueur(liste1Ptr));
	printf("La Liste2 est-elle vide ? : %s, elle a une longueur de %" PRIu64
	       "\n", estVide(liste2Ptr) ? "oui" : "non", longueur(liste2Ptr));

	printf("\n------------------------------------------------------------\n");
	printf("Tests affichages");
	printf("\n------------------------------------------------------------\n");

	printf("\nListe2 en mode FORWARD  : ");
	afficher(liste2Ptr, FORWARD);

	printf("Liste2 en mode BACKWARD : ");
	afficher(liste2Ptr, BACKWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests des fonctions de supression");
	printf("\n------------------------------------------------------------\n");

	printf("\nSupression en tete de Liste2 ...");
	supprimerEnTete(liste2Ptr, &info5);

	printf("\nEtat Liste2 : ");
	afficher(liste2Ptr, FORWARD);
	printf("Info supprimee: %d\n", info5);

	printf("\nSupression en queue de Liste2 ...");
	supprimerEnQueue(liste2Ptr, &info5);

	printf("\nEtat Liste2 : ");
	afficher(liste2Ptr, FORWARD);
	printf("Info supprimee: %d\n", info5);

    printf("\nSupression des positions paires ayant des infos entre ]1,3] ...");
	supprimerSelonCritere(liste2Ptr, doubleCondition);
	printf("\nEtat Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nInsertion d'elements dans Liste2 ...");
	insererEnTete(liste2Ptr, &info1);
	insererEnTete(liste2Ptr, &info2);
	insererEnTete(liste2Ptr, &info3);

	printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nSupression des position pair de Liste2 ...");
	supprimerSelonCritere(liste2Ptr, posEstPair);

    printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nSupression des elements de Liste2 avec Info superieur a 3 ...");
	supprimerSelonCritere(liste2Ptr, infoSupATrois);

    printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests vider() et sontEgales()");
	printf("\n------------------------------------------------------------\n");

	printf("\nTentative de vider Liste2 avec une position trop grande ...");
	vider(liste2Ptr, 12);
    printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	vider(liste2Ptr, 0);
	printf("\nVidage de Liste2 depuis la position 0 ...");
    printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nEtat actuel de Liste1 : ");
	afficher(liste1Ptr, FORWARD);
	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
           sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

	printf("\nRemplissage de Liste1 et Liste2 ...");
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

	printf("\nEtat de Liste1 : ");
	afficher(liste1Ptr, FORWARD);

	printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
			 sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

	printf("\nVidage de Liste2 depuis la position 5 ...");
	vider(liste2Ptr, 5);

    printf("\nEtat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
			 sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

	printf("\nVidage complet de Liste1 et Liste2 ...");
	vider(liste2Ptr, 0);
	vider(liste1Ptr, 0);

	printf("\nEtat de Liste1 : ");
	afficher(liste1Ptr, FORWARD);

	printf("Etat de Liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Differents tests sur listes vides");
	printf("\n------------------------------------------------------------\n");

	printf("\nSupression en tete Liste2 vide ...\n");
	supprimerEnTete(liste2Ptr, &info5) == LISTE_VIDE ? printf("Liste vide") :
	printf("erreur");

	printf("\nSupression en queue de liste2 vide ...\n");
	supprimerEnQueue(liste2Ptr, &info5) == LISTE_VIDE ? printf("Liste vide") :
	printf("erreur");

	printf("\n\nSupression selon critere Liste2 vide ...\n");
	printf("avant : ");
	afficher(liste2Ptr, FORWARD);
	supprimerSelonCritere(liste2Ptr, posEstPair);
	printf("apres : ");
	afficher(liste2Ptr, FORWARD);

	//libérer mémoire
	free(liste1Ptr);
	free(liste2Ptr);

    liste1Ptr = NULL;
	liste2Ptr = NULL;

	printf("\n------------------------------------------------------------\n");
	printf("Fin de programme");
	printf("\n------------------------------------------------------------\n");

	return 0;
}


