#include <stdlib.h>
#include <string.h>

char *strclone(char s[])
{
  char *clone = NULL;
  int i;

  /* s の長さ (strlen(s)) プラス 1 の文字配列を割り当てる */
  clone = (char *)malloc(sizeof(char) * (strlen(s) + 1));

  /* コピー */
  strcpy(clone, s);
  /****
  ちなみに strcpy の中では, 次の処理が行われている
  for (i=0; s[i]!='\0'; i++) {
    clone[i] = s[i];
  }
  clone[i] = '\0';
  ***/

  return clone;
}