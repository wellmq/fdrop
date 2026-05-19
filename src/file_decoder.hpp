struct bit_buffer {
  bool *bits;
  int length;
};

class file_decoder {
public:
  static bit_buffer get_bits(unsigned char *bytes, int length);
  static char *get_string(bool *bits, int length);
};
