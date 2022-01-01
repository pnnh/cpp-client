//
// Created by Larry on 2021/12/31.
//

#include <iostream>
#include "process.h"

void start_child() {
  process::ipstream pipe_stream;
  process::child c("ls -l", process::std_out > pipe_stream);

  std::string line;

  while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
    std::cout << line << std::endl;

  c.wait();
}