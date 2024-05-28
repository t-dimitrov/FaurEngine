#include "Application.h"

#include <iostream>

namespace Faur
{
    Application::Application()
    {
        std::cout << "Application CTOR" << std::endl;
    }

    Application::~Application()
    {
        std::cout << "Application DTOR" << std::endl;
    }

    void Application::Run()
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Run i=" << i << std::endl;
        }
    }
}

