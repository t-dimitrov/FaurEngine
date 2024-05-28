#include <Faur/EntryPoint.h>

class SandboxApplication : public Faur::Application
{
public:
    SandboxApplication()
    {
    }

    virtual ~SandboxApplication()
    {
    }
};

extern Faur::Application* Faur::CreateApplication(int argc, char **argv)
{
    return new SandboxApplication();
}
