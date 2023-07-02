#include <iostream>
#include <vector>
#include "distribuicaoPD.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    int numCasosTeste = 0;
    int numTipoLigas = 0, demanda = 0;
    DistribuicaoPD centroDistribuicao = DistribuicaoPD();

    cin >> numCasosTeste;

    for (int i = 0; i < numCasosTeste; i++) {
        cin >> numTipoLigas >> demanda;
        int ligas[numTipoLigas];

        for(int j = 0; j < numTipoLigas; j++){
            cin >> ligas[j];
        }

        cout << centroDistribuicao.buscarNumeroMinimoLigas(ligas, numTipoLigas, demanda) << endl;
    }
    
    return 0;
}
