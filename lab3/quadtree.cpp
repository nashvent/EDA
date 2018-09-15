#include <bits/stdc++.h>
#include "quadtree.h"
using namespace std;

int main(){
    Punto LI(0,0);
    Punto LS(100,100);
    Quadtree qt(LI,LS,2); 
    float x,y;
    do{
        cin>>x>>y;
        qt.insert(Punto(x,y));
        cout<<"========================="<<endl;
        qt.print();
    }while(x!=-1 and y!=-1);


    return 0;
}