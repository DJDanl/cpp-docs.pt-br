---
title: extern (C++)
description: Guia para o C++ idioma extern palavra-chave.
ms.date: 01/28/2020
f1_keywords:
- extern
- extern_CPP
helpviewer_keywords:
- extern keyword [C++], linkage to non-C++ functions
- declarations, external
- external linkage, extern modifier
ms.assetid: 1e2f0ae3-ae98-4410-85b5-222d6abc865a
no-loc:
- extern
- const
- constexpr
- permissive
ms.openlocfilehash: 422b6960802c59f1c45e0c22a4a85988c808a5b3
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821760"
---
# <a name="opno-locextern-c"></a>extern (C++)

A palavra-chave **extern** pode ser aplicada a uma variável global, uma função ou uma declaração de modelo. Ele especifica que o símbolo tem *vínculo externo*. Para obter informações básicas sobre vinculação e por que o uso de variáveis globais não é recomendado, consulte [unidades de tradução e vinculação](program-and-linkage-cpp.md).

A palavra-chave **extern** tem quatro significados dependendo do contexto:

- Em uma declaração de variável global não **const** , **extern** especifica que a variável ou função é definida em outra unidade de tradução. O **extern** deve ser aplicado em todos os arquivos, exceto aquele em que a variável é definida.

- Em uma declaração de variável **const** , ele especifica que a variável tem vínculo externo. O **extern** deve ser aplicado a todas as declarações em todos os arquivos. (As variáveis de **const** global têm vínculo interno por padrão.)

- **extern "C"** especifica que a função é definida em outro lugar e usa a Convenção de chamada de linguagem C. O modificador "C" extern também pode ser aplicado a várias declarações de função em um bloco.

- Em uma declaração de modelo, **extern** especifica que o modelo já foi instanciado em outro lugar. **extern** informa ao compilador que ele pode reutilizar a outra instanciação, em vez de criar uma nova no local atual. Para obter mais informações sobre esse uso de **extern** , consulte [instanciação explícita](explicit-instantiation.md).

## <a name="opno-locextern-linkage-for-non-opno-locconst-globals"></a>extern vínculo para globais nãoconst

Quando o vinculador vê **extern** antes de uma declaração de variável global, ele procura a definição em outra unidade de tradução. Declarações de variáveis não **const** no escopo global são externas por padrão. Aplique apenas **extern** às declarações que não fornecem a definição.

```cpp
//fileA.cpp
int i = 42; // declaration and definition

//fileB.cpp
extern int i;  // declaration only. same as i in FileA

//fileC.cpp
extern int i;  // declaration only. same as i in FileA

//fileD.cpp
int i = 43; // LNK2005! 'i' already has a definition.
extern int i = 43; // same error (extern is ignored on definitions)
```

## <a name="opno-locextern-linkage-for-opno-locconst-globals"></a>extern vínculo para const globais

Um **const** variável global tem vínculo interno por padrão. Se você quiser que a variável tenha vínculo externo, aplique a palavra-chave **extern** à definição e a todas as outras declarações em outros arquivos:

```cpp
//fileA.cpp
extern const int i = 42; // extern const definition

//fileB.cpp
extern const int i;  // declaration only. same as i in FileA
```

## <a name="opno-locextern-opno-locconstexpr-linkage"></a>extern vinculação de constexpr

No Visual Studio 2017 versão 15,3 e anteriores, o compilador sempre deu uma variável **constexpr** vinculação interna, mesmo quando a variável foi marcada **extern** . No Visual Studio 2017 versão 15,5 e posterior, a opção de compilador [/Zc: externConstexpr](../build/reference/zc-externconstexpr.md) habilita o comportamento correto de conformidade com padrões. Eventualmente, a opção se tornará o padrão. A opção [/permissive-](../build/reference/permissive-standards-conformance.md) não permite **/Zc: externConstexpr**.

```cpp
extern constexpr int x = 10; //error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada **extern** **constexpr** , ele deverá ser marcado `__declspec(selectany)` para ter corretamente suas declarações duplicadas combinadas:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

## <a name="opno-locextern-c-and-opno-locextern-c-function-declarations"></a>extern declarações de função "C"C++e extern ""

No C++, quando usado com uma cadeia de caracteres, **extern** especifica que as convenções de vinculação de outro idioma estão sendo usadas para o declarador (es). As funções e os dados de C podem ser acessados somente se eles forem declarados anteriormente como tendo vínculo C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.

A C++ Microsoft dá suporte às cadeias de caracteres **"C"** e **C++""** no campo *String-literal* . Todos os arquivos de inclusão padrão usam a sintaxe **extern "C"** para permitir que as funções de biblioteca de tempo de execução sejam C++ usadas em programas.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar nomes que têm vínculo C:

```cpp
// Declare printf with C linkage.
extern "C" int printf(const char *fmt, ...);

//  Cause everything in the specified
//  header files to have C linkage.
extern "C" {
    // add your #include statements here
#include <stdio.h>
}

//  Declare the two functions ShowChar
//  and GetChar with C linkage.
extern "C" {
    char ShowChar(char ch);
    char GetChar(void);
}

//  Define the two functions
//  ShowChar and GetChar with C linkage.
extern "C" char ShowChar(char ch) {
    putchar(ch);
    return ch;
}

extern "C" char GetChar(void) {
    char ch;
    ch = getchar();
    return ch;
}

// Declare a global variable, errno, with C linkage.
extern "C" int errno;
```

Se uma função tiver mais de uma especificação de vinculação, ela deverá concordar. É um erro declarar funções como tendo C e C++ vinculação. Além disso, se duas declarações para uma função ocorrem em um programa — uma com uma especificação de vinculação e a outra sem — a declaração com a especificação de vinculação deve ser a primeira. Todas as declarações redundantes de funções que já têm a especificação de vinculação são atribuídas a uma vinculação especificada na primeira declaração. Por exemplo:

```cpp
extern "C" int CFunc1();
...
int CFunc1();            // Redeclaration is benign; C linkage is
                         //  retained.

int CFunc2();
...
extern "C" int CFunc2(); // Error: not the first declaration of
                         //  CFunc2;  cannot contain linkage
                         //  specifier.
```

## <a name="see-also"></a>Veja também

\ [palavras-chave](../cpp/keywords-cpp.md)
\ [de vínculo e unidades de tradução](program-and-linkage-cpp.md)
[extern especificador de classe de armazenamento em C](../c-language/extern-storage-class-specifier.md)\
[Comportamento de identificadores em C](../c-language/behavior-of-identifiers.md)\
[Ligação em C](../c-language/linkage.md)
