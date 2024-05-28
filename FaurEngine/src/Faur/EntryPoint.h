#pragma once
#include "Core/Application.h"

#include <iostream>

extern Faur::Application* Faur::CreateApplication(int argc, char** argv);

int main(int argc, char** argv)
{
    Faur::Application* app = Faur::CreateApplication(argc, argv);
    app->Run();
    delete app;

    std::cin.get();
    return 0;
}

