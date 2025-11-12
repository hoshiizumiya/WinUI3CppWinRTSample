#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include <winrt/Windows.Graphics.Display.h>
#include <iostream>

#include "BlankWindow.xaml.h"
#include "UserMainPage.xaml.h"
#include <winrt/Microsoft.UI.Windowing.h>
#include <winrt/Microsoft.UI.Interop.h>
#include <Microsoft.UI.Xaml.Window.h>

// 包含我们的Helper类
#include "Helpers/WindowHelper.h"

using namespace winrt::Windows::Foundation;
using namespace winrt;
using namespace Microsoft::UI::Windowing;
using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3App1C__::implementation
{
	/// <summary>
	/// Initializes the singleton application object.  This is the first line of authored code
	/// executed, and as such is the logical equivalent of main() or WinMain().
	/// </summary>
	App::App()
	{
		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
		UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e) {
			if (IsDebuggerPresent())
			{
				auto errorMessage = e.Message();
				__debugbreak();
			}
						   });
#endif
	}

	// 显式析构函数实现
	App::~App()
	{
		// unique_ptr 会自动清理
	}

	/// <summary>
	/// Invoked when the application is launched.
	/// </summary>
	/// <param name="e">Details about the launch request and process.</param>
	void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
	{
		// 设置屏幕方向
		winrt::Windows::Graphics::Display::DisplayInformation::AutoRotationPreferences(
			winrt::Windows::Graphics::Display::DisplayOrientations::Landscape);
		// 设置 DPI 感知，在 app.manifet 中设置，cpp设置调用 SetProcessDpiAwareness
		//auto uiSettings = winrt::Windows::UI::ViewManagement::UISettings();
		//auto dpi = uiSettings.TextScaleFactor(); // 获取当前 DPI 缩放比例
		//std::wcout << L"Current DPI: " << dpi << std::endl;

		//启动逻辑
		window = make<MainWindow>();
		//window.Content(make<UserMainPage>()); // in this place , we can set the content of the window to a UserMainPage
		
		// 使用WindowHelper设置窗口尺寸限制
		//SetupWindowSizeConstraints();
		
		window.Activate();
		make<BlankWindow>().Activate();
		auto window2 = make<MainWindow>();
		window2.Content(make<UserMainPage>());
		window2.Activate();
	}

	//void App::SetupWindowSizeConstraints()
	//{
	//	try {
	//		// 创建窗口大小管理器
	//		m_windowManager = std::make_unique<WinUI3Helpers::ModernWindowSizeManager>();
	//		
	//		// 初始化管理器
	//		m_windowManager->Initialize(window);
	//		
	//		// 设置最小尺寸为 800x600
	//		m_windowManager->SetMinSize(800, 600);
	//		
	//		// 设置最大尺寸为 1600x1200
	//		m_windowManager->SetMaxSize(1600, 1200);
	//	}
	//	catch (const std::exception& ex) {
	//		// 处理异常
	//		std::wcout << L"Failed to setup window size constraints: " << std::endl;
	//	}
	//	catch (...) {
	//		std::wcout << L"Unknown error while setting up window constraints" << std::endl;
	//	}
	//}
}
