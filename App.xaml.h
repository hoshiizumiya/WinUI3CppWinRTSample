#pragma once

#include "App.xaml.g.h"
namespace winrt::WinUI3App1C__::implementation
{
    struct App : AppT<App>
    {
        App();
        ~App(); // 显式声明析构函数

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
        //std::unique_ptr<WinUI3Helpers::ModernWindowSizeManager> m_windowManager;
        
        // 私有方法
        //void SetupWindowSizeConstraints();
    };
}
