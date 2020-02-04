#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <memory>
#include "multimedia.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;


class Group: public list<MultimediaPtr>{

    private:

        string name = " ";

    public:

        Group(const string& name0):name(name0){}

        ~Group(){}

        void setName(const string& name0) {
          name = name0;
        }

        string getGroupName() const {return name;}

        void showVariables(std::ostream & s);


};

#endif // GROUP_H



