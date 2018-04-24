void invMixColumns(unsigned char** state);
void invShiftRows(unsigned char** state);
void invSubBytes(unsigned char** state);
void addRoundKey(unsigned char** state, unsigned char** key);
void decrypt(unsigned char** state, unsigned char** key, int length, int rounds);
