#include "funciones.h"


int main () {
    string dirName="documentos/";
    vector<string> files = vector<string>();
    getdir(dirName,files);
    vector<string>documentos;
    string palabras;
    for (unsigned int i = 0;i < files.size();i++) {
        if(files[i].size()>4){
            string path=dirName+files[i];
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
        cout<<"========================="<<endl;
        cout<<"Documento "<<x+1<<endl;
        cout<<"========================="<<endl;
        for(int y=0;y<vectPal.size();y++){
            int countW=countWord(documentos[x],vectPal[y]);
            
            if(countW){      
                cout<<vectPal[y]<<" "<<countW<<endl;
            }
            vectorCaracteristicas[x][y]=countW;
            
        }
    }
    cout<<"Size Vect Pal: "<<vectPal.size()<<endl;
    cout<<"Document size: "<<documentos.size()<<endl;
    //printVector(vectPal);
    
    return 0;
}