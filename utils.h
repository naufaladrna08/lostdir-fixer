#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <sys/types.h>

// butuh gambar doang ceunah

// compare dgn jpeg signature, not sure kalau JPG termasuk jpeg
// njir jaksel bet
bool isJPEG(const std::vector<u_char>& data);

// compare dgn png signature
bool isPNG(const std::vector<u_char>& data);

// compare dgn tiff signature
bool isTIFF(const std::vector<unsigned char>& data);

#endif