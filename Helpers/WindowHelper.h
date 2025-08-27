#pragma once
#include "pch.h"
#include "Win32WindowHelper.h"
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <Microsoft.UI.Xaml.Window.h>
#include <winrt/Windows.Graphics.h>

namespace WinUI3Helpers {

    class ModernWindowSizeManager
    {
    private:
        winrt::Microsoft::UI::Windowing::AppWindow m_appWindow{ nullptr };
        winrt::Microsoft::UI::Xaml::Window m_window{ nullptr };
        WindowSizeManager m_win32Manager; // 结合 Win32 方法

        // 私有方法
        void OnWindowSizeChanged();

    public:
        // 构造函数
        ModernWindowSizeManager() = default;

        // 禁止拷贝构造和赋值
        ModernWindowSizeManager(const ModernWindowSizeManager&) = delete;
        ModernWindowSizeManager& operator=(const ModernWindowSizeManager&) = delete;

        // 初始化窗口管理器
        void Initialize(winrt::Microsoft::UI::Xaml::Window const& window);

        // 设置最小尺寸
        void SetMinSize(int width, int height);

        // 设置最大尺寸
        void SetMaxSize(int width, int height);

        // 获取当前窗口对象
        winrt::Microsoft::UI::Xaml::Window GetWindow() const { return m_window; }

        // 获取 AppWindow（如果可用）
        winrt::Microsoft::UI::Windowing::AppWindow GetAppWindow() const { return m_appWindow; }

        // 获取底层 Win32 管理器
        WindowSizeManager& GetWin32Manager() { return m_win32Manager; }
    };

} // namespace WinUI3Helpers