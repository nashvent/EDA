#include <bits/stdc++.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std;

int getdir (string dir, vector<string> &files){
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

string readfile(string fileName){
    string line;
    string texto;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            texto=texto+line;
        }
        myfile.close();
    }
    return texto;
}

vector<string> readfilevector(string filename){
    fstream file;
    string word, t, q;
    vector<string>palabras=vector<string>();
    file.open(filename.c_str()); 
    while (file >> word){
        //cout << word << endl;
        palabras.push_back(word);
    }
    return palabras;
}

void removeSubstrs(string& s, string& p) { 
  string::size_type n = p.length();
  for (string::size_type i = s.find(p);
      i != string::npos;
      i = s.find(p))
      s.erase(i, n);
}

template <class T>
void removeDuplicateEl(vector<T>&vec) { 
    sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}

template<class T>
void printVector(T vect){
    for(int x=0;x<vect.size();x++){
        cout<<vect[x]<<endl;
    }
}

void stringToVector(string palabras,vector<string>& vectorPalabras){    
    stringstream ss(palabras);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    //copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(std::cout, "\n"));
    vectorPalabras=vstrings;
}

void replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return ;
    str.replace(start_pos, from.length(), to);    
}


void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

void removeSpecialCharsFromString(string &allWords){
    //vector<string> stopwords=readfilevector("./stopwords/lista.txt");
    vector<string> special=readfilevector("./stopwords/specialChars.txt");    
    for(int x=0;x<special.size();x++){
        //removeSubstrs(allWords,special[x]);
        replaceAll(allWords,special[x]," ");
    }
}

void removeStopWordsFromVector(vector<string>&vect){
    vector<string> stopwords=readfilevector("./stopwords/lista.txt");
     for(int x=0;x<stopwords.size();x++){
        for(int y=0;y<vect.size();y++){
            //string stopWord=" "+stopwords[x]+" ";
            //replaceAll(vect[y],stopWord," ");
            if(vect[y]==stopwords[x] || vect[y].size()<3){
                vect.erase(vect.begin() + y);
                y--;
            }
        }
    }
}

int countWord(string s, string key){
    int count = 0;
    size_t pos=0;
    while ((pos = s.find(key, pos)) != string::npos) {
        ++count;
        ++pos;
    }
    return count;
}


