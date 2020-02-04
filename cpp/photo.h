#ifndef PHOTO_H
#define PHOTO_H


#include "multimedia.h"

class Photo : public Multimedia{

    private:
        int latitude;
        int longitude;

    public :
        Photo();
        Photo(string name, string pathname, int latitude=0,int longitude=0);
        int getLatitude() const;
        int getLongitude() const;
        void setLatitude(int newLatitude);
        void setLongitude(int newLatitude);
        ~Photo() override {std::cout << "Photo " << getName() << " is dying." << std::endl;}
        void showVariables(std::ostream & s) const override;
        void display() const override;

};

#endif // PHOTO_H
