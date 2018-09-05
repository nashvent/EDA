#include "funciones.h"


int main () {
    string dirName="documentos/";
    vector<string> archivos = vector<string>();
    getdir(dirName,archivos);
    vector<string>documentos;
    string palabras;
    for (unsigned int i = 0;i < archivos.size();i++) {
        if(archivos[i].size()>4){
            string path=dirName+archivos[i];
            string palTemp=readfile(path);
            transform(palTemp.begin(), palTemp.end(), palTemp.begin(), ::tolower);
            documentos.push_back(palTemp);
            palabras=palabras+palTemp;
        }
    }
    removeSpecialCharsFromString(palabras);
    vector<string>vectPal;
    stringToVector(palabras,vectPal);
    removeDuplicateEl(vectPal);
    removeStopWordsFromVector(vectPal);
    vector< vector<int> > vectorCaracteristicas(documentos.size(), vector<int>(vectPal.size()));
    for(int x=0;x<documentos.size();x++){
       /* cout<<"========================="<<endl;
        cout<<"Documento "<<x+1<<endl;
        cout<<"========================="<<endl;*/
        for(int y=0;y<vectPal.size();y++){
            int countW=countWord(documentos[x],vectPal[y]);
            
            if(countW){      
                //cout<<vectPal[y]<<" "<<countW<<endl;
            }
            vectorCaracteristicas[x][y]=countW;
            
        }
    }
    printVector(vectPal);
    cout<<"Size Vect Pal: "<<vectPal.size()<<endl;
    cout<<"Document size: "<<documentos.size()<<endl;
    //printVector(vectPal);
    
    return 0;
}