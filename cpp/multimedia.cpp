#include "multimedia.h"



Multimedia::Multimedia(string newName , string newPathname)
{
    name = newName;
    pathname = newPathname;
}



void Multimedia::setName(string newName){
     name = newName;
}

void Multimedia::setPathName(string newPathName){
     name = newPathName;
}


string Multimedia::getName() const{
    return name;
}


string Multimedia::getPathname() const{
    return pathname;
}


/**
 * \fn void Multimedia::showVariables(std::ostream &s) const
 * \brief Montre les variables du multimédia
 *
 * \param s le ostream sur lequel elle les montre
 *
 */

void Multimedia::showVariables(std::ostream &s) const{
    s << name << " " << pathname << endl;
}


