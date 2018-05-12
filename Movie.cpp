#include "Movie.h"

#include <string>
//Constructors

Movie::Movie(int id, string titol, float rating){
    this->id = id;
    this->titol = titol;
    this->rating = rating;
}

//Consultors
int Movie::getId(){
    return this->id;
}
string Movie::getTitol(){
    return this->titol;
}
float Movie::getRating(){
    return this->rating;
}
    
//Modificadors
void Movie::setId(int id){
    this->id = id;
}
void Movie::setTitol(string titol){
    this->titol = titol;
}
void Movie::setRating(float rating){
    this->rating = rating;
}
    
string Movie::toString(){
    return this->getTitol()+to_string(this->getRating());
}
    
