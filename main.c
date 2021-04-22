#include "listes_dynamiques.h"
#include <stdio.h>

int main() {
   Liste* liste1Ptr = initialiser();
   Liste* liste2Ptr = initialiser();
   printf("%d \n",estVide(liste1Ptr));
   printf("%zu", longueur(liste1Ptr));
   insererEnTete(liste2Ptr, (const Info *) 12);
   insererEnTete(liste2Ptr, (const Info *) 13);
   return 0;
}
