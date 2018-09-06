#include <bits/stdc++.h>
using namespace std;

class Punto{
    public:
        int x,y;
        Punto(int nx=0,int ny=0){
            x=nx;
            y=ny;
        }
        bool esIgual(Punto b){
            if(b.x==x && b.y==y){
                return true;
            }
            return false;
        }
};

bool contiene(Punto LI,Punto LS,Punto pnt){
    if(LI.x<=pnt.x and LS.x>=pnt.x and LI.y<=pnt.y and LS.y>=pnt.y){
        return true;
    }
    return false;
}

class Nodo{
    public:
        Punto tl,br; //Tl : topLeft  br: bottonRight
        vector<Nodo*>hijos;
        vector<Punto>data;
        bool hoja;
        Nodo(Punto ntl,Punto nbr){ //0,0 100,100, 3;
            hijos.resize(4);
            tl=ntl;
            br=nbr;
            hoja=true;
        } 
};

class Quadtree{
    public:
        Nodo *root;
        int maxEl;
        Punto LI,LS;
        Quadtree(Punto nLI,Punto nLS,int nmaxEl){
            maxEl=nmaxEl;
            LI=nLI;
            LS=nLS;
        }
        void insert(Punto);
        Nodo*search(Punto);
        bool pertenece(Punto);
};


void QuadTree::insert(Punto pnt){
    Nodo *obj=search(pnt);
    if(obj==NULL){
        return;
    }
    obj->data.push_back(pnt);
    if(obj->data.size()>maxEl){
        obj->dividir();
    }
    return;
}

Nodo* QuadTree::search(Punto pnt){
    Nodo*temp=root;
    
    
    
    
    return temp;

}

