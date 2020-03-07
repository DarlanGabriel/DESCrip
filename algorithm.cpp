#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstddef>
#include <type_traits>
using namespace std;
string palcon;

void convHex(string palavra, string &palcon, char * b){
    for(int i = 0; i < palavra.length(); i++){
        sprintf(b, "%02x", palavra[i]);
        palcon.push_back(b[0]);
        palcon.push_back(b[1]);
    }
}

int main(){
    char b[2];
    int i = 0;
    string palavra, palcon;
    getline(cin, palavra);
    convHex(palavra, palcon, b);
    while(palcon[i] != 0 && !(palcon[i] < 33)){
        cout << palcon[i];
        i++;
    }
    cout << "\n";
    return 0;
}