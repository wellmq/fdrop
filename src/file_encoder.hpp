class file_encoder {
public:
  static bool *get_bits(char *string, int length);
  static void insert_data(bool *bits, int length, unsigned char *image_bytes,
                          int bytes_length);
};
