#include "ui/view/main_window.h"

namespace mixi
{
namespace gldemo // OpenGL Demo
{

MainWindow::MainWindow()
{

}

void MainWindow::render()
{
    logWindow_.render();
    ImGui::Begin("Demo");
    if (ImGui::Button("Push 99 Lines to Log")) {
        static int cnt = 0;
        for (int i = 0; i < 99; i++) {
            logWindow_.push("hello world " + std::to_string(cnt++));
        }
    }
    ImGui::End();
}

} // namespace gldemo
} // namespace mixi
