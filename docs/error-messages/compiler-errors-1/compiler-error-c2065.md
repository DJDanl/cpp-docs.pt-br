---
title: C2065 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2065
dev_langs:
- C++
helpviewer_keywords:
- C2065
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 128bd124c2536d86c8b673b54abc4b5505526b41
ms.openlocfilehash: 5a3a0d4389a958f421f23a4dc96a395eaf3e22ab
ms.contentlocale: pt-br
ms.lasthandoff: 05/10/2017

---
# <a name="compiler-error-c2065"></a>C2065 de erro do compilador
'Identificador': identificador não declarada  
  
O compilador não pode encontrar a declaração de um identificador. Se o identificador é uma variável, você deve especificar o tipo da variável em uma declaração antes de ser usada. Se o identificador é um nome de função, os parâmetros que usa a função devem ser especificados em uma declaração antes da função pode ser usada. Se o identificador é a marca de um tipo definido pelo usuário, por exemplo, um `class` ou `struct`, o tipo da marca deve ser declarado antes de ser usada. Se o identificador é um alias de tipo, o tipo deve ser declarado usando um `using` declaração ou `typedef` para o tipo possa ser usado.  
  
Há várias causas possíveis para esse erro. Aqui estão alguns dos problemas mais comuns:
  
## <a name="example-misspelled-identifier"></a>Exemplo: identificador incorreta  
  
Esse erro normalmente ocorre quando o nome do identificador está incorreto ou o identificador usa as letras maiusculas e minúsculas erradas. O nome na declaração deve corresponder exatamente ao nome que você usar.  
  
```cpp  
// C2065_spell.cpp  
// compile with: cl /EHsc C2065_spell.cpp 
#include <iostream> 
using namespace std; 
int main() { 
    int someIdentifier = 42; 
    cout << "Some Identifier: " << SomeIdentifier << endl;   
    // C2065: 'SomeIdentifier': undeclared identifier 
    // To fix, correct the spelling:  
    // cout << "Some Identifier: " << someIdentifier << endl;   
}  
```
  
## <a name="example-missing-header-file"></a>Exemplo: faltando o arquivo de cabeçalho  
  
Você não incluiu o arquivo de cabeçalho que declara o identificador. Verifique se o arquivo que contém a declaração do identificador é incluído em todos os arquivos de origem que usam.  
  
```cpp  
// C2065_header.cpp  
// compile with: cl /EHsc C2065_spell.cpp 

//#include <stdio.h> 
int main() { 
    fpos_t file_position = 42; // C2065: 'fpos_t': undeclared identifier 
    // To fix, uncomment the #include <stdio.h> line
    // to include the header where fpos_t is defined  
} 
```  
  
Você pode ver este erro nos arquivos de origem do aplicativo de área de trabalho do Windows, se você definir `VC_EXTRALEAN`, `WIN32_LEAN_AND_MEAN`, ou `WIN32_EXTRA_LEAN`. Essas macros de pré-processador excluir alguns arquivos de cabeçalho do Windows. h e afxv\_w32.h para acelerar compila. Procure no Windows. h e afxv_w32.h para obter uma descrição atualizada do que foi excluído.  
  
## <a name="eample-missing-closing-quote"></a>Eample: aspas de fechamento ausente  
  
Esse erro pode ocorrer se estiver faltando aspas de fechamento após uma constante de cadeia de caracteres. Isso é uma maneira fácil confundir o compilador. 
  
```cpp  
// C2065_quote.cpp  
// compile with: cl /EHsc C2065_quote.cpp 
#include <iostream>  

int main() { 
    // Fix this issue by adding the closing quote to "Aaaa"
    char * first = "Aaaa, * last = "Zeee"; 
    std::cout << "Name: " << first 
        << " " << last << std::endl; // C2065: 'last': undeclared identifier 
} 
```  
  
## <a name="example-use-iterator-outside-for-loop-scope"></a>Exemplo: usar iterador fora de escopo de loop  
  
Esse erro pode ocorrer se você declarar uma variável de iterador em uma `for` loop e, em seguida, tente usar essa variável de iterador fora do escopo de `for` loop. Permite que o compilador a [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador por padrão. Consulte [suporte a iterador depurar](../../standard-library/debug-iterator-support.md) para obter mais informações.  
  
```cpp  
// C2065_iter.cpp  
// compile with: cl /EHsc C2065_iter.cpp 
#include <iostream> 
#include <string> 

int main() {
    // char last = '!'; 
    std::string letters{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" }; 
    for (const char& c : letters) {
        if ('Q' == c) {
            std::cout << "Found Q!" << std::endl;
        }
        // last = c;
    }
    std::cout << "Last letter was " << c << std::endl; // C2065
    // Fix by using a variable declared in an outer scope.
    // Uncomment the lines that declare and use 'last' for an example.
    // std::cout << "Last letter was " << last << std::endl; // C2065
} 
```  
  
## <a name="example-preprocessor-removed-declaration"></a>Exemplo: declaração removida pré-processador  
  
Esse erro pode ocorrer se você fizer referência a uma função ou variável no código condicionalmente compilado que não é compilado para a sua configuração atual. Isso também pode ocorrer se você chamar uma função em um arquivo de cabeçalho que não é suportado atualmente em seu ambiente de compilação. Se determinados variáveis ou funções estão disponíveis somente quando uma macro de pré-processador específica é definida, verifique se o código que chama as funções só pode ser compilado quando a mesma macro de pré-processador é definida. Esse problema é fácil especiais no IDE, porque a declaração da função fica acinzentada se as macros de pré-processador necessárias não estão definidas para a configuração de compilação atual.  
  
Este é um exemplo de código que funciona quando a compilação de depuração, mas não de varejo:  
  
```cpp  
// C2065_defined.cpp
// Compile with: cl /EHsc /W4 /MT C2065_defined.cpp
#include <iostream>
#include <crtdbg.h>
#ifdef _DEBUG
    _CrtMemState oldstate;
#endif
int main() {
    _CrtMemDumpStatistics(&oldstate); 
    std::cout << "Total count " << oldstate.lTotalCount; // C2065
    // Fix by guarding references the same way as the declaration:
    // #ifdef _DEBUG
    //    std::cout << "Total count " << oldstate.lTotalCount;
    // #endif
}
```
  
## <a name="example-use-an-unscoped-identifier"></a>Exemplo: use um identificador de fora do escopo  
  
Esse erro pode ocorrer se o identificador de escopo não é corretamente. Por exemplo, quando operadores e funções de biblioteca padrão C++ não são totalmente qualificados por namespace, ou você não tiver colocado o `std` namespace para o escopo atual usando um `using` diretiva, o compilador não pode encontrá-los. Para corrigir esse problema, você deve totalmente qualificar os nomes de identificador, ou especifique o namespace com o `using` diretiva.  
  
Este exemplo não compila porque `cout` e `endl` são definidos no `std` namespace:  
  
```cpp  
// C2065_scope.cpp  
// compile with: cl /EHsc C2065_scope.cpp 
// using namespace std;   // Uncomment this line to fix  
#include <iostream>  
int main() {  
    cout << "Hello" << endl;   // C2065 'cout': undeclared identifier 
                               // C2065 'endl': undeclared identifier
    // Or try the following line instead  
    std::cout << "Hello" << std::endl;  
}
```  
  
Os identificadores que são declarados dentro de `class`, `struct`, ou `enum class` tipos, também deve ser qualificado pelo nome do escopo delimitador.
  
## <a name="example-ccli-type-deduction-failure"></a>Exemplo: C + + Falha na dedução de tipo CLI  
  
Esse erro pode ocorrer ao chamar uma função genérica, se o argumento de tipo pretendida não pode ser deduzido dos parâmetros usados. Para obter mais informações, consulte [funções genéricas (C + + CLI)](../../windows/generic-functions-cpp-cli.md).  
  
```cpp  
// C2065_b.cpp  
// compile with: /clr  
generic <typename ItemType>  
void G(int i) {}  
  
int main() {  
   // global generic function call  
   G<T>(10);   // C2065  
   G<int>(10);   // OK - fix with a specific type argument  
}  
```  
  
## <a name="example-ccli-attribute-parameters"></a>Exemplo: C + + parâmetros do atributo CLI  
  
Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: parâmetro procurando atributos do Visual C++.  
  
```cpp  
// C2065_attributes.cpp  
// compile with: cl /c /clr C2065_attributes.cpp  
[module(DLL, name=MyLibrary)];   // C2065  
// try the following line instead  
// [module(dll, name="MyLibrary")];  
  
[export]  
struct MyStruct {  
   int i;  
};  
```  

