#include "header.h"

short sa[512];
int   result[512] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, int* __restrict__ result) {
  int i;
  for (i = 0; i < 512; i++) {
    result[i] = (int) sa[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result[0], &result[512]);
  init_memory(&sa[0], &sa[512]);
  BENCH("Example10b", example10b(sa,result), Mi*4/512*512, digest_memory(&result[0], &result[512]));
 
  return 0;
}