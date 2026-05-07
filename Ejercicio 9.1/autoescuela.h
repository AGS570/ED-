#ifndef AUTOESCUELA
#define AUTOESCUELA

#include<bits/stdc++.h>

class autoescuela{
public:
autoescuela(){};

//O(1)
void alta(std::string A,std::string P){
    if(this->alumnos.count(A) == 0){
        this->alumnos[A] = 0;
    }else{
        baja(A);
    }
    this->alumnoProfesor[A] = P;
    this->clase[P].insert(A);
}

//O(1)
bool es_alumno(std::string A, std::string P){
    if(this->alumnoProfesor.count(A) == 0 || this->alumnoProfesor[A] != P )return false;
    else return true;
}

//O(1)
int puntuacion(std::string A){

    if(alumnos.count(A) != 0) return this->alumnos[A];
    throw std::domain_error("El alumno" + A + "no esta matriculado.");
}

//O(1)
void actualizar(std::string A, int n){
    if(this->alumnos.count(A) != 0)
        this->alumnos[A] += n;
    else 
     throw std::domain_error("El alumno" + A + "no esta matriculado.");
}

//O(n)
std::vector<std::string> examen(std::string P, int N){
    std::vector<std::string> v;
    if(this->clase.count(P) != 0){
        for(auto it = this->clase[P].begin(); it != this->clase[P].end(); ++it){
            if(this->alumnos[*it] >= N) v.push_back(*it);
        }
    } 
    return v;
}

//O(1)
void aprobar(std::string A){
    if(this->alumnos.count(A) != 0){
        baja(A);
        this->alumnos.erase(A);
        this->alumnoProfesor.erase(A);
        return;
    }else throw std::domain_error("El alumno" + A + "no esta matriculado.");
}

private:

std::map<std::string,int> alumnos;
std::map<std::string,std::set<std::string>> clase;
std::map<std::string,std::string> alumnoProfesor;

//O(1)
void baja(std::string A){
    std::string p = alumnoProfesor[A];
    if(this->clase.count(p)!= 0)
        this->clase[p].erase(A);
}
};


#endif