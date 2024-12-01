#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

FILE * fp;
NUMBER_OF_LINES = 6;
NUMBER_OF_SPACES = 2; 
NUMBER_OF_DIGITS = 1; 

int compare( const void* a, const void* b)
{
   int int_a = * ( (int*) a );
   int int_b = * ( (int*) b );

   // an easy expression for comparing
   return (int_a > int_b) - (int_a < int_b);
}

char * subString(int size, int start, char* orig){
  char *new = malloc(size);
  for(int i = 0; i < size;i++){
    new[i] = orig[start + i];
    printf("%c", new[i]);
    printf("%d", i);
  }
  new[size] = '\0';
  printf("\n");
  return new;
}


int main() {
  fp = fopen("Day1Input.txt", "r");
  char * line = NULL;
  size_t len = 0;
  int read;
  int list1[NUMBER_OF_LINES];
  int list2[NUMBER_OF_LINES];  

  if(fp == NULL) {
    printf("Not able to open the file.");
  }
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
      char* line1 = subString(NUMBER_OF_DIGITS, 0, line);
      char* line2 = subString(NUMBER_OF_DIGITS, NUMBER_OF_DIGITS + NUMBER_OF_SPACES, line);
      list1[i] = atoi(line1);
      list2[i] = atoi(line2);
  }
  int n = sizeof(list1) / sizeof(list1[0]);
  qsort( list1, n, sizeof(int), compare );
  qsort( list2, n, sizeof(int), compare );
  int differnce = 0;
  for(int i = 0; i < NUMBER_OF_LINES;i++){
     if(list1[i] < list2[i] ){
        differnce += list2[i] - list1[i];
     } else {
      differnce += list1[i] - list2[i];
    }
  }
  printf("The diff is %d", differnce);
  return 0;


}
