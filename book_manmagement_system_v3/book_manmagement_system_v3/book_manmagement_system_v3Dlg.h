
// book_manmagement_system_v3Dlg.h : ͷ�ļ�
//

#pragma once


// Cbook_manmagement_system_v3Dlg �Ի���
class Cbook_manmagement_system_v3Dlg : public CDialogEx
{
// ����
public:
	DECLARE_DYNAMIC(Cbook_manmagement_system_v3Dlg)
	Cbook_manmagement_system_v3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BOOK_MANMAGEMENT_SYSTEM_V3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
};
