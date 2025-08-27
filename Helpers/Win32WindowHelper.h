#pragma once
#include "pch.h"
#include <windows.h>
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <Microsoft.UI.Xaml.Window.h>
#include <winrt/Windows.Foundation.h>

namespace WinUI3Helpers {

    class WindowSizeManager
    {
    private:
        HWND m_hwnd = nullptr;
        SIZE m_minSize = { 300, 200 };
        SIZE m_maxSize = { 1920, 1080 };
        WNDPROC m_originalWndProc = nullptr;

        // 静态窗口过程
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    public:
        // 构造函数和析构函数
        WindowSizeManager() = default;
        ~WindowSizeManager();

        // 禁止拷贝构造和赋值
        WindowSizeManager(const WindowSizeManager&) = delete;
        WindowSizeManager& operator=(const WindowSizeManager&) = delete;

        // 方法1：通过 IWindowNative 接口获取 HWND
        HWND GetWindowHandle(winrt::Microsoft::UI::Xaml::Window const& window);

        // 初始化窗口管理器
        void Initialize(winrt::Microsoft::UI::Xaml::Window const& window);

        // 设置最小尺寸
        void SetMinSize(int width, int height);

        // 设置最大尺寸
        void SetMaxSize(int width, int height);

        // 获取当前窗口句柄
        HWND GetHwnd() const { return m_hwnd; }
    };

} // namespace WinUI3Helpers