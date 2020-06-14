#include <iostream>

using namespace std;

int main(){
    char op;
    float numbers[2];
    unsigned i=0;

    cout<<"digite os dois numeros"<<endl;

    for(i=0;i<2;i++) cin>>numbers[i];

    cout<<"digite a operacao\n";

    cin>>op;

    switch(op){
        case '+':
            cout<< numbers[0]+numbers[1]<<endl;
            break;
        case '-':
            cout<< numbers[0]-numbers[1]<<endl;
            break;
        case '*':
            cout<< numbers[0]*numbers[1]<<endl;
            break;
        case '/':
            cout<< numbers[0]/numbers[1]<<endl;
            break;
        default:
            cout<< "operacao invalida \n";
            break;
    }

    return 0;
}