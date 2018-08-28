#include <bits/stdc++.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
using namespace std;

int getdir (string dir, vector<string> &files)
{
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

string readFile(string fileName){
    string line;
    string texto;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            cout << line << '\n';
            texto=texto+line;
        }
        myfile.close();
    }
    return texto;
}


int main () {
    string dirName="documentos/";
    //string dir = string("./documentos");
    
    vector<string> files = vector<string>();

    getdir(dirName,files);

    for (unsigned int i = 0;i < files.size();i++) {
        //cout << files[i] << endl;
        string path=dirName+files[i];
        cout<<readFile(path)<<endl;
    }

    //


    return 0;
}