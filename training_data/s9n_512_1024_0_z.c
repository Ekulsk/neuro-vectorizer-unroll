#include "header.h"

int G[512][1024];
__attribute__((noinline))
void example8 (int z) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<512-1; i+=2) {
     for (j=0; j<1024-1; j+=2) {
       G[i][j] = z;
       G[i+1][j] = z;
       G[i][j+1] = z;
       G[i+1][j+1] = z;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][1024]);
  BENCH("Example8",   example8(8), 2048, digest_memory(&G[0][0], &G[0][1024]));
 
  return 0;
}