#include <iostream>
#include "src/directory_listing.hh"

#ifdef _WIN32
  // UnChecked platform (_WIN64)
#elif __APPLE__
  #include <sys/resource.h>
  #include <unistd.h>
#endif

void rusage();

int main() {
  rusage();
  {
    std::unique_ptr<DirectoryListing> d(new DirectoryListing("./"));
    rusage();
    d->read();
    rusage();
    rusage();
    for (int i = 0; i < d->getList().size(); ++i) {
      std::cout << d->getList()[i] << std::endl;
    }
    rusage();
  }
  rusage();
  return 0;
}

void rusage() {
#ifdef __APPLE__
  struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  std::cout << "maxrss=" << r.ru_maxrss << std::endl;
#endif
}
