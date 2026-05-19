#include "file_io.hpp"
#include <fstream>
#include <ios>
#include <iostream>

byte_buffer file_io::read_bmp(char *path) {
  std::ifstream ifstream;
  ifstream.open(path, std::ios::binary | std::ios::ate);
  if (!ifstream.is_open()) {
    std::cerr << "file opening error" << std::endl;
    std::abort();
  }
  int length = ifstream.tellg();
  ifstream.seekg(0, std::ios::beg);
  unsigned char *bytes = new unsigned char[length];
  ifstream.read((char *)bytes, length);
  ifstream.close();
  byte_buffer bb;
  bb.bytes = bytes;
  bb.length = length;
  return bb;
}

void file_io::write_bmp(char *path, unsigned char *image, int length) {
  std::ofstream ofstream;
  ofstream.open(path, std::ios::binary);
  if (!ofstream.is_open()) {
    std::cerr << "file opening error" << std::endl;
    std::abort();
  }
  ofstream.write((char *)image, length);
}
