void mixColumns(unsigned char** state);
void shiftRows(unsigned char** state);
void subBytes(unsigned char** state);
void addRoundKey(unsigned char** state, unsigned char** key);
void encrypt(unsigned char** state, unsigned char** key, int length, int rounds);
