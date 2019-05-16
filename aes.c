#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/aes.h>

AES_KEY ekey;
AES_KEY dkey;

unsigned char	uAesKey[32]={0};

unsigned char in[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
unsigned char out[16]={0};

void dump(const char *caption, unsigned char *buffer, int size) {
  printf("%s\n", caption);
  for (int i=0; i<size; i++) {
    printf("%02X ", buffer[i]);
  }
  printf("\n");
}

int main() {
  scanf("%32s", uAesKey);
  dump("KEY: ", uAesKey, 32);

  AES_set_decrypt_key(uAesKey, 256, &dkey);
  AES_set_encrypt_key(uAesKey, 256, &ekey);
  dump("MSG: ", in, sizeof(in));

  memset(out, 0, sizeof(out));
  AES_ecb_encrypt(in, out, &ekey, AES_ENCRYPT);
  dump("ECRYPTED: ", out, sizeof(out));

  memset(in, 0, sizeof(in));
  AES_ecb_encrypt(out, in, &dkey, AES_DECRYPT);
  dump("DECRYPTED: ", in, sizeof(in));

  return 0;
}
