#pragma once

#include "pch.h"
#include "app/imgui_window.h"

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

};


}
}


