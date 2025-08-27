#include "pch.h"
#include "WindowHelper.h"

namespace WinUI3Helpers {

    void ModernWindowSizeManager::Initialize(winrt::Microsoft::UI::Xaml::Window const& window)
    {
        m_window = window;
        
        // 获取 AppWindow（如果可用）
        try {
            m_appWindow = window.AppWindow();
        }
        catch (...) {
            // AppWindow 可能不可用，继续使用 Win32 方法
        }

        // 同时初始化 Win32 管理器处理精确的尺寸限制
        m_win32Manager.Initialize(window);

        // 如果 AppWindow 可用，监听窗口大小变化事件
        if (m_appWindow)
        {
            m_appWindow.Changed([this](auto&&, auto&& args) {
                if (args.DidSizeChange())
                {
                    OnWindowSizeChanged();
                }
            });
        }
    }

    void ModernWindowSizeManager::SetMinSize(int width, int height)
    {
        // 使用 Win32 方法设置精确限制
        m_win32Manager.SetMinSize(width, height);

        // 可选：通过 AppWindow 设置建议尺寸（如果可用）
        if (m_appWindow)
        {
            auto currentSize = m_appWindow.Size();
            if (currentSize.Width < width || currentSize.Height < height)
            {
                winrt::Windows::Graphics::SizeInt32 newSize{};
                int32_t newWidth = currentSize.Width > width ? currentSize.Width : width;
                int32_t newHeight = currentSize.Height > height ? currentSize.Height : height;
                newSize.Width = newWidth;
                newSize.Height = newHeight;
                m_appWindow.Resize(newSize);
            }
        }
    }

    void ModernWindowSizeManager::SetMaxSize(int width, int height)
    {
        m_win32Manager.SetMaxSize(width, height);

        if (m_appWindow)
        {
            auto currentSize = m_appWindow.Size();
            if (currentSize.Width > width || currentSize.Height > height)
            {
                winrt::Windows::Graphics::SizeInt32 newSize{};
                int32_t newWidth = currentSize.Width < width ? currentSize.Width : width;
                int32_t newHeight = currentSize.Height < height ? currentSize.Height : height;
                newSize.Width = newWidth;
                newSize.Height = newHeight;
                m_appWindow.Resize(newSize);
            }
        }
    }

    void ModernWindowSizeManager::OnWindowSizeChanged()
    {
        // 响应窗口大小变化的逻辑
        if (m_appWindow)
        {
            auto size = m_appWindow.Size();
            // 可以在这里添加额外的尺寸验证逻辑
            // 例如：记录日志、触发回调等
        }
    }

} // namespace WinUI3Helpers