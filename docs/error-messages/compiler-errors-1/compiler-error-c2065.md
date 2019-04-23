---
title: Erro do compilador C2065
ms.date: 09/01/2017
f1_keywords:
- C2065
helpviewer_keywords:
- C2065
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
ms.openlocfilehash: 3daf2cd532cd07225b822c80b46fc28274d4e2a8
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59779395"
---
# <a name="compiler-error-c2065"></a>Erro do compilador C2065

> '*identificador*': identificador não declarado

O compilador não é possível encontrar a declaração de um identificador. Há muitas causas possíveis para esse erro. As causas mais comuns de C2065 são que o identificador não tenha sido declarado, o identificador está incorreto, o cabeçalho no qual o identificador é declarado não é incluído no arquivo ou o identificador está faltando um qualificador de escopo, por exemplo, `cout` em vez de `std::cout`. Para obter mais informações sobre declarações em C++, consulte [declarações e definições (C++)](../../cpp/declarations-and-definitions-cpp.md).

Aqui estão alguns problemas comuns e soluções mais detalhadamente.

## <a name="the-identifier-is-undeclared"></a>O identificador não está declarado

Se o identificador é uma variável ou um nome de função, você deve declará-la antes que ele pode ser usado. Uma declaração de função também deve incluir os tipos de seus parâmetros para a função possa ser usada. Se a variável é declarada usando `auto`, o compilador deve ser capaz de inferir o tipo do seu inicializador.

Se o identificador é um membro de uma classe ou struct ou declarado em um namespace, ele deve ser qualificado pelo nome de classe ou struct, ou o nome do namespace, quando usado fora do escopo de namespace, classe ou struct. Como alternativa, o namespace deve ser colocado no escopo por um `using` diretiva, como `using namespace std;`, ou o nome do membro deve ser colocado no escopo por uma `using` declaração, como `using std::string;`. Caso contrário, o nome não qualificado é considerado um identificador não declarado no escopo atual.

Se o identificador é a marca para um tipo definido pelo usuário, por exemplo, uma `class` ou `struct`, o tipo da marca deve ser declarado antes que ele pode ser usado. Por exemplo, a declaração `struct SomeStruct { /*...*/ };` deve existir antes que você pode declarar uma variável `SomeStruct myStruct;` em seu código.

Se o identificador é um alias de tipo, o tipo deve ser declarado usando um `using` declaração ou `typedef` antes que ele pode ser usado. Por exemplo, você deve declarar `using my_flags = std::ios_base::fmtflags;` antes de usar `my_flags` como um alias de tipo para `std::ios_base::fmtflags`.

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

## <a name="example-use-an-unscoped-identifier"></a>Exemplo: usar um identificador sem escopo

Esse erro pode ocorrer se o identificador não está no escopo corretamente. Se você vir C2065 quando você usa `cout`, essa é a causa. Quando operadores e funções de biblioteca padrão C++ não são totalmente qualificados por namespace, ou você não tiver colocado o `std` namespace no escopo atual, usando um `using` diretiva, o compilador não é possível encontrá-los. Para corrigir esse problema, você deve totalmente qualificar os nomes de identificador, ou especifique o namespace com o `using` diretiva.

Este exemplo falhará ao ser compilado porque `cout` e `endl` são definidos na `std` namespace:

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

Identificadores que são declarados dentro de `class`, `struct`, ou `enum class` tipos também devem ser qualificados pelo nome do respectivo escopo delimitador quando usá-los fora do escopo.

## <a name="example-precompiled-header-isnt-first"></a>Exemplo: cabeçalho pré-compilado não é primeiro

Esse erro pode ocorrer se você colocar qualquer diretivas de pré-processador, como #include, #define, ou #pragma, antes do #include de um arquivo de cabeçalho pré-compilado. Se seu arquivo de origem usa um arquivo de cabeçalho pré-compilado (ou seja, se ele é compilado usando o **/Yu** opção de compilador), todas as diretivas de pré-processador antes do arquivo de cabeçalho pré-compilado serão ignoradas.

Este exemplo falhará ao ser compilado porque `cout` e `endl` são definidos na \<iostream > cabeçalho, que é ignorado porque ele está incluído para que o arquivo de cabeçalho pré-compilado. Para compilar este exemplo, crie todos os três arquivos, em seguida, compilar Stdafx e compilar C2065_pch.cpp.

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

Para corrigir esse problema, adicione o #include do \<iostream > no arquivo de cabeçalho pré-compilado ou move-lo após o arquivo de cabeçalho pré-compilado está incluído no arquivo de origem.

## <a name="example-missing-header-file"></a>Exemplo: está faltando o arquivo de cabeçalho

Você não incluiu o arquivo de cabeçalho que declara o identificador. Verifique se o arquivo que contém a declaração para o identificador está incluído em todos os arquivos de origem que o utiliza.

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

Outra causa possível é se você usar uma lista de inicializadores sem incluir o \<initializer_list > cabeçalho.

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

Você pode ver este erro nos arquivos de origem do aplicativo de área de trabalho do Windows, se você definir `VC_EXTRALEAN`, `WIN32_LEAN_AND_MEAN`, ou `WIN32_EXTRA_LEAN`. Essas macros de pré-processador excluir alguns arquivos de cabeçalho do Windows. h e afxv\_w32.h para acelerar compila. Procure no Windows. h e afxv_w32.h para uma descrição atualizada do que foi excluído.

## <a name="example-missing-closing-quote"></a>Exemplo: aspas de fechamento ausente

Esse erro pode ocorrer se estiver faltando aspas de fechamento após uma constante de cadeia de caracteres. Isso é uma maneira fácil confundir o compilador. Observe que as aspas de fechamento ausente podem ser várias linhas antes do local do erro relatado.

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

## <a name="example-use-iterator-outside-for-loop-scope"></a>Exemplo: usar o iterador fora do escopo de loop for

Esse erro pode ocorrer se você declarar uma variável do iterador em um `for` loop e, em seguida, tente usar essa variável de iterador fora do escopo de `for` loop. O compilador permite que o [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) opção de compilador por padrão. Ver [suporte a iterador de depuração](../../standard-library/debug-iterator-support.md) para obter mais informações.

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

Esse erro pode ocorrer se você se referir a uma função ou variável que está no código compilado condicionalmente que não seja compilado para a sua configuração atual. Isso também pode ocorrer se você chamar uma função em um arquivo de cabeçalho que não é suportado atualmente no seu ambiente de compilação. Se determinadas variáveis ou funções estão disponíveis somente quando uma macro de pré-processador específica é definida, verifique se o código que chama as funções só pode ser compilado quando a mesma macro do pré-processador é definida. Esse problema é mais fácil identificar no IDE, porque a declaração da função fica acinzentada se as macros de pré-processador necessárias não estão definidas para a configuração de compilação atual.

Este é um exemplo de código que funciona quando você compilar na depuração, mas não de varejo:

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

## <a name="example-ccli-type-deduction-failure"></a>Exemplo: C++/ Falha na dedução de tipo CLI

Esse erro pode ocorrer ao chamar uma função genérica, se o argumento de tipo pretendida não pode ser deduzido dos parâmetros usados. Para obter mais informações, consulte [funções genéricas (C++/CLI)](../../extensions/generic-functions-cpp-cli.md).

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

## <a name="example-ccli-attribute-parameters"></a>Exemplo: C++/ Parâmetros de atributo CLI

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: parâmetros de verificação para os atributos do Visual C++.

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
