#include "file_decoder.hpp"

bit_buffer file_decoder::get_bits(unsigned char *bytes, int length) {
  int zero_bits = 0;
  int real_bits = 0;
  int bit_index = 0;
  bool *bits = new bool[length];
  for (int i = 100; i < length; i++) {
    if ((bytes[i] & 1) == 1) {
      zero_bits = 0;
      bits[bit_index] = true;
    } else {
      zero_bits += 1;
      bits[bit_index] = false;
    }
    bit_index++;
    real_bits++;
    if (zero_bits == 8) {
      break;
    }
  }
  bit_buffer bb;
  bb.bits = bits;
  bb.length = real_bits;
  return bb;
}

char *file_decoder::get_string(bool *bits, int length) {
  unsigned char *bytes = new unsigned char[length / 8];
  for (int i = 0; i < length / 8; i++) {
    unsigned char result = 0;
    for (int j = 0; j < 8; j++) {
      char bit = (bits[i * 8 + j]) ? 1 : 0;
      char shifted_bit = bit << (7 - j);
      result |= shifted_bit;
    }
    bytes[i] = result;
  }
  return (char *)bytes;
}
