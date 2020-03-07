#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

void conv(char c, char *b){
    sprintf(b, "%02x", c);
}

string convHex(string palavra, string palcon, char * b){
    for(int i = 0; i < palavra.length(); i++){
        conv(palavra[i], b);
        palcon[i * 2] = b[0];
        palcon[i * 2 + 1] = b[1];
        cout << palcon[i * 2] << palcon[i * 2 + 1];
    }
    return palcon;
}

int main(){
    char b[2];
    string palavra, palcon;
    getline(cin, palavra);
    palcon = convHex(palavra, palcon, b);
    cout << palcon << "\n";
    return 0;
}