#include <iostream>
#include "process.h"

int main(int argc, char *argv[]) {
  std::cerr << "Hello Client" << std::endl;

  start_child();
}