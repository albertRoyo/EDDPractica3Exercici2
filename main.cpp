#include <iostream>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <fstream>
#include "BSTMovieFinder.h"

using namespace std;

void mostrar_menu(vector<string> vec_options){
    for (int i = 0; i < vec_options.size(); ++i){
        cout <<"  "<<i+1<<". "<<vec_options[i]<<endl;
    }
}

int main(){    //Usada la estructura switch de la primera pràctica
    vector<string> vec_options(6);
    vec_options = {"Inserir fitxer", "Mostrar arbre", "Llegir fitxer de cerca", 
                   "Mostrar profunditat", "Sortir"};
    int instruccio;
    
    BSTMovieFinder* movieTree;
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "  Que vols fer?" << endl;
        mostrar_menu(vec_options);
        cin >> instruccio;
        //try{
            switch (instruccio){
                case 1:{    //Inserir fitxer
                    movieTree = new BTSMovieFinder();
                    cout << "Estructura creada!" << endl;
                    cout << "Quin fitxer vols afegir(P/G)?" << endl;
                    char c;
                    cin >> c;
                    string nomFitxer;
                    if (c == 'P'){
                        nomFitxer = "movie_rating_small.txt";
                    }
                    else if (c == 'G'){
                        nomFitxer = "movie_rating.txt";
                    }
                    clock_t start = clock();
                    movieTree->appendMovies(nomFitxer);
                    cout << "Arbre inicialitzat amb les dades de '" << nomFitxer << "'." << endl;
                    cout << "El temps de creació del arbre ha sigut de " << (double)(clock()-start)/CLOCKS_PER_SEC << " segons." << endl;
                }
                
                case 2:{    //Mostrar arbre
                    vector<Movie> movies = movieTree->arbre->printInorder();
                    char c = 'y';
                    int j = 0;
                    while (c == 'y'){
                        int k;
                        for (int i = j; i < j+40 and i < movies.size(); ++i){//Potser trobes una forma millor
                           cout << movies[i].toString() << endl;
                           k=i;
                        }
                        j=k;
                        cout << "Vols imprimir les següents 40 pel·lícules(y/n)?" << endl;
                        cin >> c;
                    }
                }
                    
                case 3:{    //LLegir fitxer de cerca
                    ifstream fitxer("cercaPelicules.txt");
                    int trobades = 0;
                    int total = 0;
                    clock_t start = clock();
                    while (!fitxer.eof()){
                        ++total;
                        string sID;
                        fitxer >> sID;
                        TreeNode<Movie>* newNode = movieTree->arbre->search(stoi(sID));
                        if (newNode != nullptr){
                            ++trobades;
                        }
                        delete [] newNode;
                    }
                    fitxer.close();
                    cout << "S'han trobat " << trobades << " películes d'un total de " << total << "." << endl;
                    cout << "Ha trigat un temps de " << (double)(clock()-start)/CLOCKS_PER_SEC << " segons." << endl;
                }
                
                case 4:{    //Mostrar profunditat
                    int height = movieTree->arbre->getHeight();
                    cout << "La profunditat del arbre és " << height << "." << endl;
                }
                case 5:{    //Sortir
                    break;
                }
                
                default:{
                    cout << "Instrucció incorrecte" << endl;
                }
            }
    }
    while (instruccio != 5);    //Sortir
}
