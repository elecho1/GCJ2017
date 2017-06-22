#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  FILE *fp;

  int i, j, l;
  int t;

  char s[1002];
  int strlength;
  int k;
  int count;
  int flag;

  fp = fopen("a.out", "w");

  scanf("%d", &t);

  for (i=0; i<t; i++) {
    count = 0;
    flag = 0;
    scanf("%s %d", s, &k);
    strlength = strlen(s);

    for (j=0; j < strlength-k+1; j++) {
      //printf("%c ", s[j]);
      if (s[j] == '-') {
        //printf("Hello!\n");
        count++;
        for (l=j; l<j+k; l++) {
          if (s[l] == '-') {
            s[l] = '+';
          }
          else {
            s[l] = '-';
          }
        }
      }
      //printf("%s\n", s);
    }
    
    for (j=strlength-k+1; j<strlength; j++) {
      //printf("%c", s[j]);
      if (s[j] == '-') {
        flag = 1;
        break;
      }
    }

    fprintf(fp, "Case #%d: ", i+1);
    if (flag == 1) {
      fprintf(fp, "IMPOSSIBLE\n");
    }
    else {
      fprintf(fp, "%d\n", count);
    }
  }
  
  return 0;
}