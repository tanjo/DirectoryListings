DirectoryListings
=================

フォルダ内のファイルの一覧を取得してリストで返す  
  
  
設定
=================

まず、設定として  
  
[プロジェクト(P)]  
↓  
  
[hogehogeのプロパティ]  
  
↓  
  
[構築プロパティ]  
  
↓  
  
[プロジェクトの既定値]  
  
↓  
  
[文字セット]  
  
↓  
  
[マルチ バイト文字セットを使用する]  
  
に設定する  
  
  
  
サンプルコード
=================
    #include <iostream>
    
    #include "directory_listings.h"
    
    int main(int argc, char *argv[])
    {
        // ファイル入力
        std::vector<std::string> backfilelist = Dir::read("DirectoryListings");
        for(int i = 0; i < backfilelist.size(); i++){
            std::cout << backfilelist[i] << std::endl;
        }
        return 0;
    }
  
  
実行結果
=================
    .gitignore
    directory_listings.h
    README.md