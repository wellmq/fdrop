struct byte_buffer {
  unsigned char *bytes;
  int length;
};
class file_io {
public:
  static byte_buffer read_bmp(char *path);
  static void write_bmp(char *path, unsigned char *image, int length);
};
