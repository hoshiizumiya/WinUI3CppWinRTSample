#include "pch.h"
#include "UserMainPage.xaml.h"
#if __has_include("UserMainPage.g.cpp")
#include "UserMainPage.g.cpp"
#endif
#include "winrt/Windows.UI.Xaml.Interop.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::WinUI3App1C__::implementation
{
	//页面加载事件，参数省略了命名空间前缀
	void UserMainPage::Page_Loaded(IInspectable const& sender, RoutedEventArgs const& e)
	{
		InitializeComponent();
		// 在此处添加对界面元素的访问或其他初始化逻辑，注意要使用 Loaded 方法
	}


}
void winrt::WinUI3App1C__::implementation::UserMainPage::openHomePage()
{
	mainFrame().Navigate(xaml_typename<HomePage>());
}
void winrt::WinUI3App1C__::implementation::UserMainPage::openOtherPage()
{
	mainFrame().Navigate(xaml_typename<OtherPage>());

}
void winrt::WinUI3App1C__::implementation::UserMainPage::openSettingsPage()
{
	mainFrame().Navigate(xaml_typename<SettingsPage>());

}

//内容援引事件
void winrt::WinUI3App1C__::implementation::UserMainPage::NavigationView_ItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
{
	if (args.IsSettingsInvoked())//方法指示 InvokedItem 是否为 Settings 的菜单项
	{
		//打开设置界面 open setting page
		openSettingsPage();
	}
	else
	{
		//为确定哪个页面会被请求，已给每个页面设置独一无二的的 Tag 
		//Tag 在 xaml 中被自动解析并装箱成一个 IInspectable 属性。IInspectable 是所有 WinRT 接口的根属性，使用拆箱函数转化为目标 String 类型字符串
		// 这样设计主要为了语言互操作性 C# 的 object、JS 的 Object、C++ 的 IInspectable 可以相互转换
		//使用 unbox_value<T>()	从 IInspectable 提取具体类型
		hstring tag = unbox_value<hstring>(args.InvokedItemContainer().Tag());
		if (tag == L"home")
			openHomePage();
		else if(tag==L"other")
		{
			openOtherPage();
		}

	}
}

void winrt::WinUI3App1C__::implementation::UserMainPage::mainFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
{
	nav().IsBackEnabled(mainFrame().CanGoBack());
}

void winrt::WinUI3App1C__::implementation::UserMainPage::nav_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
{
	mainFrame().GoBack();
}
