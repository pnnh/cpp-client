#include <iostream>
#include "process.h"
#include "logger/logger.h"

int main(int argc, char *argv[]) {
  std::cerr << "Hello Client" << std::endl;
  if (argc < 2) {
    std::cerr << "参数数量有误" << std::endl;
    return 1;
  }

  logger::log_trace("hello");
  logger::log_debug("hello");
  logger::log_info("hello");
  logger::log_warning("hello");
  logger::log_error("hello");
  logger::log_fatal("hello");

  std::string path = argv[1];
  std::cout << "path: " << path << std::endl;

  start_child();
}