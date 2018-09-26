#include <bits/stdc++.h>
#include "quadtree.h"
using namespace std;


vector<string> splitString(string str){
    vector<string>vect;
    string word;
    stringstream stream(str);
    while( getline(stream, word, ',') )
        vect.push_back(word);
    return vect;
}
int main(){
    int maxLim=300;
    Punto LI(0,0);
    Punto LS((float)maxLim,(float)maxLim);
    Quadtree qt(LI,LS,3); 
    float x,y;
    ofstream ofs;
    ofs.open("anish2.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofs.open("anish.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    /*ifstream file("crime50k.csv");
    string str; 
    while (std::getline(file, str))
    {
        vector<string>temp;
        temp=splitString(str);
        cout<<temp[15]<<endl;
    }*/
    srand (time(NULL));
    
    for(int i=0;i<50000;i++){
        x=rand()%maxLim;
        y=rand()%maxLim;
        qt.insert(Punto(x,y));
    }
 

 

    cout<<"SALI"<<endl;
    qt.print();

    return 0;
}