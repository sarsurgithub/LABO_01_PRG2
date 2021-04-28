/*
 -----------------------------------------------------------------------------------
 Nom du fichier : conditions_supression.c
 Auteur(s)      : Jallon Sarah, Louis Hadrien, Martins Tenorio Richard V.
 Date creation  : 28.04.2021

 Description    : definition des fonctions du fichier conditions_suppression.h

 Remarque(s)    : -

 Compilateur    : Mingw-w64 g++ 8.1.0
                  Apple clang version 12.0.0 (clang-1200.0.32.29)
 -----------------------------------------------------------------------------------
*/

#include "listes_dynamiques.h"
#include "conditions_suppression.h"

bool doubleCondition(size_t position, const Info* info) {
    if (position % 2 == 0 && *info > 1 && *info <= 3) return true;
    return false;
}

bool posEstPair(size_t position, const Info* info) {
    if (position % 2 == 0) return true;
    return false;
}

bool infoSupATrois(size_t position, const Info* info) {
    if (*info > 3) return true;
    return false;
}
