#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096


int32_t mem[MEM_SIZE];

// PROTÓTIPOS

void dump_mem(uint32_t address, uint32_t wSize);

// LOADS

int32_t lw(uint32_t address, int32_t kte);

int32_t lh(uint32_t address, int32_t kte);

int32_t lhu(uint32_t address, int32_t kte);

int32_t lb(uint32_t address, int32_t kte);

int32_t lbu(uint32_t address, int32_t kte);

//STORES

void sw(uint32_t address, int32_t kte, int32_t data);

void sh(uint32_t address, int32_t kte, int16_t data);

void sb(uint32_t address, int32_t kte, int8_t data);

//TESTES

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

void userTest() {

    volatile int i;

    for (i = 0; i < 40; i += 4) {
        sw(i, 0, 0);
    }

    dump_mem(0, 10);

    sb(0, 4, 0x10);
    sb(0, 5, 0x0B);
    sb(0, 6, 0xAC);
    sb(0, 7, 0x09);

    sh(0, 10, 0xFF00);
    sh(0, 14, 0x00FF);
    sb(10, 7, 0xFF);
    sb(10, 10, 0xFF);

    sw(36, 0, 0x1234CAFE);

    sh(20, 6, 0xC1C0);
    sb(20, 9, 0xAC);
    sb(32, 0, 0xEC);

    printf("\n\n");
    dump_mem(0, 10);
    printf("\n\n");

    lw(36, 0);
    lh(36, 0);
    lh(10, 0);
    lhu(10, 0);
    lb(28, 4);
    lb(20, 0);
    lbu(10, 10);

}


void main() {

    test();
    userTest();
}

void dump_mem(uint32_t address, uint32_t nWords) {

    if ((address) % 4 != 0) {
        printf("Address invalid! Must be multiple of four.\n");

    }
    else {
        uint8_t i;

        for (i = 0; i < nWords; i++){
            printf("mem[%d] = %08X\n", i, mem[address]);
            address += 1;

        }
    }
}



int32_t lw(uint32_t address, int32_t kte) {
    printf("load_word(%d, %d)\n", address, kte);
    if ((address + kte) % 4 != 0) {
        printf("\tAddress invalid! Must be multiple of four.\n");

    } else {

        int32_t data;
        int32_t *wordPointer = (int32_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 32b em 32b

        data = wordPointer[(address + kte)/4];
        printf("\tHEXADECIMAL -> 0x%08X\n\tDECIMAL -> %d\n\n", data, data);

    }
}



int32_t lh(uint32_t address, int32_t kte) {
    printf("load_half(%d, %d)\n", address, kte);
    if ((address + kte) % 2 != 0) {
        printf("\tAddress invalid! Must be multiple of two.\n");

    } else {

        int16_t data;
        int16_t *halfPointer = (int16_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b

        data = halfPointer[(address + kte)/2];
        printf("\tHEXADECIMAL -> 0x%04X\n\tDECIMAL -> %d\n\n", (uint16_t) data, data);

    }
}

int32_t lhu(uint32_t address, int32_t kte) {
    printf("load_uhalf(%d, %d)\n", address, kte);
    if ((address + kte) % 2 != 0) {
        printf("\tAddress invalid! Must be multiple of two.\n");

    } else {

        uint16_t data;
        uint16_t *halfPointer = (uint16_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b

        data = halfPointer[(address + kte)/2];
        printf("\tHEXADECIMAL -> 0x%04X\n\tDECIMAL -> %d\n\n", data, data);

    }
}


int32_t lb(uint32_t address, int32_t kte) {
    printf("load_byte(%d, %d)\n", address, kte);
    int8_t data;
    int8_t *bytePointer = (int8_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

    data = bytePointer[address + kte];
    printf("\tHEXADECIMAL -> 0x%02X\n\tDECIMAL -> %d\n\n", (uint8_t) data, data);


}

int32_t lbu(uint32_t address, int32_t kte) {
    printf("load_ubyte(%d, %d)\n", address, kte);
    uint8_t data;
    uint8_t *bytePointer = (uint8_t *) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b

    data = bytePointer[address + kte];
    printf("\tHEXADECIMAL -> 0x%02X\n\tDECIMAL -> %d\n\n", data, data);


}


void sw(uint32_t address, int32_t kte, int32_t data) {

    if ( (address + kte)%4 != 0 ) {
        printf("Address invalid! Must be multiple of four.\n");

    }
    else {
        int32_t *wordPointer = (int32_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 32b em 32b
        wordPointer[(address + kte)/4] = data;
    }

}

void sh(uint32_t address, int32_t kte, int16_t data) {

    if ( (address + kte)%2 != 0 ) {
        printf("Address invalid! Must be multiple of two.\n");

    }
    else {
    int16_t *halfPointer = (int16_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 16b em 16b
    halfPointer[(address + kte)/2] = data;
    }
}

void sb(uint32_t address, int32_t kte, int8_t data) {

    int8_t *bytePointer = (int8_t*) mem; //Inicializo um ponteiro que aponta para o início da MEM e anda de 8b em 8b
    bytePointer[address + kte] = data;

}