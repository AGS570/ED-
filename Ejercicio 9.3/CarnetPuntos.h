#ifndef CARNET_PUNTOS_H
#define CARNET_PUNTOS_H

#include <bits/stdc++.h>

class CarnetPuntos{

public:

//coste O(1)
void nuevo(std::string dni){
    if(carnet.count(dni) != 0){
        throw std::domain_error("Conductor duplicado");
    }
    carnet[dni] = 15;
    points[15].insert(dni);
}

//coste O(1)
void quitar(std::string dni, int puntos){
    if(carnet.count(dni) == 0){
        throw std::domain_error("Conductor inexistente");
    }
    if(puntos != 0){
        int &p = carnet[dni];
        points[p].erase(dni);
        p -= puntos;
        if(p < 0) p = 0;
        points[p].insert(dni);
    }
}

//coste O(1)
int consultar(std::string dni){
    if(carnet.count(dni) == 0){
       throw std::domain_error("Conductor inexistente");
    }

    return carnet[dni];
}

//coste O(1)
int cuantos_con_puntos(int puntos){
    if(puntos < 0 || puntos > 15){
       throw std::domain_error("Puntos no validos");
    }

    return points[puntos].size();
}

private:

std::unordered_map<std::string, int> carnet;
std::unordered_map<int,std::unordered_set<std::string>> points;
};

#endif