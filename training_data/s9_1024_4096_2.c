#include "header.h"

int Output[1024][4096];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<1024; i++) {
     for (j=0; j<4096; j++) {
       Output[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Output[0][0], &Output[0][4096]);
  BENCH("Example8",   example8(8), 256, digest_memory(&Output[0][0], &Output[0][4096]));
 
  return 0;
}