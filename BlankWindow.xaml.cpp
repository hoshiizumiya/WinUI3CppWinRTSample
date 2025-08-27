#include "pch.h"
#include "BlankWindow.xaml.h"
#if __has_include("BlankWindow.g.cpp")
#include "BlankWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3App1C__::implementation
{
	BlankWindow::BlankWindow()
	{
		InitializeComponent();
		// 在此处添加对界面元素的访问或其他初始化逻辑
		// Add access to interface elements or other initialization logic here
	}
}
