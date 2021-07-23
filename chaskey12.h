/*
   Chaskey-12 C Header File
   Chaskey 12-round

   Written in 2015 by Nicky Mouha, based on Chaskey
   Modified in 2017 by Aaron Lindsay
   Modified in 2021 for simple library use on microcontroller boards

*/

#ifndef _CHASKEY12_H
#define _CHASKEY12_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHASKEY12_TAG_SIZE (0x10)

#ifndef CHASKEY12_ROUNDS
#define CHASKEY12_ROUNDS 12
#endif

void chaskey12_subkeys(uint32_t k1[4], uint32_t k2[4], const uint32_t k[4]);
void chaskey12(uint8_t *tag, const size_t taglen, const uint8_t *m, const size_t mlen, const uint32_t k[4], const uint32_t k1[4], const uint32_t k2[4]);

typedef struct {
  uint32_t tag[4];
  uint32_t k1[4];
  uint32_t k2[4];
  size_t len;
  union {
    uint32_t u32[4];
    uint8_t u8[16];
  } m;
} Chaskey12Context;

void chaskey12_init(Chaskey12Context* context, const uint32_t k[4], const uint32_t k1[4], const uint32_t k2[4]);
void chaskey12_process(Chaskey12Context* context, const uint8_t* m, size_t len);
void chaskey12_finish(Chaskey12Context* context);
const uint8_t* chaskey12_tag(Chaskey12Context* context);

#ifdef __cplusplus
}
#endif

#endif
