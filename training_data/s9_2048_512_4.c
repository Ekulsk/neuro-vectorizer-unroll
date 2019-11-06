#include "header.h"

int assign[2048][512];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<2048; i++) {
     for (j=0; j<512; j++) {
       assign[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][512]);
  BENCH("Example8",   example8(8), 1024, digest_memory(&assign[0][0], &assign[0][512]));
 
  return 0;
}