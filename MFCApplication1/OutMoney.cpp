#include "pch.h"
#include "OutMoney.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#include "UserDataDlg.h"
//�������ģʽΪ��Debug���������Debug����򹩵���ʹ��
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//��ʼӳ�䱾�Ի����ڵ��¼�
BEGIN_MESSAGE_MAP(OutMoneyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY_CANCEL, &OutMoneyDlg::OnClickedButtonOutmoneyCancel)
	ON_BN_CLICKED(IDC_BUTTON_OUTMONEY_OK, &OutMoneyDlg::OnClickedButtonOutmoneyOk)
END_MESSAGE_MAP()
//���Ի����ڵ��¼�ӳ�����


OutMoneyDlg::OutMoneyDlg(CWnd* pParent /*=nullptr*/)//	�����봢������ڵĹ��췽��������Ϊ���򸸴���ָ��Ϊ��
	: CDialogEx(IDD_OUTMONEY, pParent)//		Ϊ�����봢������ڰ���Դ
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//Ϊ�����봢����������ͼ��
}



void OutMoneyDlg::OnClickedButtonOutmoneyCancel()
{
	this->SendMessage(WM_CLOSE);
}

BOOL OutMoneyDlg::OnInitDialog() // ���Ի����ʼ��ʱִ�д˺���
{
	this->SetIcon(m_hIcon, FALSE);// Ϊ�����봢�����������ͼ��
	return TRUE;//����һ��û�������1
}

void OutMoneyDlg::OnClickedButtonOutmoneyOk()
{
	//��ʼ��ȡ������ڽ�Ǯ����
	CEdit* moneyEdit;//�������������ָ��
	moneyEdit = (CEdit*)GetDlgItem(IDC_EDIT_OUTMONEY_NUMBER);//�����������ָ��ָ�������
	CString moneyEditText;//�����ַ����������洢������ڵĽ��
	moneyEdit->GetWindowText(moneyEditText);//��������ڵĽ������moneyEditText��������
	double inputMoney = _ttof(moneyEditText);//�����ַ��������͵Ľ��ת���ɡ�double�����ͣ�������ʹ��
	//������ڽ�Ǯ������ȡ����

	FileRW file("userdata"), userLineNumberFile("userlinenumber");//���ļ���userdata���͡�userlinenumber��
	CString userLineNumberStr = userLineNumberFile.getColumn(0)->get(0);//����userlinenumber���ļ������ݴ���ַ���
	int userLineNumber = _ttoi(userLineNumberStr);//��userlinenumber������ת��Ϊ����
	ArrayList<CString>* moneyArr = file.getColumn(3);//��ȡ�����˵Ľ��
	double money = _ttof (moneyArr->get(userLineNumber));//����ǰ�û��Ľ��ַ�����ת��Ϊdouble���ͣ�������ʹ��
	money -= inputMoney;//��ǰ�û��Ľ��-=����Ľ��
	
	CString resultMoneyStr;//�����ַ�����resultMoneyStr��
	resultMoneyStr.Format(_T("%lf"), money);//�����ս��д���ַ�����resultMoneyStr��
	moneyArr->set(userLineNumber, resultMoneyStr);//����ǰ�û��Ľ���޸�Ϊ����֮��Ľ��

	if ((moneyEditText.Compare(_T("")) == 0)) {//�������Ϊ��
		MessageBox(_T("��������Ϊ��"), _T("����"), MB_OK);//�����Ի��򣨲���1���Ի������ݣ�����2���Ի�����⣬����3��ȷ����ť��
		delete moneyArr;//ɾ�������洢�����û���Ǯ������
	}
	else {
		if (!(moneyEditText == moneyEditText.SpanIncluding(_T("0123456789.")))) {//�������������г������ֺ�С����������ַ�
			MessageBox(_T("������������Ƿ��ַ�"), _T("����"), MB_OK);//�����Ի��򣨲���1���Ի������ݣ�����2���Ի�����⣬����3��ȷ����ť��
			delete moneyArr;//ɾ�������洢�����û���Ǯ������
		}
		else {
			file.writeColumn(3, moneyArr);//���ļ�д�������û��Ľ�Ǯ��Ϣ
			delete moneyArr;//ɾ�������洢�����û���Ǯ������
			MessageBox(_T("ȡ����") + moneyEditText + _T("  RMB(CNY)"), _T("ȡ��ɹ�"), MB_OK);//�����Ի��򣨲���1���Ի������ݣ�����2���Ի�����⣬����3��ȷ����ť��
			HWND hWnd = ::FindWindow(NULL, _T("�˻�����"));//��ȡ����Ϊ���˻��������Ĵ���
			EndDialog(0);//��ģ̬�Ի����͹ر���Ϣ
			SendMessageA(hWnd, WM_CLOSE, NULL, NULL);//�����Ϊ���˻��������Ĵ��ڣ����͡��رձ����ڡ�����
			UserDataDlg userDataDlg;//�������û����桱�Ĵ���7
			userDataDlg.DoModal();//����ģ̬����
		}
	}
}
