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
    points[15].push_front(dni);
    pos[dni] = points[15].begin();

}

//coste O(1)
void quitar(std::string dni, int puntos){
    if(carnet.count(dni) == 0){
        throw std::domain_error("Conductor inexistente");
    }
    if(puntos != 0){
        int &p = carnet[dni];
        points[p].erase(pos[dni]);
        p -= puntos;
        if(p < 0) p = 0;
        points[p].push_front(dni);
        pos[dni] = points[p].begin();
    }
}
//coste O(1)
void recuperar(std::string dni, int puntos){
    if(carnet.count(dni) == 0){
        throw std::domain_error("Conductor inexistente");
    }
    int &p = carnet[dni];
    if(puntos != 0 && p < 15){
        points[p].erase(pos[dni]);
        p += puntos;
        if(p > 15) p = 15;
        points[p].push_front(dni);
        pos[dni] = points[p].begin();
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

//coste O(1)
std::list<std::string> lista_por_puntos(int puntos){
    if(puntos < 0 || puntos > 15){
       throw std::domain_error("Puntos no validos");
    }

    return points[puntos];
}


private:

std::unordered_map<std::string, int> carnet;
std::unordered_map<int,std::list<std::string>> points;
std::unordered_map<std::string,std::list<std::string>::iterator> pos ;
};

#endif