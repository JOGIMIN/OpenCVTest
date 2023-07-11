#include "OpenCVTest\stdafx.h"
#include "AniUtil.h"
#include <math.h>
#include <string>

using namespace std;

#ifdef _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

//______________________________________________________________________________
/** @brief Event�� ó���Ѵ�.			 										 
*/
void DoEvents()
{
	MSG message;
	if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
	{
		::TranslateMessage(&message);
		::DispatchMessage(&message);
	}
}

/** @brief ms���� Waiting�Ѵ�.			 										 
*/
void Delay(long ms, BOOL bEvent)
{
	double s, e;
	double Ms = (double) ms;
	s = (double) GetCurrentTime();
	do
	{
		if(bEvent)
			DoEvents();

		Sleep(1);
		e = (double) GetCurrentTime();
	}
	while ((e - s) < Ms);
}



//______________________________________________________________________________
/** @brief �ݿø� ó��
*/
int RoundUp(double value)
{
	return (int) ((value > 0) ? value + 0.9 : value - 0.9);
}

int RoundupInt(double value)
{
	return (int) ((value > 0) ? value + 0.5 : value - 0.5);
}

long RoundupLong(double value)
{
	return (long) ((value > 0) ? value + 0.5 : value - 0.5);
}

/** @brief ū�� 
*/
double GetMax(double v1, double v2)
{
	return (double) ((v1 > v2) ? v1 : v2);
}

/** @brief �ٻ�ġ Ȯ�� 
*/
bool IsAboutSame(double ref, double v1, double in_pos)
{
	return ( (ref-in_pos < v1) && (ref+in_pos > v1) );
}


/** @brief ��� ��� ���ϱ� 
*/
double GetMean(double* array, int size)
{
	double sum = 0.0;

	for (int i = 0; i < size; i++)
		sum += array[i];

	return sum / size;
}

/** @brief ǥ�� ���� ��� 
*/
double GetStandardDeviation(double* array, int size, int option)
{
	// Option 0 / 1
	// ǥ���� ǥ������ ���ϱ� (STDEV) : GetStandardDeviation(foo, sizeof(foo) / sizeof(foo[0]), 1));
	// ������ ��ü�� ǥ������ ���ϱ� (STDEVP) : GetStandardDeviation(foo, sizeof(foo) / sizeof(foo[0]), 0));

	// �迭 ��Ұ� 1���ۿ� ���� ����
	// NaN(���ڰ� �ƴ�)�̶�� �ǹ̷�
	// -1.#IND0 �� ��ȯ
	if (size < 2) return sqrt(-1.0);

	double sum = 0.0;
	double sd = 0.0;
	double diff;
	double meanValue = GetMean(array, size);

	for (int i = 0; i < size; i++) {
		diff = array[i] - meanValue;
		sum += diff * diff;
	}
	sd = sqrt(sum / (size - option));

	return sd;
}

// ��Ÿ��� ���� ( �밢�� ���� �� �غ��� ������ ���� ���ϱ�)
double GetPitaHight(double x, double y)
{
	// x = �밢, y = �غ�
	return sqrt((x*x) - (y*y));
}
// ��Ÿ��� ���� ( ���� �� �غ��� ������ �밢�� ���� ���ϱ�)
double GetPita(double x, double y)
{
	// x = �غ�, y = ����
	return sqrt((x*x) + (y*y));
}

//______________________________________________________________________________
/** @brief um -> mm (Cstring)
 @return "0.001"
*/
CString GetDouble2String_MM(double tmp_d)
{
	CString strValue;
	tmp_d *= 0.001;
	strValue.Format(_T("%6.3f"),tmp_d);
	return strValue;
}

//______________________________________________________________________________
/** @brief �ý��� ��¥�� ���ϴ� �Լ�
 @return "1999-00-00"
*/
CString GetDateString()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%d-%02d-%02d"), now.GetYear(), now.GetMonth(), now.GetDay());
	return strDate;
}

//______________________________________________________________________________
/** @brief �ý��� ��¥�� ���ϴ� �Լ�2
 @return "19990000"
*/
CString GetDateString2()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%d%02d%02d"), now.GetYear(), now.GetMonth(), now.GetDay());
	return strDate;
}
//______________________________________________________________________________
/** @brief �ý��� ��¥,�ð��� ���ϴ� �Լ�2
// @return "1999000000" << 131110 kmh
 @return "99000000"
*/
CString GetDateString3()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
//<< 131110 kmh
//	strDate.Format("%04d%02d%02d%02d", now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour());
	strDate.Format(_T("%02d%02d%02d%02d"), now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour());
//<<
	return strDate;
}

//______________________________________________________________________________
/** @brief �ý��� ��¥,�ð��� ���ϴ� �Լ�2
 @return "1999000000"
*/
CString GetDateString4()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%04d%02d%02d%02d%02d%02d"), now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
	return strDate;
}

//______________________________________________________________________________
/** @brief �ý��� ��¥,�ð��� ���ϴ� �Լ�5
 @return "0000"
*/
CString GetDateString5()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%02d-%02d"), now.GetMonth(), now.GetDay());
	return strDate;
}

//______________________________________________________________________________
/** @brief �ý��� ��¥,�ð��� ���ϴ� �Լ�5
@return "0000/00/00 00:00:00"
*/
CString GetDateString6()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%04d/%02d/%02d %02d:%02d:%02d"), now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
	return strDate;
}


//______________________________________________________________________________
/** @brief �ý��� ��¥,�ð��� ������ ���ϴ� �Լ�4
 @return "1999\\00\\00\\00\\"
*/
CString GetDateString4Folder()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%04d\\%02d\\%02d\\%02d\\"), now.GetYear(), now.GetMonth(), now.GetDay(), now.GetHour());
	return strDate;
}
//______________________________________________________________________________
/** @brief �ý��� �ð��� ���ϴ� �Լ� 
 @return "00:00:00"
*/
CString GetTimeString()
{
	COleDateTime now;
	CString strTime;
	now = COleDateTime::GetCurrentTime();
	strTime.Format(_T("%02d:%02d:%02d"), now.GetHour(), now.GetMinute(), now.GetSecond());
	return strTime;
}

//______________________________________________________________________________
/** @brief �ý��� �ð��� ���ϴ� �Լ�2
 @return "000000"
*/
CString GetTimeString2()
{
	COleDateTime now;
	CString strTime;
	now = COleDateTime::GetCurrentTime();
	strTime.Format(_T("%02d%02d%02d"), now.GetHour(), now.GetMinute(), now.GetSecond());
	return strTime;
}

//______________________________________________________________________________
/** @brief �ý��� �ð��� ���ϴ� �Լ�3
 @return "000000"
*/
CString GetTimeString3()
{
	COleDateTime now;
	CString strTime;
	now = COleDateTime::GetCurrentTime();
	strTime.Format(_T("%02d%02d%02d%02d%02d"), now.GetMonth(), now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());
	return strTime;
}
//________________________________________________________________________________
/** @brief �ý��� �ð��� ���ϴ� �Լ�3
 @return "00"
 */
CString GetTimeString4()
{
	COleDateTime now;
	CString strDate;
	now = COleDateTime::GetCurrentTime();
	strDate.Format(_T("%02d"), now.GetHour());
	return strDate;
}
//______________________________________________________________________________
int String2Hex(CString strVal)
{
	if (strVal.IsEmpty())
		return 0x0;
	int value;
	strVal.MakeUpper();
//>> 130227 JSPark
#if _MSC_VER > 1200 // VS6.0 �̻�
#ifdef _MBCS
	sscanf_s(strVal.GetString(), _T("%X"), &value);
#else
	size_t bufSize = strVal.GetLength()+1;
	size_t ret;
	char * szchar = new char[bufSize];
	memset(szchar, 0, bufSize);
	wcstombs_s(&ret, szchar, bufSize, strVal.GetBuffer(), bufSize); 
	
	sscanf_s(szchar, "%X", &value);
	delete [] szchar;
#endif
#else // VS6.0 ����
	_stscanf(strVal, "%X", &value);
#endif
//<<
	return value;
}

CString Hex2String(int value)
{
	CString strVal;
	strVal.Format(_T("%X"), value);
	return strVal;
}

int Hex2Int(char cHex)
{
	switch(cHex){
		case 'F':
		case 'f':	return(15);
		case 'E':
		case 'e':	return(14);
		case 'D':
		case 'd':	return(13);
		case 'C':
		case 'c':	return(12);
		case 'B':
		case 'b':	return(11);
		case 'A':
		case 'a':	return(10);
		case '9':	return(9);
		case '8':	return(8);
		case '7':	return(7);
		case '6':	return(6);
		case '5':	return(5);
		case '4':	return(4);
		case '3':	return(3);
		case '2':	return(2);
		case '1':	return(1);
		default:	return(0);
	}
}

unsigned char Hex2Byte(char hex)
{
	switch(hex)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': case 'a': return 10;
	case 'B': case 'b': return 11;
	case 'C': case 'c': return 12;
	case 'D': case 'd': return 13;
	case 'E': case 'e': return 14;
	case 'F': case 'f': return 15;
	}
	return 32;
}

//______________________________________________________________________________
int String2Int(CString strVal)
{
	if (strVal.IsEmpty())
		return 0;
	int value;
//>> 130227 JSPark
#if _MSC_VER > 1200 // VS6.0 �̻�
#ifdef _MBCS
	sscanf_s(strVal.GetString(), _T("%X"), &value);
#else
	size_t bufSize = strVal.GetLength()+1;
	size_t ret;
	char * szchar = new char[bufSize];
	memset(szchar, 0, bufSize);
	wcstombs_s(&ret, szchar, bufSize, strVal.GetBuffer(), bufSize); 
	
	sscanf_s(szchar, "%d", &value);
	delete [] szchar;
#endif
#else // VS6.0 ����
	_stscanf(strVal, "%X", &value);
#endif
//<<
	return value;
}

CString Int2String(int value)
{
	CString strVal;
	strVal.Format(_T("%d"), value);
	return strVal;
}

//______________________________________________________________________________
float String2Float(CString strVal)
{
	if (strVal.IsEmpty())
		return 0.0f;
	float value;
//>> 130227 JSPark
#if _MSC_VER > 1200 // VS6.0 �̻�
#ifdef _MBCS
	sscanf_s(strVal.GetString(), _T("%f"), &value);
#else
	size_t bufSize = strVal.GetLength()+1;
	size_t ret;
	char * szchar = new char[bufSize];
	memset(szchar, 0, bufSize);
	wcstombs_s(&ret, szchar, bufSize, strVal.GetBuffer(), bufSize); 
	
	sscanf_s(szchar, "%f", &value);
	delete [] szchar;
#endif
#else // VS6.0 ����
	_stscanf(strVal, "%f", &value);
#endif
//<<
	return value;
}

CString Float2String(float value, CString strFormat)
{
	CString strVal;
	strVal.Format(strFormat, value);
	return strVal;
}

//______________________________________________________________________________
double String2Double(CString strVal)
{
	if (strVal.IsEmpty())
		return 0.0;
	double value;
//>> 130227 JSPark
#if _MSC_VER > 1200 // VS6.0 �̻�
#ifdef _MBCS
	sscanf_s(strVal.GetString(), _T("%lf"), &value);
#else
	size_t bufSize = strVal.GetLength()+1;
	size_t ret;
	char * szchar = new char[bufSize];
	memset(szchar, 0, bufSize);
	wcstombs_s(&ret, szchar, bufSize, strVal.GetBuffer(), bufSize); 
	
	sscanf_s(szchar, "%lf", &value);
	delete [] szchar;
#endif
#else // VS6.0 ����
	_stscanf(strVal, "%lf", &value);
#endif
//<<
	return value;
}

CString Double2String(double value, CString strFormat)
{
	CString strVal;
	strVal.Format(strFormat, value);
	return strVal;
}

//______________________________________________________________________________
BOOL FileExists(LPCTSTR strFilePath)
{
	CFileFind aFile;
	BOOL IsExist = aFile.FindFile(strFilePath);
	aFile.Close();
	return IsExist;
}

BOOL FileExists(LPCTSTR strStartPath, LPCTSTR strFileName)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	tstring strFileFound = strStartPath;
	strFileFound += _T("\\*.*");		 
	
    WIN32_FIND_DATA info;
	
	BOOL bRet = FALSE;
	HANDLE hp = FindFirstFile(strFileFound.c_str(), &info);   //���丮�� ������ �ִ��� ù��° ���ϸ�.
    do
    {
        if (!((_tcscmp(info.cFileName, _T("."))==0) || (_tcscmp(info.cFileName, _T(".."))==0))) 
		{
            if((info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==FILE_ATTRIBUTE_DIRECTORY)  //Sub���丮�� �����ϴ°�� 
            {
                tstring strSubFolder = strStartPath;
				strSubFolder += _T("\\");
				strSubFolder += info.cFileName;
				
				if((bRet = FileExists(strSubFolder.c_str(), strFileName)))
					break;
            }
			else if(!_tcscmp(info.cFileName, strFileName))
			{
				bRet = TRUE;
				break;
			}
        }
		
    }while(FindNextFile(hp, &info));
	
    FindClose(hp);
	
	return bRet;
}

BOOL FileExists(CString& strStartFolder, CString strFileName, bool SearchSubFolder)
{
	CString strFilePath;
	if (strStartFolder.Right(1) != _T("\\"))
		strStartFolder += _T("\\");
	strFilePath = strStartFolder + strFileName;
	CFileFind aFile;
	BOOL IsExist = aFile.FindFile(strFilePath);
	if (IsExist || !SearchSubFolder)
	{
		aFile.Close();
		return IsExist;
	}

	CString strFile = strStartFolder + _T("*.*");
	IsExist = aFile.FindFile(strFile);
	if (IsExist)
	{
		IsExist = aFile.FindNextFile();
		while (IsExist)
		{
			if (aFile.IsDirectory() && !aFile.IsDots())
			{
				strFile = aFile.GetFilePath() + _T("\\") + strFileName;
				if (FileExists(strFile))
				{
					strStartFolder = aFile.GetFilePath();
					aFile.Close();
					return TRUE;
				}
			}
			IsExist = aFile.FindNextFile();
			Delay(2, TRUE);  //<< 150613 JYLee
		}
		if (aFile.IsDirectory() && !aFile.IsDots())
		{
			strFile = aFile.GetFilePath() + _T("\\") + strFileName;
			if (FileExists(strFile))
			{
				strStartFolder = aFile.GetFilePath();
				aFile.Close();
				return TRUE;
			}
		}
	}
	aFile.Close();
	return FALSE;
}

//______________________________________________________________________________
/** @brief Radian -> Degree �Լ�
 @return Degree
*/
double Rad2Deg(double s)
{
	return (s * 180.0 / MATHFUNC_PI);
}

/** @brief Degree -> Radian �Լ�
 @return Radian
*/
double Deg2Rad(double s)
{
	return (s * MATHFUNC_PI / 180.0);
}

CString GetExtractionCommaMsg(CString& strMsg)
{
	int count = strMsg.Find(',');
	CString m = strMsg.SpanExcluding(_T(","));
	if(count == -1)
	{
		strMsg = _T(""); 
		return m;
	}
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString GetExtractionTabMsg(CString& strMsg)
{
	int count = strMsg.Find('\t');
	CString m = strMsg.SpanExcluding(_T("\t"));
	if(count == -1)
	{
		strMsg = _T(""); 
		return m;
	}
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString GetExtractionDotMsg(CString& strMsg)
{
	int count = strMsg.Find('.');
	CString m = strMsg.SpanExcluding(_T("."));
	if(count == -1)
	{
		strMsg = _T(""); 
		return m;
	}
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString GetExtractionSpaceMsg(CString& strMsg)
{
	int count = strMsg.Find(' ');
	CString m = strMsg.SpanExcluding(_T(" "));
	if(count == -1)
	{
		strMsg = _T(""); 
		return m;
	}
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString GetExtractionParenthese(CString& strMsg)
{
	int count = strMsg.Find('(');
	CString m = strMsg.SpanExcluding(_T(","));
	if (count == -1)
	{
		strMsg = _T("");
		return m;
	}
	strMsg = strMsg.Mid(count + 1);
	return m;
}

CString GetExtractionSquareMsg(CString& strMsg)
{
	int count = strMsg.Find('(');
	CString m = strMsg.SpanExcluding(_T("("));
	if (count == -1)
	{
		strMsg = L"";
		return m;
	}
	strMsg = strMsg.Mid(count + 1);
	return m;
}

CString GetExtractionHypenBeforeMsg(CString strMsg1)
{
	CString strMsg;
	strMsg = strMsg1;
	int count = strMsg.Find('-');
	CString m = strMsg.Left(count);
	if (m.GetLength() > 0)
	{
		return m;
	}
	else
	{
		m = _T("");
		return m;
	}
}

CString GetExtractionHypenMsg(CString &strMsg)
{
	int count = strMsg.Find('-');
	CString m = strMsg.SpanExcluding(_T("-"));
	if (count == -1)
	{
		strMsg = _T("");
		return m;
	}
	strMsg = strMsg.Mid(count + 1);
	return m;
}

CString GetExtractionHypenAfterMsg(CString strMsg1)
{
	CString strMsg;
	strMsg = strMsg1;
	int count = strMsg.Find('-');
	CString m = strMsg.Mid(count + 1);
	if (m.GetLength() > 0)
	{
		return m;
	}
	else
	{
		m = _T("");
		return m;
	}
}

CString GetExtractionDashMsg(CString& strMsg) //140404 JSPark
{
	int count = strMsg.Find('-');
	CString m = strMsg.SpanExcluding(_T("-"));
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString GetExtractionColonMsg(CString& strMsg) //140404 JSPark
{
	int count = strMsg.Find(':');
	CString m = strMsg.SpanExcluding(_T(":"));
	strMsg = strMsg.Mid(count+1);
	return m;
}

CString Hex2Bin(CString& sHex)
{
	CString sBin;
	long	lValue;
	TCHAR *ptr;
	
	lValue = _tcstol(sHex, &ptr, 16);
	_ltot(lValue, sBin.GetBuffer(0), 2);

// 	CString sBin, sTmp;
// 	long n;
// 	char *str, *ptr;
// 
// 	str = new char[2];
// 	memset(str, NULL, sizeof(char)*2);
// 	for(int i=0; i< sHex.GetLength(); i++)
// 	{
// 		memcpy(str, sHex.Mid(i,1), 1);
// 		n = strtol(str, &ptr, 16);
// 		for(int j=0; j<4; j++)
// 		{
// 			itoa(n & 0x1, str,10);
// 			sTmp += str;
// 			n = n>>1;
// 		}
// 		sTmp.MakeReverse();
// 		sBin += sTmp;
// 		sTmp = _T("");
// 	}
// 
// 	delete [] str; str = NULL;

	return sBin;
}

extern CString GetNowSystemTimeMilliseconds()
{
	SYSTEMTIME local;
	CString strTime = _T("");
	
	//Year-month-Day Hour:Minute:Second:Milliseconds Display

	::GetLocalTime(&local);		
	strTime.Format(_T("%04d-%02d-%02d %02d:%02d:%02d:%03d"),
		(int)local.wYear, 
		(int)local.wMonth, 
		(int)local.wDay ,
		(int)local.wHour, 
		(int)local.wMinute, 
		(int)local.wSecond,
		(int)local.wMilliseconds);

	return strTime;
}

extern CString GetNowSystemTimeMilliseconds2()
{
	SYSTEMTIME local;
	CString strTime = _T("");
	

	::GetLocalTime(&local);		
	strTime.Format(_T("%02d:%02d:%02d:%03d"),
		(int)local.wHour, 
		(int)local.wMinute, 
		(int)local.wSecond,
		(int)local.wMilliseconds);

	return strTime;
}
//>>JMhwang 12.02.08
extern CString GetNowSystemTimeMillisecondsSirius()
{
	SYSTEMTIME local;
	CString strTime = _T("");
	
	//Year-month-Day Hour:Minute:Second:Milliseconds Display
	
	::GetLocalTime(&local);		
	strTime.Format(_T("%04d%02d%02d%02d%02d%02d"),
		(int)local.wYear, 
		(int)local.wMonth, 
		(int)local.wDay ,
		(int)local.wHour, 
		(int)local.wMinute, 
		(int)local.wSecond);

	return strTime;

}
extern CString GetNowSystemTimeMillisecondsSirius2()
{
	SYSTEMTIME local;
	CString strTime = _T("");
	
	//Year-month-Day Hour:Minute:Second:Milliseconds Display
	
	::GetLocalTime(&local);		
	strTime.Format(_T("%04d-%02d-%02d\t%02d:%02d:%02d:%03d"),
		(int)local.wYear, 
		(int)local.wMonth, 
		(int)local.wDay ,
		(int)local.wHour, 
		(int)local.wMinute, 
		(int)local.wSecond,
		(int)local.wMilliseconds);
	
	return strTime;
}

extern CString GetNowSystemTimeMillisecondsSirius3()
{
	SYSTEMTIME local;
	CString strTime = _T("");
	
	//Year-month-Day Hour:Minute:Second:Milliseconds Display
	
	::GetLocalTime(&local);		
	strTime.Format(_T("%02d:%02d:%02d:%03d"),
		(int)local.wHour, 
		(int)local.wMinute, 
		(int)local.wSecond,
		(int)local.wMilliseconds);
	
	return strTime;
}
//<<
//______________________________________________________________________________
// ���ڿ� ���� ä���
void FillSpace(TCHAR *pszIn, short nStr)
{
	TCHAR *pszDm = new TCHAR[_tcslen(pszIn) + 1];
	short	nLen = (short)_tcslen(pszIn);
	
	memset(pszDm, 0, sizeof(TCHAR) * (nLen + 1));
	if (nLen != 0) { _tcsncpy(pszDm, pszIn, nLen); }
	
	memset(pszIn, ' ', nStr);	*(pszIn + nStr) = '\0';
	if (nLen == 0) { 
		delete [] pszDm;	pszDm = NULL; 
		return; 
	}
	if (nStr == 0) { 
		delete [] pszDm;	pszDm = NULL;
		return; 
	}
	if (nLen > nStr) { nLen = nStr; }
	
	_tcsncpy(pszIn, pszDm, nLen);	
	delete [] pszDm;	pszDm = NULL;
}

void Select_Sort(int parm_data[], int parm_count) 
{ 	
    int min_data = 0, min_index = 0; 	
    int i, j; 	
    int comparison_count = 0; 	
	
    for(i = 0; i < parm_count - 1; i++){ 		
        min_index = i; 		
        min_data = parm_data[i]; 		
        for(j = i + 1; j < parm_count; j++){ 			
            comparison_count++; 			
            if(min_data > parm_data[j]){ 				
                min_data = parm_data[j]; 				
                min_index = j; 				
            } 			
        } 		
        parm_data[min_index] = parm_data[i];		
        parm_data[i] = min_data; 		
    } 	
} 

// CString �� Char
char* StringToChar(CString str)
{	
	char *szStr = NULL;	
#if defined(UNICODE) || defined(_UNICODE)	
	int nLen = str.GetLength() * 2;	
	TCHAR *tszTemp = NULL;	
	tszTemp = new TCHAR[nLen];	
	memset(tszTemp, 0x00, nLen*sizeof(TCHAR));	
	_tcscpy(tszTemp, str);	
	// Get size (�������Ǵ¹���Ʈ������)	
	int nSize = WideCharToMultiByte(CP_ACP, 0, tszTemp, -1, NULL, NULL, NULL, NULL);	
	szStr = new char[nSize];	
	memset(szStr, 0x00, nSize);	
	WideCharToMultiByte(CP_ACP, 0, tszTemp, -1, szStr, nSize, NULL, NULL);	
	if(tszTemp)		
	{		
		delete [] tszTemp;		
		tszTemp = NULL;		
	}	
#else	
	int nLen = str.GetLength() + 1;	
	szStr = new char[nLen];	
	memset(szStr, 0x00, nLen);	
	strcpy(szStr, str);	
#endif	
	return szStr;	
}

// Char �� CString
CString CharToString(char *str)
{	

	CString cStr;	
#if defined(UNICODE) || defined(_UNICODE)	
	int nLen = strlen(str) + 1;	
	TCHAR *tszTemp = NULL;	
	tszTemp = new TCHAR[nLen];	
	memset(tszTemp, 0x00, nLen*sizeof(TCHAR));	
	MultiByteToWideChar(CP_ACP, 0, str, -1, tszTemp, nLen*sizeof(TCHAR));	
	cStr.Format(_T("%s"), tszTemp);	
	if(tszTemp)		
	{		
		delete [] tszTemp;		
		tszTemp = NULL;		
	}	
#else	
	cStr.Format("%s", str);	
#endif	

#if defined(UNICODE) || defined(_UNICODE)	
	delete [] tszTemp;
#endif

	return cStr;		
}

int CheckAndCreateFolder(LPCTSTR szFolderPath)
{
	DWORD dwRet = GetFileAttributes(szFolderPath);
	if(dwRet != FILE_ATTRIBUTE_DIRECTORY)		// ������ �������� �ʴ� ���.
	{	
		int iRet = CreateDirectory(szFolderPath, NULL);
		
		if( iRet==0 )						// �������� ���� ���. 
		{
			AfxMessageBox(_T("Directory Creation Fail.!!"));
			return -1;
		}
	}
	else
		return 0;
	
	return 1;
}

void DeleteFolderAndFile(LPCTSTR szFolderPath)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	tstring strFileFound = szFolderPath;
	strFileFound += _T("\\*.*");		 
	
    WIN32_FIND_DATA info;

	HANDLE hp = FindFirstFile(strFileFound.c_str(), &info);   //���丮�� ������ �ִ��� ù��° ���ϸ�.
    do
    {
        if (!((_tcscmp(info.cFileName, _T("."))==0) || (_tcscmp(info.cFileName, _T(".."))==0))) 
		{
            if((info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==FILE_ATTRIBUTE_DIRECTORY)  //Sub���丮�� �����ϴ°�� 
            {
                tstring strSubFolder = szFolderPath;
				strSubFolder += _T("\\");
				strSubFolder += info.cFileName;

				DeleteFolderAndFile(strSubFolder.c_str()); /// {return (_Ptr == 0 ? _Nullstr() : _Ptr); } 
				//RemoveDirectory(strPath);		// ���⼭ ȣ���ϸ� ���� ������ ����
             }
            else
			{
				strFileFound = szFolderPath;
				strFileFound += _T("\\");
				strFileFound += info.cFileName;
				BOOL retVal = DeleteFileW(strFileFound.c_str());
            }

        }

    }while(FindNextFile(hp, &info));
    
	FindClose(hp);

	RemoveDirectory(szFolderPath); //���⼭ ȣ���ϸ� �ֻ��� �������� ����
}

void DeleteFolderAndFile(LPCTSTR szFolderPath, time_t result)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	tstring strFileFound = szFolderPath;
	strFileFound += _T("\\*.*");

	WIN32_FIND_DATA info;

	CFileStatus	rStatus;

	HANDLE hp = FindFirstFile(strFileFound.c_str(), &info);   //���丮�� ������ �ִ��� ù��° ���ϸ�.
	do
	{
		if (!((_tcscmp(info.cFileName, _T(".")) == 0) || (_tcscmp(info.cFileName, _T("..")) == 0)))
		{
			if ((info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)  //Sub���丮�� �����ϴ°�� 
			{
				tstring strSubFolder = szFolderPath;
				strSubFolder += _T("\\");
				strSubFolder += info.cFileName;

				DeleteFolderAndFile(strSubFolder.c_str(), result); /// {return (_Ptr == 0 ? _Nullstr() : _Ptr); } 
																   //RemoveDirectory(strPath);		// ���⼭ ȣ���ϸ� ���� ������ ����
			}
			else
			{
				strFileFound = szFolderPath;
				strFileFound += _T("\\");
				strFileFound += info.cFileName;
				CFile::GetStatus(strFileFound.c_str(), rStatus);
				if (rStatus.m_mtime.GetTime() < result) {
					BOOL retVal = ::DeleteFileW(strFileFound.c_str());
				}
			}

		}

	} while (FindNextFile(hp, &info));

	FindClose(hp);

	RemoveDirectory(szFolderPath); //���⼭ ȣ���ϸ� �ֻ��� �������� ����
}

void AutoDeleteFile(CString strTarget, int nDuration)
{
	BOOL	bWorking;

	CFileFind	finder;
	CFileStatus	rStatus;
	CString		strFileName;
	CString		strFileNameUnder;

	struct tm when;
	__time64_t long_time;
	time_t	result;

	_time64(&long_time);
	int err = _localtime64_s(&when, &long_time);
	if (err) return;

	when.tm_mday = when.tm_mday - nDuration;
	result = mktime(&when);

	bWorking = finder.FindFile(strTarget);
	if (!bWorking) return;
	int i = 0;

	while (bWorking) {
		bWorking = finder.FindNextFile();

		if (finder.IsDots() != TRUE) {
			strFileName = finder.GetFilePath();
			DeleteFolderAndFile(strFileName, result);
			//CFile::GetStatus(strFileName, rStatus);
			//if (rStatus.m_mtime.GetTime() < result) {
			//	if (finder.IsDirectory() != TRUE) {
			//		DeleteFileW(strFileName);
			//	}
			//	else {
			//		CString strtemp = strFileName;
			//		strtemp += "\\*.*";
			//		AutoDeleteFile(strtemp, nDuration);
			//		RemoveDirectory(strFileName);
			//	}
			//}
		}
	}
}

BOOL CreateFolders(LPCTSTR szFolderPath)
{
	tstring strPath(szFolderPath);
	tstring strDir;
	DWORD dwRet;
	int iRet;

	int index(0);

	index = strPath.find(':', index);
	if(index < 0)
		index = 0;
	else
		index +=2;

	do
	{
		index = strPath.find('\\', index);
		
		if(index < 0)
			break;
		
		strDir = strPath.substr(0,index);

		if(strDir == _T("") || strDir == _T("\\"))
		{
			index++;
			continue;
		}

		dwRet = GetFileAttributes(strDir.c_str());
		if(dwRet != FILE_ATTRIBUTE_DIRECTORY)		// ������ �������� �ʴ� ���.
		{
			iRet = CreateDirectory(strDir.c_str(), NULL);
			if( iRet == ERROR_PATH_NOT_FOUND )		// �������� ���� ���. 
				return FALSE;
		}

		index++;

	}while(1);

	//������ ����...
	dwRet = GetFileAttributes(strPath.c_str());
	if(dwRet != FILE_ATTRIBUTE_DIRECTORY)		// ������ �������� �ʴ� ���.
	{
		int iRet = CreateDirectory(strPath.c_str(), NULL);
		if( iRet == ERROR_PATH_NOT_FOUND )		// �������� ���� ���. 
			return FALSE;
	}

	return TRUE;
} 

BOOL CopyFolderAndFile(LPCTSTR strSvrFolderPath, LPCTSTR strDefFolderPath)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	tstring strFileFound = strSvrFolderPath;
	strFileFound += _T("\\*.*");
	tstring strDefFile;

	DWORD dwRet = GetFileAttributes(strDefFolderPath);
	if(dwRet != FILE_ATTRIBUTE_DIRECTORY)		// ������ �������� �ʴ� ���.
	{
		int iRet = CreateDirectory(strDefFolderPath, NULL);
		if( iRet == ERROR_PATH_NOT_FOUND )		// �������� ���� ���. 
			return FALSE;
	}

	WIN32_FIND_DATA info;

	HANDLE hp = FindFirstFile(strFileFound.c_str(), &info);   //���丮�� ������ �ִ��� ù��° ���ϸ�.
    do
    {
        if (!((_tcscmp(info.cFileName, _T("."))==0) || (_tcscmp(info.cFileName, _T(".."))==0))) 
		{
            if((info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==FILE_ATTRIBUTE_DIRECTORY)  //Sub���丮�� �����ϴ°�� 
            {
                tstring strSubSvrFolder = strSvrFolderPath;
				strSubSvrFolder += _T("\\");
				strSubSvrFolder += info.cFileName;

				tstring strSubDefFolder = strDefFolderPath;
				strSubDefFolder += _T("\\");
				strSubDefFolder += info.cFileName;

				if(!CopyFolderAndFile(strSubSvrFolder.c_str(), strSubDefFolder.c_str()))
					return FALSE; 
             }
            else
			{
				strFileFound = strSvrFolderPath;
				strFileFound += _T("\\");
				strFileFound += info.cFileName;

				strDefFile = strDefFolderPath;
				strDefFile += _T("\\");
				strDefFile += info.cFileName;
				
				CopyFileW(strFileFound.c_str(), strDefFile.c_str(), FALSE);
            }
        }

    }while(FindNextFile(hp, &info));
    
	FindClose(hp);

	return TRUE;
}
//>>150313.kty
// double _ttof(LPCTSTR strVal)
// {
// #ifdef _UNICODE
// 	int len = _tcslen(strVal); //strlen�� NULL ���� ���� �������� ���̷� ī��Ʈ��
// 	char* szVal = new char[len];
// 	memset(szVal, NULL, len);
// 	wcstombs(szVal, strVal, len);
// 	double dVal = _ttof(szVal);
// 	delete[] szVal;
// #else
// 	double dVal = _ttof(strVal);
// #endif
// 
// 	return dVal;
// }

//>> 140513 JSPark
//////////////////////////////////////////////////////////////////////////
int findstr(const char *str, const char *what)
{
	int i, j, Ls=strlen(str), Lw=strlen(what);

	for(i=0;i<=Ls-Lw;i++){
		if(str[i] == what[0]){
			for(j=1;j<Lw;j++){
				if(str[i+j] != what[j]){
					break;
				}
			}
			if(j == Lw) return i;
		}
	}
	return -1;
}

bool str_remove(char* str, int start, int end)
{
	int i, len = strlen(str);	// ������ ���� ���� ���ڿ��� ������ ����.
	for(i=0; i<len; i++)
	{
		// value�� NULL�϶�, Empty Line ���� ����!
		if(end==0 && i==len-2)
			break;

		str[start+i-1] = str[end+i];
	}
	
	return true; 
}

bool str_insert(char* str, char* src, int nStart)
{
	char* ctmp=NULL;

	int i;
	int len1 = strlen(str);
	int len2 = strlen(src);

	for(i=len1; i>=nStart-1; i--)
	{
		str[i+len2] = str[i];
	}
	// �߰��� ���ڿ� ����.
	for(i=0; i<len2; i++)
	{
		str[i+nStart-1] = src[i];
	}
	return true; 
}
//////////////////////////////////////////////////////////////////////////
//<<

/** @brief Radian -> cos,sin �Լ�
@return Degree
*/
//���ϴ� ���� s
//�������� ����� x
double UVWTablePitch(double s, double x, double cur)
{
	double dResult(0.);

	if (x == ThetaX)
		dResult = (StageRotatvalue)*sin(Deg2Rad(s) + Deg2Rad(x) + Deg2Rad(cur)) - (StageRotatvalue)*sin(Deg2Rad(x) + Deg2Rad(cur));
	else if (x == ThetaY1 || x == ThetaY2)
		dResult = (StageRotatvalue)*cos(Deg2Rad(s) + Deg2Rad(x) + Deg2Rad(cur)) - (StageRotatvalue)*cos(Deg2Rad(x) + Deg2Rad(cur));

//	if (x == ThetaX)
//		dResult = (StageRotatvalue*SQRT2)*sin(Deg2Rad(s) + Deg2Rad(x) + Deg2Rad(cur)) - (StageRotatvalue*SQRT2)*sin(Deg2Rad(x) + Deg2Rad(cur));
//	else if (x == ThetaY1 || x == ThetaY2)
//		dResult = (StageRotatvalue*SQRT2)*cos(Deg2Rad(s) + Deg2Rad(x) + Deg2Rad(cur)) - (StageRotatvalue*SQRT2)*cos(Deg2Rad(x) + Deg2Rad(cur));

	//if(abs(dResult) > 5.) //������ �ɶ� �����̶� �ٸ��� �� �Ȱܶ�,,,EX)
	//	dResult = 0.

	return dResult;
}
//______________________________________________________________________________

//>> 150612 HSOh HBITMAP ���� ������ bmp ���Ϸ� �����Ѵ�.
BOOL SaveBitmap(HBITMAP hbit, LPCTSTR Path)
{
	if (hbit == NULL) //150522 JSLee
		return FALSE;

	BITMAPFILEHEADER fh;
	BITMAPINFOHEADER ih;
	BITMAP bit;
	BITMAPINFO *pih;
	int PalSize;
	HANDLE hFile;
	DWORD dwWritten, Size;
	HDC hdc;
	hdc = GetDC(NULL);
	GetObject(hbit, sizeof(BITMAP), &bit);
	ih.biSize = sizeof(BITMAPINFOHEADER);
	ih.biWidth = bit.bmWidth;
	ih.biHeight = bit.bmHeight;
	ih.biPlanes = 1;
	ih.biBitCount = bit.bmPlanes*bit.bmBitsPixel;

	if (ih.biBitCount > 8)
		ih.biBitCount = 24;

	ih.biCompression = BI_RGB;
	ih.biSizeImage = 0;
	ih.biXPelsPerMeter = 0;
	ih.biYPelsPerMeter = 0;
	ih.biClrUsed = 0;
	ih.biClrImportant = 0;
	PalSize = (ih.biBitCount == 24 ? 0 : 1 << ih.biBitCount)*sizeof(RGBQUAD);
	pih = (BITMAPINFO *)malloc(ih.biSize + PalSize);
	pih->bmiHeader = ih;
	GetDIBits(hdc, hbit, 0, bit.bmHeight, NULL, pih, DIB_RGB_COLORS);
	ih = pih->bmiHeader;
	if (ih.biSizeImage == 0) {
		ih.biSizeImage = ((((ih.biWidth*ih.biBitCount) + 31) & ~31) >> 3) * ih.biHeight;
	}
	Size = ih.biSize + PalSize + ih.biSizeImage;
	pih = (BITMAPINFO *)realloc(pih, Size);
	GetDIBits(hdc, hbit, 0, bit.bmHeight, (PBYTE)pih + ih.biSize + PalSize, pih, DIB_RGB_COLORS);
	fh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + PalSize;
	fh.bfReserved1 = 0;
	fh.bfReserved2 = 0;
	fh.bfSize = Size + sizeof(BITMAPFILEHEADER);
	fh.bfType = 0x4d42;
	hFile = CreateFile(Path, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile, &fh, sizeof(fh), &dwWritten, NULL);
	WriteFile(hFile, pih, Size, &dwWritten, NULL);
	ReleaseDC(NULL, hdc);
	CloseHandle(hFile);

	return TRUE;
}
//<<
extern void Char2DWORD2(unsigned char* strVal, WORD* sum, int iSize)
{
	DWORD val(0);
	for (int i = iSize; i >= 0; i--)
	{
		if (i % 2 == 1)
		{
			val = 0;
		}
		if (i < iSize)
			val += strVal[i];
		else
			val += 0x20;
		if (i % 2 == 1)
			val = val << 8;
		sum[i / 2] = (WORD)val;
	}
}

void SetSystemTime(CString strTime)
{
	CString tmp = strTime;

	int a; // ���ڸ� ������ ��ȯ
	a = _ttoi(strTime);

	//if (strTIme < 12 )
	//return;

	if (a < 12) //sk strtime = a�� ����
		return;

	SYSTEMTIME s;
	GetLocalTime(&s);
	s.wYear = _ttoi(tmp.Left(4));
	s.wMonth = _ttoi(tmp.Mid(4, 2));
	s.wDay = _ttoi(tmp.Mid(6, 2));
	s.wHour = _ttoi(tmp.Mid(8, 2));
	s.wMinute = _ttoi(tmp.Mid(10, 2));
	SetLocalTime(&s);


}