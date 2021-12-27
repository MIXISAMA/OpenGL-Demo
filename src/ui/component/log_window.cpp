#include "ui/component/log_window.h"

namespace mixi
{
namespace gldemo
{

LogWindow::LogWindow() :
    logLinesLimit(200)
{

}

void LogWindow::render()
{
    ImGui::Begin("Log");

    if (ImGui::Button("Clear")) {
        logs_.clear();
    }

    ImGui::SameLine();

    int linesLimit = logLinesLimit / 100;
    ImGui::PushItemWidth(100);
    ImGui::SliderInt("Lines Limit", &linesLimit, 2, 20, "%d00");
    ImGui::PopItemWidth();
    logLinesLimit = linesLimit * 100;

    ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    ImGuiListClipper clipper;
    clipper.Begin(logs_.size());

    while (clipper.Step()) {
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
            switch (logs_[i].severity)
            {
            case INFO:
                ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "[INFO]");
                break;
            case WARNING:
                ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.3f, 1.0f), "[WARN]");
                break;
            case ERROR:
                ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f), "[ERRO]");
                break;
            case FATAL:
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "[FATA]");
                break;
            }
            ImGui::SameLine();
            ImGui::TextUnformatted(logs_[i].content.c_str());
            if (ImGui::BeginPopupContextItem(std::to_string(i).c_str())) {
                if (ImGui::Button("Copy")) {
                    ImGui::LogToClipboard();
                    ImGui::LogText("%s", logs_[i].content.c_str());
                    ImGui::LogFinish();
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }
        }
    }

    clipper.End();

    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
        ImGui::SetScrollHereY(1.0f);
    }

    ImGui::EndChild();

    ImGui::End();
}

void LogWindow::push(Severity severity, const std::string& log)
{
    logs_.push_back({severity, log});
    while (logs_.size() > logLinesLimit) {
        logs_.pop_front();
    }
}

}
}