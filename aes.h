void encrypt(unsigned int** state, unsigned int* key, int rounds);
void addRoundKey(unsigned int** state, unsigned int* key, int ki);
void subBytes(unsigned int** state);
void shiftRows(unsigned int** state);
void mixColumns(unsigned int** state);
void decrypt(unsigned int** state, unsigned int* key, int rounds);
void invMixColumns(unsigned int** state);
void invShiftRows(unsigned int** state);
void invSubBytes(unsigned int** state);
