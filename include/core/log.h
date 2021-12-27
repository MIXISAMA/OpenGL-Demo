#pragma once

#include "pch.h"

namespace mixi
{
namespace core
{

class Log
{
public:

    class Adaptor
    {
    friend Log;
    public:

        using Ptr = std::shared_ptr<Adaptor>;

    private:

        virtual void info(const std::string& content);
        virtual void warning(const std::string& content);
        virtual void error(const std::string& content);
        virtual void fatal(const std::string& content);

    };

    static void Info(const std::string& content);
    static void Warning(const std::string& content);
    static void Error(const std::string& content);
    static void Fatal(const std::string& content);

    static void SetAdaptor(const Adaptor::Ptr& adaptor);

private:

    static Adaptor::Ptr Adaptor_;

};

}
}