#pragma once
#include "Core/Application.h"
#include "Core/Core.h"

extern Faur::Application* Faur::CreateApplication(int argc, char** argv);

int main(int argc, char** argv)
{
    Faur::Logger::Init();

    Faur::Application* app = Faur::CreateApplication(argc, argv);
    FAUR_CORE_ASSERT(app, "Faur::CreateApplication(int, char**) returns nullptr");
    app->Run();
    delete app;

    Faur::Logger::Shutdown();

    return 0;
}
