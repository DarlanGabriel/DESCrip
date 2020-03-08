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
    while(x != 28){
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

void dezesseis(string ck, string *kn){
    int x = 1;
    int i = 1;
    string aux;
    while(i < 17){
        aux = ck.substr(x, 28 - x) + ck.substr(0, x);
        kn[i - 1] = aux;
        aux.clear();
        if(i == 1 || i == 8 || i == 15){
            x = x + 1;
        }else{
            x = x + 2;
        }
        i++;
    }
}

void gerandoK(string cndn, string &pc2){
    pc2.push_back(cndn[13]);
    pc2.push_back(cndn[16]);
    pc2.push_back(cndn[10]);
    pc2.push_back(cndn[23]);
    pc2.push_back(cndn[0]);
    pc2.push_back(cndn[4]);

    pc2.push_back(cndn[2]);
    pc2.push_back(cndn[27]);
    pc2.push_back(cndn[14]);
    pc2.push_back(cndn[5]);
    pc2.push_back(cndn[20]);
    pc2.push_back(cndn[9]);

    pc2.push_back(cndn[22]);
    pc2.push_back(cndn[18]);
    pc2.push_back(cndn[11]);
    pc2.push_back(cndn[3]);
    pc2.push_back(cndn[25]);
    pc2.push_back(cndn[7]);

    pc2.push_back(cndn[15]);
    pc2.push_back(cndn[6]);
    pc2.push_back(cndn[26]);
    pc2.push_back(cndn[19]);
    pc2.push_back(cndn[12]);
    pc2.push_back(cndn[1]);

    pc2.push_back(cndn[40]);
    pc2.push_back(cndn[51]);
    pc2.push_back(cndn[30]);
    pc2.push_back(cndn[36]);
    pc2.push_back(cndn[46]);
    pc2.push_back(cndn[54]);

    pc2.push_back(cndn[29]);
    pc2.push_back(cndn[39]);
    pc2.push_back(cndn[50]);
    pc2.push_back(cndn[44]);
    pc2.push_back(cndn[32]);
    pc2.push_back(cndn[47]);

    pc2.push_back(cndn[43]);
    pc2.push_back(cndn[48]);
    pc2.push_back(cndn[38]);
    pc2.push_back(cndn[55]);
    pc2.push_back(cndn[33]);
    pc2.push_back(cndn[52]);

    pc2.push_back(cndn[45]);
    pc2.push_back(cndn[41]);
    pc2.push_back(cndn[49]);
    pc2.push_back(cndn[35]);
    pc2.push_back(cndn[28]);
    pc2.push_back(cndn[31]);
}

void permutP(string palbin, string &ip){
    int y = 58;
    int x = y;
    while(x != 0){
        ip.push_back(palbin[x - 1]);
        x = x - 8;
        if(x < 0){
            y = y + 2;
            x = y;
        }
    }
    y = 57;
    x = y;
    while(x != -1){
        ip.push_back(palbin[x - 1]);
        x = x - 8;
        if(x < 0 && x != -1){
            y = y + 2;
            x = y;
        }
    }
}

void ajuste(string &r0){
    string nova;
    nova.push_back(r0[31]);
    for(int i = 1; i < 6; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 4; i < 10; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 8; i < 14; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 12; i < 18; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 16; i < 22; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 20; i < 26; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 24; i < 30; i++){
        nova.push_back(r0[i - 1]);
    }
    for(int i = 28; i < 33; i++){
        nova.push_back(r0[i - 1]);
    }
    nova.push_back(r0[0]);
    r0.clear();
    r0 = nova;

    cout << r0 << "\n";
}

void xorei(string &r0, string pc2){
    string aux;
    for(int i = 0; i < 48; i++){
        if(r0[i] == pc2[i]){
            aux.push_back('0');
        }else{
            aux.push_back('1');
        }
    }
    r0.clear();
    r0 = aux;
    cout << pc2 << "\n";
    cout << r0 << "\n";
}

void cripto(string &r0, string &l0, string *pc2, string aux){
    aux = l0;
    l0.clear();
    l0 = r0;
    ajuste(r0);
    xorei(r0, pc2[0]);
}

int main(){
    char b[2], c[65];
    int i = 0;
    string chave, palcon, paldes; //parte hexadecimal
    string palbin;
    string pc1, c0, d0;
    string cn[16], dn[16], kn[16], cndn[16], pc2[16];
    string palavra, ip, l0, r0, aux;

    getline(cin, chave);
    convHex(chave, palcon, b);

    cout << palcon << "\n";

    desHex(c, paldes, b);
    cout << paldes << "\n";

    convBin(palcon, palbin);
    cout << palbin << "\n";

    permut(palbin, pc1);
    cout << pc1 << "\n";

    c0 = pc1.substr(0, 28);
    d0 = pc1.substr(28, 28);

    cout << c0 << "\n";
    cout << d0 << "\n";

    dezesseis(c0, cn);
    dezesseis(d0, dn);

    for(int i = 0; i < 16; i++){
        cout << cn[i] << "\n";
    }

    for(int i = 0; i < 16; i++){
        cout << dn[i] << "\n";
    }

    for(int i = 0; i < 16; i++){
        cndn[i] = cn[i] + dn[i];
        cout << cndn[i] << "\n";
    }

    for(int i = 0; i < 16; i++){
        gerandoK(cndn[i], pc2[i]);
        cout << pc2[i] << "\n";
    }

    palbin.clear();
    palcon.clear();

    getline(cin, palavra);

    convHex(palavra, palcon, b);

    cout << palcon << "\n";

    convBin(palcon, palbin);
    cout << palbin << "\n";

    permutP(palbin, ip);
    cout << ip << "\n";

    l0 = ip.substr(0, 32);
    r0 = ip.substr(32, 32);

    cout << l0 << "\n";
    cout << r0 << "\n";

    cripto(r0, l0, pc2, aux);
    
    return 0;
}