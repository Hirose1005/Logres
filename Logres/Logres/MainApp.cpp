#include <windows.h>
#include <string>

#include "resource.h"
#include "MainApp.h"
#include "Job.h"

// 定数
const char* JOBNAME[MAX_JOB] = 
{
	"デスペラード",
	"古代機鋼兵",
	"剣姫"
};

// グローバル変数
std::shared_ptr<Logres> g_pLogres;
std::shared_ptr<Job> g_pSelectedJob;


// このコード モジュールに含まれる関数の宣言を転送します:
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	// 初期化
	g_pLogres = std::make_shared<Logres>();	// インスタンス作成
	

	// ダイアログボックス作成
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);

	return 0;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		// コンボボックスにデータを追加
		HWND hWndList = GetDlgItem(hWnd, IDC_JOB);
		for (int i = 0; i < g_pLogres->GetJobNum(); i++)
		{
			// ジョブデータを登録
			int pos = (int)SendMessage(hWndList, CB_ADDSTRING, 0, (LPARAM)g_pLogres->GetJob(i)->GetJobName());
			SendMessage(hWndList, CB_INITSTORAGE, pos, (LPARAM)i);
		}

		return FALSE;
	}

	case WM_COMMAND:
	{
		// ジョブ選択リストウィンドウ取得
		HWND hWndList = GetDlgItem(hWnd, IDC_JOB);

		switch (wParam)
		{
		case CB_SELECT:
			if (SendMessage(hWndList, CB_GETCURSEL, 0, 0) >= 0)
			{
				g_pSelectedJob = g_pLogres->GetJob((SendMessage(hWndList, CB_GETCURSEL, 0, 0)));
			}
			
			return FALSE;
		
		}
		return FALSE;
	}
		
	case WM_CLOSE:
		EndDialog(hWnd, IDOK);
		return FALSE;
	}
	return FALSE;
}

Logres::Logres()
{
	// ジョブデータの作成
	m_pJobs.push_back(std::make_shared<Kodai>());
	m_pJobs.push_back(std::make_shared<Despe>());
	m_pJobs.push_back(std::make_shared<Kenki>());
}

Logres::~Logres()
{
	// データの開放
	for (int i = 0; i < m_pJobs.size(); i++)
	{
		m_pJobs[i].reset();
	}
}