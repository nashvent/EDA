#include <bits/stdc++.h>
#include <iostream>
#include <fstream>  
using namespace std;

class Punto{
    public:
        float x,y;
        Punto(float nx=0,float ny=0){
            x=nx;
            y=ny;
        }
        bool esIgual(Punto b){
            if(b.x==x && b.y==y){
                return true;
            }
            return false;
        }
        void print(){
            //cout<<" ("<<x<<","<<y<<") ";
            ofstream file; 
            file.open("anish2.txt",std::ios_base::app | std::ios_base::out);
            file<<x<<","<<y<< endl;
            file.close();
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
        Punto LI,LS; //LI : topLeft  LS: bottonRight
        vector<Nodo*>hijos;
        vector<Punto>data;
        bool hoja;
        Nodo(Punto nLI,Punto nLS){ //0,0 100,100, 3;
            hijos.resize(4);
            LI=nLI;
            LS=nLS;
            hoja=true;
        } 
        bool pertenece(Punto pnt){
            return contiene(LI,LS,pnt);
        }
        void dividir(int limEl){
            float xm=(LI.x+LS.x)/2;
            float ym=(LI.y+LS.y)/2;
            hijos[0]=new Nodo(Punto(LI.x,ym),Punto(xm,LS.y));
            hijos[1]=new Nodo(Punto(xm,ym),LS);
            hijos[2]=new Nodo(LI,Punto(xm,ym));
            hijos[3]=new Nodo(Punto(xm,LI.y),Punto(LS.x,ym));
            for(int t=0;t<data.size();t++){
                for(int x=0;x<4;x++){
                    if(hijos[x]->pertenece(data[t])){
                        hijos[x]->data.push_back(data[t]);
                        if(hijos[x]->data.size()>limEl){
                            hijos[x]->dividir(limEl);
                        }
                    }   
                }
            }
            hoja=false;
            data.resize(0);
            return;      
        }

        int posicion(Punto pnt){
            for(int x=0;x<data.size();x++){
                if(data[x].esIgual(pnt)){
                    return x;
                }
            }
            return -1;
        }
        void printLimites(){
            cout<<"LI("<<LI.x<<","<<LI.y<<") ";
            cout<<"LS("<<LS.x<<","<<LS.y<<")";
            cout<<endl;
        }

        void printData(){
            //cout<<"Data: ";
            for(int i=0;i<data.size();i++){
                data[i].print();
            }
            //cout<<endl;
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
            root=new Nodo(LI,LS);
        }
        void insert(Punto);
        int search(Punto,Nodo*&);
        bool remove(Punto);
        void print();
        void printR(Nodo *);
        void generateTxt();
        void printRT(Nodo *);
};


void Quadtree::insert(Punto pnt){
    Nodo* obj;
    int posicion=search(pnt,obj);
    if(obj==NULL or posicion!=-1 or (pnt.x==-1 and pnt.y==-1)){
        return;
    }
    obj->data.push_back(pnt);
    if(obj->data.size()>maxEl){
        obj->dividir(maxEl);
    }
    return;
}

int Quadtree::search(Punto pnt,Nodo* &temp){
    temp=root;
    bool verif;
    while(!temp->hoja){
        verif=true;
        for(int x=0;x<temp->hijos.size();x++){
            if(temp->hijos[x]->pertenece(pnt)){
                temp=temp->hijos[x];
                verif=false;
                break;
            }
        }
        if(verif){
            
            return temp->posicion(pnt);
        }
        
    }
    return temp->posicion(pnt);
}

bool Quadtree::remove(Punto pnt){
    Nodo*obj;
    int posicion=search(pnt,obj);
    if(obj==NULL or posicion!=-1){
        return false;
    }
    obj->data.erase(obj->data.begin() + posicion);
    return true;
}

void Quadtree::printR(Nodo *p){
    if(p!=NULL){   
        //p->printLimites();
        p->printData();
        if(!p->hoja){
            for(int x=0;x<4;x++){
                //cout<<"Hijo "<<x+1<<endl;
                printR(p->hijos[x]);  
            }
        }
        else{
            ofstream file; 
        file.open("anish.txt",std::ios_base::app | std::ios_base::out);
        file<<p->LI.x<<","<<p->LI.y
        <<","<<p->LS.x<<","<<p->LS.y<< endl;
        
        file.close();
        }
    
    }
}


void Quadtree::print(){
    Nodo* temp=root;
    printR(temp);             
}
/*
void Quadtree::generateTxt(){
    ofstream outfile ("puntos1.txt");
    Nodo *p=root;

    while(p!=NULL){
        outfile <<p->LI.x<<","<<p->LI.y
        <<","<<LS.x<<","<<LS.y<< std::endl;

    }

    outfile.close();
}
*/
