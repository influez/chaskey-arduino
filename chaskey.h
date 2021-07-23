/*
   Chaskey C Header File
   Chaskey 8-round

   Written in 2015 by Nicky Mouha, based on Chaskey
   Modified in 2017 by Aaron Lindsay
   Modified in 2021 for simple library use on microcontroller boards

*/

#ifndef _CHASKEY_H
#define _CHASKEY_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHASKEY_TAG_SIZE (0x10)

#ifndef CHASKEY_ROUNDS
#define CHASKEY_ROUNDS 8
#endif

void chaskey_subkeys(uint32_t k1[4], uint32_t k2[4], const uint32_t k[4]);
void chaskey(uint8_t *tag, const size_t taglen, const uint8_t *m, const size_t mlen, const uint32_t k[4], const uint32_t k1[4], const uint32_t k2[4]);

typedef struct {
  uint32_t tag[4];
  uint32_t k1[4];
  uint32_t k2[4];
  size_t len;
  union {
    uint32_t u32[4];
    uint8_t u8[16];
  } m;
} ChaskeyContext;

void chaskey_init(ChaskeyContext* context, const uint32_t k[4], const uint32_t k1[4], const uint32_t k2[4]);
void chaskey_process(ChaskeyContext* context, const uint8_t* m, size_t len);
void chaskey_finish(ChaskeyContext* context);
const uint8_t* chaskey_tag(ChaskeyContext* context);
int test_vectors();

#ifdef __cplusplus
}
#endif

#endif
