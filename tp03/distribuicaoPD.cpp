#include "distribuicaoPD.hpp"
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

DistribuicaoPD::DistribuicaoPD(){}

int DistribuicaoPD::buscarNumeroMinimoLigas(int ligas[], int numTipoLigas, int demanda){
    // cria uma tabela para armazenar a quantidade minima de ligas para representar cada valor entre 0 e a demanda 
    int tabela [demanda + 1]; 

    tabela[0] = 0; // nenhuma liga precisa ser utilizada para somar 0

    for(int i = 1; i <= demanda; i++){
        tabela[i] = INF; // seta a posicao i como infinito ja que ainda nao houve a contabilizacao de nenhuma liga

        for (int j = 0; j < numTipoLigas; j++){
            if(ligas[j] <= i){
                // soma 1 (nova liga adicionada a solucao) a cada solucao armazenada em j
                int subSolucao = tabela[i - ligas[j]] + 1;

                // atualiza o numero de ligas necessarias caso a sub solucao seja menor do que a armazenada na tabela
                if (subSolucao != INF && subSolucao < tabela[i]){
                    tabela[i] = subSolucao;
                }
            }
        }
    }
 
    // como sempre teremos uma liga de tamanho 1, ou seja sempre tera solucao, apenas retornamos a soma obtida para a demanda
    return tabela[demanda];
}

DistribuicaoPD::~DistribuicaoPD(){}
