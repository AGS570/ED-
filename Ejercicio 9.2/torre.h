#ifndef TORRE_H
#define TORRE_H

#include<bits/stdc++.h>
enum class Direccion { Norte, Sur, Este, Oeste };

class torre{
public:

void anyadir_torre(const std::string &nombre, int x, int y){
    if(torres.count(nombre)== 0){
        std::pair<int,int> pos = {x,y};
        if(ocupadas.count(pos) == 0){
            torres[nombre] = pos;
            ocupadas[pos] = nombre;
        }else{
            throw std::domain_error("Posicion ocupada");
        }
    }
    else{
        throw std::domain_error("Torre ya existente");
    }
}

void eliminar_torre(const std::string &nombre){
    if(torres.count(nombre)== 0)
        throw std::domain_error("Torre no existente");
    else{
        ocupadas.erase(torres[nombre]);
        torres.erase(nombre);
    }
}

std::pair<int,int> posicion(const std::string &nombre) const{
    if(torres.count(nombre)!= 0){
        std::pair<int,int> pos = torres.at(nombre);
        return pos;
    }else   
        throw std::domain_error("Torre no existente");
}

std::pair<bool,std::string>torre_en_posicion(int x, int y){
    std::pair<int,int> pos = {x,y};
    std::pair<bool,std::string> p;
    if(ocupadas.count(pos)== 1){
        p.first= true;
        p.second = ocupadas[pos];
    }else{
        p.first = false;
    }
    return p;
}

std::string torre_mas_cercana(const std::string &nombre, const Direccion &dir) const{
    if(torres.count(nombre)!= 0){
        std::pair<int,int> pos = torres.at(nombre);
        int x=0,y=0;
        switch(dir){
        case Direccion::Norte:
            auto it = ocupadas.lower_bound(pos);
            while(it != ocupadas.end() && it->first.second != y){
                ++it;
            }
        break;
        case Direccion::Sur:
            auto it = ocupadas.upper_bound(pos);
            while(it != ocupadas.end() && it->first.second != y){
                ++it;
            }
        break;
        case Direccion::Este:
            auto it = ocupadas.upper_bound(pos);
            while(it != ocupadas.end() && it->first.first != x){
                ++it;
            }
        break;
        case Direccion::Oeste:
            auto it = ocupadas.upper_bound(pos);
            while(it != ocupadas.end() && it->first.first != x){
                ++it;
            }
        break;
       } 
       
    }else   
        throw std::domain_error("Torre no existente");
}

private:
std::map<std::string,std::pair<int,int> >torres;
std::map<std::pair<int,int>,std::string> ocupadas;
};
#endif

