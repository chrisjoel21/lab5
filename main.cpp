#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include "ArgumentManager.h"
#include <map>


using namespace std;

int main(int argc, char *argv[]){
ArgumentManager am (argc, argv);
string input = am.get("input");
string output = am.get("output");

//ifstream ifs("input1.txt");
//ofstream ofs("output1.txt");

ifstream ifs(input);
ofstream ofs(output);
map<string, int> words;
string line;

while ((ifs >> line)){
//cout << line;
char a;
//string line2;
for(int i = 0; i < line.size(); i++){
    
    
if(!isalpha(line[i]) && line[i] !='\'' && line[i] !='-'){
        line.erase(remove(line.begin(), line.end(), line[i]), line.end());
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        //cout << line <<endl;
    }
    if(isalpha(line[i])){
    char a = tolower(line[i]);
    line[i] = a;
    }
    

}
//cout << line2 <<endl;
if(words.empty()){
    words.insert(pair<string, int>(line,1));
}
else{
    int num;
    map<string, int>::iterator itr;
    
    itr = words.find(line);
    if(itr !=words.end()){
        itr->second += 1;
        //cout << "found match and added" <<endl;
    }
    else{
        words.insert(pair<string, int>(line,1));
        //cout << "added a new element" <<endl;
    }
    
}
}
map<string, int>::iterator itr;
for( itr = words.begin(); itr != words.end(); ++itr){
            //cout << "Key => " << itr->first << " Value => " << itr->second << endl;  
            ofs << itr->first << ": " << itr->second << endl;          
      }  


return 0;


}
