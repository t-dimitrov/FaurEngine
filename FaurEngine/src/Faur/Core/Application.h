#pragma once

namespace Faur
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:

    };

    // To be implemented by the client
    Application* CreateApplication(int argc, char** argv);
}

