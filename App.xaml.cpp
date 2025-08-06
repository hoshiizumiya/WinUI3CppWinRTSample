#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include <winrt/Windows.Graphics.Display.h>
#include <iostream>

#include "BlankWindow.xaml.h"
#include "UserMainPage.xaml.h"

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
		//MainWindow.Activate()
		//window.Content(make<UserMainPage>()); // in this place , we can set the content of the window to a UserMainPage
		window.Activate();
		//make<BlankWindow>().Activate();

	}
}
