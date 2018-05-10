#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:

    //Constructors
    Movie();
    Movie(int id, string titol, double rating);
    
    //Consultors
    int getId();//potser no serà necessaria
    string getTitol();
    double getRating();
    
    //Modificadors
    void setId(int id);
    void setTitol(string titol);
    void setRating(double rating);
    
    string toString();
    
}
    
#endif /* MOVIE_H */
