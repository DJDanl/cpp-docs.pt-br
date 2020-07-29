---
title: :::no-loc(extern):::C
description: 'Guia para a :::no-loc(extern)::: palavra-chave da linguagem C++.'
ms.date: 01/28/2020
f1_keywords:
- ':::no-loc(extern):::'
- :::no-loc(extern):::_CPP
helpviewer_keywords:
- ':::no-loc(extern)::: keyword [C++], linkage to non-C++ functions'
- declarations, :::no-loc(extern):::al
- ':::no-loc(extern):::al linkage, :::no-loc(extern)::: modifier'
ms.assetid: 1e2f0ae3-ae98-4410-85b5-222d6abc865a
no-loc:
- ':::no-loc(extern):::'
- ':::no-loc(const):::'
- ':::no-loc(constexpr):::'
- ':::no-loc(permissive):::'
ms.openlocfilehash: 510352f9e99e513f4a426f6ef89be4474085d97c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227498"
---
# <a name="no-locextern-c"></a>:::no-loc(extern):::C

A **`:::no-loc(extern):::`** palavra-chave pode ser aplicada a uma variável global, função ou declaração de modelo. Ele especifica que o símbolo tem a * :::no-loc(extern)::: vinculação Al*. Para obter informações básicas sobre vinculação e por que o uso de variáveis globais não é recomendado, consulte [unidades de tradução e vinculação](program-and-linkage-cpp.md).

A **`:::no-loc(extern):::`** palavra-chave tem quatro significados dependendo do contexto:

- Em uma declaração de **`:::no-loc(const):::`** variável não global, **`:::no-loc(extern):::`** especifica que a variável ou função é definida em outra unidade de tradução. O **`:::no-loc(extern):::`** deve ser aplicado em todos os arquivos, exceto aquele em que a variável é definida.

- Em uma **`:::no-loc(const):::`** declaração de variável, ele especifica que a variável tem :::no-loc(extern)::: vínculo al. O **`:::no-loc(extern):::`** deve ser aplicado a todas as declarações em todos os arquivos. (As **`:::no-loc(const):::`** variáveis globais têm vínculo interno por padrão.)

- ** :::no-loc(extern)::: "C"** especifica que a função é definida em outro lugar e usa a Convenção de chamada de linguagem C. O :::no-loc(extern)::: modificador "C" também pode ser aplicado a várias declarações de função em um bloco.

- Em uma declaração de modelo, **`:::no-loc(extern):::`** especifica que o modelo já foi instanciado em outro lugar. **`:::no-loc(extern):::`** informa ao compilador que ele pode reutilizar a outra instanciação, em vez de criar uma nova no local atual. Para obter mais informações sobre esse uso de **`:::no-loc(extern):::`** , consulte [instanciação explícita](explicit-instantiation.md).

## <a name="no-locextern-linkage-for-non-no-locconst-globals"></a>:::no-loc(extern):::vínculo para não :::no-loc(const)::: globais

Quando o vinculador vê **`:::no-loc(extern):::`** antes de uma declaração de variável global, ele procura a definição em outra unidade de tradução. As declarações de não **`:::no-loc(const):::`** variáveis em escopo global são :::no-loc(extern)::: Al por padrão. Aplica-se somente **`:::no-loc(extern):::`** às declarações que não fornecem a definição.

```cpp
//fileA.cpp
int i = 42; // declaration and definition

//fileB.cpp
:::no-loc(extern)::: int i;  // declaration only. same as i in FileA

//fileC.cpp
:::no-loc(extern)::: int i;  // declaration only. same as i in FileA

//fileD.cpp
int i = 43; // LNK2005! 'i' already has a definition.
:::no-loc(extern)::: int i = 43; // same error (:::no-loc(extern)::: is ignored on definitions)
```

## <a name="no-locextern-linkage-for-no-locconst-globals"></a>:::no-loc(extern):::vínculo para :::no-loc(const)::: globais

**`:::no-loc(const):::`** Por padrão, uma variável global tem ligação interna. Se você quiser que a variável tenha :::no-loc(extern)::: vínculo Al, aplique a **`:::no-loc(extern):::`** palavra-chave à definição e a todas as outras declarações em outros arquivos:

```cpp
//fileA.cpp
:::no-loc(extern)::: :::no-loc(const)::: int i = 42; // :::no-loc(extern)::: :::no-loc(const)::: definition

//fileB.cpp
:::no-loc(extern)::: :::no-loc(const)::: int i;  // declaration only. same as i in FileA
```

## <a name="no-locextern-no-locconstexpr-linkage"></a>:::no-loc(extern)::::::no-loc(constexpr):::vinculação

No Visual Studio 2017 versão 15,3 e anteriores, o compilador sempre deu uma **`:::no-loc(constexpr):::`** variável de vinculação interna, mesmo quando a variável foi marcada **`:::no-loc(extern):::`** . No Visual Studio 2017 versão 15,5 e posterior, a opção de compilador [/Zc: :::no-loc(extern)::: Constexpr](../build/reference/zc-:::no-loc(extern)::::::no-loc(constexpr):::.md) habilita o comportamento correto de conformidade com padrões. Eventualmente, a opção se tornará o padrão. A [/:::no-loc(permissive):::-](../build/reference/:::no-loc(permissive):::-standards-conformance.md) opção não habilita **/Zc: :::no-loc(extern)::: Constexpr**.

```cpp
:::no-loc(extern)::: :::no-loc(constexpr)::: int x = 10; //error LNK2005: "int :::no-loc(const)::: x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada **`:::no-loc(extern):::`** **`:::no-loc(constexpr):::`** , ele deverá ser marcado `__declspec(selectany)` corretamente para ter suas declarações duplicadas combinadas:

```cpp
:::no-loc(extern)::: :::no-loc(constexpr)::: __declspec(selectany) int x = 10;
```

## <a name="no-locextern-c-and-no-locextern-c-function-declarations"></a>:::no-loc(extern):::Declarações de função "C" e :::no-loc(extern)::: "C++"

Em C++, quando usado com uma cadeia de caracteres, **`:::no-loc(extern):::`** especifica que as convenções de vinculação de outro idioma estão sendo usadas para o declarador (es). As funções e os dados de C podem ser acessados somente se eles forem declarados anteriormente como tendo vínculo C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.

O Microsoft C++ dá suporte às cadeias de caracteres **"C"** e **"C++"** no campo de *cadeia literal* . Todos os arquivos de inclusão padrão usam a sintaxe ** :::no-loc(extern)::: "C"** para permitir que as funções de biblioteca de tempo de execução sejam usadas em programas C++.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar nomes que têm vínculo C:

```cpp
// Declare printf with C linkage.
:::no-loc(extern)::: "C" int printf(:::no-loc(const)::: char *fmt, ...);

//  Cause everything in the specified
//  header files to have C linkage.
:::no-loc(extern)::: "C" {
    // add your #include statements here
#include <stdio.h>
}

//  Declare the two functions ShowChar
//  and GetChar with C linkage.
:::no-loc(extern)::: "C" {
    char ShowChar(char ch);
    char GetChar(void);
}

//  Define the two functions
//  ShowChar and GetChar with C linkage.
:::no-loc(extern)::: "C" char ShowChar(char ch) {
    putchar(ch);
    return ch;
}

:::no-loc(extern)::: "C" char GetChar(void) {
    char ch;
    ch = getchar();
    return ch;
}

// Declare a global variable, errno, with C linkage.
:::no-loc(extern)::: "C" int errno;
```

Se uma função tiver mais de uma especificação de vinculação, ela deverá concordar. É um erro declarar funções como tendo vínculos C e C++. Além disso, se duas declarações para uma função ocorrem em um programa — uma com uma especificação de vinculação e a outra sem — a declaração com a especificação de vinculação deve ser a primeira. Todas as declarações redundantes de funções que já têm a especificação de vinculação são atribuídas a uma vinculação especificada na primeira declaração. Por exemplo:

```cpp
:::no-loc(extern)::: "C" int CFunc1();
...
int CFunc1();            // Redeclaration is benign; C linkage is
                         //  retained.

int CFunc2();
...
:::no-loc(extern)::: "C" int CFunc2(); // Error: not the first declaration of
                         //  CFunc2;  cannot contain linkage
                         //  specifier.
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)\
[Unidades de tradução e vinculação](program-and-linkage-cpp.md)\
[:::no-loc(extern):::Especificador de classe de armazenamento em C](../c-language/:::no-loc(extern):::-storage-class-specifier.md)\
[Comportamento de identificadores em C](../c-language/behavior-of-identifiers.md)\
[Ligação em C](../c-language/linkage.md)
