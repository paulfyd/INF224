#include "group.h"


void Group::showVariables(std::ostream & s){
  s << "Name of the group :";
  s << getGroupName() <<  endl  ;
  s << "Elements of the group :";
  for (iterator i = begin(); i != end(); ++i){
      (*i)->showVariables(s);
    }
  s << endl;
}
