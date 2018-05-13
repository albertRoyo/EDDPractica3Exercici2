
#ifndef BSTMOVIEFINDER_H
#define BSTMOVIEFINDER_H

#include "BinarySearchTree.h"
#include "Movie.h"
#include <string>
using namespace std;


class BSTMovieFinder {
    
    public:
        
        BSTMovieFinder();
        virtual ~BSTMovieFinder();
        void appendMovies(string filename);
        void insertMovie(int movieID, string title, float rating);
        string showMovie(int movieID);
        Movie findMovie(int movieID);
        float findRatingMovie(int movieID);
        
        BinarySearchTree<Movie>* arbre;//atribut public per poder-hi accedir des del main
        
};
#endif /* #define BSTMOVIEFINDER_H*/