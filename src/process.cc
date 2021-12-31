//
// Created by Larry on 2021/12/31.
//

#include "process.h"

process::child start_child() {
  std::string exec = "bjam";
  std::vector<std::string> args;
  args.push_back("bjam");
  args.push_back("--version");

  process::context ctx;
  ctx.stdout_behavior = process::capture_stream();

  return process::launch(exec, args, ctx);
}