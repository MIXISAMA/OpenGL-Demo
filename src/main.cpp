#include "app/application.h"
#include "ui/view/main_window.h"

int main(int argc, const char** argv)
{
    mixi::gldemo::Application app(argv[0]);
    mixi::gldemo::MainWindow window;
    app.loop(&window);
    return 0;
}
