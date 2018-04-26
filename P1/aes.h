unsigned char** keyExpansion(unsigned char key[], int Nk, int Nr);
void subWord(unsigned char word[4]);
void rotWord(unsigned char word[4]);

void addRoundKey(unsigned char** state, unsigned char** key, int offset);

void subBytes(unsigned char** state);
void invSubBytes(unsigned char** state);

void mixColumns(unsigned char** state);
void invMixColumns(unsigned char** state);

void shiftRows(unsigned char** state);
void invShiftRows(unsigned char** state);

void aesEncrypt(unsigned char** state, unsigned char** key, int rounds);
void aesDecrypt(unsigned char** state, unsigned char** key, int rounds);

unsigned char* encrypt(unsigned char key[], unsigned char plaintext[]);
unsigned char* decrypt(unsigned char key[], unsigned char ciphertext[]);
