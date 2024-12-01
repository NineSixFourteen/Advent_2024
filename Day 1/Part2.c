#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

FILE * fp;
const int NUMBER_OF_LINES = 1000;
const int NUMBER_OF_SPACES = 3; 
const int NUMBER_OF_DIGITS = 5; 

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
  }
  new[size] = '\0';
  printf("\n");
  return new;
}

int calc_simularity_score(int item, int* list2){
    int counter = 0;
    for(int i =0 ; i < NUMBER_OF_LINES;i++){
        if(item == list2[i]){
            counter++;
        }
    }
    printf("Occ : %d, item : %d\n",counter, item);
    return counter * item;
}


int main() {
  fp = fopen("Day1Input.txt", "r");
  char * line = NULL;
  size_t len = NUMBER_OF_DIGITS + NUMBER_OF_SPACES + NUMBER_OF_DIGITS;
  int read;
  int list1[1000];
  int list2[1000];  

  if(fp == NULL) {
    printf("Not able to open the file.");
  }
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    printf("%s",line);
      char* line1 = subString(NUMBER_OF_DIGITS, 0, line);
      char* line2 = subString(NUMBER_OF_DIGITS, NUMBER_OF_SPACES + NUMBER_OF_DIGITS, line);
      list1[i] = atoi(line1);
      printf("list value : %d, atoi(list) value : %d\n", list1[i], atoi(line1));
      list2[i] = atoi(line2);
      printf("list value : %d, atoi(list) value : %d\n", list2[i], atoi(line2));
      i++;
  }
  int score = 0;
  printf("%d,%d,%d\n",list1[0],list1[1],list1[2]);
  for(int i = 0; i < NUMBER_OF_LINES;i++){
     score += calc_simularity_score(list1[i], list2);
  }
  printf("The score is %d", score);
  return 0;
}
