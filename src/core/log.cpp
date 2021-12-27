#include "core/log.h"

namespace mixi
{
namespace core
{

void Log::Adaptor::info(const std::string& content)
{
    std::cout << "[INFO] " << content << std::endl;
}

void Log::Adaptor::warning(const std::string& content)
{
    std::cout << "[WARN] " << content << std::endl;
}

void Log::Adaptor::error(const std::string& content)
{
    std::cout << "[ERRO] " << content << std::endl;
}

void Log::Adaptor::fatal(const std::string& content)
{
    std::cout << "[FATA] " << content << std::endl;
}

Log::Adaptor::Ptr Log::Adaptor_ = Adaptor::Ptr(new Adaptor());

void Log::Info(const std::string& content)
{
    Adaptor_->info(content);
}

void Log::Warning(const std::string& content)
{
    Adaptor_->warning(content);
}

void Log::Error(const std::string& content)
{
    Adaptor_->error(content);
}

void Log::Fatal(const std::string& content)
{
    Adaptor_->fatal(content);
}

void Log::SetAdaptor(const Adaptor::Ptr& adaptor)
{
    Adaptor_ = adaptor;
}

} // namespace mixi
} // namespace core
