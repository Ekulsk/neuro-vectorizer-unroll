#include "header.h"

short sa[4096];
short sb[4096];
int   result1[4096] ALIGNED16;
int   result2[4096] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, int* __restrict__ result1, int* __restrict__ result2) {
  int i;
  for (i = 0; i < 4096-1; i+=2) {
    result1[i] = (int) sa[i];
result1[i+1] = (int) sa[i+1];
    result2[i] = (int) sb[i];
result2[i+1] = (int) sb[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result1[0], &result1[4096]);
  init_memory(&result2[0], &result2[4096]);
  init_memory(&sa[0], &sa[4096]);
  init_memory(&sb[0], &sb[4096]);
  BENCH("Example10b", example10b(sa,sb,result1,result2), Mi*4/4096*512, digest_memory(&result1[0], &result1[4096])+digest_memory(&result2[0], &result2[4096]));
 
  return 0;
}