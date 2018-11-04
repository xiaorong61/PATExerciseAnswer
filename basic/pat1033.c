#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  char bad[100000 + 1], should[100000 + 1];
  gets(bad);
  gets(should);
  for (int i = 0, length = strlen(should); i < length; i++) {
    if (strchr(bad, toupper(should[i])) != NULL) continue;
    if (isupper(should[i]) && strchr(bad, '+') != NULL) continue;
    putchar(should[i]);
  }
  return 0;
}