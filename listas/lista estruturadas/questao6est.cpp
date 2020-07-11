/*Faça um programa que, dado um valor em reais (sem centavos), mostre a menor 
combinação existente de notas (R$ 100, 50, 20, 10, 5 e 2) para esse valor. */

#include <iostream>

using namespace std;

int contanotas(int &v, int q)
{
  unsigned n;
  while (v > 1)
  {
    n = v / q;
    v %= q;
  }
  return n;
}

int main()
{
  unsigned value;

  cout << "Digite o valor: " << endl;
  cin >> value;
  if (value <= 0)
  {
    cerr << "Valor incorreto" << endl;
    return 0;
  }

  unsigned not2 = 0, not5 = 0, not10 = 0, not20 = 0, not50 = 0, not100 = 0;

  not100 = contanotas(value, 100);
  not50 = contanotas(value, 50);
  not20 = contanotas(value, 20);
  not10 = contanotas(value, 10);
  not5 = contanotas(value, 5);
  not2 = contanotas(value, 2);

  cout << value << " " << not100 << endl;
  return 0;
}