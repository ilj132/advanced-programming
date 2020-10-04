#include <iostream>
#include <cmath>
#include "Poly.h"

///Construtores e destrutores
void Poly::clean()
{
    if (x != NULL)
        delete[] x;
    x = NULL;
    grau = 0;
}

void Poly::create(unsigned Num)
{
    grau = Num;
    x = (grau >= 0 ? new double[grau+1] : NULL);
}

void Poly::copy(const Poly &P)
{
    create(P.grau);
    for (unsigned i = 0; i <= grau; i++)
        x[i] = P.x[i];
}

Poly::Poly(unsigned Num)
{
    create(Num);

    for (unsigned i = 0; i <= grau; i++)
        x[i] = 0.0;
}



///Sobrecarga de Operadores

void Poly::operator=(const Poly &P)
{
    //testa se num tá fazendo P=P
    if (this != &P)
    {
        //testa se é do mesmo tamanho ou não
        if (this->grau == P.grau)
        {
            for (unsigned i = 0; i <= grau; i++)
                x[i] = P.x[i];
        }
        else
        {
            clean();
            copy(P);
        }
    }
}

/// Negativo de um vetor (- unario)
Poly Poly::operator-() const
{
    Poly prov(grau);
    for (unsigned i = 0; i <=grau; i++)
        prov.x[i] = -x[i];
    return prov;
}

/*/// Metodo de consulta que retorna o valor de um elemento do vetor
/// Este metodo eh chamado quando o [] aparece no lado direito de uma operacao
/// Por exemplo, y = x[2] ou cout << x[2]
double Poly::operator[](unsigned i) const
{
    if (i >= N)
    {
        cerr << "Indice invalido\n";
        return 0.0;
    }
    return x[i];
}

/// Metodo de consulta que retorna uma referencia para um elemento do vetor
/// Este metodo eh chamado quando o [] aparece no lado esquerdo de uma operacao
/// Por exemplo, x[2] = 7.0 ou cin >> x[2]
double &Poly::operator[](unsigned i)
{
    static double prov = 0.0;
    if (i >= N)
    {
        cerr << "Indice invalido\n";
        return prov;
    }
    return x[i];
}*/


///Entrada e saída de dados
ostream &operator<<(ostream &X, const Poly &P){
    int i = P.grau;
    do{
        if(i==P.grau)  X<<P.x[i]<<"*x^"<<i;
        else if(i==1){
            if(P.x[i]>0){ X<<"+"<<P.x[i]<<"*x";}
            else{X<<P.x[i]<<"*x";}
        }
        else if(i==0){
            if(P.x[i]>0){ X<<"+"<<P.x[i];}
            else{X<<P.x[i];}
        }
        else{
            if(P.x[i]>0){ X<<"+"<<P.x[i]<<"*x^"<<i;}
            else { X<<P.x[i]<<"*x^"<<i;}
        }
            i--;
    }while(i>=0);
    return X;
}

istream &operator>>(istream &X, Poly &P)
{
    for(int i= P.grau; i>=0; i--){
        cout<<"x^"<<i<<": ";
        X >> P.x[i];
    }
    return X;
}

/*double getValor (double valor){
    prov = 0.0;
    for(unsigned i=0 ; i<P.grau ; i++)
        prov+= x[i] * valor;
    return prov;

}*/

/// Soma de vetores
Poly Poly::operator+(const Poly &P) const
{
    if (grau != P.grau)
    {
        unsigned grauprov = (grau > P.grau? grau : P.grau);
        unsigned menorgrau= (grau > P.grau? P.grau : grau);
        Poly prov(grauprov);
        for(int i=0;i<menorgrau;i++) prov.x[i] = x[i] + P.x[i];
        for(int i=menorgrau;i<=grauprov;i++) prov.x[i] = x[i] + P.x[i];

        return prov;
    }
    else{
        Poly prov(grau);
        for (unsigned i = 0; i <= grau; i++)
            prov.x[i] = x[i] + P.x[i];
        return prov;
    }
}

/*/// Subtracao de vetores (- binario)
Poly Poly::operator-(const Poly &P) const
{
   if (grau != P.grau)
    {
        unsigned grauprov = (grau > P.grau? grau : P.grau);
        Poly prov(grauprov);
        for(int i=0;i<=prov.grau;i++) prov.x[i] = x[i] - P.x[i];
        return prov;
    }
    else{
        Poly prov(grau);
        for (unsigned i = 0; i <= grau; i++)
            prov.x[i] = x[i] - P.x[i];
        return prov;
    }
}*/

/*/// Norma euclidiana de um vetor
double Poly::norma() const
{
    double soma(0.0);
    for (unsigned i = 0; i < N; i++)
        soma += x[i] * x[i];
    return sqrt(soma);
}

/// Produto escalar
double Poly::escalar(const Poly &V) const
{
    if (N != V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return 0.0;
    }
    double prov(0.0);
    for (unsigned i = 0; i < N; i++)
        prov += x[i] * V.x[i];
    return prov;
}

/// Produto vetorial (apenas para vetores de dimensao 3)
Poly Poly::vetorial(const Poly &V) const
{
    if (N != 3 || N != V.N)
    {
        cerr << "Dimensoes incompativeis\n";
        return Poly();
    }
    Poly prov(3);
    prov.x[0] = x[1] * V.x[2] - x[2] * V.x[1];
    prov.x[1] = x[2] * V.x[0] - x[0] * V.x[2];
    prov.x[2] = x[0] * V.x[1] - x[1] * V.x[0];
    return prov;
}*/
