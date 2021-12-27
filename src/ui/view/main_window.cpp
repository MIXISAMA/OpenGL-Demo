#include "ui/view/main_window.h"
#include "core/log.h"
#include "app/log.h"

namespace mixi
{
namespace gldemo // OpenGL Demo
{

using Log = core::Log;

MainWindow::MainWindow() :
    logWindow_(LogWindow::Ptr(new LogWindow()))
{
    Log::SetAdaptor(LogAdaptor::Ptr(new LogAdaptor(logWindow_)));
}

MainWindow::~MainWindow()
{
    Log::SetAdaptor(Log::Adaptor::Ptr(new Log::Adaptor()));
}

void MainWindow::render()
{
    logWindow_->render();
    ImGui::Begin("Demo");
    if (ImGui::Button("Push 99 Lines to Log")) {
        static int cnt = 0;
        for (int i = 0; i < 29; i++) {
            Log::Info("hello world " + std::to_string(cnt++));
        }
        for (int i = 29; i < 49; i++) {
            Log::Warning("hello world " + std::to_string(cnt++));
        }
        for (int i = 49; i < 69; i++) {
            Log::Error("hello world " + std::to_string(cnt++));
        }
        for (int i = 69; i < 99; i++) {
            // Log::Fatal("hello world " + std::to_string(cnt++));
            Log::Info("hello world " + std::to_string(cnt++));
        }
    }
    ImGui::End();
}

} // namespace gldemo
} // namespace mixi
