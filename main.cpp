#include <iostream>
#include <string>
#include <utils.h>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <fstream>

int main(int argc, char const *argv[]) {
  std::string lostdirPath = "";

  if (argc <= 1) {
    std::cout << "Please provide LOST.DIR path" << std::endl;
    return 1;
  }

  // set lost dir path
  lostdirPath = argv[1];

  // open the lost dir path
  DIR* dir = opendir(lostdirPath.c_str());

  if (dir == nullptr) {
    std::cerr << "Error opening directory" << std::endl;
    return 1;
  }

  struct dirent* entry;

  while ((entry = readdir(dir))) {
    // regular file
    if (entry->d_type == DT_REG) {
      // process
      std::string filename = lostdirPath + "/" + entry->d_name;

      std::ifstream file(filename, std::ios::binary);
      if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
      }

      std::vector<unsigned char> header(8); // Read the first 8 bytes
      file.read(reinterpret_cast<char*>(header.data()), header.size());

      if (isJPEG(header)) {
        std::string newname = filename + ".JPG";
        std::cout << "Processing JPEG file : ./" << filename;

        if (std::rename(filename.c_str(), newname.c_str()) == 0) {
          std::cout << " [DONE] " << std::endl;
        } else {
          std::cerr << " [ERR]" << std::endl;
          perror("Error details");
          return 1;
        }
        
      } else if (isPNG(header)) {
        std::string newname = filename + ".png";
        std::cout << "Processing PNG file : ./" << filename;

        if (std::rename(filename.c_str(), newname.c_str()) == 0) {
          std::cout << " [DONE] " << std::endl;
        } else {
          std::cerr << " [ERR]" << std::endl;
          perror("Error details");
          return 1;
        }
        
      } else if (isTIFF(header)) {
        std::string newname = filename + ".tiff";
        std::cout << "Processing TIFF file : ./" << filename;

        if (std::rename(filename.c_str(), newname.c_str()) == 0) {
          std::cout << " [DONE] " << std::endl;
        } else {
          std::cerr << " [ERR]" << std::endl;
          perror("Error details");
          return 1;
        }
        
      } else {
        std::cout << "Unknown file type. Skipping." << std::endl;
      }

      file.close();
    } 
  }

  closedir(dir);

  return 0;
}
