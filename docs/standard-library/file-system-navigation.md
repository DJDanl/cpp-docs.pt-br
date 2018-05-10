---
title: Navegação no sistema de arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
ms.assetid: f7cc5f5e-a541-4e00-87c7-a3769ef6096d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0f5b1eeef0e5f07b0867eb79afc76ba9037a95e7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="file-system-navigation"></a>Navegação no sistema de arquivos

O cabeçalho \<filesystem > implementa a Especificação técnica para o Sistema de arquivos C++ ISO/IEC TS 18822:2015 (rascunho final: [ISO/IEC JTC 1/SC 22/WG 21 N4100](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4100.pdf)) e tem tipos e funções que permitem escrever código independente da plataforma para navegar no sistema de arquivos. Por ser de plataforma cruzada, ele contém APIs que não são relevantes para sistemas Windows. Por exemplo, isso significa que `is_fifo(const path&)` sempre retorna `false` no Windows.

## <a name="overview"></a>Visão geral

Use as APIs \<filesystem> para as seguintes tarefas:

- iterar em arquivos e diretórios em um caminho especificado

- obter informações sobre arquivos, incluindo a hora de criação, o tamanho, a extensão e o diretório raiz

- compor, decompor e comparar caminhos

- criar, copiar e excluir diretórios

- copiar e excluir arquivos

Para obter mais informações sobre E/S de arquivos usando a Biblioteca Padrão, consulte [Programação iostream](../standard-library/iostream-programming.md).

## <a name="paths"></a>Caminhos

### <a name="constructing-and-composing-paths"></a>Construindo e compondo caminhos

Caminhos no Windows (desde o XP) são armazenados nativamente em Unicode. A classe [path](../standard-library/path-class.md) executa automaticamente todas as conversões de cadeias de caracteres necessárias. Ele aceita argumentos de matrizes de caracteres estreitas e largas, bem como os tipos `std::string` e `std::wstring` formatados como UTF8 ou UTF16. A classe `path` também normaliza automaticamente separadores de caminho. Você pode usar uma única barra invertida como separador de diretório em argumentos do construtor. Isso permite usar as mesmas cadeias de caracteres para armazenar caminhos em ambientes Windows e UNIX:

```cpp
path pathToDisplay(L"/FileSystemTest/SubDir3");     // OK!
path pathToDisplay2(L"\\FileSystemTest\\SubDir3");  // Still OK as always
path pathToDisplay3(LR"(\FileSystemTest\SubDir3)"); // Raw string literals are OK, too.
```

Para concatenar dois caminhos, você pode usar os operadores sobrecarregados `/` e `/=`, que são análogos aos operadores `+` e `+=` em `std::string` e `std::wstring`. O objeto `path` fornecerá, convenientemente, os separadores se você não fizer isso.

```cpp
path myRoot("C:/FileSystemTest");  // no trailing separator, no problem!
myRoot /= path("SubDirRoot");      // C:/FileSystemTest/SubDirRoot
```

### <a name="examining-paths"></a>Examinando caminhos

A classe path tem vários métodos que retornam informações sobre diversas partes do caminho, diferente da entidade do sistema de arquivos a que pode se referir. Você pode obter a raiz, o caminho relativo, o nome de arquivo, a extensão de arquivo e muito mais. É possível iterar em um objeto de caminho para examinar todas as pastas na hierarquia. O exemplo a seguir mostra como iterar em um caminho (não no diretório a que faz referência) e como recuperar informações sobre suas partes.

```cpp
// filesystem_path_example.cpp
// compile by using: /EHsc
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>

using namespace std;
using namespace std::experimental::filesystem;

wstring DisplayPathInfo()
{
    // This path may or may not refer to an existing file. We are
    // examining this path string, not file system objects.
    path pathToDisplay(L"C:/FileSystemTest/SubDir3/SubDirLevel2/File2.txt ");

    wostringstream wos;
    int i = 0;
    wos << L"Displaying path info for: " << pathToDisplay << endl;
    for (path::iterator itr = pathToDisplay.begin(); itr != pathToDisplay.end(); ++itr)
    {
        wos << L"path part: " << i++ << L" = " << *itr << endl;
    }

    wos << L"root_name() = " << pathToDisplay.root_name() << endl
        << L"root_path() = " << pathToDisplay.root_path() << endl
        << L"relative_path() = " << pathToDisplay.relative_path() << endl
        << L"parent_path() = " << pathToDisplay.parent_path() << endl
        << L"filename() = " << pathToDisplay.filename() << endl
        << L"stem() = " << pathToDisplay.stem() << endl
        << L"extension() = " << pathToDisplay.extension() << endl;

    return wos.str();
}

void main(int argc, char* argv[])
{
    wcout << DisplayPathInfo() << endl;
    // wcout << ComparePaths() << endl; // see following example
    wcout << endl << L"Press Enter to exit" << endl;
    wstring input;
    getline(wcin, input);
}
```

O código produz esta saída:

```Output
Displaying path info for: C:\FileSystemTest\SubDir3\SubDirLevel2\File2.txt
path part: 0 = C:
path part: 1 = \
path part: 2 = FileSystemTest
path part: 3 = SubDir3
path part: 4 = SubDirLevel2
path part: 5 = File2.txt
root_name() = C:
root_path() = C:\
relative_path() = FileSystemTest\SubDir3\SubDirLevel2\File2.txt
parent_path() = C:\FileSystemTest\SubDir3\SubDirLevel2
filename() = File2.txt
stem() = File2
extension() = .txt
```

### <a name="comparing-paths"></a>Comparando caminhos

A classe `path` sobrecarrega os mesmos operadores de comparação que `std::string` e `std::wstring`. Quando compara dois caminhos, você está executando uma comparação de cadeia de caracteres após os separadores terem sido normalizados. Se uma barra à direita (ou barra invertida) estiver ausente, ela não será adicionada e afetará a comparação. O exemplo a seguir demonstra como os valores de caminho são comparados:

```cpp
wstring ComparePaths()
{
    path p0(L"C:/Documents");                 // no trailing separator
    path p1(L"C:/Documents/");                // p0 < p1
    path p2(L"C:/Documents/2013/");           // p1 < p2
    path p3(L"C:/Documents/2013/Reports/");   // p2 < p3
    path p4(L"C:/Documents/2014/");           // p3 < p4
    path p5(L"D:/Documents/2013/Reports/");   // p4 < p5

    wostringstream wos;
    wos << boolalpha <<
        p0.wstring() << L" < " << p1.wstring() << L": " << (p0 < p1) << endl <<
        p1.wstring() << L" < " << p2.wstring() << L": " << (p1 < p2) << endl <<
        p2.wstring() << L" < " << p3.wstring() << L": " << (p2 < p3) << endl <<
        p3.wstring() << L" < " << p4.wstring() << L": " << (p3 < p4) << endl <<
        p4.wstring() << L" < " << p5.wstring() << L": " << (p4 < p5) << endl;
    return wos.str();
}
```

```Output
C:\Documents < C:\Documents\: true
C:\Documents\ < C:\Documents\2013\: true
C:\Documents\2013\ < C:\Documents\2013\Reports\: true
C:\Documents\2013\Reports\ < C:\Documents\2014\: true
C:\Documents\2014\ < D:\Documents\2013\Reports\: true
```

Para executar esse código, cole-o no exemplo completo acima, antes de `main` e remova a marca de comentário da linha que o chama no principal.

### <a name="converting-between-path-and-string-types"></a>Convertendo entre tipos de cadeia de caracteres e caminho

Um objeto `path` é conversível implicitamente para `std::wstring` ou `std::string`. Isso significa que você pode passar um caminho para funções como [wofstream::open](../standard-library/basic-ofstream-class.md#open), conforme mostrado neste exemplo:

```cpp
// filesystem_path_conversion.cpp
// compile by using: /EHsc
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace std::experimental::filesystem;

void main(int argc, char* argv[])
{
    wchar_t* p = L"C:/Users/Public/Documents";
    path filePath(p);

    filePath /= L"NewFile.txt";

    // Open, write to, and close the file.
    wofstream writeFile(filePath, ios::out);  // implicit conversion
    writeFile << L"Lorem ipsum\nDolor sit amet";
    writeFile.close();

    // Open, read, and close the file.
    wifstream readFile;
    wstring line;
    readFile.open(filePath);  // implicit conversions
    wcout << L"File " << filePath << L" contains:" << endl;
    while (readFile.good())
    {
        getline(readFile, line);
        wcout << line << endl;
    }
    readFile.close();

    wcout << endl << L"Press Enter to exit" << endl;
    wstring input;
    getline(wcin, input);
}
```

```Output
File C:\Users\Public\Documents\NewFile.txt contains:
Lorem ipsum
Dolor sit amet

Press Enter to exit
```

## <a name="iterating-directories-and-files"></a>Iterando diretórios e arquivos

O cabeçalho \<filesystem> fornece o tipo [directory_iterator](../standard-library/directory-iterator-class.md) para iterar em diretórios únicos e a classe [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md) para iterar recursivamente em um diretório e seus subdiretórios. Depois que você construir um iterador passando para ele um objeto `path`, o iterador apontará para o primeiro directory_entry no caminho. Crie o iterador final chamando o construtor padrão.

Ao iterar em um diretório, há vários tipos de itens que você pode encontrar, incluindo, mas não se limitando a, diretórios, arquivos, links simbólicos e arquivos de soquete. O `directory_iterator` retorna seus itens como objetos [directory_entry](../standard-library/directory-entry-class.md).
