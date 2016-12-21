---
title: "Navega&#231;&#227;o no sistema de arquivos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: f7cc5f5e-a541-4e00-87c7-a3769ef6096d
caps.latest.revision: 14
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Navega&#231;&#227;o no sistema de arquivos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O cabeçalho \< filesystem \> implementa o especificação técnica do sistema de arquivo do rascunho \([Comitê técnico conjunto ISO\/IEC 1\/SC 22\/WG 21 N4100](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4100.pdf)\) e possui tipos e funções que permitem que você escreva código independente de plataforma para navegar no sistema de arquivos. Porque se trata de várias plataformas, ele contém APIs que não são relevantes para os sistemas Windows. Por exemplo, isso significa que `is_fifo(const path&)` sempre retorna `false` no Windows. O cabeçalho é baseado em um rascunho especificação técnica que não tenha sido votado em C\+\+ 17 padrão a partir do Visual Studio 2015 RTM. Seus membros são encontrados no  `std::experimental::filesystem::v1` namespace.  
  
## Visão Geral  
 Use as tarefas APIs \< filesystem \> para o seguinte:  
  
-   iterar sobre arquivos e diretórios em um caminho especificado  
  
-   obter informações sobre arquivos, incluindo a hora de criação, tamanho, extensão e diretório raiz  
  
-   compor, decompor e comparar caminhos  
  
-   criar, copiar e excluir diretórios  
  
-   copiar e excluir arquivos  
  
 Para obter mais informações sobre e\/s de arquivos usando a biblioteca padrão, consulte [iostream programação](../Topic/iostream%20Programming.md).  
  
## Caminhos  
  
### Construindo e caminhos de composição  
 Caminhos no Windows \(desde o XP\) são armazenados nativamente em Unicode. O [caminho](../Topic/path%20Class%20\(C++%20Standard%20Template%20Library\).md) classe executa automaticamente todas as conversões de cadeia de caracteres necessários. Ele aceita argumentos de ambos ampla e matrizes de caracteres estreita, bem como `std::string` e `std::wstring` tipos formatados como UTF8 ou UTF16. O `path` classe automaticamente normaliza separadores de caminho. Você pode usar uma única barra invertida como um separador de diretório nos argumentos do construtor. Isso permite que você use as mesmas cadeias de caracteres para armazenar caminhos em ambientes Windows e UNIX:  
  
```cpp  
path pathToDisplay(L"/FileSystemTest/SubDir3"); // OK! path pathToDisplay2(L"\\FileSystemTest\\SubDir3"); // Still OK as always path pathToDisplay3(LR"(\FileSystemTest\SubDir3)"); // Raw string literals are OK, too.  
```  
  
 Para concatenar dois caminhos, você pode usar o sobrecarregado `/` e `/=` operadores que são análogas à `+` e `+=` operadores `std::string` e `std::wstring`. O `path` objeto convenientemente fornecerá os separadores se você não fizer isso.  
  
```cpp  
path myRoot("C:/FileSystemTest"); // no trailing separator, no problem! myRoot /= path("SubDirRoot"); // C:/FileSystemTest/SubDirRoot  
```  
  
### Examinar caminhos  
 A classe path tem vários métodos que retornam informações sobre diversas partes do caminho, diferentes de entidade do sistema de arquivos pode se referir a. Você pode obter a raiz, o caminho relativo, o nome do arquivo, a extensão de arquivo e muito mais. Você pode iterar sobre um objeto de caminho para examinar todas as pastas na hierarquia. O exemplo a seguir mostra como iterar em um caminho \(não o diretório refere\-se a\) e para recuperar informações sobre suas partes.  
  
```cpp  
  
#include <string> #include <iostream> #include <sstream> #include <filesystem> using namespace std; using namespace std::experimental::filesystem::v1; wstring  DisplayPathInfo() { // This path may or may not refer to an existing file. We are // examining this path string, not file system objects. path pathToDisplay(L"C:/FileSystemTest/SubDir3/SubDirLevel2/File2.txt "); wostringstream wos; int i = 0; wos << L"Displaying path info for: " << pathToDisplay << endl; for (path::iterator itr = pathToDisplay.begin(); itr != pathToDisplay.end(); ++itr) { wos << L"path part: " << i++ << L" = " << *itr << endl; } wos << L"root_name() = " << pathToDisplay.root_name() << endl << L"root_path() = " << pathToDisplay.root_path() << endl << L"relative_path() = " << pathToDisplay.relative_path() << endl << L"parent_path() = " << pathToDisplay.parent_path() << endl << L"filename() = " << pathToDisplay.filename() << endl << L"stem() = " << pathToDisplay.stem() << endl << L"extension() = " << pathToDisplay.extension() << endl; return wos.str(); } void main(int argc, char* argv[]) { wcout << DisplayPathInfo() << endl; // wcout << ComparePaths() << endl; // see following example wcout << endl << L"Press Enter to exit" << endl; wstring input; getline(wcin, input); }  
```  
  
 O código produz esta saída:  
  
```cpp  
Displaying path info for: C:\FileSystemTest\SubDir3\SubDirLevel2\File2.txt path part: 0 = C: path part: 1 = \ path part: 2 = FileSystemTest path part: 3 = SubDir3 path part: 4 = SubDirLevel2 path part: 5 = File2.txt root_name() = C: root_path() = C:\ relative_path() = FileSystemTest\SubDir3\SubDirLevel2\File2.txt parent_path() = C:\FileSystemTest\SubDir3\SubDirLevel2 filename() = File2.txt stem() = File2 extension() = .txt  
```  
  
### Comparando caminhos  
 O `path` classe sobrecarrega os mesmos operadores de comparação como `std::string` e `std::wstring`. Quando você compara dois caminhos, você está executando uma comparação de cadeia de caracteres após os separadores foram normalizados. Se uma barra à direita \(ou barra invertida\) está ausente não será adicionado e afeta a comparação. O exemplo a seguir demonstra como se comparam valores de caminho:  
  
```cpp  
  
wstring ComparePaths() { path p0(L"C:/Documents"); // no trailing separator path p1(L"C:/Documents/"); //p0 < p1 path p2(L"C:/Documents/2013/"); // p1 < p2 path p3(L"C:/Documents/2013/Reports/"); // p2 < p3 path p4(L"C:/Documents/2014/");  // p3 < p4 path p5(L"D:/Documents/2013/Reports/"); // p4 < p5 wostringstream wos; wos << boolalpha << p0.wstring() << L" < " << p1.wstring() << L": " << (p0 < p1) << endl << p1.wstring() << L" < " << p2.wstring() << L": " << (p1 < p2) << endl << p2.wstring() << L" < " << p3.wstring() << L": " << (p2 < p3) << endl << p3.wstring() << L" < " << p4.wstring() << L": " << (p3 < p4) << endl << p4.wstring() << L" < " << p5.wstring() << L": " << (p4 < p5) << endl; return wos.str(); } /* Output: C:\Documents < C:\Documents\: true C:\Documents\ < C:\Documents\2013\: true C:\Documents\2013\ < C:\Documents\2013\Reports\: true C:\Documents\2013\Reports\ < C:\Documents\2014\: true C:\Documents\2014\ < D:\Documents\2013\Reports\: true */  
```  
  
 Para executar esse código, cole o exemplo completo acima e remova a linha que chama no principal.  
  
### Conversão entre tipos de caminho e cadeia de caracteres  
 Um `path` objeto é implicitamente conversível para `std::wstring` ou `std::string`. Isso significa que você pode passar um caminho para funções como [wofstream::open](../Topic/basic_ofstream::open.md), conforme mostrado neste exemplo:  
  
```cpp  
wchar_t* p = L"C:/test"; path filePath(p); filePath /= L"NewFile.txt"; // Open, write to, and close the file. wofstream myFile; myFile.open(filePath); myFile << L"Lorem ipsum..."; myFile.close  
  
```  
  
## Iterando diretórios e arquivos  
 O cabeçalho \< filesystem \> fornece a [directory\_iterator](../Topic/directory_iterator%20Class.md) tipo para iterar sobre diretórios únicos e o [recursive\_directory\_iterator](../Topic/recursive_directory_iterator%20Class.md) classe iterar recursivamente em um diretório e seus subdiretórios. Depois que você construir um iterador, passando um `path` do objeto, o iterador aponta para o primeiro directory\_entry no caminho. Crie o iterador de fim chamando o construtor padrão.  
  
 Ao iterar por meio de um diretório, existem vários tipos de itens que você pode encontrar, incluindo, mas não se limitando a diretórios, arquivos, links simbólicos e arquivos de soquete. O `directory_iterator` retorna seus itens como [directory\_entry](../standard-library/directory-entry-class.md) objetos e cada objeto tem um [status\(\)](http://msdn.microsoft.com/pt-br/a70a3c55-3a76-417f-abaf-862ff94b2056) membro que informa que tipo de entrada você está examinando. Examinando esse valor, você pode tomar decisões sobre o que fazer qualquer entrada específica. O exemplo a seguir itera em um único diretório, e se a entrada de diretório é um arquivo regular, o código imprime algumas informações sobre esse arquivo. Se a entrada for um diretório, somente o nome é exibido.  
  
```cpp  
#include <string> #include <iostream> #include <iomanip> #include <filesystem> #include <chrono> #include <time.h> using namespace std; using namespace std::experimental::filesystem::v1; // Display the last write time for the file wstring LastWriteTimeToLocalTime(const path& file_path) { const auto last = chrono::system_clock::to_time_t(last_write_time(file_path)); tm timeinfo; localtime_s(&timeinfo, &last); wchar_t buf[56]; _wasctime_s(buf, 56, &timeinfo); // appends '\n' return wstring{ buf }; } // List files and directories in the specified path void DisplayFolderContents(const path& p) { wcout << L"Begin iterating " << p.wstring() << endl; for (const auto& entry : directory_iterator{ p }) { if (is_regular_file(entry.status())) { wcout << L" File: " << entry.path().filename() << " : " << LastWriteTimeToLocalTime(entry.path()); } else if (is_directory(entry.status())) { wcout << L" Dir: " << entry.path().filename() << endl; } } } void main() { wstring dir{ LR"(C:\users\public\documents\)" }; path p{ dir }; if (!is_directory(p)) { wcout << L"No such directory: " << dir << endl; return; } DisplayFolderContents(p); // IterateFolderRecursively(p); // see example wcout << endl << L"Press Enter to exit" << endl; wstring input; getline(wcin, input); }  
```  
  
### Iteração recursiva de árvore um diretório  
 O exemplo a seguir mostra como iterar recursivamente por meio de uma árvore de diretório. Para executar essa função, cole o exemplo de código anterior após a função DisplayFolderContents e remova a linha que chama no principal.  
  
```cpp  
// List files and directories recursively in the path void IterateFolderRecursively(const path& p) { wcout << L"Begin iterating " << p.wstring() << " recursively" << endl; for (recursive_directory_iterator it{ p }, end; it != end; ++it) { if (is_regular_file(it->status())) { wcout << setw(it.depth()) << L" " << L"File: " << it->path().filename() << L" : " << LastWriteTimeToLocalTime(it->path()); } else if (is_directory(it->status())) { wcout << setw(it.depth()) << L" " << L"Dir: " << it->path().filename() << endl; } } }  
```  
  
### Tratamento de links simbólicos  
 Detecção de link simbólico ainda não é suportada no Visual C\+\+ a partir do Visual Studio 2015.