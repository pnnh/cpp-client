//
// Created by Larry on 2021/12/31.
//

#ifndef CPP_CLIENT_PROCESS_H
#define CPP_CLIENT_PROCESS_H

#include <boost/filesystem.hpp>
#include <boost/process.hpp>
#include <string>
#include <vector>

namespace process = ::boost::process;

process::child start_child();

#endif //CPP_CLIENT_PROCESS_H
