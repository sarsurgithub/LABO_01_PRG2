#include "listes_dynamiques.h"
#include "stdlib.h"
#include "stdint.h"

Liste* initialiser() {
   Liste* nouvelleListe = (Liste*) calloc(1, sizeof(Liste));
   return nouvelleListe;
}

bool estVide(const Liste* liste) {
  return liste->queue == NULL && liste->tete == NULL;
}


size_t longueur(const Liste* liste) {
	if (liste->queue == NULL && liste->tete == NULL) return 0;
	if (liste->queue == liste->tete) return 1;
   return (size_t) (liste->queue - liste->tete);
}

void afficher(const Liste* liste, Mode mode) {

}

Status insererEnTete(Liste* liste, const Info* info) {
   Element* el = (Element*) malloc(sizeof(Element));
   if (el == NULL) {
      return MEMOIRE_INSUFFISANTE;
   }

   *el = (Element) {
      .info = *info,
      .suivant = liste->tete,
      .precedent = NULL
   };

	if (longueur(liste)) {
		liste->tete->precedent = el;
	} else {
		// Liste vide
		liste->queue = el;
	}

   liste->tete = el;

   return OK;
}

Status insererEnQueue(Liste* liste, const Info* info) {
    Element* el = (Element*) malloc(sizeof(Element));
    if (el == NULL) return MEMOIRE_INSUFFISANTE;

    *el = (Element) {
        .info = *info,
        .precedent = liste->queue,
        .suivant = NULL
    };

    liste->queue->suivant, liste->queue = el;

    return OK;
}

Status supprimerEnTete(Liste* liste, Info* info) {
    liste->tete = liste->tete->suivant;
    free(liste->tete);
    // TODO: check a faire ???????

    return OK;
}

Status supprimerEnQueue(Liste* liste, Info* info) {

}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)) {

}

void vider(Liste* liste, size_t position) {

}

bool sontEgales(const Liste* liste1, const Liste* liste2) {

}
