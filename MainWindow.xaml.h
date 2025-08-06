#pragma once

#include "MainWindow.g.h"

namespace winrt::WinUI3App1C__::implementation
{
	struct MainWindow : MainWindowT<MainWindow>
	{
	private:
		int32_t manualIndex = 0;
		int32_t sourceIndex = 0;
		int32_t boundIndex = 0;

		//
		winrt::Windows::Foundation::Collections::IObservableVector<hstring> sourceArray{ winrt::single_threaded_observable_vector<hstring>() };//光标处在当前行或选中目标行时ctrl+D即可快速复制该行

		//
		winrt::Windows::Foundation::Collections::IObservableVector<hstring> boundArray{ winrt::single_threaded_observable_vector<hstring>() };


	public:
		MainWindow();

		// 实现绑定的属性
		winrt::Windows::Foundation::Collections::IObservableVector<hstring> collection();//alt+enter直接快速创建定义
		//winrt::event_token Loaded(winrt::Microsoft::UI::Xaml::RoutedEventHandler const& handler);
		//
		//void Loaded(event_token const& token);


		//手动添加项按钮点击事件
		void addManualListButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		//
		void addSourceItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
		//
		void addBoundListButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

		void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
	};
}

namespace winrt::WinUI3App1C__::factory_implementation
{
	struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
	{
	};
}
