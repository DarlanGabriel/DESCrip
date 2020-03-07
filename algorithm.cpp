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

void convBin(string palcon, string &palbin){
    int i = 0;
    while(palcon[i] != 0){
        if(palcon[i] == '0'){
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('0');
        }else if(palcon[i] == '1'){
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('1');
        }else if(palcon[i] == '2'){
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('0');
        }else if(palcon[i] == '3'){
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('1');
        }else if(palcon[i] == '4'){
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('0');
        }else if(palcon[i] == '5'){
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('1');
        }else if(palcon[i] == '6'){
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('0');
        }else if(palcon[i] == '7'){
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('1');
        }else if(palcon[i] == '8'){
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('0');
        }else if(palcon[i] == '9'){
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('0');
            palbin.push_back('1');
        }else if(palcon[i] == 'a'){
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('0');
        }else if(palcon[i] == 'b'){
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('1');
            palbin.push_back('1');
        }else if(palcon[i] == 'c'){
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('0');
        }else if(palcon[i] == 'd'){
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('0');
            palbin.push_back('1');
        }else if(palcon[i] == 'e'){
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('0');
        }else{
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('1');
            palbin.push_back('1');
        }
        i++;
    }
}

int main(){
    char b[2], c[65];
    int i = 0;
    string palavra, palcon, paldes; //parte hexadecimal
    string palbin;
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

    convBin(palcon, palbin);
    cout << palbin << "\n";
    return 0;
}