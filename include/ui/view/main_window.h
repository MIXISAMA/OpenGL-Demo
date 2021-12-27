#pragma once

#include "pch.h"
#include "core/imgui_window.h"

#include "ui/component/log_window.h"

namespace mixi
{
namespace gldemo // OpenGL Demo
{

class MainWindow : public app::ImguiWindow
{
public:

    MainWindow();
    ~MainWindow() = default;

    void render() override;

private:

    LogWindow logWindow_;

};


}
}


