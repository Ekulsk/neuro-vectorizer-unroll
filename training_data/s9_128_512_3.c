#include "header.h"

int result[128][512];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<512; j++) {
       result[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&result[0][0], &result[0][512]);
  BENCH("Example8",   example8(8), 16384, digest_memory(&result[0][0], &result[0][512]));
 
  return 0;
}