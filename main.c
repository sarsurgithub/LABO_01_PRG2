#include "listes_dynamiques.h"
#include <stdio.h>

bool elPair(size_t position, const Info* info);


int main() {
    Liste *liste1Ptr = initialiser();
    Liste *liste2Ptr = initialiser();

    const Info info1 = 1;
    const Info info2 = 2;
    const Info info3 = 3;
    const Info info4 = 4;

    insererEnTete(liste2Ptr, &info1);
    insererEnTete(liste2Ptr, &info2);
    insererEnTete(liste2Ptr, &info3);

    insererEnQueue(liste2Ptr, &info4);

//    afficher(liste2Ptr, FORWARD);
//    afficher(liste2Ptr, BACKWARD);

//    insererEnQueue(liste1Ptr, &info1);
//    insererEnQueue(liste1Ptr, &info2);
//
//    Info infoDeleted1;
//    Info infoDeleted2;
//    Info infoDeleted3;
//
//    longueur(liste2Ptr);
//
//    afficher(liste1Ptr, FORWARD);
//    supprimerEnTete(liste1Ptr, &infoDeleted1);
//    supprimerEnTete(liste1Ptr, &infoDeleted3);
//    afficher(liste1Ptr, FORWARD);
//
//    //supprimerEnQueue(liste2Ptr, &infoDeleted2);
//
//
    //supprimerSelonCritere(liste2Ptr, &elPair);
    afficher(liste2Ptr, FORWARD);
//    size_t uselessVarAgain = 2;
//    vider(liste2Ptr,uselessVarAgain);
//    afficher(liste2Ptr, FORWARD);


    Liste* liste3Ptr = initialiser();
    Liste* liste4Ptr = initialiser();
    Info i1 = 1;
    Info i2 = 2;
    Info i3 = 3;
    Info i4 = 4;


    insererEnQueue(liste3Ptr, &i1);
    insererEnQueue(liste3Ptr, &i2);
    insererEnQueue(liste3Ptr, &i3);
    insererEnQueue(liste3Ptr, &i4);

    insererEnQueue(liste4Ptr, &i1);
    insererEnQueue(liste4Ptr, &i2);
    insererEnQueue(liste4Ptr, &i4);

    printf("egale : %d", sontEgales(liste3Ptr, liste4Ptr));

    return 0;
}

bool elPair(size_t position, const Info* info) {
    if (*info == 3) return true;
    return false;
}
