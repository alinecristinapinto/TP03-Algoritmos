#include "distribuicaoPD.hpp"
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

DistribuicaoPD::DistribuicaoPD(){}

int DistribuicaoPD::buscarNumeroMinimoLigas(int ligas[], int numTipoLigas, int demanda){
    this->tabela = new int[demanda + 1]; 

    for(int i = 0; i < (demanda+1); i++){
        tabela[i] = INF;
    }

    tabela[0] = 0;

    for(int i = 1; i <= demanda; i++){
        for (int j = 0; j < numTipoLigas; j++){
            if(ligas[j] <= i){
                int sub_res = tabela[i - ligas[j]];
                if (sub_res != INF && sub_res + 1 < tabela[i])
                    tabela[i] = sub_res + 1;
            }
        }
    }

    if (tabela[demanda] == INF)
        return -1;
 
    return tabela[demanda];
}

DistribuicaoPD::~DistribuicaoPD(){
    delete this->tabela;
}
