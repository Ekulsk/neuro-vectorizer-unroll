#include "header.h"

short in[512];
int   out[512] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ out) {
  int i;
  for (i = 0; i < 512; i++) {
    out[i] = (int) in[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[512]);
  init_memory(&in[0], &in[512]);
  BENCH("Example10b", example10b(in,out), Mi*4/512*512, digest_memory(&out[0], &out[512]));
 
  return 0;
}