#include "CMyString.h"
#include <iostream>
#include <cstring>
using namespace std;

CMyString::CMyString()
	:m_pszData(NULL)
	, m_nLength(0)
{

}

CMyString::~CMyString()
{
	delete m_pszData;
}

int CMyString::SetString(const char* pszParam)
{
	if (pszParam == NULL)
		return 0;

	m_nLength = strlen(pszParam);

	if (m_nLength == 0)
		return 0;

	m_pszData = new char[m_nLength+1];
	
	strcpy_s(m_pszData, sizeof(char) * (m_nLength + 1), pszParam);

	cout << "m_nLength:   " << m_nLength << endl;;
	cout << "m_pszData:   " << m_pszData << endl;
	return 0;
}

const char* CMyString::GetString()
{
	return NULL;
}

void CMyString::Release()
{

}