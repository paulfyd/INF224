#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

class Video : public Multimedia{

    private:
        int duree;

    public :
        Video(string name, string pathname, int duree=0);
        int getDuree() const;
        void setDuree(int newDuree);
        virtual ~Video() override {std::cout << "Photo " << getName() << " is dying." << std::endl;}
        void showVariables(std::ostream & s) const override;
        void  display() const override;

};

#endif // VIDEO_
