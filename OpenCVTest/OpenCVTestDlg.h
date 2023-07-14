
// OpenCVTestDlg.h : 헤더 파일
//
#pragma once

//#include "ReadBarcode.h"
#include <zbar.h>
#include <opencv2\opencv.hpp>
#include <opencv2\barcode\include\opencv2\barcode.hpp>
#include <opencv2\imgproc.hpp>
#include <vector>
#include "afxcmn.h"
#include "afxwin.h"



using namespace cv;

// COpenCVTestDlg 대화 상자
class COpenCVTestDlg : public CDialogEx
{
// 생성입니다.
public:
	COpenCVTestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCVTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Mat m_MatImage;
	Mat m_MatPreprocessingImage;
	afx_msg void OnBnClickedImageLoad();
	afx_msg void OnBnClicked1dBarcodeTest();
	afx_msg void OnBnClicked2dBarcodeTest();
	afx_msg void OnBnClickedFindShapeTest();
	bool NotInList(Point newObject);
	afx_msg void OnBnClickedMarkAreaSave();
	afx_msg void OnBnClickedMarkAreaTest();

	afx_msg void OnBnClickedFindShapeTest2();
	afx_msg void OnBnClickedFindBlobTest();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_ThredMin;
	CSliderCtrl m_ThredMax;
	CEdit m_ThredMinPos;
	CEdit m_ThredMaxPos;
	CButton m_ctrlBinaryCheck;
	CButton m_ctrlBinaryInvCheck;
	CButton m_ctrlMaskChek;
	CButton m_ctrlOTSUCheck;
	CButton m_ctrlToZeroCheck;
	CButton m_ctrlToZeroInvCheck;
	CButton m_ctrlTriangleCheck;
	CButton m_ctrlTruncCheck;
	CButton m_ctrlExternalCheck;
	CButton m_ctrlListCheck;
	CButton m_ctrlCCOMPCheck;
	CButton m_ctrlTREECheck;
	CButton m_ctrlNoneCheck;
	CButton m_ctrlSimpleCheck;
	afx_msg void OnBnClickedThreshBinaryCheck();
	afx_msg void OnBnClickedThreshBinaryInvCheck();
	afx_msg void OnBnClickedThreshMaskCheck();
	afx_msg void OnBnClickedThreshOtsuCheck();
	afx_msg void OnBnClickedThreshTozeroCheck();
	afx_msg void OnBnClickedThreshTozeroInvCheck();
	afx_msg void OnBnClickedThreshTriangleCheck();
	afx_msg void OnBnClickedThreshTruncCheck();
	afx_msg void OnBnClickedContoursRetrExternalCheck();
	afx_msg void OnBnClickedContoursRetrListCheck();
	afx_msg void OnBnClickedContoursRetrCcompCheck();
	afx_msg void OnBnClickedContoursTreeCheck();
	afx_msg void OnBnClickedContoursApproxNoneCheck();
	afx_msg void OnBnClickedContoursApproxSimpleCheck();

	void DisplayThresholdImage(Mat Image);

public:
	int m_nThredCheckBoxValue;
	int m_nContoursCheckBoxValue;
	int m_nCountoursApproxCheckBoxValue;

	int m_nThresValue;
	int m_nMaxValue;
	CEdit m_ctrlMindist;
	CEdit m_ctrlParam1;
	CEdit m_ctrlParam2;
	CEdit m_ctrlThresMin;
	CEdit m_ctrlThresMax;
	CEdit m_ctrlApertureSize;
	CEdit m_ctrlBlobMinThres;
	CEdit m_ctrlBlobMaxThres;
	CEdit m_ctrlBlobMinCircularity;
	CEdit m_ctrlBlobMaxCircularity;
	CEdit m_ctrlBlobMinArea;
	CEdit m_ctrlBlobMaxArea;
	CEdit m_ctrlBlobMinConvexity;
	CEdit m_ctrlBlobMaxConvexity;
	CEdit m_ctrlBlobMinIntiaRatio;
	CEdit m_ctrlBlobMaxIntiaRatio;
	CEdit m_ctrlBlobColor;

	afx_msg void OnBnClickedBlobCircularityUseCheck();
	afx_msg void OnBnClickedBlobAreaUseCheck();
	afx_msg void OnBnClickedBlobConvexityUseCheck();
	afx_msg void OnBnClickedBlobInertiaUseCheck();
	afx_msg void OnBnClickedBlobColorUseCheck();

	bool m_bCircularityUseFlag;
	bool m_bAreaUseFlag;
	bool m_bConvexityUseFlag;
	bool m_bIntiaRatioUseFlag;
	bool m_bBlobColorUseFlag;

	CButton m_ctrlCircularityUseCheck;
	CButton m_ctrlAreaUseCheck;
	CButton m_ctrlConvexityUseCheck;
	CButton m_ctrlInnertiaUseCheck;
	CButton m_ctrlColorUseCheck;
	
	CComboBox m_ctrlPreProcessingCombo;
	CListCtrl m_ctrlPreProcessingList;
	afx_msg void OnBnClickedPreprocessingAddBtn();
	afx_msg void OnBnClickedPreprocessingSaveBtn();
	afx_msg void OnBnClickedPreprocessingDeleteBtn();

	int m_PreProcessingAddCnt;

	afx_msg void OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedPreprocessingItemDnBtn();
	afx_msg void OnBnClickedPreprocessingItemUpBtn();
	afx_msg void OnHdnItemclickList3(NMHDR *pNMHDR, LRESULT *pResult);

	void PreProcessDisplayChange(int nIndex);

	CString m_strListIndex[100];
	CString m_strListName[100];

	CString m_strPreParam1[100];
	CString m_strPreParam2[100];
	CString m_strPreParam3[100];
	CString m_strPreParam4[100];
	CString m_strPreParam5[100]; 
	CString m_strPreParam6[100];

	CStatic m_ctrlPreProcessParam1;
	CStatic m_ctrlPreProcessParam2;
	CStatic m_ctrlPreProcessParam3;
	CStatic m_ctrlPreProcessParam4;
	CStatic m_ctrlPreProcessParam5;
	CStatic m_ctrlPreProcessParam6;

	CComboBox m_ctrlComboParma1;
	CComboBox m_ctrlComboParma2;
	CComboBox m_ctrlComboParma3;
	CComboBox m_ctrlComboParma4;
	CComboBox m_ctrlComboParma5;
	CComboBox m_ctrlComboParma6;

	CEdit m_ctrlEditParam1;
	CEdit m_ctrlEditParam2;
	CEdit m_ctrlEditParam3;
	CEdit m_ctrlEditParam4;
	CEdit m_ctrlEditParam5;
	CEdit m_ctrlEditParam6;
	afx_msg void OnBnClickedPreprocessingTestBtn2();
	Mat PreProcessingImage(Mat OriginImage, CString strIndex, CString strName);

	void PreProcessingDataLoad(int nDevice);

	void LoadModelData(CString strModel);

	void SaveModelData(CString strModel);
	
	void SetParametor_1(int nCnt, CString strData = _T("")) { m_strPreParam1[nCnt] = strData; }
	CString  GetParametor_1(int nCnt) const { return m_strPreParam1[nCnt]; }

	void SetParametor_2(int nCnt, CString strData = _T("")) { m_strPreParam2[nCnt] = strData; }
	CString  GetParametor_2(int nCnt) const { return m_strPreParam2[nCnt]; }

	void SetParametor_3(int nCnt, CString strData = _T("")) { m_strPreParam3[nCnt] = strData; }
	CString  GetParametor_3(int nCnt) const { return m_strPreParam3[nCnt]; }
	
	void SetParametor_4(int nCnt, CString strData = _T("")) { m_strPreParam4[nCnt] = strData; }
	CString  GetParametor_4(int nCnt) const { return m_strPreParam4[nCnt]; }

	void SetParametor_5(int nCnt, CString strData = _T("")) { m_strPreParam5[nCnt] = strData; }
	CString  GetParametor_5(int nCnt) const { return m_strPreParam5[nCnt]; }

	void SetParametor_6(int nCnt, CString strData = _T("")) { m_strPreParam6[nCnt] = strData; }
	CString  GetParametor_6(int nCnt) const { return m_strPreParam6[nCnt]; }
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void CheckParamData();
	afx_msg void OnBnClickedFindHarrisDetect();
	static void mouseCallback(int event, int x, int y, int flags, void * userdata);

};

