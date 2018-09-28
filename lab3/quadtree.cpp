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
    int maxLim=100;
    Punto LI(41,-89 );
    Punto LS(43,-87);
    //Punto LI(0,0);
    //Punto LS(100,100);
    
    Quadtree qt(LI,LS,10); 
    float x,y;
    ofstream ofs;
    ofs.open("anish2.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofs.open("anish.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ifstream file("crime50k.csv");
    string str;
    int cont=0;
    float xMin,xMax,yMin,yMax; 
    while (std::getline(file, str))
    {
        vector<string>temp;
        string strtemp=str;
        temp=splitString(strtemp);
        float xtemp = ::atof(temp[18].c_str());
        float ytemp = ::atof(temp[19].c_str());
        qt.insert(Punto(xtemp,ytemp));
        if(cont%1000==0){
            cout<<"Vamos "<<cont<<endl;        
        }
        cont++;
        //cout<<cont++<<" "<<temp[18]<<" "<<temp[19]<<endl;
        
    }
 
    
    /*srand (time(NULL));
    
    for(int i=0;i<1000;i++){
        x=(rand()%maxLim)+0.2;
        y=rand()%maxLim+0.2;
        qt.insert(Punto(x,y));
    }
 */
    
 

    cout<<"SALI"<<endl;
    qt.print();

    return 0;
}