#include <iostream>
#include <time.h>

using namespace std;

int main(){
    unsigned num=0, tent=0, N=0;
    
    srand(time(NULL));

    num=rand()%101;
    cout<<num<<endl;
    do{
        cout<<"digite sua tentativa de numero"<<endl;
        cin>> tent;
        if(tent<num) cout<< "numero abaixo do sorteado, tente novamente \n"<<endl;
        if(tent>num) cout<< "numero acima do sorteado, tente novamente \n"<<endl;
        N++;
    }while(tent!=num);

    cout<<"Voce acertou, o numero era: "<<num<<endl;

    return 0;
}