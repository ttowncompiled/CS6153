void encrypt(unsigned int** state, unsigned int* key, int len);
void addRoundKey(unsigned int** state, unsigned int* key, int keyi);
void subBytes(unsigned int** state);
void shiftRows(unsigned int** state);
void mixColumns(unsigned int** state);
void decrypt(unsigned int** state, unsigned int* key, int len);
void invSubBytes(unsigned int** state);
void invShiftRows(unsigned int** state);
void invMixColumns(unsigned int** state);