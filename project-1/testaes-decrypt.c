#include <stdlib.h>
#include <stdio.h>
#include "aes-decrypt.h"

void testInvSubBytes();
void testInvShiftRows();
void testInvMixColumns();

int main() {
    printf("? TESTING aes-decrypt ...\n");
    testInvSubBytes();
    testInvShiftRows();
    testInvMixColumns();
    printf("+ FINISHED aes-decrypt\n");
    return 0;
}

void testInvSubBytes() {
    printf("? \tTESTING invSubBytes ...\n");
    unsigned char input[4][4] = {
        {0x19,0xdb,0xa1,0xb4},
        {0xe3,0x86,0xf8,0xc6},
        {0x32,0x6a,0x3e,0xe8},
        {0x65,0x5e,0x78,0xdd}
    };
    unsigned char output[4][4] = {
        {0x8e,0x9f,0xf1,0xc6},
        {0x4d,0xdc,0xe1,0xc7},
        {0xa1,0x58,0xd1,0xc8},
        {0xbc,0x9d,0xc1,0xc9}
    };
    unsigned char** state = (unsigned char**) malloc(4*sizeof(unsigned char*));
    for (int i = 0; i < 4; i++) {
        state[i] = (unsigned char*) malloc(4*sizeof(char));
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i][j];
        }
    }
    invSubBytes(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED invSubBytes\n");
}

void testInvShiftRows() {
    printf("? \tTESTING invShiftRows ...\n");
    unsigned char input[4][4] = {
        {0x8e,0x9f,0x01,0xc6},
		{0xdc,0x01,0xc6,0x4d},
		{0x01,0xc6,0xa1,0x58},
		{0xc6,0xbc,0x9d,0x01}
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
    invShiftRows(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED invShiftRows\n");
}

void testInvMixColumns() {
    printf("? \tTESTING invMixColumns ...\n");
    unsigned char input[4][4] = {
        {0x8e,0x9f,0x01,0xc6},
        {0x4d,0xdc,0x01,0xc6},
        {0xa1,0x58,0x01,0xc6},
        {0xbc,0x9d,0x01,0xc6}
    };
    unsigned char output[4][4] = {
        {0xdb,0xf2,0x01,0xc6},
        {0x13,0x0a,0x01,0xc6},
        {0x53,0x22,0x01,0xc6},
        {0x45,0x5c,0x01,0xc6}
    };
    unsigned char** state = (unsigned char**) malloc(4*sizeof(unsigned char*));
    for (int i = 0; i < 4; i++) {
        state[i] = (unsigned char*) malloc(4*sizeof(char));
        for (int j = 0; j < 4; j++) {
            state[i][j] = input[i][j];
        }
    }
    invMixColumns(state);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (state[i][j] != output[i][j]) {
                printf("! \t\tEXPECTED %d RECEIVED %d, (%d, %d)\n", output[i][j], state[i][j], i, j);
            }
        }
    }
    printf("+ \tFINISHED invMixColumns\n");
}
