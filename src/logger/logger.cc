//
// Created by Larry on 2022/1/12.
//

#include "logger.h"

#include <fstream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/date_time/local_time/local_time.hpp>

#include <iostream>
#include <locale>

namespace boost_log = boost::log;
namespace boost_trivial = boost_log::trivial;
namespace boost_sources = boost_log::sources;
namespace boost_expressions = boost_log::expressions;
namespace boost_sinks = boost_log::sinks;
namespace boost_keywords = boost_log::keywords;
namespace local_time = boost::local_time;
namespace posix_time = boost::posix_time;

class Logger {
 public:
  Logger() noexcept {
    typedef boost_sinks::synchronous_sink<boost_sinks::text_ostream_backend> text_sink;
    boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

    boost::shared_ptr<std::ostream> stream(&std::clog, boost::null_deleter());
    sink->locked_backend()->add_stream(stream);

    //auto date_osstr = isoExtendedTime();

//    boost_log::formatter formatter = boost_expressions::stream
//        << date_osstr
//        << " ["
//        << boost_log::trivial::severity
//        << "] "
//        << boost_expressions::message;
//
//    sink->set_formatter(formatter);

    boost_log::core::get()->add_sink(sink);
  }

  void log(std::string const &content, boost_trivial::severity_level level) {
    boost_sources::severity_logger<boost_trivial::severity_level> lg;

    std::string level_str;
    switch (level) {
      case boost_trivial::trace:level_str = "trace";
        break;
      case boost_trivial::info:level_str = "info";
        break;
      case boost_trivial::warning:level_str = "warning";
        break;
      case boost_trivial::error:level_str = "error";
        break;
      case boost_trivial::fatal:level_str = "fatal";
        break;
      case boost_trivial::debug:
      default: level_str = "debug";
    }
    auto date_osstr = isoExtendedTime();
    BOOST_LOG_SEV(lg, level) << date_osstr
                             << " ["
                             << level_str
                             << "] " << content;
  }

  std::string isoExtendedTime() {
    auto *facet = new local_time::local_time_facet("%Y-%m-%d %H:%M:%S%F%Q");

    posix_time::ptime my_ptime = posix_time::second_clock::universal_time();
    local_time::local_date_time now(my_ptime, utc_time_zone);

    std::ostringstream date_osstr;
    date_osstr.imbue(std::locale(date_osstr.getloc(), facet));
    date_osstr << now;

    return date_osstr.str();
  }
 private:
  local_time::time_zone_ptr utc_time_zone{new local_time::posix_time_zone("GMT")};
};

namespace logger {
static Logger _logger;
void log_trace(std::string const &content) {
  _logger.log(content, boost_trivial::trace);
}
void log_debug(std::string const &content) {
  _logger.log(content, boost_trivial::debug);
}
void log_info(std::string const &content) {
  _logger.log(content, boost_trivial::info);
}
void log_warning(std::string const &content) {
  _logger.log(content, boost_trivial::warning);
}
void log_error(std::string const &content) {
  _logger.log(content, boost_trivial::error);
}
void log_fatal(std::string const &content) {
  _logger.log(content, boost_trivial::fatal);
}
}
