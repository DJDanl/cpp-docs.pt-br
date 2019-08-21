---
title: Erro do compilador C2065
ms.date: 08/19/2019
f1_keywords:
- C2065
helpviewer_keywords:
- C2065
ms.assetid: 78093376-acb7-45f5-9323-5ed7e0aab1dc
ms.openlocfilehash: 40d1d0744588c4b7911e84f5e57a6b40372b48cf
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630129"
---
# <a name="compiler-error-c2065"></a>Erro do compilador C2065

> '*Identifier*': identificador não declarado

O compilador não pode localizar a declaração para um identificador. Há muitas causas possíveis para esse erro. As causas mais comuns de C2065 são que o identificador não foi declarado, o identificador é digitado incorretamente, o cabeçalho em que o identificador é declarado não está incluído no arquivo ou o identificador não tem um qualificador de escopo, por `cout` exemplo, em vez de `std::cout`. Para obter mais informações sobre declarações C++no, consulte [declarações e definiçõesC++()](../../cpp/declarations-and-definitions-cpp.md).

Aqui estão alguns problemas e soluções comuns com mais detalhes.

## <a name="the-identifier-is-undeclared"></a>O identificador não está declarado

Se o identificador for uma variável ou um nome de função, você deverá declará-lo antes que possa ser usado. Uma declaração de função também deve incluir os tipos de seus parâmetros antes que a função possa ser usada. Se a variável for declarada usando `auto`, o compilador deverá ser capaz de inferir o tipo de seu inicializador.

Se o identificador for um membro de uma classe ou struct, ou declarado em um namespace, ele deverá ser qualificado pelo nome de classe ou struct, ou pelo nome do namespace, quando usado fora do escopo de struct, classe ou namespace. Como alternativa, o namespace deve ser colocado no escopo por uma `using` diretiva `using namespace std;`, como, ou o nome do membro deve ser colocado no escopo por `using` `using std::string;`uma declaração, como. Caso contrário, o nome não qualificado será considerado um identificador não declarado no escopo atual.

Se o identificador for a marca para um tipo definido pelo usuário, por exemplo, um `class` ou `struct`, o tipo da marca deverá ser declarado antes que possa ser usado. Por exemplo, a Declaração `struct SomeStruct { /*...*/ };` deve existir antes que você possa declarar uma `SomeStruct myStruct;` variável em seu código.

Se o identificador for um alias de tipo, o tipo deverá ser declarado usando uma `using` declaração ou `typedef` antes que possa ser usado. Por exemplo, você deve declarar `using my_flags = std::ios_base::fmtflags;` antes de poder usar `my_flags` como um alias de tipo `std::ios_base::fmtflags`para.

## <a name="example-misspelled-identifier"></a>Exemplo: identificador com ortografia incorreta

Esse erro geralmente ocorre quando o nome do identificador é digitado incorretamente ou o identificador usa letras maiúsculas e minúsculas incorretas. O nome na declaração deve corresponder exatamente ao nome usado.

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

Esse erro pode ocorrer se o identificador não tiver o escopo correto. Se você vir C2065 quando usar `cout`, essa é a causa. Quando C++ funções e operadores de biblioteca padrão não são totalmente qualificados pelo namespace ou você não colocou o `std` namespace no escopo atual usando uma `using` diretiva, o compilador não consegue encontrá-los. Para corrigir esse problema, você deve qualificar totalmente os nomes de identificador ou especificar o namespace com a `using` diretiva.

Este exemplo não é compilado porque `cout` e `endl` estão definidos no `std` namespace:

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

Os identificadores declarados nos `class`tipos `struct`, ou `enum class` também devem ser qualificados pelo nome de seu escopo delimitador quando você os usa fora desse escopo.

## <a name="example-precompiled-header-isnt-first"></a>Exemplo: cabeçalho pré-compilado não é primeiro

Esse erro pode ocorrer se você colocar quaisquer diretivas de pré-processador, como #include, #define ou #pragma, antes da #include de um arquivo de cabeçalho pré-compilado. Se o arquivo de origem usar um arquivo de cabeçalho pré-compilado (ou seja, se for compilado usando a opção de compilador **/Yu** ), todas as diretivas de pré-processador antes do arquivo de cabeçalho pré-compilado serão ignoradas.

Este exemplo não é compilado porque `cout` e `endl` são definidos no cabeçalho \<de > iostream, que é ignorado porque está incluído antes do arquivo de cabeçalho pré-compilado. Para criar este exemplo, crie todos os três arquivos, compile stdafx. cpp e compile C2065_pch. cpp.

```cpp
// pch.h (stdafx.h in Visual Studio 2017 and earlier)
#include <stdio.h>
```

```cpp
// pch.cpp (stdafx.cpp in Visual Studio 2017 and earlier)
// Compile by using: cl /EHsc /W4 /c /Ycstdafx.h stdafx.cpp
#include "pch.h"
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

Para corrigir esse problema, adicione o #include do \<iostream > no arquivo de cabeçalho pré-compilado ou mova-o depois que o arquivo de cabeçalho pré-compilado estiver incluído no arquivo de origem.

## <a name="example-missing-header-file"></a>Exemplo: arquivo de cabeçalho ausente

Você não incluiu o arquivo de cabeçalho que declara o identificador. Verifique se o arquivo que contém a declaração do identificador está incluído em cada arquivo de origem que o usa.

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

Outra causa possível é se você usar uma lista de inicializadores sem \<incluir o cabeçalho de > initializer_list.

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

Você poderá ver esse erro nos arquivos de origem do aplicativo da área de `VC_EXTRALEAN`trabalho `WIN32_LEAN_AND_MEAN`do Windows `WIN32_EXTRA_LEAN`se definir, ou. Essas macros de pré-processador excluem alguns arquivos de cabeçalho de Windows. h\_e afxv W32. h para agilizar a compilação. Procure em Windows. h e afxv_w32. h uma descrição atualizada do que é excluído.

## <a name="example-missing-closing-quote"></a>Exemplo: ausência de aspas de fechamento

Esse erro pode ocorrer se você não tiver uma aspa de fechamento após uma constante de cadeia de caracteres. Essa é uma maneira fácil de confundir o compilador. Observe que as aspas de fechamento ausentes podem ser várias linhas antes do local de erro relatado.

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

## <a name="example-use-iterator-outside-for-loop-scope"></a>Exemplo: usar o iterador fora do escopo do loop

Esse erro pode ocorrer se você declarar uma variável de iterador `for` em um loop e, em seguida, tentar usar essa variável `for` de iterador fora do escopo do loop. O compilador habilita a opção de compilador [/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) por padrão. Consulte [debug Iterator support](../../standard-library/debug-iterator-support.md) para obter mais informações.

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

## <a name="example-preprocessor-removed-declaration"></a>Exemplo: declaração removida do pré-processador

Esse erro pode ocorrer se você se referir a uma função ou variável que está em código compilado condicionalmente que não é compilado para sua configuração atual. Isso também pode ocorrer se você chamar uma função em um arquivo de cabeçalho que não tem suporte atualmente em seu ambiente de compilação. Se determinadas variáveis ou funções estiverem disponíveis apenas quando uma macro de pré-processador específica for definida, verifique se o código que chama essas funções só pode ser compilado quando a mesma macro de pré-processador for definida. Esse problema é fácil de detectar no IDE, pois a declaração da função estará esmaecida se as macros de pré-processador necessárias não estiverem definidas para a configuração de compilação atual.

Este é um exemplo de código que funciona quando você cria em depuração, mas não para o varejo:

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

## <a name="example-ccli-type-deduction-failure"></a>Exemplo: C++Falha de dedução de tipo/CLI

Esse erro pode ocorrer ao chamar uma função genérica, se o argumento de tipo pretendido não puder ser deduzido dos parâmetros usados. Para obter mais informações, consulte [funções genéricasC++(/CLI)](../../extensions/generic-functions-cpp-cli.md).

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

## <a name="example-ccli-attribute-parameters"></a>Exemplo: C++Parâmetros de atributo/CLI

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: verificação de C++ parâmetros para atributos visuais.

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
