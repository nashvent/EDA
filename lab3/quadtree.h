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

class Nodo{
    public:
        Punto pos;
        int data;
        Nodo(Punto npos,int ndata){
            pos=npos;
            data=ndata;
        }
        Nodo(){
            data=0;
        }
};

class QuadTree{
    public:
        Nodo *nodo;
        Punto tl,br; //Tl : topLeft  br: bottonRight
        QuadTree *treeTL,*treeTR;
        QuadTree *treeBL,*treeBR;
        QuadTree(Punto ntl,Punto nbr){
            nodo=NULL;
            treeTL=treeTR=NULL;
            treeBL=treeBR=NULL;
            tl=ntl;
            br=nbr;
        } 
        void insert(Nodo*);
        Nodo*search(Punto);
        bool pertenece(Punto);
};

void QuadTree::insert(Nodo* nnodo){
    if(nnodo==NULL)
        return ;
    if(!pertenece(nnodo->pos))
        return;
    

}