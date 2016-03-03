#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "arrayInput.txt"
#define oFILE_NAME "arrayOutput.txt"

int main(void){
  FILE *fp, *ofp;
  int i, j, k, d, t, y, sum = 0;
  char str[100];
  int A[3][3] = {0};
  int B[3][3] = {0};
  int R[3][3] = {0};
  

  //opening a file
  fp = fopen(FILE_NAME, "r");
  if (fp == NULL){
    fprintf(stderr,"Usage: Error opening file!\n");
    exit(EXIT_FAILURE);
  }
  //loading the A array
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      fscanf(fp, "%s",str);
      A[i][j] = atoi(str);
    }
  } 
  //loading the B array
  for (k = 0; k < 3; k++){
    for (d = 0; d < 3; d++){
      fscanf(fp, "%s",str);
      B[k][d] = atoi(str);
    }
  }
  //Running the matrix multiplication
  for (t = 0; t < 3; t++) {
    for (y = 0; y < 3; y++) {
      for (k = 0; k < 3; k++) {
	sum = sum + A[t][k]*B[k][y];
      }
 
      R[t][y] = sum;
      sum = 0;
    }
  }
  //opening an output file
  ofp=fopen(oFILE_NAME,"w");
  if (ofp == NULL){
    fprintf(stderr, "Usage: Error opennin file!\n");
    exit(EXIT_FAILURE);
  }
  //printing the product in the console and the output file
  printf("Product:-\n");
  for (t = 0; t < 3; t++) {
    for (y = 0; y < 3; y++){
      printf("%d\t", R[t][y]);
      fprintf(ofp,"%d\t",R[t][y]);
    }
    printf("\n");
    fprintf(ofp,"\n");
  }

  fclose(fp);
  fclose(ofp);
}
