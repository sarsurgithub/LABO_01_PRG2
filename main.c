#include "listes_dynamiques.h"
#include <stdio.h>

int main() {
   Liste* liste1Ptr = initialiser();
   Liste* liste2Ptr = initialiser();

   const Info info1 = 1;
   const Info info2 = 2;
   const Info info3 = 3;

   insererEnTete(liste2Ptr, &info1);
   insererEnTete(liste2Ptr, &info2);
   insererEnTete(liste2Ptr, &info3);
   return 0;
}
