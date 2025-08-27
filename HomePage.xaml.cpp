#include "pch.h"
#include "HomePage.xaml.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3App1C__::implementation
{
	HomePage::HomePage()
	{
		InitializeComponent();
		// 在此处添加对界面元素的访问或其他初始化逻辑
		// Add access to interface elements or other initialization logic here
	}
	//
	//void HomePage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	//{
	//	// 在此处添加对界面元素的访问或其他初始化逻辑
	//	// Add access to interface elements or other initialization logic here
	//}

	//void OnNavigatedFrom(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
	//{
	//	// 在此处添加对界面元素的访问或其他清理逻辑
	//	// Add access to interface elements or other cleanup logic here
	//}

}
