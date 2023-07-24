
// OpenCVTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "OpenCVTest.h"
#include "OpenCVTestDlg.h"
#include "afxdialogex.h"
#include "..\ProfileDataIF.h"
#include <iostream>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace cv;
using namespace zbar;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

bool m_bDraggingFlag = false;
int m_nPosX, m_nPosY;
int m_nSecondPosX, m_nSecondPosY;
Mat g_MatImage;

vector<Point> detectedObjects;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenCVTestDlg ��ȭ ����



COpenCVTestDlg::COpenCVTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPENCVTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCVTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_THRESHOLD_MIN, m_ThredMin);
	DDX_Control(pDX, IDC_SLIDER_THRESHOLD_MAX, m_ThredMax);
	DDX_Control(pDX, IDC_EDIT_THRED_MIN, m_ThredMinPos);
	DDX_Control(pDX, IDC_EDIT_THRED_MAX, m_ThredMaxPos);
	DDX_Control(pDX, IDC_THRESH_BINARY_CHECK, m_ctrlBinaryCheck);
	DDX_Control(pDX, IDC_THRESH_BINARY_INV_CHECK, m_ctrlBinaryInvCheck);
	DDX_Control(pDX, IDC_THRESH_MASK_CHECK, m_ctrlMaskChek);
	DDX_Control(pDX, IDC_THRESH_OTSU_CHECK, m_ctrlOTSUCheck);
	DDX_Control(pDX, IDC_THRESH_TOZERO_CHECK, m_ctrlToZeroCheck);
	DDX_Control(pDX, IDC_THRESH_TOZERO_INV_CHECK, m_ctrlToZeroInvCheck);
	DDX_Control(pDX, IDC_THRESH_TRIANGLE_CHECK, m_ctrlTriangleCheck);
	DDX_Control(pDX, IDC_THRESH_TRUNC_CHECK, m_ctrlTruncCheck);
	DDX_Control(pDX, IDC_CONTOURS_RETR_EXTERNAL_CHECK, m_ctrlExternalCheck);
	DDX_Control(pDX, IDC_CONTOURS_RETR_LIST_CHECK, m_ctrlListCheck);
	DDX_Control(pDX, IDC_CONTOURS_RETR_CCOMP_CHECK, m_ctrlCCOMPCheck);
	DDX_Control(pDX, IDC_CONTOURS_TREE_CHECK, m_ctrlTREECheck);
	DDX_Control(pDX, IDC_CONTOURS_APPROX_NONE_CHECK, m_ctrlNoneCheck);
	DDX_Control(pDX, IDC_CONTOURS_APPROX_SIMPLE_CHECK, m_ctrlSimpleCheck);
	DDX_Control(pDX, IDC_CIRCLE_MIN_DIST, m_ctrlMindist);
	DDX_Control(pDX, IDC_CIRCLE_PARAM1, m_ctrlParam1);
	DDX_Control(pDX, IDC_CIRCLE_PARAM2, m_ctrlParam2);
	DDX_Control(pDX, IDC_CANNY_THRES_MIN, m_ctrlThresMin);
	DDX_Control(pDX, IDC_CANNY_THRES_MAX, m_ctrlThresMax);
	DDX_Control(pDX, IDC_CANNY_APERTURE_SIZE, m_ctrlApertureSize);
	DDX_Control(pDX, IDC_BLOB_MIN_THRESHOLD, m_ctrlBlobMinThres);
	DDX_Control(pDX, IDC_BLOB_MAX_THRESHOLD, m_ctrlBlobMaxThres);
	DDX_Control(pDX, IDC_BLOB_MIN_CIRCULARITY, m_ctrlBlobMinCircularity);
	DDX_Control(pDX, IDC_BLOB_MAX_CIRCULARITY, m_ctrlBlobMaxCircularity);
	DDX_Control(pDX, IDC_BLOB_MIN_AREA, m_ctrlBlobMinArea);
	DDX_Control(pDX, IDC_BLOB_MAX_AREA, m_ctrlBlobMaxArea);
	DDX_Control(pDX, IDC_BLOB_MIN_CONVEXITY, m_ctrlBlobMinConvexity);
	DDX_Control(pDX, IDC_BLOB_MAX_CONVEXITY, m_ctrlBlobMaxConvexity);
	DDX_Control(pDX, IDC_BLOB_MIN_INERTIARATIO, m_ctrlBlobMinIntiaRatio);
	DDX_Control(pDX, IDC_BLOB_MAX_INERTIARATIO, m_ctrlBlobMaxIntiaRatio);
	DDX_Control(pDX, IDC_BLOB_CIRCULARITY_USE_CHECK, m_ctrlCircularityUseCheck);
	DDX_Control(pDX, IDC_BLOB_AREA_USE_CHECK, m_ctrlAreaUseCheck);
	DDX_Control(pDX, IDC_BLOB_CONVEXITY_USE_CHECK, m_ctrlConvexityUseCheck);
	DDX_Control(pDX, IDC_BLOB_INERTIA_USE_CHECK, m_ctrlInnertiaUseCheck);
	DDX_Control(pDX, IDC_BLOB_COLOR, m_ctrlBlobColor);
	DDX_Control(pDX, IDC_BLOB_COLOR_USE_CHECK, m_ctrlColorUseCheck);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlPreProcessingCombo);

	DDX_Control(pDX, IDC_LIST3, m_ctrlPreProcessingList);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM1, m_ctrlPreProcessParam1);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM2, m_ctrlPreProcessParam2);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM3, m_ctrlPreProcessParam3);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM4, m_ctrlPreProcessParam4);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM5, m_ctrlPreProcessParam5);
	DDX_Control(pDX, IDC_STATIC_PREPROCESSING_PARAM6, m_ctrlPreProcessParam6);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM1, m_ctrlComboParma1);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM2, m_ctrlComboParma2);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM3, m_ctrlComboParma3);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM4, m_ctrlComboParma4);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM5, m_ctrlComboParma5);
	DDX_Control(pDX, IDC_COMBO_PREPROCESSING_PARAM6, m_ctrlComboParma6);	

	DDX_Control(pDX, IDC_PREPROCESSING_PARAM1, m_ctrlEditParam1);
	DDX_Control(pDX, IDC_PREPROCESSING_PARAM2, m_ctrlEditParam2);
	DDX_Control(pDX, IDC_PREPROCESSING_PARAM3, m_ctrlEditParam3);
	DDX_Control(pDX, IDC_PREPROCESSING_PARAM4, m_ctrlEditParam4);
	DDX_Control(pDX, IDC_PREPROCESSING_PARAM5, m_ctrlEditParam5);
	DDX_Control(pDX, IDC_PREPROCESSING_PARAM6, m_ctrlEditParam6);

}

BEGIN_MESSAGE_MAP(COpenCVTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IMAGE_LOAD, &COpenCVTestDlg::OnBnClickedImageLoad)
	ON_BN_CLICKED(IDC_1D_BARCODE_TEST, &COpenCVTestDlg::OnBnClicked1dBarcodeTest)
	ON_BN_CLICKED(IDC_2D_BARCODE_TEST, &COpenCVTestDlg::OnBnClicked2dBarcodeTest)
	ON_BN_CLICKED(IDC_FIND_SHAPE_TEST, &COpenCVTestDlg::OnBnClickedFindShapeTest)
	ON_BN_CLICKED(IDC_MARK_AREA_SAVE, &COpenCVTestDlg::OnBnClickedMarkAreaSave)
	ON_BN_CLICKED(IDC_MARK_AREA_TEST, &COpenCVTestDlg::OnBnClickedMarkAreaTest)
	ON_BN_CLICKED(IDC_FIND_SHAPE_TEST2, &COpenCVTestDlg::OnBnClickedFindShapeTest2)
	ON_BN_CLICKED(IDC_FIND_BLOB_TEST, &COpenCVTestDlg::OnBnClickedFindBlobTest)
	ON_WM_HSCROLL()



	ON_BN_CLICKED(IDC_THRESH_BINARY_CHECK, &COpenCVTestDlg::OnBnClickedThreshBinaryCheck)
	ON_BN_CLICKED(IDC_THRESH_BINARY_INV_CHECK, &COpenCVTestDlg::OnBnClickedThreshBinaryInvCheck)
	ON_BN_CLICKED(IDC_THRESH_MASK_CHECK, &COpenCVTestDlg::OnBnClickedThreshMaskCheck)
	ON_BN_CLICKED(IDC_THRESH_OTSU_CHECK, &COpenCVTestDlg::OnBnClickedThreshOtsuCheck)
	ON_BN_CLICKED(IDC_THRESH_TOZERO_CHECK, &COpenCVTestDlg::OnBnClickedThreshTozeroCheck)
	ON_BN_CLICKED(IDC_THRESH_TOZERO_INV_CHECK, &COpenCVTestDlg::OnBnClickedThreshTozeroInvCheck)
	ON_BN_CLICKED(IDC_THRESH_TRIANGLE_CHECK, &COpenCVTestDlg::OnBnClickedThreshTriangleCheck)
	ON_BN_CLICKED(IDC_THRESH_TRUNC_CHECK, &COpenCVTestDlg::OnBnClickedThreshTruncCheck)
	ON_BN_CLICKED(IDC_CONTOURS_RETR_EXTERNAL_CHECK, &COpenCVTestDlg::OnBnClickedContoursRetrExternalCheck)
	ON_BN_CLICKED(IDC_CONTOURS_RETR_LIST_CHECK, &COpenCVTestDlg::OnBnClickedContoursRetrListCheck)
	ON_BN_CLICKED(IDC_CONTOURS_RETR_CCOMP_CHECK, &COpenCVTestDlg::OnBnClickedContoursRetrCcompCheck)
	ON_BN_CLICKED(IDC_CONTOURS_TREE_CHECK, &COpenCVTestDlg::OnBnClickedContoursTreeCheck)
	ON_BN_CLICKED(IDC_CONTOURS_APPROX_NONE_CHECK, &COpenCVTestDlg::OnBnClickedContoursApproxNoneCheck)
	ON_BN_CLICKED(IDC_CONTOURS_APPROX_SIMPLE_CHECK, &COpenCVTestDlg::OnBnClickedContoursApproxSimpleCheck)
	ON_BN_CLICKED(IDC_BLOB_CIRCULARITY_USE_CHECK, &COpenCVTestDlg::OnBnClickedBlobCircularityUseCheck)
	ON_BN_CLICKED(IDC_BLOB_AREA_USE_CHECK, &COpenCVTestDlg::OnBnClickedBlobAreaUseCheck)
	ON_BN_CLICKED(IDC_BLOB_CONVEXITY_USE_CHECK, &COpenCVTestDlg::OnBnClickedBlobConvexityUseCheck)
	ON_BN_CLICKED(IDC_BLOB_INERTIA_USE_CHECK, &COpenCVTestDlg::OnBnClickedBlobInertiaUseCheck)
	ON_BN_CLICKED(IDC_BLOB_COLOR_USE_CHECK, &COpenCVTestDlg::OnBnClickedBlobColorUseCheck)
	ON_BN_CLICKED(IDC_PREPROCESSING_ADD_BTN, &COpenCVTestDlg::OnBnClickedPreprocessingAddBtn)
	ON_BN_CLICKED(IDC_PREPROCESSING_SAVE_BTN, &COpenCVTestDlg::OnBnClickedPreprocessingSaveBtn)
	ON_BN_CLICKED(IDC_PREPROCESSING_DELETE_BTN, &COpenCVTestDlg::OnBnClickedPreprocessingDeleteBtn)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST3, &COpenCVTestDlg::OnNMDblclkList3)
	ON_BN_CLICKED(IDC_PREPROCESSING_ITEM_DN_BTN, &COpenCVTestDlg::OnBnClickedPreprocessingItemDnBtn)
	ON_BN_CLICKED(IDC_PREPROCESSING_ITEM_UP_BTN, &COpenCVTestDlg::OnBnClickedPreprocessingItemUpBtn)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &COpenCVTestDlg::OnHdnItemclickList3)
	ON_BN_CLICKED(IDC_PREPROCESSING_TEST_BTN2, &COpenCVTestDlg::OnBnClickedPreprocessingTestBtn2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_FIND_HARRIS_DETECT, &COpenCVTestDlg::OnBnClickedFindHarrisDetect)
	ON_BN_CLICKED(IDC_BUTTON1, &COpenCVTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// COpenCVTestDlg �޽��� ó����

BOOL COpenCVTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ctrlPreProcessingList.InsertColumn(0, L"����", LVCFMT_LEFT, 70, -1);
	m_ctrlPreProcessingList.InsertColumn(1, L"�Լ���", LVCFMT_LEFT, 100, -1);
	m_ctrlPreProcessingList.SetExtendedStyle(LVS_EX_GRIDLINES);
	m_ctrlPreProcessingList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_ctrlPreProcessParam1.ShowWindow(FALSE);
	m_ctrlPreProcessParam2.ShowWindow(FALSE);
	m_ctrlPreProcessParam3.ShowWindow(FALSE);
	m_ctrlPreProcessParam4.ShowWindow(FALSE);
	m_ctrlPreProcessParam5.ShowWindow(FALSE);
	m_ctrlPreProcessParam6.ShowWindow(FALSE);

	m_ctrlComboParma1.ShowWindow(FALSE);
	m_ctrlComboParma2.ShowWindow(FALSE);
	m_ctrlComboParma3.ShowWindow(FALSE);
	m_ctrlComboParma4.ShowWindow(FALSE);
	m_ctrlComboParma5.ShowWindow(FALSE);
	m_ctrlComboParma6.ShowWindow(FALSE);

	m_ctrlEditParam1.ShowWindow(FALSE);
	m_ctrlEditParam2.ShowWindow(FALSE);
	m_ctrlEditParam3.ShowWindow(FALSE);
	m_ctrlEditParam4.ShowWindow(FALSE);
	m_ctrlEditParam5.ShowWindow(FALSE);
	m_ctrlEditParam6.ShowWindow(FALSE);

	m_ctrlComboParma1.ResetContent();
	m_ctrlComboParma2.ResetContent();
	m_ctrlComboParma3.ResetContent();
	m_ctrlComboParma4.ResetContent();
	m_ctrlComboParma5.ResetContent();
	m_ctrlComboParma6.ResetContent();

	m_ThredMin.SetRange(0, 255);
	m_ThredMax.SetRange(0, 255);
	m_ThredMin.SetPos(0);
	m_ThredMax.SetPos(255);
	m_ThredMinPos.SetWindowTextW(_T("0"));
	m_ThredMaxPos.SetWindowTextW(_T("255"));

	m_ctrlBinaryCheck.SetCheck(true);
	m_ctrlExternalCheck.SetCheck(true);
	m_ctrlNoneCheck.SetCheck(true);

	m_ctrlThresMin.SetWindowTextW(_T("0"));
	m_ctrlThresMax.SetWindowTextW(_T("0"));
	m_ctrlApertureSize.SetWindowTextW(_T("0"));
	m_ctrlMindist.SetWindowTextW(_T("0"));
	m_ctrlParam1.SetWindowTextW(_T("0"));
	m_ctrlParam2.SetWindowTextW(_T("0"));

	m_ctrlThresMin.SetWindowTextW(_T("0"));
	m_ctrlThresMax.SetWindowTextW(_T("0"));
	m_ctrlApertureSize.SetWindowTextW(_T("0"));
	m_ctrlBlobMinThres.SetWindowTextW(_T("0"));
	m_ctrlBlobMaxThres.SetWindowTextW(_T("0"));
	m_ctrlBlobMinCircularity.SetWindowTextW(_T("0"));
	m_ctrlBlobMaxCircularity.SetWindowTextW(_T("0"));
	m_ctrlBlobMinArea.SetWindowTextW(_T("0"));
	m_ctrlBlobMaxArea.SetWindowTextW(_T("0"));
	m_ctrlBlobMinConvexity.SetWindowTextW(_T("0"));
	m_ctrlBlobMaxConvexity.SetWindowTextW(_T("0"));
	m_ctrlBlobMinIntiaRatio.SetWindowTextW(_T("0"));
	m_ctrlBlobMaxIntiaRatio.SetWindowTextW(_T("0"));
	m_ctrlBlobColor.SetWindowTextW(_T("0"));

	m_nThredCheckBoxValue = 0;
	m_nContoursCheckBoxValue = 0;
	m_nCountoursApproxCheckBoxValue = 1;
	m_nThresValue = 0;
	m_nMaxValue = 255;
	m_bCircularityUseFlag = false;
	m_bAreaUseFlag = false;
	m_bConvexityUseFlag = false;
	m_bIntiaRatioUseFlag = false;
	m_bBlobColorUseFlag = false;
	m_PreProcessingAddCnt = 1;

	
	SetTimer(100, 1000, NULL);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void COpenCVTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void COpenCVTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR COpenCVTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenCVTestDlg::OnBnClickedImageLoad()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strCFilePath;
	String strFilePath;
	Mat ReSizeImage;
	CRect rect;
	HWND hwnd = AfxGetMainWnd()->m_hWnd;

	SetTimer(1, 100, NULL);


	static TCHAR BASED_CODE szFilter[] = _T("�̹��� ����(*.BMP, *.GIF, *.JPG) | *.BMP;*.GIF;*.JPG;*.bmp;*.jpg;*.gif |�������(*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*.jpg"), _T("image"), OFN_HIDEREADONLY, szFilter);

	dlg.DoModal();

	strCFilePath = dlg.GetPathName();
	strFilePath = String(CT2CA(strCFilePath));

	m_MatImage = imread(strFilePath, IMREAD_ANYCOLOR);
	if (m_MatImage.empty())
	{
		return;
	}

	//resize(m_MatImage, ReSizeImage, Size(1024, 768));
	resize(m_MatImage, m_MatImage, Size(1024, 768));
	imshow("ImageViewer", m_MatImage);
	setMouseCallback("ImageViewer", mouseCallback); //23.06.08 gmjo ���콺 �̺�Ʈ ó��.

	m_MatImage = m_MatImage;
	m_MatPreprocessingImage = m_MatImage; 
	g_MatImage = m_MatImage;

}


void COpenCVTestDlg::OnBnClicked1dBarcodeTest()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//Ptr<barcode::BarcodeDetector> bardet = makePtr<barcode::BarcodeDetector>();
	//vector<string> decoded_info;
	//vector<barcode::BarcodeType> decoded_format;
	//bool ok = bardet->detectAndDecode(m_MatImage, decoded_info, decoded_format, image);
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	// obtain image data  
	char file[256];
	cin >> file;
	Mat img = m_MatPreprocessingImage;//imread(file, 0);
	Mat imgout;
	cvtColor(img, img, COLOR_BGR2GRAY);
	cvtColor(img, imgout, COLOR_GRAY2BGR);
	//imgout = img;
//	resize(imgout, imgout, Size(320, 232));
	int width = img.cols;
	int height = img.rows;
	uchar *raw = (uchar *)img.data;
	// wrap image data 
	// Video Capture API
	// Y800 = 8bit Gray Image
	// RGB = RGB������ �̹���. �Ϲ������� �� �ΰ����� ����.
	Image image(width, height, "Y800", raw, width * height);
	// scan the image for barcodes  
	int n = scanner.scan(image);
	// extract results  
	for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) 
	{
		vector<Point> vp;
		// do something useful with results  
		//cout << "decoded " << symbol->get_type_name()
		//	<< " symbol "" << symbol->get_data() << '"' <<" "<< endl;  
			int n = symbol->get_location_size();
		for (int i = 0; i<n; i++)
		{
			vp.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
		}
		RotatedRect r = minAreaRect(vp);
		Point2f pts[4];
		r.points(pts);
		for (int i = 0; i<4; i++)
		{
			line(imgout, pts[i], pts[(i + 1) % 4], Scalar(255, 0, 0), 3);
		}
		putText(imgout, symbol->get_data(), Point(30, 30), 2, 1.2, Scalar(0, 255, 0));
	}
	// ������ String Data�� �������ִ� Stirng ���� �߰� �ʿ�.

	imshow("ImageViewer", imgout);

	// clean up  
	image.set_data(NULL, 0);
	waitKey();
}			

void COpenCVTestDlg::OnBnClicked2dBarcodeTest() //23.06.19 gmjo QRCodeDetector -> Zbar �������� ���Ͽ� �̻��.
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	QRCodeDetector Detector;
	vector<Point> pt;
	Mat DetectImage;

	DetectImage = m_MatPreprocessingImage.clone();

	if (Detector.detect(DetectImage, pt))
	{
		polylines(DetectImage, pt, true, Scalar(0, 255, 255), 2);

		String info = Detector.decode(DetectImage, pt);
		if (!info.empty())
		{
			polylines(DetectImage, pt, true, Scalar(0, 255, 255), 2);
			putText(DetectImage, info, Point(30,30), 2, 1.2, Scalar(0, 255, 0));
		}
	}
	imshow("ImageViewer", DetectImage);
	waitKey();
}


void COpenCVTestDlg::OnBnClickedMarkAreaSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	Mat Image = imread("D:\\VisionData\\CrobImage.bmp");
	CString strFileTemp;
	String strFileName;
	double angle = 0;
	Mat rotationMatrix;
	Mat roTatedImage;
	
	Point2f center(Image.cols / 2.0, Image.rows / 2.0);
	for (int i = 0; i < 365; i++)
	{
		angle = 0;
		angle = angle + i;
		rotationMatrix = getRotationMatrix2D(center, angle, 1.0);	
		warpAffine(Image, roTatedImage, rotationMatrix, Image.size());
		strFileTemp.Format(_T("D:\\VisionData\\CrobImage%d.bmp"), i);
		strFileName = String(CT2CA(strFileTemp));
		imwrite(strFileName, roTatedImage);
	}
}


void COpenCVTestDlg::OnBnClickedMarkAreaTest()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Mat OriginImage = m_MatPreprocessingImage.clone();
	Mat TempImage;
	Mat ProcessingImage;
	double minVal, maxVal;
	Point minLoc, maxLoc;
	Point matchLoc;

	TempImage = imread("D:\\VisionData\\CrobImage.bmp");
	/*
	0: TM_SQDIFF
	1: TM_SQDIFF_NORMED
	2: TM_CCORR
	3: TM_CCORR_NORMED
	4: TM_CCOEFF
	5: TM_CCOEFF_NORMED";
	*/
	//cvtColor(OriginImage, OriginImage, COLOR_GRAY2BGR);
	matchTemplate(OriginImage, TempImage, ProcessingImage, TM_CCOEFF_NORMED);


	//int count = 0;
	//for (int x = 0; x < ProcessingImage.cols; x++)
	//{
	//	for (int y = 0; y < ProcessingImage.rows; y++)
	//	{
	//		if (ProcessingImage.at<float>(y, x) > 0.9 && NotInList(Point(x, y)))
	//		{
	//			detectedObjects.push_back(Point(x, y));
	//			rectangle(OriginImage, Point(x, y), Point(x + TempImage.cols, y + TempImage.rows),
	//				Scalar(0, 0, 255), 1);
	//			count++;
	//		}
	//
	//	}
	//}
	//imshow("ImageViewer", OriginImage);
	//imshow("templ", TempImage);
	//imshow("result", ProcessingImage);
	//return;

	normalize(ProcessingImage, ProcessingImage, 0, 1, NORM_MINMAX, -1, Mat());
	minMaxLoc(ProcessingImage, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	matchLoc = maxLoc;
	rectangle(OriginImage, matchLoc, Point(matchLoc.x + TempImage.cols, matchLoc.y + TempImage.rows), Scalar(0, 0, 255), 1);

	circle(ProcessingImage, matchLoc, 3, Scalar(0, 0, 255), 1);

	imshow("ImageViewer", OriginImage);
	imshow("templ", TempImage);
	imshow("result", ProcessingImage);
}

bool COpenCVTestDlg::NotInList(Point newObject)
{
	

	for (int i = 0; i < detectedObjects.size(); i++)
	{
		float a = detectedObjects[i].x - newObject.x;
		float b = detectedObjects[i].y - newObject.y;

		if (sqrt(a*a + b*b) < 5.0) return false;
	}

	return true;
}

void COpenCVTestDlg::OnBnClickedFindShapeTest() //���� ã��.
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Mat ImageBinary;
	Mat MorphologyImage;
	Mat OldImage = m_MatPreprocessingImage.clone();
	CString cstrCirclePos;
	String strCirclePos;
	int x, y;
	resize(OldImage, OldImage, Size(1024, 768));

	CString strThresMin, strThresMax, strApertureSize;
	int nThresMin, nThresMax, nApertureSize;
	m_ctrlThresMin.GetWindowTextW(strThresMin);
	m_ctrlThresMax.GetWindowTextW(strThresMax);
	m_ctrlApertureSize.GetWindowTextW(strApertureSize);
	nThresMin = _ttoi(strThresMin);
	nThresMax = _ttoi(strThresMax);
	nApertureSize = _ttoi(strApertureSize);

	CString strMindist, strParam1, strParam2;
	int nMindist, nParam1, nParam2;
	m_ctrlMindist.GetWindowTextW(strMindist);
	m_ctrlParam1.GetWindowTextW(strParam1);
	m_ctrlParam2.GetWindowTextW(strParam2);
	nMindist = _ttoi(strMindist);
	nParam1 = _ttoi(strParam1);
	nParam2 = _ttoi(strParam2);

	
	vector<Vec3f> circles;

	try
	{	//			 image, circles, method, dp, minDist, param1 = 100, param2 = 100, minRadius = 0, maxRadius = 0
		HoughCircles(OldImage, circles, HOUGH_GRADIENT, 1, nMindist, nParam1, nParam2);
	}
	catch (const cv::Exception& e)
	{
		AfxMessageBox(_T("HoughCircles fail"));
	}
	
	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		Point center(c[0], c[1]);
		int radius = c[2];
		x = c[0];
		y = c[1];

		//vector<Point> boundaryPoints;
		//for (int angle = 0; angle < 360; angle++)
		//{
		//	int Center_x = cvRound(x + radius * cos(angle * CV_PI / 180));
		//	int Center_y = cvRound(y + radius * sin(angle * CV_PI / 180));
		//	boundaryPoints.push_back(cv::Point(x, y));
		//}
		//
		//bool isHollowOnEdge = false;
		//for (size_t i = 0; i < boundaryPoints.size() - 1; i++)
		//{
		//	double distance = cv::norm(boundaryPoints[i + 1] - boundaryPoints[i]);
		//	if (distance > 10) // �Ÿ��� �ް��ϰ� �����ϴ� ���� Ȯ�� (������ �Ӱ谪 ����)
		//	{
		//		isHollowOnEdge = true;
		//		break;
		//	}
		//}
		//
		//if (isHollowOnEdge)
		//	cv::circle(OldImage, cv::Point(x, y), radius, cv::Scalar(0, 0, 255), 2);




	
		cstrCirclePos.Format(_T("%d,%d"), x, y);
		strCirclePos = String(CT2CA(cstrCirclePos));
		cvtColor(OldImage, OldImage, COLOR_GRAY2BGR);
		circle(OldImage, center, radius, Scalar(0, 255, 0), 2);
		circle(OldImage, center, 2, Scalar(0, 0, 255), 3);
		putText(OldImage, strCirclePos, center, 2, 1.2, Scalar(0, 255, 0));
	}

	imshow("ImageViewer", OldImage);
}
void COpenCVTestDlg::OnBnClickedFindShapeTest2() //�簢��, �ﰢ�� ã��
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Mat OldImage = m_MatPreprocessingImage.clone();
	Mat ImageGray;
	Mat binary;

	if (OldImage.empty())
	{
		return;
	}

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
//	bitwise_not(binary, binary);

	try
	{
		findContours(OldImage, contours, hierarchy, m_nContoursCheckBoxValue, m_nCountoursApproxCheckBoxValue); //��ο� ��濡�� ���� ��ü�� ã�°��� ������.
	}
	catch (const cv::Exception& e)
	{
		AfxMessageBox(_T("not find Contours"));
	}
	for (size_t i = 0; i < contours.size(); i++)
	{
		vector<Point> approx;
		approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

		if (approx.size() == 4)
		{
			polylines(OldImage, approx, true, Scalar(0, 255, 0), 5);
			string strRect = "Rectangle";
			putText(OldImage, strRect, approx[0], 2, 0.7, Scalar(0, 0, 0));
		}
		else if (approx.size() == 3)
		{
			polylines(OldImage, approx, true, Scalar(0, 255, 0), 5);
			string strRect = "Triangle";
			putText(OldImage, strRect, approx[0], 2, 0.7, Scalar(0, 0, 0));
		}
		
	}
	//resize(binary, binary, Size(1024, 768));
	imshow("ImageViewer", OldImage);
}


void COpenCVTestDlg::OnBnClickedFindBlobTest()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	CString strminThreshold;
	CString strmaxThreshold;
	CString strminArea;
	CString strminCircularity;
	CString strminConvexity;
	CString strblobColor;
	CString strminInertiaRatio;

	m_ctrlBlobMinThres.GetWindowTextW(strminThreshold);
	m_ctrlBlobMaxCircularity.GetWindowTextW(strmaxThreshold);
	m_ctrlBlobMinArea.GetWindowTextW(strminArea);
	m_ctrlBlobMinCircularity.GetWindowTextW(strminCircularity);
	m_ctrlBlobMinConvexity.GetWindowTextW(strminConvexity);
	m_ctrlBlobColor.GetWindowTextW(strblobColor);
	m_ctrlBlobMinIntiaRatio.GetWindowTextW(strminInertiaRatio);

	int nMinThreshold		 = _ttoi(strminThreshold);
	int nMaxThreshold		 = _ttoi(strmaxThreshold);
	int nblobColor			 = _ttoi(strblobColor);
	double fMinArea			 = _ttof(strminArea);
	double fMinCircularity   = _ttof(strminCircularity);
	double fMinConvexity	 = _ttof(strminConvexity);
	double fMinInertiaRatio  = _ttof(strminInertiaRatio);

	SimpleBlobDetector::Params params;
	params.filterByCircularity	= m_bCircularityUseFlag;		// ������ ���͸� ���
	params.filterByArea			= m_bAreaUseFlag;		// ���� ���͸� ���
	params.filterByConvexity	= m_bConvexityUseFlag;		// ���� ���� ���͸� ���
	params.filterByInertia		= m_bIntiaRatioUseFlag;	// ���� ���� ���͸� ���
	params.filterByColor		= m_bBlobColorUseFlag;
	params.minThreshold			=  nMinThreshold;	 //20;		//�ּ� �Ӱ谪
	params.maxThreshold			=  nMaxThreshold;	 //200;		// �ִ� �Ӱ谪	
	params.blobColor			=  nblobColor;		 //0;		// 0 : ��ο� ��� ���� / 255 : ���� ��� ����
	params.minArea				=  fMinArea;		 //1;		// �ּ� ����
	params.minCircularity		=  fMinCircularity;	 //0.7;		//�ּ� ������
	params.minConvexity			=  fMinConvexity;	 //0.78;		// �ּ� ���� ����
	params.minInertiaRatio		=  fMinInertiaRatio; //0.01;		// ���� �ּ� ����
	
	Mat mImage = m_MatPreprocessingImage.clone();
	Mat mBinaryImage;
	Mat mGrayImage;

	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
	vector<KeyPoint> keypoints;
	try
	{
		detector->detect(mImage, keypoints);
		drawKeypoints(mImage, keypoints, mImage, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	}
	catch (const cv::Exception& e)
	{
		AfxMessageBox(_T("defect fail"));
	}
	

	imshow("blob", mImage);
	waitKey();
}


void COpenCVTestDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if (IDC_SLIDER_THRESHOLD_MIN == pScrollBar->GetDlgCtrlID())
	{
		int nPos = m_ThredMin.GetPos();
		CString strPos;
		strPos.Format(_T("%d"), nPos);
		m_ThredMinPos.SetWindowTextW(strPos);
		m_nThresValue = nPos;
		DisplayThresholdImage(m_MatImage);

	}
	else if (IDC_SLIDER_THRESHOLD_MAX == pScrollBar->GetDlgCtrlID())
	{
		int nPos = m_ThredMax.GetPos();
		CString strPos;
		strPos.Format(_T("%d"), nPos);
		m_ThredMaxPos.SetWindowTextW(strPos);
		m_nMaxValue = nPos;
		DisplayThresholdImage(m_MatImage);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void COpenCVTestDlg::OnBnClickedThreshBinaryCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(true);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);

	m_nThredCheckBoxValue = 0;
}


void COpenCVTestDlg::OnBnClickedThreshBinaryInvCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(true);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);

	m_nThredCheckBoxValue = 1;

}


void COpenCVTestDlg::OnBnClickedThreshMaskCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(true);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);

	m_nThredCheckBoxValue = 2;
}


void COpenCVTestDlg::OnBnClickedThreshOtsuCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(true);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);


	m_nThredCheckBoxValue = 3;
}


void COpenCVTestDlg::OnBnClickedThreshTozeroCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(true);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);


	m_nThredCheckBoxValue = 4;
}


void COpenCVTestDlg::OnBnClickedThreshTozeroInvCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(true);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(false);

	m_nThredCheckBoxValue = 7;
}


void COpenCVTestDlg::OnBnClickedThreshTriangleCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(true);
	m_ctrlTruncCheck.SetCheck(false);

	m_nThredCheckBoxValue = 8;
}


void COpenCVTestDlg::OnBnClickedThreshTruncCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlBinaryCheck.SetCheck(false);
	m_ctrlBinaryInvCheck.SetCheck(false);
	m_ctrlMaskChek.SetCheck(false);
	m_ctrlOTSUCheck.SetCheck(false);
	m_ctrlToZeroCheck.SetCheck(false);
	m_ctrlToZeroInvCheck.SetCheck(false);
	m_ctrlTriangleCheck.SetCheck(false);
	m_ctrlTruncCheck.SetCheck(true);

	m_nThredCheckBoxValue = 16;
}


void COpenCVTestDlg::OnBnClickedContoursRetrExternalCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlExternalCheck.SetCheck(true);
	m_ctrlListCheck.SetCheck(false);
	m_ctrlCCOMPCheck.SetCheck(false);
	m_ctrlTREECheck.SetCheck(false);

	m_nContoursCheckBoxValue = 0;

}


void COpenCVTestDlg::OnBnClickedContoursRetrListCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlExternalCheck.SetCheck(false);
	m_ctrlListCheck.SetCheck(true);
	m_ctrlCCOMPCheck.SetCheck(false);
	m_ctrlTREECheck.SetCheck(false);

	m_nContoursCheckBoxValue = 1;

}


void COpenCVTestDlg::OnBnClickedContoursRetrCcompCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlExternalCheck.SetCheck(false);
	m_ctrlListCheck.SetCheck(false);
	m_ctrlCCOMPCheck.SetCheck(true);
	m_ctrlTREECheck.SetCheck(false);

	m_nContoursCheckBoxValue = 2;
}


void COpenCVTestDlg::OnBnClickedContoursTreeCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlExternalCheck.SetCheck(false);
	m_ctrlListCheck.SetCheck(false);
	m_ctrlCCOMPCheck.SetCheck(false);
	m_ctrlTREECheck.SetCheck(true);


	m_nContoursCheckBoxValue = 3;
}


void COpenCVTestDlg::OnBnClickedContoursApproxNoneCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlNoneCheck.SetCheck(true);
	m_ctrlSimpleCheck.SetCheck(false);

	m_nCountoursApproxCheckBoxValue = 1;
}


void COpenCVTestDlg::OnBnClickedContoursApproxSimpleCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_ctrlNoneCheck.SetCheck(false);
	m_ctrlSimpleCheck.SetCheck(true);

	m_nCountoursApproxCheckBoxValue = 2;
}


void COpenCVTestDlg::DisplayThresholdImage(Mat Image)
{
	Mat OldImage = Image.clone();
	Mat BinaryImage;
	threshold(OldImage, BinaryImage, m_nThresValue, m_nMaxValue, m_nContoursCheckBoxValue);

	imshow("ImageViewer", BinaryImage);
}

void COpenCVTestDlg::OnBnClickedBlobCircularityUseCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlCircularityUseCheck.GetCheck() == true)
	{
		m_ctrlCircularityUseCheck.SetCheck(true);
		m_bCircularityUseFlag = true;
	}
	else
	{
		m_ctrlCircularityUseCheck.SetCheck(false);
		m_bCircularityUseFlag = false;
	}
}


void COpenCVTestDlg::OnBnClickedBlobAreaUseCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlAreaUseCheck.GetCheck() == true)
	{
		m_ctrlAreaUseCheck.SetCheck(true);
		m_bAreaUseFlag = true;
	}
	else
	{
		m_ctrlAreaUseCheck.SetCheck(false);
		m_bAreaUseFlag = false;
	}
}


void COpenCVTestDlg::OnBnClickedBlobConvexityUseCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlConvexityUseCheck.GetCheck()== true)
	{
		m_ctrlConvexityUseCheck.SetCheck(true);
		m_bConvexityUseFlag = true;
	}
	else
	{
		m_ctrlConvexityUseCheck.SetCheck(false);
		m_bConvexityUseFlag = false;
	}
}


void COpenCVTestDlg::OnBnClickedBlobInertiaUseCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlInnertiaUseCheck.GetCheck() == true)
	{
		m_ctrlInnertiaUseCheck.SetCheck(true);
		m_bIntiaRatioUseFlag = true;
	}
	else
	{
		m_ctrlInnertiaUseCheck.SetCheck(false);
		m_bIntiaRatioUseFlag = false;
	}
}


void COpenCVTestDlg::OnBnClickedBlobColorUseCheck()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlColorUseCheck.GetCheck() == true)
	{
		m_ctrlColorUseCheck.SetCheck(true);
		m_bBlobColorUseFlag = true;
	}
	else
	{
		m_ctrlColorUseCheck.SetCheck(false);
		m_bBlobColorUseFlag = false;
	}
}



void COpenCVTestDlg::OnBnClickedPreprocessingAddBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp;
	CString strAddCnt;
	if (m_PreProcessingAddCnt == 0)
	{
		m_PreProcessingAddCnt = 1;
	}
	strAddCnt.Format(_T("%d"), m_PreProcessingAddCnt);
	
	try
	{	
		m_ctrlPreProcessingCombo.GetLBText(m_ctrlPreProcessingCombo.GetCurSel(), strTemp);
	}
	catch (CException *ex)
	{
		AfxMessageBox(_T("���õ� ���� �����ϴ�."));
	}


	m_ctrlPreProcessingList.InsertItem(0, strAddCnt);
	//m_ctrlPreProcessingList.SetItem(0, 0, LVIF_TEXT, strAddCnt, 0, 0, 0, NULL);
	m_ctrlPreProcessingList.SetItem(0, 1, LVIF_TEXT, strTemp, 0, 0, 0, NULL);

	m_strListIndex[m_PreProcessingAddCnt - 1] = strAddCnt;
	m_strListName[m_PreProcessingAddCnt - 1] = strTemp;

	m_PreProcessingAddCnt++;
	
}


void COpenCVTestDlg::OnBnClickedPreprocessingSaveBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�. 
	int nIndex = m_ctrlPreProcessingList.GetSelectionMark();
	nIndex = abs(abs(nIndex - m_PreProcessingAddCnt) - 1);
	nIndex = nIndex - 1;

	CString strParam1, strParam2, strParam3, strParam4, strParam5, strParam6;

	bool bComboUse1, bComboUse2, bComboUse3, bComboUse4, bComboUse5, bComboUse6;

	if (m_strListName[nIndex] == _T("cvtColor"))
	{
		bComboUse1 = true; bComboUse2 = false; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("GaussianBlur"))
	{
		bComboUse1 = true; bComboUse2 = true; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("Threshold"))
	{
		bComboUse1 = false; bComboUse2 = false; bComboUse3 = true; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("Canny"))
	{
		bComboUse1 = false; bComboUse2 = false; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("Dilate"))
	{
		bComboUse1 = true; bComboUse2 = true; bComboUse3 = true; bComboUse4 = true; bComboUse5 = true; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("Erode"))
	{
		bComboUse1 = true; bComboUse2 = true; bComboUse3 = true; bComboUse4 = true; bComboUse5 = true; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("warpAffine"))
	{
		bComboUse1 = false; bComboUse2 = false; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("Sobel"))
	{
		bComboUse1 = true; bComboUse2 = true; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	else if (m_strListName[nIndex] == _T("bitwise"))
	{
		bComboUse1 = true; bComboUse2 = false; bComboUse3 = false; bComboUse4 = false; bComboUse5 = false; bComboUse6 = false;
	}
	

	if (bComboUse1)
	{
		m_ctrlComboParma1.GetWindowTextW(strParam1);
		m_strPreParam1[nIndex] = strParam1.Left(1);
	}
	else
	{
		m_ctrlEditParam1.GetWindowTextW(strParam1);
		m_strPreParam1[nIndex] = strParam1;
	}
	if (bComboUse2)
	{
		m_ctrlComboParma2.GetWindowTextW(strParam2);
		m_strPreParam2[nIndex] = strParam2.Left(1);
	}
	else
	{
		m_ctrlEditParam2.GetWindowTextW(strParam2);
		m_strPreParam2[nIndex] = strParam2;
	}
	if (bComboUse3)
	{
		m_ctrlComboParma3.GetWindowTextW(strParam3);
		m_strPreParam3[nIndex] = strParam3.Left(1);
	}
	else
	{
		m_ctrlEditParam3.GetWindowTextW(strParam3);
		m_strPreParam3[nIndex] = strParam3;
	}
	if (bComboUse4)
	{
		m_ctrlComboParma4.GetWindowTextW(strParam4);
		m_strPreParam4[nIndex] = strParam4.Left(1);
	}
	else
	{
		m_ctrlEditParam4.GetWindowTextW(strParam4);
		m_strPreParam4[nIndex] = strParam4;
	}
	if (bComboUse5)
	{
		m_ctrlComboParma5.GetWindowTextW(strParam5);
		m_strPreParam5[nIndex] = strParam5.Left(1);
	}
	else
	{
		m_ctrlEditParam5.GetWindowTextW(strParam5);
		m_strPreParam5[nIndex] = strParam5;
	}
	if (bComboUse6)
	{
		m_ctrlComboParma6.GetWindowTextW(strParam6);
		m_strPreParam6[nIndex] = strParam6.Left(1);
	}
	else
	{
		m_ctrlEditParam6.GetWindowTextW(strParam6);
		m_strPreParam6[nIndex] = strParam6;
	}
}


void COpenCVTestDlg::OnBnClickedPreprocessingDeleteBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�
	int nIndex = m_ctrlPreProcessingList.GetSelectionMark();
	m_ctrlPreProcessingList.DeleteItem(nIndex);
	m_PreProcessingAddCnt--;
	if (0 >= m_PreProcessingAddCnt)
	{
		m_PreProcessingAddCnt = 0;
	}

}


void COpenCVTestDlg::OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nIndex =  m_ctrlPreProcessingList.GetSelectionMark();
	nIndex = abs(abs(nIndex - m_PreProcessingAddCnt) - 1);
	PreProcessDisplayChange(nIndex - 1);
	PreProcessingDataLoad(nIndex - 1);
	*pResult = 0;
}

void COpenCVTestDlg::OnBnClickedPreprocessingItemUpBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp1, strTemp2;
	CString strUpIndex, strUpName;
	CString strParam1, strParam2, strParam3, strParam4, strParam5, strParam6;
	CString strUPParam1, strUPParam2, strUPParam3, strUPParam4, strUPParam5, strUPParam6;

	int nIndex = m_ctrlPreProcessingList.GetSelectionMark();
	nIndex = abs(abs(nIndex - m_PreProcessingAddCnt) - 1);
	nIndex = nIndex - 1;

	strTemp2.Format(_T("%s"), m_strListName[nIndex]);
	strUpName.Format(_T("%s"), m_strListName[nIndex + 1]);
	m_strListName[nIndex] = strUpName;
	m_strListName[nIndex + 1] = strTemp2;

	m_ctrlPreProcessingList.DeleteAllItems();

	for (int i = 0; i < m_PreProcessingAddCnt - 1; i++)
	{
		m_ctrlPreProcessingList.InsertItem(0, m_strListIndex[i]);
		m_ctrlPreProcessingList.SetItem(0, 1, LVIF_TEXT, m_strListName[i], 0, 0, 0, NULL);
	}

	strParam1.Format(_T("%s"), m_strPreParam1[nIndex]);
	strUPParam1.Format(_T("%s"), m_strPreParam1[nIndex + 1]);
	m_strPreParam1[nIndex] = strUPParam1;
	m_strPreParam1[nIndex + 1] = strParam1;

	strParam2.Format(_T("%s"), m_strPreParam2[nIndex]);
	strUPParam2.Format(_T("%s"), m_strPreParam2[nIndex + 1]);
	m_strPreParam2[nIndex] = strUPParam2;
	m_strPreParam2[nIndex + 1] = strParam2;

	strParam3.Format(_T("%s"), m_strPreParam3[nIndex]);
	strUPParam3.Format(_T("%s"), m_strPreParam3[nIndex + 1]);
	m_strPreParam3[nIndex] = strUPParam3;
	m_strPreParam3[nIndex + 1] = strParam3;

	strParam4.Format(_T("%s"), m_strPreParam4[nIndex]);
	strUPParam4.Format(_T("%s"), m_strPreParam4[nIndex + 1]);
	m_strPreParam4[nIndex] = strUPParam4;
	m_strPreParam4[nIndex + 1] = strParam4;

	strParam5.Format(_T("%s"), m_strPreParam5[nIndex]);
	strUPParam5.Format(_T("%s"), m_strPreParam5[nIndex + 1]);
	m_strPreParam5[nIndex] = strUPParam5;
	m_strPreParam5[nIndex + 1] = strParam5;

	strParam6.Format(_T("%s"), m_strPreParam6[nIndex]);
	strUPParam6.Format(_T("%s"), m_strPreParam6[nIndex + 1]);
	m_strPreParam6[nIndex] = strUPParam6;
	m_strPreParam6[nIndex + 1] = strParam6;
}

void COpenCVTestDlg::OnBnClickedPreprocessingItemDnBtn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strTemp1, strTemp2;
	CString strDNIndex, strDNName;
	CString strParam1, strParam2, strParam3, strParam4, strParam5, strParam6;
	CString strDNParam1, strDNParam2, strDNParam3, strDNParam4, strDNParam5, strDNParam6;

	int nIndex = m_ctrlPreProcessingList.GetSelectionMark();
	nIndex = abs(abs(nIndex - m_PreProcessingAddCnt) - 1);
	nIndex = nIndex - 1;

	m_ctrlPreProcessingList.DeleteAllItems();

	strTemp2.Format(_T("%s"), m_strListName[nIndex]);
	strDNName.Format(_T("%s"), m_strListName[nIndex - 1]);
	m_strListName[nIndex] = strDNName;
	m_strListName[nIndex - 1] = strTemp2;

	for (int i = 0; i < m_PreProcessingAddCnt - 1; i++)
	{
		m_ctrlPreProcessingList.InsertItem(0, m_strListIndex[i]);
		m_ctrlPreProcessingList.SetItem(0, 1, LVIF_TEXT, m_strListName[i], 0, 0, 0, NULL);
	}

	strParam1.Format(_T("%s"), m_strPreParam1[nIndex]);
	strDNParam1.Format(_T("%s"), m_strPreParam1[nIndex - 1]);
	m_strPreParam1[nIndex] = strDNParam1;
	m_strPreParam1[nIndex - 1] = strParam1;

	strParam2.Format(_T("%s"), m_strPreParam2[nIndex]);
	strDNParam2.Format(_T("%s"), m_strPreParam2[nIndex - 1]);
	m_strPreParam2[nIndex] = strDNParam2;
	m_strPreParam2[nIndex - 1] = strParam2;

	strParam3.Format(_T("%s"), m_strPreParam3[nIndex]);
	strDNParam3.Format(_T("%s"), m_strPreParam3[nIndex - 1]);
	m_strPreParam3[nIndex] = strDNParam3;
	m_strPreParam3[nIndex - 1] = strParam3;

	strParam4.Format(_T("%s"), m_strPreParam4[nIndex]);
	strDNParam4.Format(_T("%s"), m_strPreParam4[nIndex - 1]);
	m_strPreParam4[nIndex] = strDNParam4;
	m_strPreParam4[nIndex - 1] = strParam4;

	strParam5.Format(_T("%s"), m_strPreParam5[nIndex]);
	strDNParam5.Format(_T("%s"), m_strPreParam5[nIndex - 1]);
	m_strPreParam5[nIndex] = strDNParam5;
	m_strPreParam5[nIndex - 1] = strParam5;

	strParam6.Format(_T("%s"), m_strPreParam6[nIndex]);
	strDNParam6.Format(_T("%s"), m_strPreParam6[nIndex - 1]);
	m_strPreParam6[nIndex] = strDNParam6;
	m_strPreParam6[nIndex - 1] = strParam6;


}

void COpenCVTestDlg::OnHdnItemclickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	m_ctrlPreProcessingList.DeleteAllItems();

	for (int i = 0; i < m_PreProcessingAddCnt - 1; i++)
	{	
		m_ctrlPreProcessingList.InsertItem(0, m_strListIndex[i]);
		//m_ctrlPreProcessingList.SetItem(0, 0, LVIF_TEXT, strAddCnt, 0, 0, 0, NULL);
		m_ctrlPreProcessingList.SetItem(0, 1, LVIF_TEXT, m_strListName[i], 0, 0, 0, NULL);
	}

	*pResult = 0;
}

void COpenCVTestDlg::PreProcessDisplayChange(int nIndex)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nCheck = nIndex;

	if (m_strListName[nCheck] == _T("cvtColor"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(FALSE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(TRUE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("Dst Cnt"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam3.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam4.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam5.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));
		
		m_ctrlComboParma1.ResetContent();
		m_ctrlComboParma1.AddString(_T("4.COLOR_BGR2RGB"));
		m_ctrlComboParma1.AddString(_T("6.COLOR_BGR2GRAY"));
		m_ctrlComboParma1.AddString(_T("8.COLOR_GRAY2BGR"));
	}
	else if (m_strListName[nCheck] == _T("GaussianBlur"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(TRUE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(TRUE);
		m_ctrlComboParma2.ShowWindow(TRUE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("Size x"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("Size y"));
		m_ctrlPreProcessParam3.SetWindowTextW(_T("Sigma X"));
		m_ctrlPreProcessParam4.SetWindowTextW(_T("Sigma Y"));
		m_ctrlPreProcessParam5.SetWindowTextW(_T("BorderType"));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));

		m_ctrlComboParma1.ResetContent();
		m_ctrlComboParma2.ResetContent();
		m_ctrlComboParma3.ResetContent();
		m_ctrlComboParma4.ResetContent();
		m_ctrlComboParma5.ResetContent();

		m_ctrlComboParma1.AddString(_T("0"));
		m_ctrlComboParma1.AddString(_T("1"));
		m_ctrlComboParma1.AddString(_T("3"));
		m_ctrlComboParma1.AddString(_T("5"));
		m_ctrlComboParma1.AddString(_T("7"));
		m_ctrlComboParma1.AddString(_T("9"));

		m_ctrlComboParma2.AddString(_T("0"));
		m_ctrlComboParma2.AddString(_T("1"));
		m_ctrlComboParma2.AddString(_T("3"));
		m_ctrlComboParma2.AddString(_T("5"));
		m_ctrlComboParma2.AddString(_T("7"));
		m_ctrlComboParma2.AddString(_T("9"));

		m_ctrlComboParma3.AddString(_T("1"));
		m_ctrlComboParma3.AddString(_T("2"));
		m_ctrlComboParma3.AddString(_T("3"));
		m_ctrlComboParma3.AddString(_T("4"));
		m_ctrlComboParma3.AddString(_T("5"));
		m_ctrlComboParma3.AddString(_T("6"));
		m_ctrlComboParma3.AddString(_T("7"));
		m_ctrlComboParma3.AddString(_T("8"));
		m_ctrlComboParma3.AddString(_T("9"));
		m_ctrlComboParma3.AddString(_T("10"));

		m_ctrlComboParma4.AddString(_T("1"));
		m_ctrlComboParma4.AddString(_T("2"));
		m_ctrlComboParma4.AddString(_T("3"));
		m_ctrlComboParma4.AddString(_T("4"));
		m_ctrlComboParma4.AddString(_T("5"));
		m_ctrlComboParma4.AddString(_T("6"));
		m_ctrlComboParma4.AddString(_T("7"));
		m_ctrlComboParma4.AddString(_T("8"));
		m_ctrlComboParma4.AddString(_T("9"));
		m_ctrlComboParma4.AddString(_T("10"));

		m_ctrlComboParma5.AddString(_T("0.BORDER_CONSTANT"));
		m_ctrlComboParma5.AddString(_T("1.BORDER_REPLICATE"));
		m_ctrlComboParma5.AddString(_T("2.BORDER_REFLECT"));
		m_ctrlComboParma5.AddString(_T("3.BORDER_WRAP"));
		m_ctrlComboParma5.AddString(_T("4.BORDER_DEFAULT"));

	}
	else if (m_strListName[nCheck] == _T("Threshold"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(TRUE);
		m_ctrlPreProcessParam3.ShowWindow(TRUE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(FALSE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(TRUE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(TRUE);
		m_ctrlEditParam2.ShowWindow(TRUE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("threshold"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("MaxValue"));
		m_ctrlPreProcessParam3.SetWindowTextW(_T("type"));
		m_ctrlPreProcessParam4.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam5.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));

		m_ctrlComboParma3.ResetContent();

		
		m_ctrlComboParma3.AddString(_T("0.THRESH_BINARY"));
		m_ctrlComboParma3.AddString(_T("1.THRESH_BINARY_INV"));
		m_ctrlComboParma3.AddString(_T("2.THRESH_TRUNC"));
		m_ctrlComboParma3.AddString(_T("3.THRESH_TOZERO"));
		m_ctrlComboParma3.AddString(_T("4.THRESH_TOZERO_INV"));
		m_ctrlComboParma3.AddString(_T("7.THRESH_MASK"));
		m_ctrlComboParma3.AddString(_T("8.THRESH_OTSU"));
		m_ctrlComboParma3.AddString(_T("16.THRESH_TRIANGLE"));
	}
	else if (m_strListName[nCheck] == _T("Canny"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(TRUE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(FALSE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(TRUE);
		m_ctrlEditParam2.ShowWindow(TRUE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("threshold1"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("threshold2"));
		m_ctrlPreProcessParam3.SetWindowTextW(_T("aperturesize"));
		m_ctrlPreProcessParam4.SetWindowTextW(_T("L2gradient"));
		m_ctrlPreProcessParam5.SetWindowTextW(_T(""));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));

	}
	else if (m_strListName[nCheck] == _T("Dilate"))
	{
		m_ctrlPreProcessParam1.ShowWindow(FALSE);
		m_ctrlPreProcessParam2.ShowWindow(FALSE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(TRUE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(FALSE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(TRUE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("Kernel"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("Point x"));
		m_ctrlPreProcessParam3.SetWindowTextW(_T("Point y"));
		m_ctrlPreProcessParam4.SetWindowTextW(_T("Iterations"));
		m_ctrlPreProcessParam5.SetWindowTextW(_T("BorderType"));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));

		m_ctrlComboParma1.ResetContent();
		m_ctrlComboParma2.ResetContent();
		m_ctrlComboParma3.ResetContent();
		m_ctrlComboParma4.ResetContent();
		m_ctrlComboParma5.ResetContent();

		m_ctrlComboParma1.AddString(_T(""));
		m_ctrlComboParma4.AddString(_T("1"));
		m_ctrlComboParma4.AddString(_T("2"));
		m_ctrlComboParma4.AddString(_T("3"));
		m_ctrlComboParma4.AddString(_T("4"));
		m_ctrlComboParma4.AddString(_T("5"));
		m_ctrlComboParma4.AddString(_T("6"));
		m_ctrlComboParma4.AddString(_T("7"));
		m_ctrlComboParma4.AddString(_T("8"));
		m_ctrlComboParma4.AddString(_T("9"));

	}
	else if (m_strListName[nCheck] == _T("Erode"))
	{
		m_ctrlPreProcessParam1.ShowWindow(FALSE);
		m_ctrlPreProcessParam2.ShowWindow(FALSE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(TRUE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(FALSE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(TRUE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("Kernel"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("Point x"));
		m_ctrlPreProcessParam3.SetWindowTextW(_T("Point y"));
		m_ctrlPreProcessParam4.SetWindowTextW(_T("Iterations"));
		m_ctrlPreProcessParam5.SetWindowTextW(_T("BorderType"));
		m_ctrlPreProcessParam6.SetWindowTextW(_T(""));

		m_ctrlComboParma1.ResetContent();
		m_ctrlComboParma2.ResetContent();
		m_ctrlComboParma3.ResetContent();
		m_ctrlComboParma4.ResetContent();
		m_ctrlComboParma5.ResetContent();

		m_ctrlComboParma4.AddString(_T("1"));
		m_ctrlComboParma4.AddString(_T("2"));
		m_ctrlComboParma4.AddString(_T("3"));
		m_ctrlComboParma4.AddString(_T("4"));
		m_ctrlComboParma4.AddString(_T("5"));
		m_ctrlComboParma4.AddString(_T("6"));
		m_ctrlComboParma4.AddString(_T("7"));
		m_ctrlComboParma4.AddString(_T("8"));
		m_ctrlComboParma4.AddString(_T("9"));

	}
	//else if (m_strListName[nCheck] == _T("warpAffine"))
	//{
	//
	//}
	else if (m_strListName[nCheck] == _T("Sobel"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(TRUE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(TRUE);
		m_ctrlComboParma2.ShowWindow(TRUE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("DataType"));
		m_ctrlPreProcessParam2.SetWindowTextW(_T("��� ���� ���"));

		m_ctrlComboParma1.ResetContent();
		m_ctrlComboParma2.ResetContent();

		m_ctrlComboParma1.AddString(_T("0. CV_8U"));
		m_ctrlComboParma1.AddString(_T("1. CV_8S"));
		m_ctrlComboParma1.AddString(_T("2. CV_16U"));
		m_ctrlComboParma1.AddString(_T("3. CV_16S"));
		m_ctrlComboParma1.AddString(_T("4. CV_32S"));
		m_ctrlComboParma1.AddString(_T("5. CV_32F"));

		m_ctrlComboParma2.AddString(_T("0. Sobel X"));
		m_ctrlComboParma2.AddString(_T("1. Sobel Y"));
	}
	else if (m_strListName[nCheck] == _T("bitwise"))
	{
		m_ctrlPreProcessParam1.ShowWindow(TRUE);
		m_ctrlPreProcessParam2.ShowWindow(FALSE);
		m_ctrlPreProcessParam3.ShowWindow(FALSE);
		m_ctrlPreProcessParam4.ShowWindow(FALSE);
		m_ctrlPreProcessParam5.ShowWindow(FALSE);
		m_ctrlPreProcessParam6.ShowWindow(FALSE);

		m_ctrlComboParma1.ShowWindow(TRUE);
		m_ctrlComboParma2.ShowWindow(FALSE);
		m_ctrlComboParma3.ShowWindow(FALSE);
		m_ctrlComboParma4.ShowWindow(FALSE);
		m_ctrlComboParma5.ShowWindow(FALSE);
		m_ctrlComboParma6.ShowWindow(FALSE);

		m_ctrlEditParam1.ShowWindow(FALSE);
		m_ctrlEditParam2.ShowWindow(FALSE);
		m_ctrlEditParam3.ShowWindow(FALSE);
		m_ctrlEditParam4.ShowWindow(FALSE);
		m_ctrlEditParam5.ShowWindow(FALSE);
		m_ctrlEditParam6.ShowWindow(FALSE);

		m_ctrlPreProcessParam1.SetWindowTextW(_T("DataType"));

		m_ctrlComboParma1.ResetContent();

		m_ctrlComboParma1.AddString(_T("0. bitwise_end"));
		m_ctrlComboParma1.AddString(_T("1. bitwise_or"));
		m_ctrlComboParma1.AddString(_T("2. bitwise_xor"));
		m_ctrlComboParma1.AddString(_T("3. bitwise_not"));
	}
}


void COpenCVTestDlg::OnBnClickedPreprocessingTestBtn2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Mat OriginImage;
	Mat ReturnImage;
	OriginImage = m_MatImage.clone();

	if (OriginImage.empty())
	{
		return;
	}

	for (int i = 0; i < m_PreProcessingAddCnt - 1; i++)
	{
		if (i == 0)
		{
			ReturnImage = PreProcessingImage(OriginImage, m_strListIndex[i], m_strListName[i]);
		}
		else
		{
			ReturnImage = PreProcessingImage(ReturnImage, m_strListIndex[i], m_strListName[i]);
		}
	}

	m_MatPreprocessingImage = ReturnImage;

	imshow("ImageViewer", ReturnImage);

}


Mat COpenCVTestDlg::PreProcessingImage(Mat OriginImage, CString strIndex, CString strName)
{
	Mat ReturnImage;
	int nParam1, nParam2, nParam3, nParam4, nParam5, nParam6;
	int nIndex;
	nIndex = _ttoi(strIndex);

	nParam1 = _ttoi(m_strPreParam1[nIndex - 1]);
	nParam2 = _ttoi(m_strPreParam2[nIndex - 1]);
	nParam3 = _ttoi(m_strPreParam3[nIndex - 1]);
	nParam4 = _ttoi(m_strPreParam4[nIndex - 1]);
	nParam5 = _ttoi(m_strPreParam5[nIndex - 1]);
	nParam6 = _ttoi(m_strPreParam6[nIndex - 1]);

	if (strName == _T("cvtColor"))
	{
		cvtColor(OriginImage, ReturnImage, nParam1);
	}
	else if (strName == _T("GaussianBlur"))
	{
		GaussianBlur(OriginImage, ReturnImage, Size(nParam1, nParam2), 0);
	}
	else if (strName == _T("Threshold"))
	{
		threshold(OriginImage, ReturnImage, nParam1, nParam2, nParam3);
	}
	else if (strName == _T("Canny"))
	{
		Canny(OriginImage, ReturnImage, nParam1, nParam2, 3, false);
	}
	else if (strName == _T("Dilate"))
	{
		dilate(OriginImage, ReturnImage, Mat(), Point(-1,-1), nParam4, BORDER_CONSTANT, 3);
	}
	else if (strName == _T("Erode"))
	{
		erode(OriginImage, ReturnImage, Mat(), Point(-1, -1), nParam4, BORDER_CONSTANT, 3);
	}
	//else if (strName == _T("warpAffine"))
	//{
	//	warpAffine(OriginImage, ReturnImage, 1, Size(1,1), 1, 1, 1);
	//}
	else if (strName == _T("Sobel"))
	{
		if (nParam1 == 0)
		{
			if (nParam2 == 0)
			{
				Sobel(OriginImage, ReturnImage, CV_8U, 1, 0);
			}
			else
			{
				Sobel(OriginImage, ReturnImage, CV_8U, 0, 1);
			}								    									    
		}									    
		else if (nParam1 == 1)				    
		{									    
			if (nParam2 == 0)				    
			{								    
				Sobel(OriginImage, ReturnImage, CV_8S, 1, 0);
			}								    
			else							    
			{								    
				Sobel(OriginImage, ReturnImage, CV_8S, 0, 1);
			}								    
		}									    
		else if (nParam1 == 2)				    
		{									    
			if (nParam2 == 0)				    
			{								    
				Sobel(OriginImage, ReturnImage, CV_16U, 1, 0);
			}								    
			else							    
			{								    
				Sobel(OriginImage, ReturnImage, CV_16U, 0, 1);
			}								    
		}									    
		else if (nParam1 == 3)				    
		{									    
			if (nParam2 == 0)				    
			{								    
				Sobel(OriginImage, ReturnImage, CV_16S, 1, 0);
			}								    
			else							    
			{								    
				Sobel(OriginImage, ReturnImage, CV_16S, 0, 1);
			}								    
		}									    
		else if (nParam1 == 4)				    
		{									    
			if (nParam2 == 0)				    
			{								    
				Sobel(OriginImage, ReturnImage, CV_32S, 1, 0);
			}								    
			else							    
			{								    
				Sobel(OriginImage, ReturnImage, CV_32S, 0, 1);
			}								    
		}									    
		else if (nParam1 == 5)				    
		{									    
			if (nParam2 == 0)				    
			{								    
				Sobel(OriginImage, ReturnImage, CV_32F, 1, 0);
			}								    
			else							    
			{								    
				Sobel(OriginImage, ReturnImage, CV_32F, 0, 1);
			}
		}
	}
	else if (strName == _T("bitwise"))
	{
		if (nParam1 == 0)
		{
			bitwise_and(OriginImage, OriginImage, ReturnImage); //23.07.11 gmjo �����ʿ�
		}
		else if (nParam1 == 1)
		{
			bitwise_or(OriginImage, OriginImage, ReturnImage);//23.07.11 gmjo �����ʿ�
		}
		else if (nParam1 == 2)
		{
			bitwise_or(OriginImage, OriginImage, ReturnImage);//23.07.11 gmjo �����ʿ�
		}
		else if (nParam1 == 3)
		{
			bitwise_not(OriginImage, ReturnImage);
		}
	}
	return ReturnImage;
}

void COpenCVTestDlg::PreProcessingDataLoad(int nDevice)
{
	int nCheck = nDevice;
	int nCheckCnt = 0;
	if (m_strPreParam1[nCheck] == _T(""))
	{
		return;
	}
	if (m_strListName[nCheck] == _T("cvtColor"))
	{
		nCheckCnt = _ttoi(m_strPreParam1[nCheck]);
		if (nCheckCnt == 4)
		{
			m_ctrlComboParma1.SetCurSel(0); //�� ���������� 0���� ����.
		}
		else if (nCheckCnt == 6)
		{
			m_ctrlComboParma1.SetCurSel(1);
		}
		else if (nCheckCnt == 8)
		{
			m_ctrlComboParma1.SetCurSel(2);
		}
	}
	else if (m_strListName[nCheck] == _T("GaussianBlur"))
	{
		nCheckCnt = _ttoi(m_strPreParam1[nCheck]);
		if (nCheckCnt == 0)
		{
			m_ctrlComboParma1.SetCurSel(0);
		}
		else if (nCheckCnt == 1)
		{
			m_ctrlComboParma1.SetCurSel(1);
		}
		else if (nCheckCnt == 3)
		{
			m_ctrlComboParma1.SetCurSel(2);
		}
		else if (nCheckCnt == 5)
		{
			m_ctrlComboParma1.SetCurSel(3);
		}
		else if (nCheckCnt == 7)
		{
			m_ctrlComboParma1.SetCurSel(4);
		}
		else if (nCheckCnt == 9)
		{
			m_ctrlComboParma1.SetCurSel(5);
		}

		nCheckCnt = _ttoi(m_strPreParam2[nCheck]);
		if (nCheckCnt == 0)
		{
			m_ctrlComboParma2.SetCurSel(0);
		}
		else if (nCheckCnt == 1)
		{
			m_ctrlComboParma2.SetCurSel(1);
		}
		else if (nCheckCnt == 3)
		{
			m_ctrlComboParma2.SetCurSel(2);
		}
		else if (nCheckCnt == 5)
		{
			m_ctrlComboParma2.SetCurSel(3);
		}
		else if (nCheckCnt == 7)
		{
			m_ctrlComboParma2.SetCurSel(4);
		}
		else if (nCheckCnt == 9)
		{
			m_ctrlComboParma2.SetCurSel(5);
		}
	}
	else if (m_strListName[nCheck] == _T("Threshold"))
	{
		m_ctrlEditParam1.SetWindowTextW(m_strPreParam1[nCheck]);
		m_ctrlEditParam2.SetWindowTextW(m_strPreParam2[nCheck]);
		m_ctrlComboParma3.SetWindowTextW(m_strPreParam3[nCheck]);
	}
	else if (m_strListName[nCheck] == _T("Canny"))
	{
		m_ctrlComboParma1.SetWindowTextW(m_strPreParam1[nCheck]);
		m_ctrlComboParma2.SetWindowTextW(m_strPreParam2[nCheck]);
		m_ctrlComboParma3.SetWindowTextW(m_strPreParam3[nCheck]);
		m_ctrlComboParma4.SetWindowTextW(m_strPreParam4[nCheck]);
	}
	else if (m_strListName[nCheck] == _T("Dilate"))
	{
		m_ctrlComboParma1.SetWindowTextW(m_strPreParam1[nCheck]);
		m_ctrlComboParma2.SetWindowTextW(m_strPreParam2[nCheck]);
		m_ctrlComboParma3.SetWindowTextW(m_strPreParam3[nCheck]);
		m_ctrlComboParma4.SetWindowTextW(m_strPreParam4[nCheck]);
		m_ctrlComboParma5.SetWindowTextW(m_strPreParam5[nCheck]);
	}
	else if (m_strListName[nCheck] == _T("Erode"))
	{
		m_ctrlComboParma1.SetWindowTextW(m_strPreParam1[nCheck]);
		m_ctrlComboParma2.SetWindowTextW(m_strPreParam2[nCheck]);
		m_ctrlComboParma3.SetWindowTextW(m_strPreParam3[nCheck]);
		m_ctrlComboParma4.SetWindowTextW(m_strPreParam4[nCheck]);
		m_ctrlComboParma5.SetWindowTextW(m_strPreParam5[nCheck]);
	}
	//else if (m_strListName[nCheck] == _T("warpAffine"))
	//{
	//
	//}
	else if (m_strListName[nCheck] == _T("Sobel"))
	{
		int nCnt1, nCnt2;

		nCnt1 = _ttoi(m_strPreParam1[nCheck]);
		nCnt2 = _ttoi(m_strPreParam2[nCheck]);
		m_ctrlComboParma1.SetCurSel(nCnt1);
		m_ctrlComboParma2.SetCurSel(nCnt2);
	}
}
//void COpenCVTestDlg::LoadModelData(CString strModel)
//{
//	CString strFilePath, strFileName;
//	CProfileDataIF cDataIf;
//	strFilePath.Format(_T("D:\\VisionData\\"));
//	strFileName.Format(_T("%s%s"), strFilePath, strModel);
//	cDataIf.SetFilePath(strFileName);
//
//	CString strNode;
//	strNode.Format(_T("PF")); // ���� SEMI ����� ȣȯ�� ������. 
//
//	//SetParametor_1(cDataIf.GetString(strNode, _T("PF"),_T("")));
//	
//	
//}
//
//void COpenCVTestDlg::SaveModelData(CString strModel)
//{
//	CString strFilePath, strFileName;
//	CProfileDataIF cDataIf;
//	strFilePath.Format(_T("D:\\AVI_Data\\Model\\"));
//	strFileName.Format(_T("%s%s"), strFilePath, strModel);
//	cDataIf.SetFilePath(strFileName);
//
//	CString strNode;
//	strNode.Format(_T("PF")); // ���� SEMI ����� ȣȯ�� ������. 
//
//	//cDataIf.SetString(strNode, _T("PF"), GetParametor_1(1));
//	
//}

void COpenCVTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 100)
	{
		CheckParamData();
	}

	CDialogEx::OnTimer(nIDEvent);
}
void COpenCVTestDlg::CheckParamData()
{
	CString strminThreshold;
	CString strmaxThreshold;
	CString strminArea;
	CString strmaxArea;
	CString strminCircularity;
	CString strmaxCircularity;
	CString strminConvexity;
	CString strmaxConvexity;
	CString strminInertiaRatio;
	CString strmaxInertiaRatio;
	CString strblobColor;

	m_ctrlBlobMinThres.GetWindowTextW(strminThreshold);
	m_ctrlBlobMaxThres.GetWindowTextW(strmaxThreshold);

	m_ctrlBlobColor.GetWindowTextW(strblobColor);

	m_ctrlBlobMinCircularity.GetWindowTextW(strminCircularity);
	m_ctrlBlobMaxCircularity.GetWindowTextW(strmaxCircularity);
	
	m_ctrlBlobMinArea.GetWindowTextW(strminArea);
	m_ctrlBlobMaxArea.GetWindowTextW(strmaxArea);

	m_ctrlBlobMinConvexity.GetWindowTextW(strminConvexity);
	m_ctrlBlobMaxConvexity.GetWindowTextW(strmaxConvexity);

	m_ctrlBlobMinIntiaRatio.GetWindowTextW(strminInertiaRatio);
	m_ctrlBlobMaxIntiaRatio.GetWindowTextW(strmaxInertiaRatio);

	int nMinThreshold = _ttoi(strminThreshold);
	int nMaxThreshold = _ttoi(strmaxThreshold);
	int nblobColor = _ttoi(strblobColor);
	double fMinArea = _ttof(strminArea);
	double fMaxArea = _ttof(strmaxArea);
	double fMinCircularity = _ttof(strminCircularity);
	double fMaxCircularity = _ttof(strmaxCircularity);
	double fMinConvexity = _ttof(strminConvexity);
	double fMaxConvexity = _ttof(strmaxConvexity);
	double fMinInertiaRatio = _ttof(strminInertiaRatio);
	double fMaxInertiaRatio = _ttof(strmaxInertiaRatio);

	if (nMinThreshold < 0 || nMinThreshold > 255)
	{
		m_ctrlBlobMinThres.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("minThreshold ���� 0 �̸� or 255�ʰ� �� �� �����ϴ�."));	
	}
	if (nMaxThreshold > 255 || 0 > nMaxThreshold)
	{
		m_ctrlBlobMaxThres.SetWindowTextW(_T("255"));
		AfxMessageBox(_T("MaxThreshold ����  0 �̸� or 255 �ʰ��� �� �����ϴ�."));
	}

	if (nMinThreshold > nMaxThreshold)
	{
		m_ctrlBlobMinThres.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("MinThreshold ���� MaxThreshold���� Ŭ �� �����ϴ�."));
	}
	
	if (0 > nblobColor || nblobColor > 255)
	{
		m_ctrlBlobColor.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("blobColor ���� 0 �̸� 255 �ʰ��� �� �����ϴ�."));
	}
	if (fMinArea > 1 || fMaxArea > 1)
	{
		m_ctrlBlobMinArea.SetWindowTextW(_T("0"));
		m_ctrlBlobMaxArea.SetWindowTextW(_T("0"));
		if (fMinArea > 1)
		{
			AfxMessageBox(_T("MinArea ���� 1 �ʰ��� �� �����ϴ�."));
		}
		else
		{
			AfxMessageBox(_T("MaxArea ���� 1 �ʰ��� �� �����ϴ�."));
		}
		
	}
	else if (fMinArea > fMaxArea)
	{
		m_ctrlBlobMinArea.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("MinArea ���� MinArea�� �ʰ��� �� �����ϴ�."));
	}
	if (fMinCircularity > 1 || fMaxCircularity > 1)
	{
		m_ctrlBlobMinCircularity.SetWindowTextW(_T("0"));
		m_ctrlBlobMaxCircularity.SetWindowTextW(_T("0"));
		if (fMinCircularity > 1)
		{
			AfxMessageBox(_T("MinCircularity ���� 1 �ʰ��� �� �����ϴ�."));
		}
		else
		{
			AfxMessageBox(_T("MaxCircularity ���� 1 �ʰ��� �� �����ϴ�."));
		}
		
	}
	else if (fMinCircularity > fMaxCircularity)
	{
		m_ctrlBlobMinCircularity.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("MinCircularity ���� MaxCircularity�� �ʰ��� �� �����ϴ�."));
	}

	if (fMinConvexity > 1 || fMaxConvexity > 1)
	{
		m_ctrlBlobMinConvexity.SetWindowTextW(_T("0"));
		m_ctrlBlobMaxConvexity.SetWindowTextW(_T("0"));
		if (fMinConvexity > 1)
		{
			AfxMessageBox(_T("MinConvexity ���� 1 �ʰ��� �� �����ϴ�."));
		}
		else
		{
			AfxMessageBox(_T("MaxConvexity ���� 1 �ʰ��� �� �����ϴ�."));
		}
		
	}
	else if (fMinConvexity > fMaxConvexity)
	{
		m_ctrlBlobMinConvexity.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("MinConvexity ���� MaxConvexity�� �ʰ��� �� �����ϴ�."));
	}
	if (fMinInertiaRatio > 1 || fMaxInertiaRatio > 1)
	{
		m_ctrlBlobMinIntiaRatio.SetWindowTextW(_T("0"));
		m_ctrlBlobMaxIntiaRatio.SetWindowTextW(_T("0"));
		if (fMinInertiaRatio > 1)
		{
			AfxMessageBox(_T("MinInertiaRatio ���� 1 �ʰ��� �� �����ϴ�."));
		}
		else
		{
			AfxMessageBox(_T("MaxInertiaRatio ���� 1 �ʰ��� �� �����ϴ�."));
		}
	}
	else if (fMinInertiaRatio > fMaxInertiaRatio)
	{
		m_ctrlBlobMinIntiaRatio.SetWindowTextW(_T("0"));
		AfxMessageBox(_T("MinInertiaRatio ���� MaxInertiaRatio�� �ʰ��� �� �����ϴ�."));
	}
}

void COpenCVTestDlg::OnBnClickedFindHarrisDetect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	cv::Mat image = m_MatImage.clone();

	// ORB ��ü ����
	cv::Ptr<cv::Feature2D> orb = cv::ORB::create();

	// Ű ����Ʈ�� ��ũ���� ���
	std::vector<cv::KeyPoint> keypoints;
	cv::Mat descriptors;
	orb->detectAndCompute(image, cv::noArray(), keypoints, descriptors);

	// Ű ����Ʈ �׸���
	cv::Mat image_with_keypoints;
	cv::drawKeypoints(image, keypoints, image_with_keypoints);

	// ��� ǥ��
	cv::namedWindow("ORB keypoints", cv::WINDOW_NORMAL);
	cv::imshow("ORB keypoints", image_with_keypoints);
	cv::waitKey(0);
	//..dddd
}

void COpenCVTestDlg::mouseCallback(int event, int x, int y, int flags, void* userdata)
{
	COpenCVTestDlg m_pMain;
	Mat MatTechingImg = g_MatImage.clone();

	if (event == EVENT_LBUTTONDOWN)
	{
		m_bDraggingFlag = true;
		m_nPosY = y;	
		m_nPosX = x;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		if (m_bDraggingFlag == true)
		{
			rectangle(MatTechingImg, Point(m_nPosX, m_nPosY), Point(x, y), Scalar(255, 0, 0), 2);
			imshow("ImageViewer", MatTechingImg);
		}
	}
	else if (event == EVENT_LBUTTONUP)
	{		
		if (m_bDraggingFlag == true)
		{
			m_bDraggingFlag = false;
			int width, height;
			width = x - m_nPosX;
			height = y - m_nPosY;
			if (width > 0 && height > 0)
			{
				rectangle(MatTechingImg, Point(m_nPosX, m_nPosY), Point(x, y), Scalar(255, 0, 0), 2);
				imshow("ImageViewer", MatTechingImg);
			}
			m_nSecondPosX = width;
			m_nSecondPosY = height;
		}	
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		// Rectangle ���� ���� �߶󳻼� �����ϱ�.
		Mat CrobImage;
		Rect rc(m_nPosX, m_nPosY, m_nSecondPosX, m_nSecondPosY);
		CrobImage = MatTechingImg(rc);
		imwrite("D:\\VisionData\\CrobImage.bmp", CrobImage);
		imshow("ImageViewer2", CrobImage);

	}
}
bool COpenCVTestDlg::WarpPolarTest()
{

	Mat image = m_MatImage.clone();
	Mat OldImage = m_MatImage.clone();
	vector<Vec3f> circles;
	CString cstrCirclePos;
	String strCirclePos;

	bool bUseContours;
	bool bUseHoughLine;
	bool bUseWarpPolar;
	bool bUseFindDarkArea;

	bUseWarpPolar = false;
	bUseFindDarkArea = true;
	bUseContours = false;
	bUseHoughLine = true;

	if (image.empty())
	{
		return true;
	}
	
	HoughCircles(image, circles, HOUGH_GRADIENT, 1, 50, 100, 100);

	if (bUseFindDarkArea)
	{
		// �̹����� �׷��̽����Ϸ� ��ȯ�մϴ�.
		Mat grayImage;
	//	cvtColor(OldImage, grayImage, COLOR_BGR2GRAY);
		Vec3i c = circles[0];
		Point center(c[0], c[1]);
		int radius = c[2];
		int x = c[0];
		int y = c[1];

		// ���� ������ �ش��ϴ� ����ũ�� �����մϴ�.
		Mat mask = Mat::zeros(image.size(), CV_8UC1);
		circle(mask, center, radius, Scalar(255), -1);

		// �̹��� ����ȭ�� �����մϴ�. (������ ����̰� ������ ������ ã�� ���̹Ƿ� �����մϴ�.)
		Mat binaryImage;
		threshold(OldImage, binaryImage, 23, 255, THRESH_BINARY);
		bitwise_not(binaryImage, binaryImage);
		// ���� �̹������� ������ ������ ã���ϴ�.
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
		findContours(binaryImage, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

		// ������ ������ ������ ����մϴ�.
		double totalArea = 0.0;
		for (const auto& contour : contours)
		{
			double area = contourArea(contour);
			totalArea += area;
		}

		// ������ ������ ������ ����մϴ�.
		std::cout << "Black region area: " << totalArea << " pixels" << std::endl;

		// ������ ������ �׸����� ǥ���� �̹����� ����մϴ�.
		cvtColor(image, image, COLOR_GRAY2BGR);
		drawContours(image, contours, -1, Scalar(0, 0, 255), 2);
		imshow("Image with Black Region", image);
	}

	if (bUseWarpPolar)
	{
		for (size_t i = 0; i < circles.size(); i++)
		{
			Vec3i c = circles[i];
			Point center(c[0], c[1]);
			int radius = c[2];
			int x = c[0];
			int y = c[1];

			cstrCirclePos.Format(_T("%d,%d"), x, y);
			strCirclePos = String(CT2CA(cstrCirclePos));
			cvtColor(OldImage, OldImage, COLOR_GRAY2BGR);
			circle(OldImage, center, radius, Scalar(0, 255, 0), 2);
			circle(OldImage, center, 2, Scalar(0, 0, 255), 3);
			putText(OldImage, strCirclePos, center, 2, 1.2, Scalar(0, 255, 0));
			imshow("ImageViewer", OldImage);

			// �� ��ǥ ��ȯ �߽� ��ǥ ����
			Point2f center2(c[0], c[1]);

			//Point2f center(image.cols / 2, image.rows / 2);

			// �� ��ǥ�� ��ȯ�� ��� �̹��� ũ�� ����
			Size polarSize(2592, 1944);

			// �� ��ǥ ��ȯ ����
			Mat polarImage;
			Mat polarImage_canny;
			warpPolar(image, polarImage, polarSize, center2, polarSize.width / 2, INTER_LINEAR | WARP_FILL_OUTLIERS);

			// ��� ���
			resize(polarImage, polarImage, Size(1024, 768));
			imshow("Polar Transformed Image", polarImage);
			Canny(polarImage, polarImage_canny, 50, 255, 3, false);
			imshow("Polar Canny Image", polarImage_canny);

			if (bUseContours)
			{
				Mat ContoursImage;
				vector<vector<Point>> contours;
				vector<Vec4i> hierarchy;
				findContours(polarImage_canny, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE); //��ο� ��濡�� ���� ��ü�� ã�°��� ������.

				vector<vector<Point> >hull(contours.size());

				cvtColor(polarImage_canny, polarImage_canny, COLOR_GRAY2BGR);
				for (int j = 0; j < contours.size(); j++)
				{
					convexHull(contours[j], hull[j]);
				}
				for (int j = 0; j < contours.size(); j++)
				{
					//if (contours[j].size() > 1000)
					//{
					drawContours(polarImage_canny, contours, j, Scalar(255, 0, 255), 1);
					//}
					//if (hull[j].size() > 0)
					//{
					//	drawContours(polarImage_canny, hull, j, Scalar(255, 0, 0), 1);
					//}
				}



				imshow("Polar Canny Image", polarImage_canny);
			}
			if (bUseHoughLine)
			{
				CString strThreshold, strMin, strMax;
				int nParam1, nParam2, nParam3;
				GetDlgItem(IDC_TEST_MAX_VALUE)->GetWindowTextW(strMax);
				GetDlgItem(IDC_TEST_MIN_VALUE)->GetWindowTextW(strMin);
				GetDlgItem(IDC_TEST_THRESHOLD)->GetWindowTextW(strThreshold);
				nParam1 = _ttoi(strThreshold);
				nParam2 = _ttoi(strMin);
				nParam3 = _ttoi(strMax);

				if (nParam1 == 0)
				{
					nParam1 = 100;
				}
				if (nParam2 == 0)
				{
					nParam2 = 100;
				}
				if (nParam3 == 0)
				{
					nParam3 = 10;
				}

				vector<Vec4i> lines;
				HoughLinesP(polarImage_canny, lines, 1, (CV_PI / 180), nParam1, nParam2, nParam3);
				//��� ����  ,Threshold, min_line_length, max_line_gap
				Mat lineImage = polarImage_canny.clone();
				cvtColor(polarImage, polarImage, COLOR_GRAY2BGR);
				for (size_t i = 0; i < lines.size(); i++)
				{
					cv::Vec4i line = lines[i];
					cv::line(polarImage, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(255, 0, 0), 2);
				}

				//cv::Mat combinedImage;
				//cv::hconcat(image, polarImage_canny, combinedImage);
				//cv::hconcat(combinedImage, lineImage, combinedImage);

				cv::imshow("Detected Lines", polarImage);
			}
		}
	}

	waitKey(0);
	destroyAllWindows();

	return 0;
}


void COpenCVTestDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	WarpPolarTest();
}
