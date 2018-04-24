#include <stdlib.h>
#include <stdio.h>
#include "aes-encrypt.h"

void testSubBytes();
void testShiftRows();
void testMixColumns();

int main() {
    printf("? TESTING aes-encrypt ...\n");
    testSubBytes();
    testShiftRows();
    testMixColumns();
    printf("+ FINISHED aes-encrypt\n");
    return 0;
}

void testSubBytes() {
    printf("? \tTESTING subBytes ...\n");
    unsigned char input[4][4] = {
        {0x8e,0x9f,0xf1,0xc6},
        {0x4d,0xdc,0xe1,0xc7},
        {0xa1,0x58,0xd1,0xc8},
        {0xbc,0x9d,0xc1,0xc9}
    };
    unsigned char output[4][4] = {
        {0x19,0xdb,0xa1,0xb4},
        {0xe3,0x86,0xf8,0xc6},
        {0x32,0x6a,0x3e,0xe8},
        {0x65,0x5e,0x78,0xdd}
    };
    unsigned char** state = (unsigned char**) malloc(4*sizeof(unsigned char*));
    for (int i = 0; i < 4; i++) {
        state[i] = (unsigned char*) malloc(4*sizeof(char));
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i][j];
        }
    }
    subBytes(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED subBytes\n");
}

void testShiftRows() {
    printf("? \tTESTING shiftRows ...\n");
    unsigned char input[4][4] = {
        {0x8e,0x9f,0x01,0xc6},
		{0x4d,0xdc,0x01,0xc6},
		{0xa1,0x58,0x01,0xc6},
		{0xbc,0x9d,0x01,0xc6}
    };
    unsigned char output[4][4] = {
        {0x8e,0x9f,0x01,0xc6},
		{0xdc,0x01,0xc6,0x4d},
		{0x01,0xc6,0xa1,0x58},
		{0xc6,0xbc,0x9d,0x01}
    };
    unsigned char** state = (unsigned char**) malloc(4*sizeof(unsigned char*));
    for (int i = 0; i < 4; i++) {
        state[i] = (unsigned char*) malloc(4*sizeof(char));
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i][j];
        }
    }
    shiftRows(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED shiftRows\n");
}

void testMixColumns() {
    printf("? \tTESTING mixColumns ...\n");
    unsigned char input[4][4] = {
        {0xdb,0xf2,0x01,0xc6},
        {0x13,0x0a,0x01,0xc6},
        {0x53,0x22,0x01,0xc6},
        {0x45,0x5c,0x01,0xc6}
    };
    unsigned char output[4][4] = {
        {0x8e,0x9f,0x01,0xc6},
        {0x4d,0xdc,0x01,0xc6},
        {0xa1,0x58,0x01,0xc6},
        {0xbc,0x9d,0x01,0xc6}
    };
    unsigned char** state = (unsigned char**) malloc(4*sizeof(unsigned char*));
    for (int i = 0; i < 4; i++) {
        state[i] = (unsigned char*) malloc(4*sizeof(char));
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i][j];
        }
    }
    mixColumns(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED mixColumns\n");
}
