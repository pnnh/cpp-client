//
// Created by Larry on 2022/1/12.
//

#ifndef CPP_CLIENT_LOGGER_H
#define CPP_CLIENT_LOGGER_H

#include <string>

namespace logger {
void log_trace(std::string const &content);
void log_debug(std::string const &content);
void log_info(std::string const &content);
void log_warning(std::string const &content);
void log_error(std::string const &content);
void log_fatal(std::string const &content);
}

#endif //CPP_CLIENT_LOGGER_H
