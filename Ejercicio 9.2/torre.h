#ifndef TORRE_H
#define TORRE_H

#include<bits/stdc++.h>
enum class Direccion { Norte, Sur, Este, Oeste };

class torre{
public:

//coste O(log n)
void anyadir_torre(const std::string &nombre, int x, int y){
    if(torres.count(nombre)== 0){
        std::pair<int,int> pos = {x,y};
        if(ocupadas.count(pos) == 0){
            por_columna[x][y] = nombre;  
            torres[nombre] = pos;
            ocupadas[pos] = nombre;
            por_columna[x][y] = nombre;  // AÑADIR
            por_fila[y][x] = nombre;     // AÑADIR
            
        }else{
            throw std::domain_error("Posicion ocupada");
        }
    }
    else{
        throw std::domain_error("Torre ya existente");
    }
}

//coste O(log n)
void eliminar_torre(const std::string &nombre){
    if(torres.count(nombre)== 0)
        throw std::domain_error("Torre no existente");
    else{
        auto pos = torres[nombre];
        por_columna[pos.first].erase(pos.second);   // AÑADIR
        por_fila[pos.second].erase(pos.first);
        ocupadas.erase(torres[nombre]);
        torres.erase(nombre);
    }
}

//coste O(log n)
std::pair<int,int> posicion(const std::string &nombre) const{
    if(torres.count(nombre)!= 0){
        std::pair<int,int> pos = torres.at(nombre);
        return pos;
    }else   
        throw std::domain_error("Torre no existente");
}

//coste O(log n)
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

//coste O(log n)
std::string torre_mas_cercana(const std::string &nombre, const Direccion &dir) const {
        auto it_t = torres.find(nombre);
        if (it_t == torres.end()) throw std::domain_error("Torre no existente");

        int x = it_t->second.first;
        int y = it_t->second.second;

        if (dir == Direccion::Norte) {
            auto const& col = por_columna.at(x);
            auto it = col.upper_bound(y);
            if (it == col.end()) throw std::domain_error("No hay torres en esa direccion");
            return it->second;
        } 
        else if (dir == Direccion::Sur) {
            auto const& col = por_columna.at(x);
            auto it = col.lower_bound(y);
            if (it == col.begin()) throw std::domain_error("No hay torres en esa direccion");
            return (--it)->second;
        } 
        else if (dir == Direccion::Este) {
            auto const& fila = por_fila.at(y);
            auto it = fila.upper_bound(x);
            if (it == fila.end()) throw std::domain_error("No hay torres en esa direccion");
            return it->second;
        } 
        else { 
            auto const& fila = por_fila.at(y);
            auto it = fila.lower_bound(x);
            if (it == fila.begin()) throw std::domain_error("No hay torres en esa direccion");
            return (--it)->second;
        }
    }


private:
std::map<std::string,std::pair<int,int> >torres;
std::map<std::pair<int,int>,std::string> ocupadas;

std::map<int, std::map<int,std::string>> por_columna;
std::map<int, std::map<int,std::string>> por_fila;

std::map<std::string, std::pair<int,int>> por_nombre;
std::map<std::pair<int,int>, std::string> por_posicion;
};
#endif

