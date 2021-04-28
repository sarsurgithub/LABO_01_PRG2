/*
 -----------------------------------------------------------------------------------
 Nom du fichier : conditions_supression.c
 Auteur(s)      : Jallon Sarah, Louis Hadrien, Martins Tenorio Richard V.
 Date creation  : 28.04.2021

 Description    : ensemble de fonctions a utiliser avec la fonction
                  supprimerSelonCriteres de listes_dynamiques.h

 Remarque(s)    : -

 Compilateur    : Mingw-w64 g++ 8.1.0
                  Apple clang version 12.0.0 (clang-1200.0.32.29)
 -----------------------------------------------------------------------------------
*/

#ifndef LABO_01_PRG2_CONDITIONS_SUPPRESSION_H
#define LABO_01_PRG2_CONDITIONS_SUPPRESSION_H

/**
 * Renvoie true lorsque la position est paire et que l'info est entre 1 non compris
 * et 3 compris.
 * @param position
 * @param info
 * @return bool
 */
bool doubleCondition(size_t position, const Info* info);

/**
 * Renvoie true lorsque la position est paire
 * @param position
 * @param info
 * @return bool
 */
bool posEstPair(size_t position, const Info* info);

/**
 * Renvoie true lorsque la valeur de info > 3
 * @param position
 * @param info
 * @return bool
 */
bool infoSupATrois(size_t position, const Info* info);

#endif //LABO_01_PRG2_CONDITIONS_SUPPRESSION_H
