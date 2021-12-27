#include "app/log.h"

namespace mixi
{
namespace gldemo
{

LogAdaptor::LogAdaptor(const LogWindow::Ptr& logWindow) :
    logWindow_(logWindow)
{

}

void LogAdaptor::info(const std::string& content)
{
    logWindow_->push(LogWindow::INFO, content);
    LOG(INFO) << content;
}

void LogAdaptor::warning(const std::string& content)
{
    logWindow_->push(LogWindow::WARNING, content);
    LOG(WARNING) << content;
}

void LogAdaptor::error(const std::string& content)
{
    logWindow_->push(LogWindow::ERROR, content);
    LOG(ERROR) << content;
}

void LogAdaptor::fatal(const std::string& content)
{
    logWindow_->push(LogWindow::FATAL, content);
    LOG(FATAL) << content;
}

Glog::Glog(const char* arg, const char* log_dir)
{
    if (log_dir != nullptr) {
        FLAGS_log_dir = log_dir;
    }
    google::InitGoogleLogging(arg);
}

Glog::~Glog()
{
    google::ShutdownGoogleLogging();
}

} // namespace gldemo
} // namespace mixi

