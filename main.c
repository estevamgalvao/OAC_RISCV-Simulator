#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096


void dump_mem(uint32_t address, uint32_t wSize, uint32_t *ptrMem);

int32_t lw(uint32_t address, int32_t kte);

int32_t lh(uint32_t address, int32_t kte);

int32_t lhu(uint32_t address, int32_t kte);

int32_t lb(uint32_t address, int32_t kte);

int32_t lbu(uint32_t address, int32_t kte);

void sw(uint32_t address, int32_t kte, int32_t data);

void sh(uint32_t address, int32_t kte, int16_t data);

void sb(uint32_t address, int32_t kte, int8_t data);






int32_t mem[MEM_SIZE];

/* FUNÇÕES A SEREM IMPLEMENTADAS:


int32_t lw(uint32_t address, int32_t kte);
 => lê um inteiro alinhado - endereços múltiplos de 4

 int32_t lh(uint32_t address, int32_t kte);
 => lê meia palavra, 16 bits - retorna inteiro com sinal

 int32_t lhu(uint32_t address, int32_t kte);
 => lê meia palavra, 16 bits formato inteiro sem sinal

 int32_t lb(uint32_t address, int32_t kte);
 => lê um byte - retorna inteiro com sinal

 int32_t lbu(uint32_t address, int32_t kte);
 => lê um byte - 8 bits formato inteiro sem sinal

 void sw(uint32_t address, int32_t kte, int32_t dado);
 => escreve um inteiro alinhado na memória - endereços múltiplos
de 4

 void sh(uint32_t address, int32_t kte, int16_t dado);
 => escreve meia palavra, 16 bits - endereços múltiplos de 2

 void sb(uint32_t address, int32_t kte, int8_t dado);
 => escreve um byte na memória

Atenção: endereço do dado = (address + kte) !
Os endereços são todos de byte. A operação de leitura de byte retorna um inteiro com
o byte lido na posição menos significativa. A escrita de um byte deve colocá-lo na
posição correta dentro da palavra de memória. Para endereçar palavras e meiaspalavras
é necessário ajustar o endereço de acordo.

 */


void main() {

    int32_t *wordPointer = (int32_t*) mem;
    int16_t *halfWordPointer = (int16_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b
    int8_t *bytePointer = (int8_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b


    mem[0] = 0;
    mem[1] = 1;

    mem[2] = 2;
    mem[3] = 3;

    mem[4] = 4;
    mem[5] = 5;

    mem[6] = 6;
    mem[7] = 7;


    bytePointer[1] = 2;

    halfWordPointer[3] = 1;

    wordPointer[6] = 64;

    printf("(Memory[0] 0x%08X)\n", (uint32_t) mem[0]);
    printf("(Memory[1] 0x%08X)\n", (uint32_t) mem[1]);
    printf("(Memory[3] 0x%08X)\n", (uint32_t) mem[2]);
    printf("(Memory[6] 0x%08X)\n", (uint32_t) mem[6]);


//    printf("WordPointer - Memory[0]: %")


//    printf("(Memory[0] 0x%02X)\n", (uint8_t) mem[0]);
//    printf("(Memory[1] 0x%02X)\n", (uint8_t) mem[0]);
//    printf("(Memory[1] 0x%04X)\n", (uint8_t) mem[0]);
//    printf("(Memory[3] 0x%02X)\n", (uint8_t) mem[0]);



}

int32_t lw(uint32_t address, int32_t kte) {

    int32_t *wordPointer = (int32_t*) mem;




}





void sw(uint32_t address, int32_t kte, int32_t data) {

    int32_t *wordPointer = (int32_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 32b em 32b
    wordPointer[address + kte] = data;

}

void sh(uint32_t address, int32_t kte, int16_t data) {

    int16_t *halfWordPointer = (int16_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b
    halfWordPointer[address + kte] = data;

}

void sb(uint32_t address, int32_t kte, int8_t data) {

    int8_t *bytePointer = (int8_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
    bytePointer[address + kte] = data;

}





/*
 * int16_t *halfWordPointer = (int32_t*) mem; qual o sentido de fazer isso?
 * int16_t *halfWordPointer = (int16_t*) mem;
 * o que significa o primeiro "int16_t" e o segundo "int16_t"?
 *
 */