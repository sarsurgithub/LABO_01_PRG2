#include "listes_dynamiques.h"
#include "stdlib.h"
#include "stdint.h"

Liste* initialiser() {
   Liste* nouvelleListe = (Liste*) malloc(sizeof(Liste));
   *nouvelleListe = (Liste) {.tete = NULL, .queue = NULL};
   return nouvelleListe;
}

bool estVide(const Liste* liste) {
  return liste->queue == NULL && liste->tete == NULL;
}


size_t longueur(const Liste* liste) {
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
      .info = info,
      .suivant = liste->tete,
      .precedent = longueur(liste) ?  : NULL
   };
   liste->tete = el;
   return OK;
}

Status insererEnQueue(Liste* liste, const Info* info) {

}

Status supprimerEnTete(Liste* liste, Info* info) {

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
