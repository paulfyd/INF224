#include "video.h"

Video::Video(string name , string pathname, int d):Multimedia(name, pathname), duree(d) {}

void Video::setDuree(int newDuree){
         duree = newDuree;
    }

int Video::getDuree() const{
    return duree;
}




/**
 * \fn Video::showVariables(std::ostream & s) const
 * \brief Affiche le nom de la video, son pathname, et sa duree
 *
 * \param s ostream d'affichage
 *
 */

void Video::showVariables(std::ostream & s) const  {
    s << name << " " << pathname <<" " << duree << endl;
}


/**
 * \fn void Video::display() const
 * \brief Joue la video
 *
 */

void Video::display() const {
    system(("mpv "+pathname+" &").c_str());
}


