
// OpenCVTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// COpenCVTestApp:
// �� Ŭ������ ������ ���ؼ��� OpenCVTest.cpp�� �����Ͻʽÿ�.
//

class COpenCVTestApp : public CWinApp
{
public:
	COpenCVTestApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern COpenCVTestApp theApp;