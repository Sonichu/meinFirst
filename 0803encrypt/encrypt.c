#include <stdio.h>
#include <stdlib.h>

#define READ_SIZE 0x100

void main() {
  char szBuf[READ_SIZE] = { 0 };
  int i = 0;
  size_t uRet = 0;
  
  FILE *fpr = NULL;
  FILE *fpw = NULL;
  fpr = fopen("sauce.txt", "rb");
  if (fpr == NULL) {
    goto SAFE_EXIT;
  }
  
  fpw = fopen("dest", "wb");
  if (fpw == NULL) {
    goto SAFE_EXIT;
  }

  while ((uRet = fread(szBuf, 1, READ_SIZE, fpr)) == READ_SIZE) {
    for (i = 0; i < uRet; i++) {
      szBuf[i] -= 3;
    }
    fwrite(szBuf, 1, uRet, fpw);
  }
  for (i = 0; i < uRet; i++) {
    szBuf[i] -= 3;
  }
  fwrite(szBuf, 1, uRet, fpw);
  
SAFE_EXIT:
  if (fpr != NULL) {
    fclose(fpr);
    fpr = NULL;
  }
  fclose(fpw);
  if (fpw != NULL) {
    fclose(fpw);
    fpw = NULL;
  }
}