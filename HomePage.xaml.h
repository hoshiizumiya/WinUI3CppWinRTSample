#pragma once

#include "HomePage.g.h"

namespace winrt::WinUI3App1C__::implementation
{
    struct HomePage : HomePageT<HomePage>
    {
        HomePage();/*
        void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);
		void OnNavigatedFrom(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);*/

    };
}

namespace winrt::WinUI3App1C__::factory_implementation
{
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {
    };
}
