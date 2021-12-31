#include <iostream>
#include "process.h"

int main(int argc, char *argv[]) {
  std::cerr << "Hello Client" << std::endl;

  process::child c = start_child();
  process::pistream &is = c.get_stdout();
  std::string line;
  while (std::getline(is, line))
    std::cout << line << std::endl;
  process::status s = c.wait();

  return s.exited() ? s.exit_status() : EXIT_FAILURE;
}