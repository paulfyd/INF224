//
// main.cpp
// Created on 21/10/2018
//



#include <iostream>
#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"
#include "cppsocket.h"
#include <memory>
#include <string>
#include <sstream>
#include "tables.h"

using namespace std;
using namespace cppu;


int main(int argc, const char* argv[])
{
    //Video * m = new Video("1", "./2.mp4",26);
    //m->showVariables(cout);
    //m->display();
    //return 0;

    int chapters[]={1,4,7};
    Multimedia * multimedia[2];
    multimedia[0] = new Film("2", "./2.mp4",26,3,chapters) ;
    multimedia[1] = new Photo("1","./1.jpg",7,3) ;

    //for (unsigned int k = 0; k < 2; ++k){

        //multimedia[k]->display();

    //}
    Film * film = new Film("2", "./2.mp4",26,3,chapters);
    Photo * photo = new Photo("1","./1.jpg",7,3);
    //film->showVariables(cout);

    Group * g = new Group("group");

    g->push_back(MultimediaPtr(film));
    g->push_back(MultimediaPtr(photo));
    //g->showVariables(cout);
    //g->pop_back();


  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());

  // cree l'objet qui gère les données
  Tables * tables = new Tables() ;

  tables->createFilm("2", "./2.mp4",26,3,chapters);
  tables->createPhoto("1","./1.jpg",4,5);

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*tables, &Tables::processRequest);

  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }

  return 0;
}





