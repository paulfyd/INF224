#include "tables.h"


Tables::Tables(){
    multimediasTable={};
    groupsTable={};

}

Tables::Tables(std::map<std::string,MultimediaPtr> multimediasTable0,std::map<std::string,GroupPtr> groupTables0){
    multimediasTable=multimediasTable0;
    groupsTable=groupTables0;
}



/**
 * \fn MultimediaPtr Tables::createPhoto(string name , string pathname , int l , int L)
 * \brief Insérer une photo dans la table
 *
 */

MultimediaPtr Tables::createPhoto(string name , string pathname , int l , int L){
    multimediasTable[name] = MultimediaPtr(new Photo(name , pathname , l , L));
    return multimediasTable[name];
}


/**
 * \fn MultimediaPtr Tables::createVideo(string name , string pathname , int l , int L)
 * \brief Insérer une video dans la table
 *
 */

MultimediaPtr Tables::createVideo(string name , string pathname , int d){
    multimediasTable[name] = MultimediaPtr(new Video(name , pathname , d));
    return multimediasTable[name];
}



/**
 * \fn MultimediaPtr Tables::createFilm(string name , string pathname , int l , int L)
 * \brief Insérer un film dans la table
 *
 */


MultimediaPtr Tables::createFilm(string name , string pathname , int d , int chapters_num , int * chapters0){
    multimediasTable[name] = MultimediaPtr(new Film(name , pathname , d , chapters_num , chapters0));
    return multimediasTable[name];
}




/**
 * \fn void Tables::search(const string &name , ostream &s)const
 * \brief Chercher un element dans la liste
 *
 * \param name Nom de l'élément que l'on veut chercher
 * \param s ostream de l'affichage
 * \return Instance nouvelle allouée d'un objet de type Str_t ou NULL.
 */

void Tables::search(const string &name , ostream &s)const{
  auto found = multimediasTable.find(name);
   if (found != multimediasTable.end()){
     s<<"The element "<<name<< " has been found: ";
     found->second->showVariables(s);
   }else
     {s << "No multimedia found ";
     auto foundGroup = groupsTable.find(name);
     if (foundGroup != groupsTable.end()){
       s<<"The group "<< name<< " has been found: ";
       foundGroup->second->showVariables(s);}

     else
      {s << "No group found ";}
    }
}


/**
 * \fn void Tables::play(const string &name) const
 * \brief Jouer un l'élément dans la liste
 *
 *\param name Nom de l'élément que l'on veut jouer
 *
 */


void Tables::play(const string &name) const{
  auto found = multimediasTable.find(name);
   if (found != multimediasTable.end()){
      cout << "We play" << '\n';
      found->second->display();
   }else
      cout << "No multimedia found" << '\n';
}



/**
 * \fn bool Tables::processRequest(TCPConnection& cnx, const string& request, string& response)
 * \brief Effectuer une requete via un serveur, connexion TCP
 *
 *\param request la requete
 *\param response reponse a la requete
 *
 */


bool Tables::processRequest(TCPConnection& cnx, const string& request, string& response)
{
    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream stream(request);
    stringstream response_stream ;
    string type;
    stream>>type;
    if ((type != "Search") && (type != "Play")) {
             response = "Error: Request not defined !";
             return true;
    }

    string fileName="";

    if(type=="Search"){
        stream>>fileName;
        search(fileName,cout);
    }
    else if (type=="Play"){
        stream>>fileName;
        play(fileName);
    }

    response = "OK : " + request;

    cerr << "response: " << response <<endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }

