#pragma once

#include "OtherPage.g.h"

namespace winrt::WinUI3App1C__::implementation
{
    struct OtherPage : OtherPageT<OtherPage>
    {
        OtherPage();

    };
}

namespace winrt::WinUI3App1C__::factory_implementation
{
    struct OtherPage : OtherPageT<OtherPage, implementation::OtherPage>
    {
    };
}
