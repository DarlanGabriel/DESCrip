#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstddef>
#include <type_traits>
using namespace std;

void convHex(string palavra, string &palcon, char * b){
    for(int i = 0; i < palavra.length(); i++){
        sprintf(b, "%02x", palavra[i]);
        palcon.push_back(b[0]);
        palcon.push_back(b[1]);
    }
}

void desHex(char * c, string &paldes, char * b){
    while(c[0] != 0){
        sscanf(c, "%2x", b);
        paldes.push_back(b[0]);
        c = c + 2;
    }
}

int main(){
    char b[2], c[65];
    int i = 0;
    string palavra, palcon, paldes;
    getline(cin, palavra);
    convHex(palavra, palcon, b);
    while(palcon[i] != 0 && !(palcon[i] < 33)){
        cout << palcon[i];
        c[i] = palcon[i];
        i++;
    }
    cout << "\n";
    desHex(c, paldes, b);
    cout << paldes << "\n";
    return 0;
}