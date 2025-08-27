#pragma once

#include "BlankWindow.g.h"

namespace winrt::WinUI3App1C__::implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow>
    {
        BlankWindow();

    };
}

namespace winrt::WinUI3App1C__::factory_implementation
{
    struct BlankWindow : BlankWindowT<BlankWindow, implementation::BlankWindow>
    {
    };
}
