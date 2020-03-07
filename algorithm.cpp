#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int main(){
    char palavra[4], palcon[7];
    scanf("%s", palavra);
    for(int i = 0; i < sizeof(palavra) - 1; i++){
        sprintf(palcon + i * 2, "%02x", palavra[i]);
    }
    printf("%s \n", palcon);
    return 0;
}