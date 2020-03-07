#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

void conv(char c, char *b){
    sprintf(b, "%02x", c);
}

int main(){
    char palavra[4], palcon[7];
    char b[2];
    scanf("%s", palavra);
    for(int i = 0; i < sizeof(palavra) - 1; i++){
        conv(palavra[i], b);
        palcon[i * 2] = b[0];
        palcon[i * 2 + 1] = b[1];
    }
    printf("%s \n", palcon);
    return 0;
}