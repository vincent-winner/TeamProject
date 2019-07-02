#pragma once

#ifndef FILE_RW_MFC_H

#define FILE_RW_MFC_H

//#include <atlstr.h>
#include <afx.h>
#include <locale>

#include "ArrayList.h"

using namespace std;
using namespace lang;

namespace lang {

	//字符串分割标志
	#define SPLIT_SIGN '\t'

	//CStringArray* DivString(CString text);//将CString分割成数组
	//ArrayList<CString>* readFileToArray(CString fileName);//将文件读入数组
	//ArrayList<CString>* splitCString(CString str);//将字符串分割成新的数组

	class FileRW {
	protected:
		CString fileName;
	public:
		FileRW(CString fileName){ this->fileName = fileName; setlocale(LC_CTYPE, ("chs"));}
		FileRW(char* fileName){ this->fileName = CString(fileName); setlocale(LC_CTYPE, ("chs"));}
		~FileRW(){}

		/**
			向文件中写入内容（文件中的内容会被覆盖）
			@strToWrite：要写入文件的字符串对象
		*/
		void write(CString strToWrite) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			file.WriteString(strToWrite.GetString());
			file.WriteString(CString("\n"));
			file.Flush();
			file.Close();
		}

		/**
			向文件中写入内容（文件中的内容会被覆盖）
			@arrayList：要写入文件的数组，数组的每一项为文件的一行数据（不带换行符）
		*/
		void write(ArrayList<CString>* arrayList) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			for (int i = 0; i < arrayList->size(); i++) {
				file.WriteString(arrayList->get(i).GetString()); 
				file.WriteString(CString("\n"));
			}
			file.Flush();
			file.Close();
		}

		/**
			向文件中追加内容（不会覆盖原有内容）
			@strToAdd：要追加进文件的字符串（不带换行符）
		*/
		void add(CString strToAdd) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			file.SeekToEnd();
			file.WriteString(strToAdd.GetString());
			file.Flush();
			file.Close();
		}

		/**
			向文件中追加内容（文件原有内容不会被覆盖）
			@arrayList：要追加进文件的数组，数组的每一项为文件的一行数据（不带换行符）
		*/
		void add(ArrayList<CString>* arrayList) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			file.SeekToEnd();
			for (int i = 0; i < arrayList->size(); i++) {
				file.WriteString(arrayList->get(i).GetString());
			}
			file.Flush();
			file.Close();
		}

		/**
			向文件中追加内容,并换行（不会覆盖原有内容）
			@strToAdd：要追加进文件的字符串（不带换行符）
		*/
		void addln(CString strToAdd) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			file.SeekToEnd();
			file.WriteString(strToAdd.GetString());
			file.WriteString(CString("\n"));
			file.Flush();
			file.Close();
		}

		/**
			向文件中追加内容，写数组一项会换一行（文件原有内容不会被覆盖）
			@arrayList：要追加进文件的数组，数组的每一项为文件的一行数据（不带换行符）
		*/
		void addln(ArrayList<CString>* arrayList) {
			CStdioFile file(this->fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
			file.SeekToEnd();
			/*for (int i = 0; i < arrayList->size(); i++) {
				file.WriteString(arrayList->get(i) + CString("\n"));
			}*/
			for (int i = 0; i < arrayList->size(); i++) {
				this->addln(arrayList->get(i).GetString());
			}
			file.Flush();
			file.Close();
		}
		
		/**
			将文件内容读取为数组，数组的每一项是文件的一行数据（没有换行符）
			@return：包含了文件所有内容的数组
		*/
		ArrayList<CString>* read() {
			return readFileToArray(this->fileName);
		}
		

		/**
			将文件中的一列内容读取为数组
			@column：指定要读取的列数
			@return：包含文件指定列的数组
		*/
		ArrayList<CString>* getColumn(int columnNumber) {
			ArrayList<CString>* columnArr = new ArrayList<CString>(100);//用来存放一列数据的数组
			ArrayList<CString>* fileRowArr = readFileToArray(this->fileName);//用来存放文件数据的数组
			for (int i = 0; i < fileRowArr->size(); i++) {
				columnArr->add(splitCString(fileRowArr->get(i))->get(columnNumber));
			}
			delete fileRowArr;
			return columnArr;
		}

		/**
			将一列数据写入指定列
			@column：要写入的列号
			@columnData：要写入的数据
		*/
		void writeColumn(int columnNum, ArrayList<CString>* columnData) {
			ArrayList<CString>* fileRowArr = this->read();
			for (int i = 0; i < fileRowArr->size(); i++) {
				ArrayList<CString>* tmpArr;
				tmpArr = splitCString(fileRowArr->get(i));
				tmpArr->set(columnNum, columnData->get(i));
				fileRowArr->set(i, composeCString(tmpArr));
			}
			this->write(fileRowArr);
			delete fileRowArr;
		}


		/**
			将文件的每一行读取为数组的每一项
			@fileName：要被打开的文件名
			@return：包含文件所有内容的数组，每一项是文件的一行数据（不带换行符）
		*/
		ArrayList<CString>* readFileToArray(CString fileName) {
			CStdioFile file(fileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);
			CString cstr;
			ArrayList<CString>* lineArr = new ArrayList<CString>();
			while (file.ReadString(cstr)) {
				lineArr->add(cstr);
			}
			file.Flush();
			file.Close();
			return lineArr;
		}

		/**
			将字符串以[ '\t' || '\n' || ' ' ]为分隔符，将字符串分割成一个新的数组
			@str：要处理的字符串
			@return：处理完的数组
		*/
		ArrayList<CString>* splitCString(CString str) {
			ArrayList<CString>* arr = new ArrayList<CString>();
			CStringArray* cstrArray = DivString(str);
			for (int i = 0; i < cstrArray->GetSize(); i++) {
				arr->add(cstrArray->GetAt(i));
			}
			return arr;
		}

		/**
			将数组的每一项以'\t'为分隔符组合成新的字符串
			@arrayList：待组合成字符串的数组
			@return：组合成的字符串
		*/
		CString composeCString(ArrayList<CString>* arrayList) {
			CString cstr(arrayList->get(0));
			for (int i = 1; i < arrayList->size(); i++) {
				cstr += CString("\t") + arrayList->get(i);
			}
			return cstr;
		}



		/**
			将CString分割成数组
			@text：要分割的字符串
			@return：分割完的字符串数组
		*/
		CStringArray* DivString(CString text)
		{
			CStringArray* m_result = new CStringArray;
			while (TRUE)
			{
				int index = text.Find(_T(SPLIT_SIGN));
				if (index == -1)
				{
					m_result->Add(text);
					return m_result;
				}
				CString test1 = text.Left(index);
				m_result->Add(test1);
				text = text.Right(text.GetLength() - index - 1);
			}

		}

	};//!class FileRW

}//!namespace lang

#endif // !FILE_RW_MFC_H
