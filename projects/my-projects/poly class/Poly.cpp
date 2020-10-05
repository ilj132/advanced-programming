#include <iostream>
#include <cmath>
#include "Poly.h"



///CONSTRUTORES E DESTRUTORES

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
    if(grau == 0) x[0]=0.0;
    else{
        x[grau]=1;
        for (int i = grau-1; i >= 0; i--)
            x[i] = 0.0;
        }
}



///SOBRECARGA DE OPERADORES

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


Poly Poly::operator-() const
{
    Poly prov(grau);
    for (unsigned i = 0; i <=grau; i++)
        prov.x[i] = -x[i];
    return prov;
}


ostream &operator<<(ostream &X, const Poly &P){
    if(P.getGrau()==0)
    {
        X<<P.x[0];
        return X;
    }
    else if(P.x[P.grau] !=1 && P.x[P.grau]!=0){
        X<<P.x[P.grau];
        if(P.grau > 1) X<<"*x^"<<P.grau;
        else X<<"*x";
    }
    else{
        if(P.grau > 1) X<<"x^"<<P.grau;
        else X<<"x";
    }

    for(int i=P.grau-1; i>=0 ; i--)
    {
        if(P.x[i]!=0){
            if(P.x[i]>0) X<<"+"<<P.x[i];
            else if(P.x[i]<0) X<<P.x[i];

            if(i==1) X<<"*x";
            else if(i!=0){
                X<<"*x^"<<i;
            }
        }
    }
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


Poly Poly::operator+(const Poly &P) const
{
    if (grau != P.grau)
    {
       int graumaior = (grau>P.grau? grau : P.grau);
       Poly prov(graumaior);
       prov.x[prov.getGrau()]=0.0;
       for(int i = graumaior ; i>= 0 ; i--) prov.x[i] = getCoef(i)+P.getCoef(i);
       return prov;
    }
    else
    {
        Poly prov(grau);
        prov.x[prov.getGrau()]=0.0;
        for (unsigned i = 0; i <= grau; i++)
            prov.x[i] = x[i] + P.x[i];
        return prov;
    }
}


Poly Poly::operator-(const Poly &P) const
{
   if (grau != P.grau)
    {
       int graumaior = (grau>P.grau? grau : P.grau);
       Poly prov(graumaior);
       for(int i = graumaior ; i>= 0 ; i--) prov.x[i] = getCoef(i)-P.getCoef(i);
       return prov;
    }
    else
    {
        Poly prov(grau);
        for (unsigned i = 0; i <= grau; i++)
            prov.x[i] = x[i] - P.x[i];
        return prov;
    }
}


Poly Poly::operator*(const Poly &P) const {

    Poly prov(grau+P.grau);
    prov.x[prov.getGrau()] = 0.0;
    for(int i=0; i<=getGrau(); i++){
        for(int j=0; j<=P.getGrau(); j++){
            prov.x[i+j] += (getCoef(i)*P.getCoef(j));
        }
    }
    return prov;
}



///METODOS

double Poly::getValor(double Num) const{
    double valor=0.0;
    for(int i = getGrau(); i>=0 ; i--) valor += getCoef(i)*pow(Num,i);
    return valor;
}


double Poly::getCoef(unsigned Num) const {
    static double prov = 0.0;
    if(Num <= grau){
        return x[Num];
    }
    else{
        return prov;
    }
}

