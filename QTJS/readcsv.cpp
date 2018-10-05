#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
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
    //crime50k.csv
    ifstream file("crime50k.csv");
    string str;
    int cont=0; 
    while (std::getline(file, str))
    {
        vector<string>temp;
        string strtemp=str;
        temp=splitString(strtemp);
        
        cout<<cont++<<" "<<temp[18]<<" "<<temp[19]<<endl;
        
    }
    return 0;
}