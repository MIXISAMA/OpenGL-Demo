#pragma once

#include "pch.h"
#include "core/log.h"
#include "ui/component/log_window.h"

namespace mixi
{
namespace gldemo
{

class LogAdaptor : public core::Log::Adaptor
{
public:

    LogAdaptor(const LogWindow::Ptr& logWindow);
    ~LogAdaptor() = default;

private:

    void info(const std::string& content);
    void warning(const std::string& content);
    void error(const std::string& content);
    void fatal(const std::string& content);

    LogWindow::Ptr logWindow_;

};

class Glog
{
public:

    Glog(const char* arg, const char* log_dir = nullptr);
    ~Glog();

};

} // namespace gldemo
} // namespace mixi

