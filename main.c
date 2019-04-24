#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096


int32_t mem[MEM_SIZE];


void dump_mem(uint32_t address, uint32_t wSize);

int32_t lw(uint32_t address, int32_t kte);

int32_t lh(uint32_t address, int32_t kte);

int32_t lhu(uint32_t address, int32_t kte);

int32_t lb(uint32_t address, int32_t kte);

int32_t lbu(uint32_t address, int32_t kte);

void sw(uint32_t address, int32_t kte, int32_t data);

void sh(uint32_t address, int32_t kte, int16_t data);



void sb(uint32_t address, int32_t kte, int8_t data);


void test() {

    sb(0, 0, 0x04);
    sb(0, 1, 0x03);
    sb(0, 2, 0x02);
    sb(0, 3, 0x01);
    sb(4, 0, 0xFF);
    sb(4, 1, 0xFE);
    sb(4, 2, 0xFD);
    sb(4, 3, 0xFC);
    sh(8, 0, 0xFFF0);
    sh(8, 2, 0x8C);
    sw(12, 0, 0xFF);
    sw(16, 0, 0xFFFF);
    sw(20, 0, 0xFFFFFFFF);
    sw(24, 0, 0x80000000);

    dump_mem(0, 7);

    printf("\n\nLOADS\n\n");

    lb(0,0);
    lb(0,1);
    lb(0,2);
    lb(0,3);
    lb(4,0);
    lb(4,1);
    lb(4,2);
    lb(4,3);
    printf("\n\nLOADS U\n\n");
    lbu(4,0);
    lbu(4,1);
    lbu(4,2);
    lbu(4,3);
    printf("\n\nLOADS HALF\n\n");
    lh(8,0);
    lh(8,2);
    printf("\n\nLOAD WORD\n\n");
    lw(12,0);
    lw(16,0);
    lw(20,0);






}

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
    int8_t *bytePointer = (int8_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

//    sb(0, 1, 0xF3);
//    printf("(Memory[0] 0x%08X)\n", bytePointer[1]);
//    lb(0, 1);
    test();









//    int32_t *wordPointer = (int32_t*) mem;
//    int16_t *halfWordPointer = (int16_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b
//
//
//    mem[0] = 0;
//    mem[1] = 1;
//
//    mem[2] = 2;
//    mem[3] = 3;
//
//    mem[4] = 4;
//    mem[5] = 5;
//
//    mem[6] = 6;
//    mem[7] = 7;
//
//
//    bytePointer[0] = 255;
//
//    halfWordPointer[3] = 65535;
//
//    wordPointer[6] = 64;
//
//    printf("(Memory[0] 0x%08X)\n", (uint32_t) mem[0]);
////    printf("(Memory[0] 0x%08X)\n", (uint8_t) mem[0]); //ele pega o primeiro byte e só exibe ele, o resto ele completa com 0
//    printf("(Memory[1] 0x%08X)\n", (uint32_t) mem[1]);
//    printf("(Memory[3] 0x%08X)\n", (uint32_t) mem[2]);
//    printf("(Memory[6] 0x%08X)\n", (uint32_t) mem[6]);






}

void dump_mem(uint32_t address, uint32_t nWords) {

    if ((address) % 4 != 0) {
        printf("Address invalid! Must be multiple of four.\n");

    }
    else {
        int8_t *bytePointer = (int8_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
        uint8_t i;

        for (i = 0; i < nWords; i++){
            printf("mem[%d] = %08X\n", i, mem[address]);
            address += 1;

        }
    }

}


int32_t lw(uint32_t address, int32_t kte) {
    if ((address + kte) % 4 != 0) {
        printf("Address invalid! Must be multiple of four.\n");

    } else {

        int32_t data;
        int32_t *bytePointer = (int32_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

        data = bytePointer[(address + kte)/4];
        printf("Hexadecimal: 0x%08X\nDecimal: %d\n", data, data);

    }
}



int32_t lh(uint32_t address, int32_t kte) {
    if ((address + kte) % 2 != 0) {
        printf("Address invalid! Must be multiple of two.\n");

    } else {

        int16_t data;
        int16_t *bytePointer = (int16_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

        data = bytePointer[(address + kte)/2];
        printf("Hexadecimal: 0x%4X\nDecimal: %d\n", (uint16_t) data, data);

    }
}

int32_t lhu(uint32_t address, int32_t kte) {
    if ((address + kte) % 2 != 0) {
        printf("Address invalid! Must be multiple of two.\n");

    } else {

        uint16_t data;
        uint16_t *bytePointer = (uint16_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

        data = bytePointer[(address + kte)/2];
        printf("Hexadecimal: 0x%4X\nDecimal: %d\n", data, data);

    }
}


int32_t lb(uint32_t address, int32_t kte) {

    int8_t data;
    int8_t *bytePointer = (int8_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

    data = bytePointer[address + kte];
    printf("Hexadecimal: 0x%2X\nDecimal: %d\n", (uint8_t) data, data);


}

int32_t lbu(uint32_t address, int32_t kte) {

    uint8_t data;
    uint8_t *bytePointer = (uint8_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

    data = bytePointer[address + kte];
    printf("Hexadecimal: 0x%2X\nDecimal: %d\n", data, data);


}


void sw(uint32_t address, int32_t kte, int32_t data) {

    if ( (address + kte)%4 != 0 ) {
        printf("Address invalid! Must be multiple of four.\n");

    }
    else {
        int32_t *bytePointer = (int32_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
        bytePointer[(address + kte)/4] = data;
    }

}

void sh(uint32_t address, int32_t kte, int16_t data) {

    if ( (address + kte)%2 != 0 ) {
        printf("Address invalid! Must be multiple of two.\n");

    }
    else {
    int16_t *bytePointer = (int16_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
    bytePointer[(address + kte)/2] = data;
    }
}

void sb(uint32_t address, int32_t kte, int8_t data) {

    int8_t *bytePointer = (int8_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
    bytePointer[address + kte] = data;


}





/*
 * int16_t *halfWordPointer = (int32_t*) mem; qual o sentido de fazer isso?
 * int16_t *halfWordPointer = (int16_t*) mem;
 * int * v
 * o que significa o primeiro "int16_t" e o segundo "int16_t"?
 *
 */