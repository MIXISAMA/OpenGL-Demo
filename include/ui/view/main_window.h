#pragma once

#include "pch.h"
#include "core/imgui_window.h"

#include "ui/component/log_window.h"

namespace mixi
{
namespace gldemo // OpenGL Demo
{

class MainWindow : public core::ImguiWindow
{
public:

    MainWindow();
    ~MainWindow();

    void render() override;

private:

    LogWindow::Ptr logWindow_;

};


}
}


