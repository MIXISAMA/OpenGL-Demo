#pragma once

#include "core/application.h"
#include "app/log.h"

namespace mixi
{
namespace gldemo
{

class Application : public core::Application
{
public:

    Application(const char* arg);
    ~Application();

private:

    Glog glog_;

};
    
} // namespace gldemo
} // namespace mixi


