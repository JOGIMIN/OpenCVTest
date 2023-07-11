// AniUtil.h: Utilities.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ANIUTIL_HEADER_INCLUDED_)
#define ANIUTIL_HEADER_INCLUDED_

#include <math.h>

//______________________________________________________________________________
// Delay
extern void DoEvents();
extern void Delay(long ms, BOOL bEvent = FALSE);

//______________________________________________________________________________
// �ݿø� ó��
extern int RoundupInt(double value);
extern long RoundupLong(double value);

#define RoundupDouble(x,dig) (floor((x)*pow(10,dig)+0.5)/pow(10,dig))
/**
�Ǽ� x�� �ݿø��� �ڸ��� dig�� �μ��� ���޹޴µ� 
dig�� 0�� ����(Zero Base)���� �ϹǷ� �츮�� �����ϴ� �Ҽ��� �ڸ������ٴ� �ϳ� �� �۴�. 
�� dig�� 0�� �� �Ҽ��� ù ��° �ڸ��� �����ϸ� n�� �� n+1�ڸ����� �ݿø��Ͽ� 
�ᱹ �ݿø� �� dig�ڸ������� ��ȿ�� ���� ���� �ȴ�. 
pow �Լ��� �����µ� �� ����ϹǷ� dig�� ������ �ָ� �����ο��� �ݿø��� �� ���� �ִ�.
123.456789�� -2�ڸ� �ݿø� = 100.000000
123.456789�� 0�ڸ� �ݿø� = 123.000000
123.456789�� 2�ڸ� �ݿø� = 123.460000
*/
extern CString GetNowSystemTimeMilliseconds();
extern CString GetNowSystemTimeMilliseconds2();
extern CString GetNowSystemTimeMillisecondsSirius();  //JMHWANG 12.02.08
extern CString GetNowSystemTimeMillisecondsSirius2();  //JMHWANG 12.02.08
extern CString GetNowSystemTimeMillisecondsSirius3(); //JMHWANG 12.02.08

// ū��
extern double GetMax(double v1, double v2);

// �ٻ�ġ Ȯ��
extern bool IsAboutSame(double ref, double v1, double in_pos);

// ��� ��� ���ϱ�
extern double GetMean(double* array, int size);

// ǥ�� ���� ��� �Լ�
double GetStandardDeviation(double* array, int size, int option);

// ��Ÿ��� ���� ( �밢�� ���� �� �غ��� ������ ���� ���ϱ�)
extern double GetPitaHight(double x, double y);
// ��Ÿ��� ���� ( ���� �� �غ��� ������ �밢�� ���� ���ϱ�)
extern double Getpita(double x, double y);

extern CString Hex2Bin(CString& sHex);
//______________________________________________________________________________
extern CString GetDouble2String_MM(double dd);
//______________________________________________________________________________
extern CString GetExtractionCommaMsg(CString& strMsg);
extern CString GetExtractionTabMsg(CString& strMsg);
extern CString GetExtractionDotMsg(CString& strMsg);
extern CString GetExtractionSpaceMsg(CString& strMsg);

extern CString GetExtractionParenthese(CString& strMsg);
extern CString GetExtractionSquareMsg(CString& strMsg);
extern CString GetExtractionHypenBeforeMsg(CString strMsg1);
extern CString GetExtractionHypenMsg(CString &strMsg);
extern CString GetExtractionHypenAfterMsg(CString strMsg1);

//>> 140404 JSPark
extern CString GetExtractionDashMsg(CString& strMsg);
extern CString GetExtractionColonMsg(CString& strMsg);
//<<
//______________________________________________________________________________
extern CString GetDateString();
extern CString GetDateString2();
extern CString GetDateString3();
extern CString GetDateString4();
extern CString GetDateString5();
extern CString GetDateString6(); //160512 JSLee
extern CString GetDateString4Folder();

extern CString GetTimeString();
extern CString GetTimeString2();
extern CString GetTimeString3();
extern CString GetTimeString4(); // kkj 12.04.10

extern int String2Hex(CString strVal);
extern int String2Int(CString strVal);
extern float String2Float(CString strVal);
extern CString Hex2String(int value);
extern CString Int2String(int value);
extern CString Float2String(float value, CString strFormat = _T("%f"));
extern double String2Double(CString strVal);
extern CString Double2String(double value, CString strFormat = _T("%lf"));
extern int Hex2Int(char cHex);
extern unsigned char Hex2Byte(char hex);

extern BOOL SaveBitmap(HBITMAP hbit, LPCTSTR Path); //150612 HSOh
extern BOOL FileExists(LPCTSTR strFilePath);
extern BOOL FileExists(LPCTSTR strStartPath, LPCTSTR strFileName);
extern BOOL FileExists(CString& strStartFolder, CString strFileName, bool SearchSubFolder);

extern int CheckAndCreateFolder(LPCTSTR szFolderPath);
extern void DeleteFolderAndFile(LPCTSTR szFolderPath);
extern BOOL CreateFolders(LPCTSTR szFolderPath);
extern BOOL CopyFolderAndFile(LPCTSTR szSvrFolderPath, LPCTSTR szDefFolderPath);

extern void FillSpace(TCHAR *pszIn, short nStr);
extern void Select_Sort(int parm_data[], int parm_count);
extern char* StringToChar(CString str);//CString�� char*�� ��ȯ
extern CString CharToString(char *str);//char*�� CString�� ��ȯ
extern void SetSystemTime(CString strTime);

extern void AutoDeleteFile(CString strTarget, int nDuration);

//______________________________________________________________________________
#define U_PI	3.14159265
#define MATHFUNC_PI	3.14159265358979323846	
#define INCH4MM 25.4

extern double Rad2Deg(double s);
extern double Deg2Rad(double s);
//extern double _ttof(LPCTSTR strVal);   //>>150313.kty  Unicode(string-->float)


//______________________________________________________________________________
//	UVW ȸ�� ����

//������ ���� ������ ��ȯ
//���� : ���� * PI / 180��
//���� ���� ������ ��ȯ
//���� : ���Ȱ� * 180�� / PI

//�� ȸ�� �ݰ�R
//��2 : SQRT = 1.414213562

//#define SQRT2 1.414213562

#define SQRT2 1.414
#define StageRotatvalue 137.2953022
//#define StageRotatvalue 30
//#define ThetaY1 123.11134
//#define ThetaY2 303.11134
//#define ThetaX 56.888658
#define ThetaY1 146.888658
#define ThetaY2 213.111342
#define ThetaX 33.111342
extern double UVWTablePitch(double s = 0.0, double x = 0.0, double cur = 0.0);
//------------------------------------------------

extern void Char2DWORD2(unsigned char* strVal, WORD* sum, int iSize); //unsigned char* -> WORD

//>> 140513 JSPark
//////////////////////////////////////////////////////////////////////////
int findstr(const char *str, const char *what);		// ���ڿ�, ã�� ����
bool str_remove(char* str, int start, int end);		// ���ڿ�, ���� ��ġ, �� ��ġ
bool str_insert(char* str, char* src, int nStart);	// ���ڿ�, ������ ���ڿ�, ��ġ
//////////////////////////////////////////////////////////////////////////
//<<
#endif

/*
��

  %y - �� 2�ڸ� (09)  
  %Y - ��ü (2009)  
		
��
  %m - 01~12 (03)			
  %b - ���� 3���� (Mar)  
  %B - ���� ��ü (March)
		
��					  
  %d - 01~31 �� ���� (10)						
  %j - 001~365 �� ���� (069)
	  
��
  %H - 00~23 24�� ���� (14)								  
  %I (�빮�� ����) - 01~12 12�� ���� (02)
				
��						  
  %M - 00~59 (12)												
��							  
  %S - 00~59 (15)
				  
����														  
  %a - ��� (Tue)														
  %A - ���� (Tuesday)												  
  %w - �Ͽ��� 0 ���� (2)														
					
��
  %U - 00~53 ��������� ������ �Ͽ��� (10)													  
  %W - 00~53 ��������� ������ ������ (10)
			
��Ÿ																			  
  %p - AM/PM (PM)																			
  %x - ��/��/�� (03/10/09)																	  
  %X - ��:��:�� (14:12:15)															
  %c - ��/��/�� ��:��:�� (03/10/09 14:12:15)
  %% - % ��ȣ (%)
  %z, %Z - �ð��� �̸� (���ѹα� ǥ�ؽ�)							
*/