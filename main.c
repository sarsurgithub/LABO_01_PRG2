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

#include "listes_dynamiques.h"
#include <stdio.h>
#include "stdlib.h"
#include <inttypes.h>

/**
 * Renvoie true lorsque la position est paire et que l'info est entre 1 non compris
 * et 3 compris.
 * @param position
 * @param info
 * @return bool
 */
bool conditionSupression(size_t position, const Info *info);

/**
 * Renvoie true lorsque la position est paire
 * @param position
 * @param info
 * @return bool
 */
bool conditionSupressionPosition(size_t position, const Info *info);

/**
 * Renvoie true lorsque la valeur de info > 3
 * @param position
 * @param info
 * @return bool
 */
bool conditionSupressionInfo(size_t position, const Info *info);

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

	printf("\nInitialisation liste1 : ");
	afficher(liste1Ptr, FORWARD);

	printf("Initialisation liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests remplissage de listes");
	printf("\n------------------------------------------------------------\n");

	printf("\nInsertion de 4 elements en tete de liste2  : ");
	insererEnTete(liste2Ptr, &info1);
	insererEnTete(liste2Ptr, &info2);
	insererEnTete(liste2Ptr, &info3);
	insererEnTete(liste2Ptr, &info4);

	afficher(liste2Ptr, FORWARD);

	printf("Insertion de 3 elements en queue de liste2 : ");
	insererEnQueue(liste2Ptr, &info4);
	insererEnQueue(liste2Ptr, &info3);
	insererEnQueue(liste2Ptr, &info2);

	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests estVide() et longueur()");
	printf("\n------------------------------------------------------------\n");

	printf("\nLa liste1 est-elle vide ? : %s, elle a une longueur de %" PRIu64
	               "\n",estVide(liste1Ptr) ? "oui" : "non", longueur(liste1Ptr));
	printf("La liste2 est-elle vide ? : %s, elle a une longueur de %" PRIu64
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

	printf("\nListe2 etat acutel : ");
	afficher(liste2Ptr, FORWARD);

	supprimerEnTete(liste2Ptr, &info5);

	printf("\nListe2 apres supression en tete : ");
	afficher(liste2Ptr, FORWARD);
	printf("Info supprimee: %d\n", info5);

	supprimerEnQueue(liste2Ptr, &info5);

	printf("\nListe2 apres supression en queue : ");
	afficher(liste2Ptr, FORWARD);
	printf("Info supprimee: %d\n", info5);

	supprimerSelonCritere(liste2Ptr, conditionSupression);
	printf("\nListe2 apres supression des positions paires ayant \n"
			 "des infos entre ]1,3]: ");
	afficher(liste2Ptr, FORWARD);

	insererEnTete(liste2Ptr, &info1);
	insererEnTete(liste2Ptr, &info2);
	insererEnTete(liste2Ptr, &info3);

	printf("\nEtat de liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nSupression par critre de position: ");
	supprimerSelonCritere(liste2Ptr, conditionSupressionPosition);
	afficher(liste2Ptr, FORWARD);

	printf("Supression par critre de info: ");
	supprimerSelonCritere(liste2Ptr, conditionSupressionInfo);
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Tests vider() et sontEgales()");
	printf("\n------------------------------------------------------------\n");

	printf("\nTentative de vider liste2 avec une position trop grande: ");
	vider(liste2Ptr, 12);
	afficher(liste2Ptr, FORWARD);

	vider(liste2Ptr, 0);
	printf("\nListe2 apres avoir ete videe depuis la position 0 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nEtat actuel de Liste1 : ");
	afficher(liste1Ptr, FORWARD);
	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
			 sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

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
	afficher(liste1Ptr, FORWARD);

	printf("Etat actuel de liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
			 sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

	printf("\nVidage de liste2 depuis la position 5: ");
	vider(liste2Ptr, 5);
	afficher(liste2Ptr, FORWARD);

	printf("\nLes listes 1 et 2 sont-elles egales ? %s\n",
			 sontEgales(liste2Ptr, liste1Ptr) ? "oui" : "non");

	printf("\nVidage complet de liste1 et liste2 : ");
	vider(liste2Ptr, 0);
	vider(liste1Ptr, 0);

	printf("\nEtat actuel de liste1 : ");
	afficher(liste1Ptr, FORWARD);

	printf("Etat actuel de liste2 : ");
	afficher(liste2Ptr, FORWARD);

	printf("\n------------------------------------------------------------\n");
	printf("Differents tests sur listes vides");
	printf("\n------------------------------------------------------------\n");

	printf("\nSupression en tete d'une liste vide: ");
	supprimerEnTete(liste2Ptr, &info5) == LISTE_VIDE ? printf("reussi") :
	printf("erreur");

	printf("\nSupression en queue d'une liste vide: ");
	supprimerEnQueue(liste2Ptr, &info5) == LISTE_VIDE ? printf("reussi") :
	printf("erreur");

	printf("\n\nSupression selon critere d'une liste vide: \n");
	printf("avant : ");
	afficher(liste2Ptr, FORWARD);
	supprimerSelonCritere(liste2Ptr, conditionSupressionPosition);
	printf("apres : ");
	afficher(liste2Ptr, FORWARD);

	//-------------------------------------------------------------------------------
	//libérer mémoire

	free(liste1Ptr);
	free(liste2Ptr);

	printf("\n------------------------------------------------------------\n");
	printf("Fin de programme");
	printf("\n------------------------------------------------------------\n");

	return 0;
}

bool conditionSupression(size_t position, const Info *info) {
	if (position % 2 == 0 && *info > 1 && *info <= 3) return true;
	return false;
}

bool conditionSupressionPosition(size_t position, const Info *info) {
	if (position % 2 == 0) return true;
	return false;
}

bool conditionSupressionInfo(size_t position, const Info *info) {
	if (*info > 3) return true;
	return false;
}

