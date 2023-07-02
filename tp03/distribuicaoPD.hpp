#ifndef DISTRIBUICAO_PD_HPP
#define DISTRIBUICAO_PD_HPP

#include <vector>

class DistribuicaoPD {
public:
    DistribuicaoPD();

    int buscarNumeroMinimoLigas(int ligas[], int numTipoLigas, int demanda);

    virtual ~DistribuicaoPD();
};

#endif //DISTRIBUICAO_PD_HPP