#include <utils.h>

bool isJPEG(const std::vector<u_char>& data) {
  if (data.size() < 3) {
    return false;
  }

  return (data[0] == 0xFF && data[1] == 0xD8 && data[2] == 0xFF);
}

bool isPNG(const std::vector<u_char>& data) {
  if (data.size() < 8) {
    return false;
  }

  return (data[0] == 0x89 && data[1] == 0x50 && data[2] == 0x4E &&
          data[3] == 0x47 && data[4] == 0x0D && data[5] == 0x0A &&
          data[6] == 0x1A && data[7] == 0x0A);
}

bool isTIFF(const std::vector<unsigned char>& data) {
  // TIFF magic number (the first 4 bytes)
  std::vector<unsigned char> tiffMagic = {0x49, 0x49, 0x2A, 0x00}; // Little-endian
  //std::vector<unsigned char> tiffMagic = {0x4D, 0x4D, 0x00, 0x2A}; // Big-endian

  if (data.size() < tiffMagic.size()) {
    return false;
  }

  for (size_t i = 0; i < tiffMagic.size(); ++i) {
    if (data[i] != tiffMagic[i]) {
      return false;
    }
  }

  return true;
}