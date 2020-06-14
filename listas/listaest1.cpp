#include <iostream>

using namespace std;

int main()
{
    unsigned N=0,i=0;
    float valor=0, *arr=NULL;
    cout<<"Digite os valores: \n";
    do{
        cin>>valor;
        
        if(valor>0)
        {
            float *prov = new float[N+1];

            for(i=0;i<N;i++) prov[i]=arr[i];
            prov[N]=valor;
            if(arr!=NULL) delete[] arr;
            arr=prov;
            N++;
        }
    }while(valor>0);

    if(N==0){
        cout<<"Voce n digitou nenhum numero valido!! \n";
        return 0;
    }
    
    float soma=0.0, media=0.0;
    for (i=0;i<N;i++) soma+=arr[i];
    media=soma/N;
    
    cout<<"A media eh: "<<media<<endl;
}