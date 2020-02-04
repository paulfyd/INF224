#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include "video.h"

class Film : public Video{

    private:

        int * chapters_array;
        int chapters_number;

    public:

        Film(string name , string pathname , int d , int chapters_num , int * chapters0):Video(name , pathname , d ) , chapters_number(chapters_num)
            {
               if (chapters_num == 0){chapters_array = nullptr;}
               else {
                        chapters_array = new int [chapters_num];
                        for ( int k = 0; k < chapters_num; k++)
                       {
                          chapters_array[k] = chapters0[k];
                       }
                    }
            }


        /**
         * \fn Film(const Film& from)
         * \brief Permet de copier un film a partir d'un autre
         *
         * \param from Film que l'on veut copier
         *
         */

        Film(const Film& from) : Video(from) {
            chapters_number = from.chapters_number;
            chapters_array = from.chapters_array ? new int[*from.chapters_array]: nullptr;
        }



        /**
         * \fn Film& operator=(const Film& from)
         * \brief Redéfinition de l'opérateur = permettant la copie
         *
         * \param from Film que l'on veut copier
         *
         */

        Film& operator=(const Film& from) {
         Video::operator=(from);
         chapters_number = from.chapters_number;
         if (chapters_array && from.chapters_array) *chapters_array = *from.chapters_array;
         else {
         delete chapters_array;
         chapters_array = from.chapters_array ? new int[*from.chapters_array] : nullptr;
              }
         return *this;
        }



        void setChapters(int * chapters0, int chapters_num){

            delete [] chapters_array;
            chapters_number = chapters_num;
            chapters_array = new  int [chapters_num];
                 for ( int k = 0; k < chapters_num; k++){
                    chapters_array[k] = chapters0[k];
                  }
        }

        ~Film() override {
            delete [] chapters_array;
            std::cout << "Film " << getName() << " is dying." << std::endl;
        }

         int getChapters_number() const {
            return chapters_number;
        }

        const int * getChapters_array() const {
              return chapters_array;
            }

        void showVariables(std::ostream & s) const override;


};



#endif // FILM_H
