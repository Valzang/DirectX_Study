// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>
// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <assert.h>

#include <crtdbg.h>

// For Debugging========================================================
//
//#include <iostream>
//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif
// =====================================================================

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

using namespace std;

extern HWND g_hWnd;
#define Safe_Release(p) {if(p) p->Release(); p = NULL ;}
#define Safe_Delete(p) {if(p) delete p; p = NULL ;}

#define SINGLETON(class_name) \
					private : \
						class_name(void); \
						~class_name(void); \
					public: \
						static class_name* Instance() \
						{ \
							static class_name instance; \
							return &instance; \
						}

#define Synthesize(varType, varName, funName) \
			protected : varType varName; \
			public : inline varType Get##funName(void) const { return varName;} \
			public : inline void Set##funName(varType var) {varName = var;} \

#define Synthesize_Pass_By_Ref(varType, varName, funName) \
			protected : varType varName; \
			public : inline varType& Get##funName(void) { return varName;} \
			public : inline void Set##funName(varType& var) {varName = var;} \

#define	Safe_Add_Ref(p)	{if(p) p->AddRef(); }

#define Synthesize_Add_Ref(varType, varName, funName) \
			protected : varType varName; \
			public : inline varType Get##funName(void) const { return varName;} \
			public : inline void Set##funName(varType var) \
								{\
									if(varName != var)\
									{\
										Safe_Add_Ref(var);\
										Safe_Release(varName); \
										varName = var;\
									}\
								}\


struct ST_PC_VERTEX
{
	D3DXVECTOR3		pos;
	D3DCOLOR		color;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3		pos;
	D3DXVECTOR3		normal;
	D3DXVECTOR2		texture;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};

struct ST_PT_VERTEX
{
	D3DXVECTOR3		pos;
	D3DXVECTOR2		texture;
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

struct ST_SPHERE
{
	float			fRadius;
	D3DXVECTOR3		vCenter;
	bool			isPicked;

	ST_SPHERE() : fRadius(0.0f), vCenter(0, 0, 0), isPicked(false) {}
};

#include "cDeviceManager.h"
#include "cObject.h"
#include "cObjectManager.h"
#include "cTextureManager.h"
#include "iMap.h"