#include "BSTMovieFinder.h"
#include <iostream>//usat per fer prova de impressió
#include <fstream>
#include <string>
using namespace std;

BSTMovieFinder::BSTMovieFinder(){
    this -> arbre = new BinarySearchTree<Movie>();
}

BSTMovieFinder::~BSTMovieFinder(){}

void BSTMovieFinder::appendMovies(string filename){
    ifstream fitxer(filename);
    while (!fitxer.eof()){
        string linea;
        getline(fitxer, linea);
        //Busquem fins a quina posició de linea està la id
        int pos1;
        bool trobat = false;
        for (int i=0; !trobat; ++i){
            if (linea[i] == ':'){//no fa falta mirar el doble ':' ja que id no pot contenir ':'
                pos1=i-1;
                trobat = true;
            }
        }
        int id = stoi(linea.substr(0, pos1));
        
        //Fem el matix amb  el títol
        int pos2;
        trobat = false;
        for (int i=pos1+2; !trobat; ++i){
            if (linea[i] == ':' and linea[i+1] == ':'){//aqui si que ho mirem ja que el titol pot contenir ':'
                pos2=i-1;
                trobat = true;
            }
        }
        string titol = linea.substr(pos1+2, pos2);
        
        //El rating serà la resta de la línea
        float rating = stof(linea.substr(pos2+2, linea.size()));
        this->insertMovie(id,titol, rating);
    }
    fitxer.close();
}
void BSTMovieFinder::insertMovie(int movieID, string title, float rating){
    Movie m(movieID, title, rating);
    this->arbre->insert(m, movieID);
    cout<<"Insert: "<<movieID<<' '<<title<<' '<<rating<<endl;//prova d'impressió
}

string BSTMovieFinder::showMovie(int movieID){
    Movie m = this->findMovie(movieID);
    return m.toString();
}

Movie BSTMovieFinder::findMovie(int movieID){
    TreeNode<Movie>* newNode = this->arbre->search(movieID);
    if (newNode != nullptr){
        Movie m = newNode->getValue();
        delete [] newNode;
        return m;
    }
}
float BSTMovieFinder::findRatingMovie(int movieID){
    Movie m = this->findMovie(movieID);
    return m.getRating();
}

