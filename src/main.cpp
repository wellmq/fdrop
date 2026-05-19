#include "file_decoder.hpp"
#include "file_encoder.hpp"
#include "file_io.hpp"
#include <cstring>
#include <iostream>

void encode(char *ipath, char *opath, char *string, int string_length) {
  byte_buffer bb = file_io::read_bmp(ipath);
  bool *bits = file_encoder::get_bits(string, string_length);
  file_encoder::insert_data(bits, string_length * 8, bb.bytes, bb.length);
  file_io::write_bmp(opath, bb.bytes, bb.length);
  delete[] bb.bytes;
}

void decode(char *ipath) {
  byte_buffer bb = file_io::read_bmp(ipath);
  bit_buffer bitb = file_decoder::get_bits(bb.bytes, bb.length);
  char *string = file_decoder::get_string(bitb.bits, bitb.length);
  std::cout << string << std::endl;
  delete[] bb.bytes;
  delete[] bitb.bits;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "Error: Insufficient arguments." << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "   Encode: ./fdrop -e \"text\" \"input.bmp\" \"output.bmp\""
              << std::endl;
    std::cout << "   Decode: ./fdrop -d \"input.bmp\"" << std::endl;
    return 0;
  }
  if (std::strcmp(argv[1], "-e") == 0) {
    if (argc < 5)
      return 0;
    encode(argv[3], argv[4], argv[2], std::strlen(argv[2]) + 1);
  }
  if (std::strcmp(argv[1], "-d") == 0) {
    if (argc < 3)
      return 0;
    decode(argv[2]);
  }
}
