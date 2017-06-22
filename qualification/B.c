#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void llitoa(long long int num, char* str, int radix) {
  int i = 0;
  while (num >= radix){
    //printf("%lld\n", num);
    //printf("%lld\n", num % radix);
    str[i] = (num % radix)+48;
    num = num / radix;
    i++;
  }
  str[i] = num+48;
  str[i+1] = '\0';
  //printf("\n%s\n\n", str);
}


long long int areversetolli(char *str) {
  //printf("%s\n", str);
  int len = strlen(str);
  long long int ans = 0;
  long long int temp = 0;
  int i, j;
  for (i=0; i<len; i++) {
    temp = str[i]-48;
    for (j=0; j<i; j++) {
      temp = temp * 10; 

    }
    ans += temp;
    //printf("%lld\n", ans);
  }

  //printf("%d\n\n", ans);

  return ans;
}

int changeascend(char *str, int len) {
  int i = 0;
  int j = 0;
  long long int temp;
  char tempstr[20];
  int changed = 0;

  while (str[j+1] != '\0') {
    if (str[j] < str[j+1]) {
      for (i=0; i<=j; i++) {
        str[i] = '9';
      }
      temp = areversetolli(&str[j+1]);
      //printf("%s\n", &str[j+1]);
      temp -= 1;
      //.inprintf("%lld\n", temp);
      if (temp == 0) {
        strcpy(&str[j+1], "\0");
      }
      else {
        llitoa(temp, tempstr, 10);
        //printf("%s\n", tempstr);

        //printf("%s\n", &str[j+1]);
        strcpy(&str[j+1], tempstr);
      }
      changed = 1;
    }
    j++;
  }

  //printf("%s\n", str);
  //printf("%d\n", strlen(str));

  return changed;
}


int main() {
  long long int i, j, k;
  int T;
  int len;
  long long int num, ans;
  char numstr[20];

  int flag;

  scanf("%d", &T);
  //printf("%d\n", T);

  for(i=0; i<T; i++){
    scanf("%lld", &num);

    
    

    llitoa(num, numstr, 10);
    len = strlen(numstr);
    //printf("%lld\n", num);
    //printf("%s\n", numstr);

    
    while (changeascend(numstr, len) != 0) {

    }
    


    

    /*
    for (j=num; j>0; j--) {
      //printf("%lld\n", j);
      char tempstr[20];
      //printf("%lld\n", j);
      flag = 0;
      llitoa(j, tempstr, 10);
      len = strlen(tempstr);
      //printf("%d\n", len);
      //printf("%s\n", tempstr);
      for (k=0; k<len-1; k++){
        if (tempstr[k] < tempstr[k+1]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        ans = j;
        break;
      }
    }
    */

    //printf("Case #%lld: %lld\n", i+1, ans);
    
    printf("Case #%lld: ", i+1);
    for (j = strlen(numstr)-1; j>=0; j--){
      printf("%c", numstr[j]);
    }
    printf("\n");
    
  }


  return 0;
}