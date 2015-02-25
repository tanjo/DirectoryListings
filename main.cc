#include <iostream>
#include "src/directory_listing.hh"

int main() {
  DirectoryListing *d = new DirectoryListing("./");
  d->read();
  std::vector<std::string> list = d->getList();
  for (int i = 0; i < list.size(); ++i) {
    std::cout << list[i] << std::endl;
  }
  return 0;
}
