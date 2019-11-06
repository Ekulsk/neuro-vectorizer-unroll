#include "header.h"

int in[16384] ALIGNED16;
int out[16384] ALIGNED16;

__attribute__((noinline))
void example4c (){
   int i;
    const int MAX = 4;
   /* feature: support for if-conversion  */
   for (i=0; i<16384-1; i+=2){
      int j = in[i];
      out[i] = (j > MAX ? MAX : 0);
      out[i+1] = j;
   }
}

int main(int argc,char* argv[]){
  init_memory(&in[0], &in[16384]);
  init_memory(&out[0], &out[16384]);
  BENCH("Example4c",  example4c(), Mi*4/16384*512, digest_memory(&out[0], &out[16384]));
 
  
  return 0;
}