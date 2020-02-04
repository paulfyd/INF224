#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
using namespace std;
#include <iostream>


class Multimedia{

    protected:

        string name, pathname;

    public:

        Multimedia(string name , string pathName);
        Multimedia();
        string getName() const;
        string getPathname() const;
        void setName(string Newname0);
        void setPathName(string NewPhatname);
        virtual ~Multimedia(){}
        virtual void showVariables(std::ostream & s) const;
        virtual void display() const=0;
};

#endif // MULTIMEDIA_H
