#include "file_encoder.hpp"

bool *file_encoder::get_bits(char *string, int length) {
  unsigned char bytes[length];
  for (int i = 0; i < length; i++) {
    bytes[i] = (unsigned char)string[i];
  }
  int bits_quantity = length * 8;
  bool *bits = new bool[bits_quantity];
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 8; j++) {
      unsigned char shifted_byte = bytes[i] >> (7 - j);
      if ((shifted_byte & 1) == 1) {
        bits[i * 8 + j] = true;
      } else {
        bits[i * 8 + j] = false;
      }
    }
  }
  return bits;
}

void file_encoder::insert_data(bool *bits, int length,
                               unsigned char *image_bytes, int bytes_length) {
  for (int i = 0; i < length; i++) {
    int image_index = i + 100;
    if (bits[i]) {
      image_bytes[image_index] |= 1;
    } else {
      image_bytes[image_index] &= 254;
    }
  }
}
