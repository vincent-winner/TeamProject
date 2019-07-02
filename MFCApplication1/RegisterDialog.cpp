#include "pch.h"
#include "RegisterDialog.h"
#include "MFCApplication1.h"
#include "resource.h"

/*
	�������ģʽΪDebug����ִ�����º궨��
	Debugģʽ�ĳ�����Խ��е���
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//��ʼӳ�䱾�Ի����ڵ��¼�
BEGIN_MESSAGE_MAP(RegisterDialog, CDialogEx)
	ON_UPDATE_COMMAND_UI(IDD_REGISTER, &RegisterDialog::OnUpdateIddRegister)//ӳ�䡰���´�������¼�
	ON_BN_CLICKED(IDC_CANCLE_BUTTON, &RegisterDialog::OnClickedCancleButton)//ӳ�䡰ȡ����ť�����¡��¼�
	ON_COMMAND(IDD_REGISTER, &RegisterDialog::OnIddRegister)//ӳ�䡰����¼�
	ON_BN_CLICKED(IDC_REGISTER_BUTTON, &RegisterDialog::OnClickedRegisterButton)//ӳ�䡰ע�ᰴť�����¡��¼�
END_MESSAGE_MAP()
//���Ի����ڵ��¼�ӳ�����



RegisterDialog::RegisterDialog(CWnd* pParent /*=nullptr*/)//��ע����桱���ڵĹ��췽��������Ϊ���򸸴���ָ��Ϊ��
	: CDialogEx(IDD_REGISTER, pParent)//˽�м̳С�C��չ���ڡ��࣬Ϊ��ע����桱���ڰ���Դ
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);//Ϊ��ע����桱�������ͼ��
}


void RegisterDialog::OnUpdateIddRegister(CCmdUI* pCmdUI)//���¾��ʱִ�д˺���
{
}


void RegisterDialog::OnClickedCancleButton()//��ȡ����ť�����ʱִ�����к���
{
	this->SendMessage(WM_CLOSE);//��ע����桱���ڷ��͡��رմ��ڡ���Ϣ
}


BOOL RegisterDialog::OnInitDialog()//�����ڳ�ʼ��ʱִ�д˺���
{
	this->SetIcon(m_hIcon,FALSE);//Ϊ��������ͼ��
	return TRUE;//����һ��ֵ�ó�������������У������û����
}

void RegisterDialog::OnIddRegister()//��������ʱִ�д˺���
{
	
}


void RegisterDialog::OnClickedRegisterButton()//���ע�ᰴťʱ��ִ�д˺���
{
	ArrayList<CString>* arrayList_Line = new ArrayList<CString>();//����һ�����齫�ļ����������ݴ�������
	CString userName, password, id, cardId;//�û��������룬���֤������
	CEdit* cedit;//�༭�����
	cedit = (CEdit*)GetDlgItem(IDC_EDIT1);//�󶨱༭�����
	cedit->GetWindowText(userName);//��ȡ�ı�������Ϣ
	userName.ReleaseBuffer();//�����ַ���������
	cedit = (CEdit*)GetDlgItem(IDC_EDIT2);//�󶨱༭�����
	cedit->GetWindowText(password);//��ȡ�ı�������Ϣ
	password.ReleaseBuffer();//�����ַ���������
	cedit = (CEdit*)GetDlgItem(IDC_EDIT3);//�󶨱༭�����
	cedit->GetWindowText(id);//��ȡ�ı�������Ϣ
	id.ReleaseBuffer();//�����ַ���������
	srand((size_t)time(NULL));//�������������

	//��ʼ�����������
	for (int i = 0; i < 11; i++) {
		cardId += char(rand() % 10 + '0');
	}
	//��������������

	arrayList_Line->add(userName);//��������ӽ�����
	arrayList_Line->add(password);//��������ӽ�����
	arrayList_Line->add(id);//�����֤����ӽ�����
	arrayList_Line->add(CString("0"));//�������û����Ϊ0
	arrayList_Line->add(cardId);//���û������������

	FileRW file("userdata");//���ļ�userdata

	BOOL isExists=FALSE;//�ж��˻��Ƿ���ڣ�FALSEΪ�����ڣ����Խ�������˻�������TRUEΪ�Ѿ����ڣ������Խ�������û�����
	ArrayList<CString>* col1 = file.getColumn(0);//��ȡ�����û���
	ArrayList<CString>* col3 = file.getColumn(2);//��ȡ�������֤��
	ArrayList<CString>* col5 = file.getColumn(4);//��ȡ���п���
	for (int i = 0; i < col1->size(); i++) {
		if (col1->get(i).Compare(userName)==0 ||//�ж��û����Ƿ��Ѿ���ע��
			col3->get(i).Compare(id)==0||//�ж����֤�Ƿ��Ѿ���ʹ��
			col5->get(i).Compare(cardId)==0) {//�жϿ����Ƿ��Ѿ���ע��
			isExists = TRUE;//�������������Ϣ������һ�����ڣ����жϸ��˻��Ѿ�������
			delete col1, col3, col5;//ɾ��û�õ�����
			break;
		}
	}

	if (!(userName=="" || password=="" || id=="")) {//������벻Ϊ��
		if (!isExists) {//����˻��Ѿ�����
			file.addln(file.composeCString(arrayList_Line));//������д���ļ�
			MessageBox(_T("���Ŀ���Ϊ��") + cardId, _T("ע��ɹ�"), MB_OK);//������Ϣ��
			delete arrayList_Line;//ɾ������
			this->SendMessage(WM_CLOSE);//�򱾴��ڹرմ�����Ϣ
		}else {
			MessageBox(_T("�����û��������֤�򿨺��Ѿ���ʹ�ã�������ע��"), _T("ע��ʧ��"), MB_OK);//������Ϣ��
			delete arrayList_Line;//ɾ������
		}
	}
	else {
		MessageBox(_T("����������ϢΪ�ջ��������ʶ����ַ�������������"), _T("ע��ʧ��"), MB_OK);//������Ϣ��
		delete arrayList_Line;//ɾ������
	}
	
}
