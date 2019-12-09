#include "header.h"

int   ia[2];
int G[128][1024];
int G2[128+2][1024];

__attribute__((noinline))
void example14(int in[][1024], int coeff[][1024], int *result) {
  int k,j,i=0;
  for (k = 0; k < 2; k++) {
    int sum = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 1024; j++)
          sum += in[i+k][j] * coeff[i][j];

    result[k] = sum;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[2]);
  init_memory(&G[0][0], &G[0][1024]);
  init_memory(&G2[0][0],&G2[0][1024]);
  BENCH("Example14",  example14(G2,G,ia), 8192, digest_memory(&ia[0], &ia[2]));
  return 0;
}