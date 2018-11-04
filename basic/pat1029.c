#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  char str1[81], str2[81], bad[81] = {0};
  scanf("%s %s", str1, str2);
  for (int i = 0, j = 0; i < strlen(str1); i++)
    if (strchr(bad, toupper(str1[i])) == NULL && strchr(str2, str1[i]) == NULL)
      bad[j++] = toupper(str1[i]);
  puts(bad);
  return 0;
}