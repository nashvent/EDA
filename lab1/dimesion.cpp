#include "bits/stdc++.h"
using namespace std;

typedef vector<float> vectf;
typedef vector<vectf> m_vectf;

m_vectf generarPuntos(int dimension,int cant){
  m_vectf m_puntos;
  for(int x=0;x<cant;x++){
    vectf punto;
    for(int y=0;y<dimension;y++){
      float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
      punto.push_back(r);
    }
    m_puntos.push_back(punto);
  }
  return m_puntos;
}

void printVector(m_vectf puntos){
  for(int x=0;x<puntos.size();x++){ 
    for(int y=0;y<puntos[x].size();y++){
        cout<<puntos[x][y]<<" ";
    }
    cout<<endl;  
  }
}

float calcDistancia(vectf punto1,vectf punto2){
    float distancia=0;
    if(punto1.size()==punto2.size()){
      for(int x=0;x<punto1.size();x++){
        distancia=distancia+pow((punto1[x]-punto2[x]),2);  
      }
    }
    return pow(distancia,0.5);
}

void calculo(m_vectf puntos){
  float promedio=0;
  float min=10000;
  float max=0;
  int cont=0;
  for(int x=0;x<puntos.size();x++){ 
    for(int y=0;y<puntos.size();y++){
      if(x!=y){
        float distTemp=calcDistancia(puntos[x],puntos[y]);
        promedio=promedio+distTemp;
        //cout<<"PROM TEMP"<<distTemp<<endl;
        cont++;
        if(distTemp>max){
          max=distTemp;
        }
        if(distTemp<min){
          min=distTemp;
        }
      }    
    }
      
  }

  cout<<"DIstancia minima "<<min<<endl;
  cout<<"DIstancia maxima "<<max<<endl;
  cout<<"DIstancia Promedio "<<promedio/cont<<endl;
}






int main(){
  vector<int>dimensiones={2,3,10,100,200,500,1000,2000,3000,4000,5000};
  //printVector(puntos);
  for(int x=0;x<dimensiones.size();x++){
    int dimen=dimensiones[x];
    cout<<"Dimension: "<<dimen<<endl;
    m_vectf puntos=generarPuntos(dimen,100);  
    calculo(puntos);
  }

  


  return 0;
}
	
