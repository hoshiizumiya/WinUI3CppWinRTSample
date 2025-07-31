#pragma once

#include "BlankWindow.g.h"

namespace winrt::WinUI3App1C__::implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow>
    {
        BlankWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

    };
}

namespace winrt::WinUI3App1C__::factory_implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow, implementation::BlankWindow>
    {
    };
}
