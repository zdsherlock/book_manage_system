
// book_manmagement_system_v3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cbook_manmagement_system_v3App:
// �йش����ʵ�֣������ book_manmagement_system_v3.cpp
//

class Cbook_manmagement_system_v3App : public CWinApp
{
public:
	Cbook_manmagement_system_v3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cbook_manmagement_system_v3App theApp;