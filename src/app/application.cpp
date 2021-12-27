#include "app/application.h"
#include "core/log.h"

namespace mixi
{
namespace gldemo
{

Application::Application(const char* arg) :
    core::Application(),
    // glog_(arg, "./log"),
    glog_(arg)
{
    core::Log::Info("Application Started");
}

Application::~Application()
{
    core::Log::Info("Application Stoped");
}

} // namespace gldemo
} // namespace mixi

