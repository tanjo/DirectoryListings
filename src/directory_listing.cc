#include "directory_listing.hh"

#ifdef _WIN32
  // UnChecked platform (_WIN64)
#elif __APPLE__
  #include <TargetConditionals.h>
  #if TARGET_OS_MAC
    #include <dirent.h>
    #include <string>
  #endif // Unsupported platform (TARGET_OS_IPHONE, TARGET_IPHONE_SIMULATOR)
#endif // Unsupported platform (__linux, __unix, __posix)

DirectoryListing::~DirectoryListing() {
  delete this->_files;
  delete this->_folder;
}

DirectoryListing::DirectoryListing() {
  DirectoryListing::DirectoryListing(nullptr);
}

DirectoryListing::DirectoryListing(const std::string &folder) {
  this->_files = new std::vector<std::string>();
  this->_folder = new std::string(folder);
}

void DirectoryListing::clear() {
  if (this->_files != nullptr) {
    this->_files->clear();
  }
  this->_folder = nullptr;
}

std::vector<std::string> const & DirectoryListing::read() {

#ifdef _WIN32
  // UnChecked platform (_WIN64)
#elif __APPLE__
  #if TARGET_OS_MAC

  DIR *dp;
  struct dirent *ep;
  dp = opendir(this->_folder->c_str());

  if (dp != nullptr) {
    while ((ep = readdir(dp))) {
      this->_files->push_back(ep->d_name);
    }
    closedir(dp);
  }

  #endif // Unsupported platform (TARGET_OS_IPHONE, TARGET_IPHONE_SIMULATOR)
#endif // Unsupported platform (__linux, __unix, __posix)

  return this->getList();
}

std::vector<std::string> const & DirectoryListing::read(const std::string &folder) {
  delete this->_folder;
  this->_folder = new std::string(folder);
  return this->read();
}

std::vector<std::string> const & DirectoryListing::getList() {
  return *this->_files;
}
