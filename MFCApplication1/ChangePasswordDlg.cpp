#include "pch.h"
#include "ChangePasswordDlg.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#include "UserDataDlg.h"

//�������ģʽΪ��Debug���������Debug����򹩵���ʹ��
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//��ʼӳ�䱾�Ի����ڵ��¼�
BEGIN_MESSAGE_MAP(ChangePasswordDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD_CANCEL, &ChangePasswordDlg::OnBnClickedButtonChangepasswordCancel)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD_OK, &ChangePasswordDlg::OnBnClickedButtonChangepasswordOk)
END_MESSAGE_MAP()
//���Ի����ڵ��¼�ӳ�����

ChangePasswordDlg::ChangePasswordDlg(CWnd* pParent /*=nullptr*/)//	���޸����롱���ڵĹ��췽��������Ϊ���򸸴���ָ��Ϊ��
	: CDialogEx(IDD_CHANGEPASSWORD, pParent)//		Ϊ���޸����롱���ڰ���Դ
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//Ϊ���޸����롱�������ͼ��
}

BOOL ChangePasswordDlg::OnInitDialog() // ���Ի����ʼ��ʱִ�д˺���
{
	this->SetIcon(m_hIcon, FALSE);// Ϊ���޸����롱��������ͼ��
	return TRUE;//����һ��û�������1
}


void ChangePasswordDlg::OnBnClickedButtonChangepasswordCancel()//����ȡ������ť������ʱ����ִ�д˺���
{
	this->SendMessage(WM_CLOSE);//�򱾴��ڷ��͡��رմ��ڡ���Ϣ
	
}


void ChangePasswordDlg::OnBnClickedButtonChangepasswordOk()//����ȷ���޸ġ���ť������ʱ����ִ�д˺���
{
	FileRW file("userdata"), userLineNumberFile("userlinenumber");//���ļ���userdata���͡�userlinenumber��
	CString userLineNumberStr = userLineNumberFile.getColumn(0)->get(0);//����userlinenumber���ļ������ݴ���ַ���
	int userLineNumber = _ttoi(userLineNumberStr);//��userlinenumber������ת��Ϊ����

	ArrayList<CString>* passwordArr = file.getColumn(1);//��ȡ�����˵�����

	//��ʼ��ȡ�ı�������
	CEdit *oldPwdBox,*newPwdBox,*reInputPwdBox;//�������������ָ��,����ָ���ı������
	oldPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_OLDPASSWORD);//�����������ָ��ָ�������
	newPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_NEWPASSWORD);//�����������ָ��ָ�������
	reInputPwdBox = (CEdit*)GetDlgItem(IDC_EDIT_CHANGEPASSWORD_REINPUTPASSWORD);//�����������ָ��ָ�������
	CString oldPwdText, newPwdText, reInputPwdText;//�����ַ����������洢������ڵ����루�����룬�����룬�������������룩
	oldPwdBox->GetWindowText(oldPwdText);//��������ڵ��������ַ���
	newPwdBox->GetWindowText(newPwdText);//��������ڵ��������ַ���
	reInputPwdBox->GetWindowText(reInputPwdText);//��������ڵ��������ַ���
	//ֹͣ��ȡ�ı�������

	BOOL oldPasswordIsTrue = FALSE;//�����жϾ������Ƿ���ȷ
	BOOL passwordIsSame=FALSE;//�����ж����������Ƿ�����һ��

	CString trueOldPassword = passwordArr->get(userLineNumber);//����ȷ��ԭ��������ַ���
	if (trueOldPassword.Compare(oldPwdText) == 0) {//�������ľ���������ȷ��
		oldPasswordIsTrue = TRUE;//����������ȷ��
	}

	if (newPwdText.Compare(reInputPwdText) == 0) {//�������������һ��
		passwordIsSame = TRUE;//����������ͬ
	}

	if (!oldPasswordIsTrue) {//����������Ǵ����
		MessageBox(_T("�������������"),_T("��ʾ"),MB_OK);//������ʾ��
		delete passwordArr;
	}else {//�������������ȷ��
		if (!passwordIsSame) {//��������������벻��ͬ
			MessageBox(_T("�����������벻��ͬ"), _T("��ʾ"), MB_OK);//������ʾ��
			delete passwordArr;
		}else {//�����������ȷ������������������ͬ
			passwordArr->set(userLineNumber, newPwdText);//�������е������޸�
			file.writeColumn(1,passwordArr);//������д���ļ�
			MessageBox(_T("������Ϊ�� ")+newPwdText,_T("��ʾ"),MB_OK);//������ʾ��
			delete passwordArr;//ɾ����������
			this->SendMessage(WM_CLOSE);//�򱾴��ڷ��͡��رմ��ڡ���Ϣ
		}
	}
}
