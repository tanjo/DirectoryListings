#pragma once

#include <vector>

class DirectoryListing {
public:
  DirectoryListing();
  DirectoryListing(const std::string &folder);
  ~DirectoryListing();

  void clear();
  std::vector<std::string> const & read();
  std::vector<std::string> const & read(const std::string &folder);
  std::vector<std::string> const & getList();

private:
  std::string *_folder;
  std::vector<std::string> *_files;
};

#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>

class DirectoryListings
{
public:

  // �t�@�C���ꗗ�擾
  // folder : �t�H���_�̐�΃p�X���͂Ƃ��� 
  // �� : "D:\\Users\\Pictures\\"
  static std::vector<std::string> read(std::string folder){
    // �錾
    std::vector<std::string> fileList;
    HANDLE hFind;
    WIN32_FIND_DATA fd;

    // �t�@�C���������̂��߂Ƀ��C���h�J�[�h�ǉ�
    // �� : "D:\\Users\\Pictures\\*.*"
    std::stringstream ss;
    ss << folder;
    std::string::iterator itr = folder.end();
    itr--;
    if(*itr != '\\') ss << '\\';
    ss << "*.*";

    // �t�@�C���T��
    // FindFirstFile(�t�@�C����, &fd);
    hFind = FindFirstFile(ss.str().c_str(), &fd);

    // �������s
    if(hFind == INVALID_HANDLE_VALUE){
      std::cout << "�t�@�C���ꗗ���擾�ł��܂���ł���" << std::endl;
      exit(1); // �G���[�I��
    }

    // �t�@�C���������X�g�Ɋi�[���邽�߂̃��[�v
    do{
      // �t�H���_�͏���
      if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        && !(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
      {
        //�t�@�C���������X�g�Ɋi�[
        char *file = fd.cFileName;
        std::string str = file;
        fileList.push_back(str);
      }
    } while(FindNextFile(hFind, &fd)); //���̃t�@�C����T��
    
    // hFind�̃N���[�Y
    FindClose(hFind); 

    return fileList;
  } 
   
};

typedef DirectoryListings Dir;

#endif
