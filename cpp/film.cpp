#include "film.h"
#include <iostream>

using namespace std;


/**
 * \fn Film::showVariables(std::ostream & s) const
 * \brief Affiche le nom du film, son pathname, ses chapitres et la duree de chacun des chapitres.
 *
 * \param s ostream d'affichage
 *
 */


void Film::showVariables(std::ostream & s) const {

  const int size = getChapters_number();
  const  int * tmp = getChapters_array();
  this->Video::showVariables(s);

  s << "This file has: " << size << " chapters." << endl;
  for (int k = 0; k < size; k++){s << "Chapter " << k+1 << " is " << tmp[k] << " minutes long." <<endl;}
};


