#ifndef TABLES_H
#define TABLES_H

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;


using GroupPtr = std::shared_ptr<Group>;
using Multimedias = std::map<string, MultimediaPtr>;
using Groups = std::map<string, GroupPtr>;

class Tables{

    private:

      Multimedias multimediasTable;
      Groups      groupsTable;

    public:

      Tables();
      ~Tables();

      Tables(std::map<std::string,MultimediaPtr> multimediasTable ,std::map<std::string,GroupPtr> groupsTable);

      MultimediaPtr createPhoto(string name , string pathname, int l, int L);
      MultimediaPtr createVideo(string name , string pathname, int d);
      MultimediaPtr createFilm(string name , string pathname , int d , int chapters_num , int * chapters0);

      GroupPtr createGroup(const string name);

      void search(const string& name, ostream &s) const;
      void play(const string &name) const;
      bool processRequest(TCPConnection& cnx, const string& request, string& response);

};

#endif // TABLES_H




