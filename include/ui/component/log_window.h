#include "pch.h"
#include "core/imgui_window.h"

namespace mixi
{
namespace gldemo
{

class LogWindow : public app::ImguiWindow
{
public:

    LogWindow();
    ~LogWindow() = default;

    void render() override;

    void push(const std::string& log);

    unsigned int logLinesLimit;

private:

    std::deque<std::string> logs_;

};

} // gldemo
} // mixi