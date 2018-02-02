---
title: C2065 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 09/01/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2065
dev_langs:
- C++
helpviewer_keywords:
- C2065
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a20fee308a8ed9d237f8fc76df60964704c9c69d
ms.sourcegitcommit: 1e367a5f5c5a6fd0b6018f4fb5edcdf2f1a8085c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2018
---
# <a name="compiler-error-c2065"></a>C2065 de erro do compilador

> '*identificador*': identificador não declarada

O compilador não pode encontrar a declaração de um identificador. Há várias causas possíveis para esse erro. As causas mais comuns de C2065 são que o identificador não tenha sido declarado, o identificador está incorreto, o cabeçalho de onde o identificador é declarado não é incluído no arquivo ou o identificador está faltando um qualificador de escopo, por exemplo, `cout` em vez de `std::cout`. Para obter mais informações sobre declarações em C++, consulte [declarações e definições (C++)](../../cpp/declarations-and-definitions-cpp.md).

Aqui estão alguns problemas comuns e soluções mais detalhadamente.

## <a name="the-identifier-is-undeclared"></a>O identificador é não declarado

Se o identificador é uma variável ou um nome de função, você deve declará-lo antes de ser usada. Uma declaração de função também deve incluir os tipos de seus parâmetros para a função possa ser usada. Se a variável é declarada usando `auto`, o compilador deve ser capaz de inferir o tipo do seu inicializador.

Se o identificador é um membro de uma classe ou struct ou declarado em um namespace, deve ser qualificado com o nome de classe ou estrutura, ou o nome do namespace, quando usada fora do escopo de namespace, classe ou estrutura. Como alternativa, o namespace deve ser colocado em escopo por um `using` diretiva como `using namespace std;`, ou o nome do membro deve ser colocado em escopo por um `using` declaração, como `using std::string;`. Caso contrário, o nome não qualificado é considerado um identificador não declarado no escopo atual.

Se o identificador é a marca de um tipo definido pelo usuário, por exemplo, um `class` ou `struct`, o tipo da marca deve ser declarado antes de ser usada. Por exemplo, a declaração `struct SomeStruct { /*...*/ };` devem existir antes que você pode declarar uma variável `SomeStruct myStruct;` em seu código.

Se o identificador é um alias de tipo, o tipo deve ser declarado usando um `using` declaração ou `typedef` antes de ser usada. Por exemplo, você deve declarar `using my_flags = std::ios_base::fmtflags;` antes de usar `my_flags` como um alias de tipo para `std::ios_base::fmtflags`.

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

## <a name="example-use-an-unscoped-identifier"></a>Exemplo: use um identificador de fora do escopo

Esse erro pode ocorrer se o identificador de escopo não é corretamente. Se você vir C2065 quando você usar `cout`, essa é a causa. Quando operadores e funções de biblioteca padrão C++ não são totalmente qualificados por namespace ou não ter colocado o `std` namespace para o escopo atual usando um `using` diretiva, o compilador não pode encontrá-los. Para corrigir esse problema, você deve totalmente qualificar os nomes de identificador, ou especifique o namespace com o `using` diretiva.

Este exemplo não compila porque `cout` e `endl` são definidos no `std` namespace:

```cpp
// C2065_scope.cpp
// compile with: cl /EHsc C2065_scope.cpp
#include <iostream>
// using namespace std;   // Uncomment this line to fix

int main() {
    cout << "Hello" << endl;   // C2065 'cout': undeclared identifier 
                               // C2065 'endl': undeclared identifier
    // Or try the following line instead
    std::cout << "Hello" << std::endl;
}
```

Os identificadores que são declarados dentro de `class`, `struct`, ou `enum class` tipos também devem ser qualificados pelo nome do seu escopo delimitador quando usá-los fora do escopo.

## <a name="example-precompiled-header-isnt-first"></a>Exemplo: o cabeçalho pré-compilado não primeiro

Esse erro pode ocorrer se você colocar todas as diretivas de pré-processamento, como #include, #define, ou #pragma, antes de #include de um arquivo de cabeçalho pré-compilado. Se o arquivo de origem usa um arquivo de cabeçalho pré-compilado (ou seja, se ele for compilado usando o **/Yu** opção de compilador) e todas as diretivas de pré-processador antes do arquivo de cabeçalho pré-compilado são ignoradas.

Este exemplo não compila porque `cout` e `endl` são definidos no \<iostream > cabeçalho, que é ignorado porque ele está incluído antes do arquivo de cabeçalho pré-compilado. Para criar este exemplo, criar todos os três arquivos, em seguida, compilar Stdafx e compilar C2065_pch.cpp.

```cpp
// stdafx.h
#include <stdio.h>
```

```cpp
// stdafx.cpp
// Compile by using: cl /EHsc /W4 /c /Ycstdafx.h stdafx.cpp
#include <stdafx.h>
```

```cpp
// C2065_pch.cpp
// compile with: cl /EHsc /W4 /Yustdafx.h C2065_pch.cpp
#include <iostream>
#include "stdafx.h"
using namespace std;

int main() {
    cout << "Hello" << endl;   // C2065 'cout': undeclared identifier
                               // C2065 'endl': undeclared identifier
}
```

Para corrigir esse problema, adicione o #include de \<iostream > no arquivo de cabeçalho pré-compilado ou move-lo após o arquivo de cabeçalho pré-compilado está incluído no arquivo de origem.

## <a name="example-missing-header-file"></a>Exemplo: faltando o arquivo de cabeçalho

Você não incluiu o arquivo de cabeçalho que declara o identificador. Verifique se o arquivo que contém a declaração do identificador é incluído em todos os arquivos de origem que usam.

```cpp
// C2065_header.cpp
// compile with: cl /EHsc C2065_header.cpp 

//#include <stdio.h> 
int main() { 
    fpos_t file_position = 42; // C2065: 'fpos_t': undeclared identifier 
    // To fix, uncomment the #include <stdio.h> line
    // to include the header where fpos_t is defined
} 
```

Outra causa possível é que se você usar uma lista de inicializadores sem incluir o \<lista_de_inicializadores > cabeçalho.

```cpp
// C2065_initializer.cpp
// compile with: cl /EHsc C2065_initializer.cpp 

// #include <initializer_list> 
int main() { 
    for (auto strList : {"hello", "world"})
        if (strList == "hello") // C2065: 'strList': undeclared identifier 
            return 1; 
    // To fix, uncomment the #include <initializer_list> line
} 
```

Você pode ver este erro nos arquivos de origem do aplicativo de área de trabalho do Windows, se você definir `VC_EXTRALEAN`, `WIN32_LEAN_AND_MEAN`, ou `WIN32_EXTRA_LEAN`. Essas macros de pré-processador excluir alguns arquivos de cabeçalho do Windows. h e afxv\_w32.h para acelerar compila. Procure no Windows. h e afxv_w32.h para obter uma descrição atualizada do que foi excluído.

## <a name="example-missing-closing-quote"></a>Exemplo: aspas de fechamento ausente

Esse erro pode ocorrer se estiver faltando aspas de fechamento após uma constante de cadeia de caracteres. Isso é uma maneira fácil confundir o compilador. Observe que as aspas de fechamento ausente podem ter várias linhas antes do local do erro relatado. 

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

## <a name="example-ccli-type-deduction-failure"></a>Exemplo: C + + Falha na dedução de tipo CLI

Esse erro pode ocorrer ao chamar uma função genérica, se o argumento de tipo pretendida não pode ser deduzido dos parâmetros usados. Para obter mais informações, consulte [funções genéricas (C + + CLI)](../../windows/generic-functions-cpp-cli.md).

```cpp
// C2065_b.cpp
// compile with: cl /clr C2065_b.cpp 
generic <typename ItemType>
void G(int i) {}

int main() {
   // global generic function call
   G<T>(10);     // C2065
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
