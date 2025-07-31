#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
namespace winrt::WinUI3App1C__::implementation
{
	// 修正1: 正确声明和定义 DebugGetCurrentRefCount，参数类型为 IInspectable 的 const 引用
	bool DebugGetCurrentRefCount(winrt::Windows::Foundation::IInspectable const& obj, uint32_t& refCount)
	{
		IUnknown* pUnk = winrt::get_unknown(obj);
		if (pUnk)
		{
			refCount = pUnk->AddRef() - 1;
			pUnk->Release();
			return true;
		}
		return false;
	}

	MainWindow::MainWindow()
	{
		InitializeComponent();

		uint32_t refCount = 0;
		// 修正2: 传递 *this 给 DebugGetCurrentRefCount
		if (DebugGetCurrentRefCount(*this, refCount))
		{
			OutputDebugStringW((L"LeakClassTestLeakWindowUnit constructed with ref count = " + std::to_wstring(refCount)).c_str());
			OutputDebugStringW(L"\r\n");
		}
		//Loaded({ [this](auto&&,auto&&) {auto xamlRoot = this->Content().XamlRoot(); }
		//	   });
		// 修正3: 确保 sourceList 和 sourceArray 已正确定义
		sourceList().ItemsSource(sourceArray);//直接使用代码绑定，访问修改 xaml 界面中的元素，简单直接，无需额外的 IDL 定义和属性访问器
	}

	winrt::Windows::Foundation::Collections::IObservableVector<hstring> MainWindow::collection()
	{
		return boundArray;
	}

	//    myButton().Content(box_value(L"Clicked"));

	void winrt::WinUI3App1C__::implementation::MainWindow::addManualListButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		manualIndex++;
		manualList().Items().Append(box_value(hstring{ L"Item" + to_hstring(manualIndex) }));

		if (manualList().SelectedItem() == nullptr)
		{
			manualList().SelectedIndex(0);
		}
	}
}

//vs 自动添加 xaml 绑定在这里声明，此处我们不再向上移动到命名空间中添加工作量
void winrt::WinUI3App1C__::implementation::MainWindow::addSourceItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	sourceIndex++;
	sourceArray.Append(hstring{ L"sourceItem" + to_hstring(sourceIndex) });
	if (sourceList().SelectedItem() == nullptr)
	{
		sourceList().SelectedIndex(0);
	}
}

void winrt::WinUI3App1C__::implementation::MainWindow::addBoundListButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	boundIndex++;
	boundArray.Append(hstring{ L"sourceItem" + to_hstring(boundIndex) });
	if (boundList().SelectedItem() == nullptr)
	{
		boundList().SelectedIndex(0);
	}
}


void winrt::WinUI3App1C__::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
	Window NewMainWindow = make<MainWindow>();
	//NewMainWindow.Dispatcher();
	NewMainWindow.Activate();
	//AppWindow;
}
