#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "Lyra2Z.h"

#define _ALIGN(x) __attribute__ ((aligned(x)))

//extern uint64_t lyra2z330_height;

void lyra2z330_regenhash(const char* input, char* output, uint32_t len)
{
  uint32_t _ALIGN(64) hash[8];

  LYRA2Z((void*)hash, 32, (void*)input, len, (void*)input, len, 2, 330, 256);

  memcpy(output, hash, 32);
}
