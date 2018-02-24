void encrypt(unsigned int** state, unsigned int* key, int len);
void addRoundKey(unsigned int** state, unsigned int* key, int keyi);
void subBytes(unsigned int** state);
void shiftRows(unsigned int** state);
void mixColumns(unsigned int** state);
void decrypt(unsigned int** state, unsigned int* key, int len);
void invSubBytes(unsigned int** state);
void invShiftRows(unsigned int** state);
void invMixColumns(unsigned int** state);

void addRoundKey(unsigned int** state, unsigned int* key, int keyi) {

}

void subBytes(unsigned int** state) {

}

void shiftRows(unsigned int** state) {

}

void mixColumns(unsigned int** state) {

}

void encrypt(unsigned int** state, unsigned int* key, int len) {
    int keyi = 0;
    addRoundKey(state, key, keyi);
    keyi += 4;
    int rounds = len/4 - 2;
    for (int i = 0; i < rounds; i++) {
        subBytes(state);
        shiftRows(state);
        mixColumns(state);
        addRoundKey(state, key, keyi);
        keyi += 4;
    }
    subBytes(state);
    shiftRows(state);
    mixColumns(state);
    addRoundKey(state, key, keyi);
}

void invSubBytes(unsigned int** state) {

}

void invShiftRows(unsigned int** state) {

}

void invMixColumns(unsigned int** state) {

}

void decrypt(unsigned int** state, unsigned int* key, int len) {
    int keyi = len-4;
    addRoundKey(state, key, keyi);
    keyi -= 4;
    int rounds = len/4 - 2;
    for (int i = 0; i < rounds; i++) {
        invShiftRows(state);
        invSubBytes(state);
        addRoundKey(state, key, keyi);
        keyi -= 4;
        invMixColumns(state);
    }
    invShiftRows(state);
    invSubBytes(state);
    addRoundKey(state, key, keyi);
}
