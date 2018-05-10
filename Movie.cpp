#include "Movie.h"

//Constructors
Movie(){
}
Movie(int id, string titol, double rating){
    this->id = id;
    this->titol = titol;
    this->rating = rating;
}

//Consultors
int getId(){
    return this->id;
}
string getTitol(){
    return this->titol;
}
double getRating(){
    return this->rating;
}
    
//Modificadors
void setId(int id){
    this->id = id;
}
void setTitol(string titol){
    this->titol = titol;
}
void setRating(double rating){
    this->rating = rating;
}
    
string toString(){
    return this->getTitol()+toString(this->getRating());
}
    
