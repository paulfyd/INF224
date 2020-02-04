#include "photo.h"
#include <string>

Photo::Photo(string name , string pathname, int l, int L) : Multimedia(name, pathname), latitude(l) , longitude(L){}


void Photo::setLatitude(int newLatitude){
         latitude = newLatitude;
}



void Photo::setLongitude(int newLongitude){
         longitude = newLongitude;
}


int Photo::getLatitude() const{
    return latitude;
}

int Photo::getLongitude() const{
    return longitude;
}



/**
 * \fn Photo::showVariables(std::ostream & s) const
 * \brief Affiche le nom de l'image, son pathname, et ses dimensions
 *
 * \param s ostream d'affichage
 *
 */

void Photo::showVariables(std::ostream & s) const  {
    s << name << " " << pathname <<" " << latitude << " " << longitude << endl;
}


/**
 * \fn void Photo::display() const
 * \brief Affiche la photo
 *
 */

void Photo::display() const {
    system(("imagej "+pathname+" &").c_str());
}

