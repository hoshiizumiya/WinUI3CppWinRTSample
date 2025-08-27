#include "pch.h"
#include "Win32WindowHelper.h"
#include <windows.h>
#include <windowsx.h>

namespace WinUI3Helpers {

    HWND WindowSizeManager::GetWindowHandle(winrt::Microsoft::UI::Xaml::Window const& window)
    {
        auto windowNative = window.try_as<::IWindowNative>();
        if (windowNative)
        {
            HWND hwnd = nullptr;
            windowNative->get_WindowHandle(&hwnd);
            return hwnd;
        }
        return nullptr;
    }

    void WindowSizeManager::Initialize(winrt::Microsoft::UI::Xaml::Window const& window)
    {
        m_hwnd = GetWindowHandle(window);
        if (m_hwnd)
        {
            // 子类化窗口过程以处理 WM_GETMINMAXINFO
            m_originalWndProc = reinterpret_cast<WNDPROC>(
                SetWindowLongPtr(m_hwnd, GWLP_WNDPROC,
                                 reinterpret_cast<LONG_PTR>(WindowProc)));

            // 存储 this 指针以在静态函数中使用
            SetWindowLongPtr(m_hwnd, GWLP_USERDATA,
                             reinterpret_cast<LONG_PTR>(this));
        }
    }

    void WindowSizeManager::SetMinSize(int width, int height)
    {
        m_minSize = { width, height };
        if (m_hwnd)
        {
            // 立即检查当前窗口大小
            RECT rect;
            GetWindowRect(m_hwnd, &rect);
            int currentWidth = rect.right - rect.left;
            int currentHeight = rect.bottom - rect.top;

            if (currentWidth < width || currentHeight < height)
            {
                SetWindowPos(m_hwnd, nullptr, 0, 0,
                             max(currentWidth, width), max(currentHeight, height),
                             SWP_NOMOVE | SWP_NOZORDER);
            }
        }
    }

    void WindowSizeManager::SetMaxSize(int width, int height)
    {
        m_maxSize = { width, height };
        if (m_hwnd)
        {
            // 立即检查当前窗口大小
            RECT rect;
            GetWindowRect(m_hwnd, &rect);
            int currentWidth = rect.right - rect.left;
            int currentHeight = rect.bottom - rect.top;

            if (currentWidth > width || currentHeight > height)
            {
                SetWindowPos(m_hwnd, nullptr, 0, 0,
                             min(currentWidth, width), min(currentHeight, height),
                             SWP_NOMOVE | SWP_NOZORDER);
            }
        }
    }

    WindowSizeManager::~WindowSizeManager()
    {
        if (m_hwnd && m_originalWndProc)
        {
            SetWindowLongPtr(m_hwnd, GWLP_WNDPROC,
                             reinterpret_cast<LONG_PTR>(m_originalWndProc));
        }
    }

    LRESULT CALLBACK WindowSizeManager::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        auto* pThis = reinterpret_cast<WindowSizeManager*>(
            GetWindowLongPtr(hwnd, GWLP_USERDATA));

        if (pThis)
        {
            switch (uMsg)
            {
            case WM_GETMINMAXINFO:
            {
                MINMAXINFO* pMinMaxInfo = reinterpret_cast<MINMAXINFO*>(lParam);
                pMinMaxInfo->ptMinTrackSize.x = pThis->m_minSize.cx;
                pMinMaxInfo->ptMinTrackSize.y = pThis->m_minSize.cy;
                pMinMaxInfo->ptMaxTrackSize.x = pThis->m_maxSize.cx;
                pMinMaxInfo->ptMaxTrackSize.y = pThis->m_maxSize.cy;
                return 0;
            }
            }

            return CallWindowProc(pThis->m_originalWndProc, hwnd, uMsg, wParam, lParam);
        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

} // namespace WinUI3Helpers