#include <iostream>
//#include <Windows.h>
#include <afxwin.h>
#include <ShlObj.h>

using namespace std;


void test()
{
	int* p = new int[10];
	cout << p + 10 << endl;
	p[10] = 396;
	cout << p[10] << endl;
}

void test01()
{
	class Cat
	{
	public:
		double x;
		double y;
		double z;
		int a[5];
	};

	auto* p = new Cat[10];
	p[10].x = 0;
	p[10].y = 1;
	p[10].z = 2;
	cout << p[10].x << "," << p[10].y << "," << p[10].z << endl;

	delete[]p;
}

int CALLBACK callback(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
		break;
	default:
		break;
	}

	return 0;
}

void test02()
{
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(bi));
	
	TCHAR str[MAX_PATH] = _T("D:\\code_git\\my_code\\demo");
	bi.lParam = (LPARAM)&str;
	bi.lpszTitle = _T("jjjjjjj");
	bi.lpfn = callback;

	SHBrowseForFolder(&bi);
}

int main()
{
	//auto x = 100;
	//cout << __cplusplus << "  " << 100 << endl;

	//test();
	//test01();
	test02();

	return 0;
}