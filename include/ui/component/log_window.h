#pragma once

#include "pch.h"
#include "core/imgui_window.h"

namespace mixi
{
namespace gldemo
{

class LogWindow : public core::ImguiWindow
{
public:

    using Ptr = std::shared_ptr<LogWindow>;

    enum Severity
    {
        INFO,
        WARNING,
        ERROR,
        FATAL,
    };

    LogWindow();
    ~LogWindow() = default;

    void render() override;

    void push(Severity severity, const std::string& log);

    unsigned int logLinesLimit;

private:

    struct Log
    {
        Severity severity;
        std::string content;
    };

    std::deque<Log> logs_;

};

} // gldemo
} // mixi