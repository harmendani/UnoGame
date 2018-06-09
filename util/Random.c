// A função randomInteger devolve um inteiro
// aleatório entre low e high inclusive,
// ou seja, no intervalo fechado low..high.
// Vamos supor que low <= high e que
// high - low + 1 <= RAND_MAX + 1.
// (O código foi copiado da biblioteca random
// de Eric Roberts.)

#define HIGH 2058
#define LOW 0

int randomInteger()
{

    int k;
    double d;
    d = (double)(rand()) / ((double)RAND_MAX + 1);
    k = d * (HIGH - LOW + 1);
    return (LOW + k);
}
