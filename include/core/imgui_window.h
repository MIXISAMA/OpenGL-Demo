#pragma once

namespace mixi
{
namespace core
{

class ImguiWindow
{
public:

    using Ptr = std::shared_ptr<ImguiWindow>;

    virtual ~ImguiWindow() = default;

    virtual void render() = 0;

};



} // namespace core
} // namespace mixi

