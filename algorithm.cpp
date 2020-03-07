#include <iostream>
#include <string>
#include <cstdlib>
#include <cstddef>
#include <type_traits>
using namespace std;

void convHex(string chave, string &palcon, char * b){
    for(int i = 0; i < chave.length(); i++){
        sprintf(b, "%02x", chave[i]);
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

void permut(string palbin, string &pc1){
    int x = 57;
    int y = x;
    int i = 0;
    while(x != 28){
        i++;
        pc1.push_back(palbin[x-1]);
        x = x - 8;
        if(x < 0){
            y = y + 1;
            x = y;
        }
    }
    x = 63;
    y = x;
    while(x != -3){
        i++;
        pc1.push_back(palbin[x-1]);
        x = x - 8;
        if(x < 0 && x != -3){
            y = y - 1;
            x = y;
        }
    }
    x = 28;
    while(x > 0){
        pc1.push_back(palbin[x-1]);
        x = x - 8;
    }
}

int main(){
    char b[2], c[65];
    int i = 0;
    string chave, palcon, paldes; //parte hexadecimal
    string palbin;
    string pc1, c0, d0;

    getline(cin, chave);
    convHex(chave, palcon, b);

    cout << palcon << "\n";

    desHex(c, paldes, b);
    cout << paldes << "\n";

    convBin(palcon, palbin);
    cout << palbin << "\n";

    permut(palbin, pc1);
    cout << pc1 << "\n";

    //c0 = pc1.substr(0, 32);
    //d0 = pc1.substr(32, 32);

    return 0;
}