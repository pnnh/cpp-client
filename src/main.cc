#include <iostream>
#include <boost/program_options.hpp>
#include "process.h"
#include "logger/logger.h"

namespace program_options = boost::program_options;

int main(int argc, char *argv[]) {
  std::cerr << "Hello Client" << std::endl;
  if (argc < 2) {
    std::cerr << "参数数量有误" << std::endl;
    return 1;
  }

  //声明需要的选项
  program_options::options_description desc("Allowed options");
  desc.add_options()
      ("help,h", "显示帮助信息")
      ("verbose,v", "显示明细")
      ("person,p", program_options::value<std::string>()->default_value("world"), "who");

  program_options::variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help")) {
    std::cout << desc;
    return 0;
  }
  std::cout << "Hello " << vm["person"].as<std::string>() << std::endl;

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