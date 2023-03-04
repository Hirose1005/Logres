#include <windows.h>
#include <string>

#include "resource.h"
#include "MainApp.h"
#include "Job.h"

// �萔
const char* JOBNAME[MAX_JOB] = 
{
	"�f�X�y���[�h",
	"�Ñ�@�|��",
	"���P"
};

// �O���[�o���ϐ�
std::shared_ptr<Logres> g_pLogres;
std::shared_ptr<Job> g_pSelectedJob;


// ���̃R�[�h ���W���[���Ɋ܂܂��֐��̐錾��]�����܂�:
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	// ������
	g_pLogres = std::make_shared<Logres>();	// �C���X�^���X�쐬
	

	// �_�C�A���O�{�b�N�X�쐬
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);

	return 0;
}

BOOL CALLBACK DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		// �R���{�{�b�N�X�Ƀf�[�^��ǉ�
		HWND hWndList = GetDlgItem(hWnd, IDC_JOB);
		for (int i = 0; i < g_pLogres->GetJobNum(); i++)
		{
			// �W���u�f�[�^��o�^
			int pos = (int)SendMessage(hWndList, CB_ADDSTRING, 0, (LPARAM)g_pLogres->GetJob(i)->GetJobName());
			SendMessage(hWndList, CB_INITSTORAGE, pos, (LPARAM)i);
		}

		return FALSE;
	}

	case WM_COMMAND:
	{
		// �W���u�I�����X�g�E�B���h�E�擾
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
	// �W���u�f�[�^�̍쐬
	m_pJobs.push_back(std::make_shared<Kodai>());
	m_pJobs.push_back(std::make_shared<Despe>());
	m_pJobs.push_back(std::make_shared<Kenki>());
}

Logres::~Logres()
{
	// �f�[�^�̊J��
	for (int i = 0; i < m_pJobs.size(); i++)
	{
		m_pJobs[i].reset();
	}
}