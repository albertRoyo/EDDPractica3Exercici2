#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie{

    public:
        //Constructors
        Movie(int id, string titol, float rating);
        ~Movie();
        
        //Consultors
        int getId();//potser no serà necessaria
        string getTitol();
        float getRating();
        
        //Modificadors
        void setId(int id);
        void setTitol(string titol);
        void setRating(float rating);
        
        string toString();
        
    private:
        int id;
        string titol;
        float rating;
        
};
    
#endif /* MOVIE_H */
