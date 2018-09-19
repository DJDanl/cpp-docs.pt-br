---
title: extern (C++) | Microsoft Docs
ms.custom: ''
ms.date: 04/12/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- extern
- extern_CPP
dev_langs:
- C++
helpviewer_keywords:
- extern keyword [C++], linkage to non-C++ functions
- declarations, external
- external linkage, extern modifier
ms.assetid: 1e2f0ae3-ae98-4410-85b5-222d6abc865a
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7b090875b9656fec52e50cb68caf9c2c047d055b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114248"
---
# <a name="extern-c"></a>extern (C++)

O **extern** palavra-chave é aplicado a uma declaração de variável, função ou o modelo global para especificar que o nome daquilo que tenha *vinculação externa*. Para obter informações sobre vinculação e por que não é recomendado o uso de variáveis globais, consulte [programa e ligação](program-and-linkage-cpp.md).

O **extern** palavra-chave tem quatro significados, dependendo do contexto:

1. em uma declaração de variável global do não const, **extern** Especifica que a variável ou função é definida em outra unidade de tradução. O **extern** deve ser aplicado em todos os arquivos, exceto aquele em que a variável é definida.
1. em uma declaração de variável const, ele especifica que a variável tem vinculação externa. O **extern** deve ser aplicado a todas as declarações em todos os arquivos. (Variáveis constantes globais têm vinculação interna por padrão.)
1. **extern "C"** Especifica que a função é definida em outro lugar e usa a convenção de chamada de linguagem C. Modificador "C" externo também pode ser aplicado a várias declarações de função em um bloco.
1. em uma declaração de modelo, ela especifica que o modelo já tenha sido instanciado em outro lugar. Essa é uma otimização que informa ao compilador que ele pode reutilizar a outra instanciação em vez de criar um novo no local atual. Para obter mais informações sobre esse uso de **extern**, consulte [modelos](templates-cpp.md).

## <a name="extern-linkage-for-non-const-globals"></a>vinculação extern para globals não const

Quando o vinculador vê **extern** antes de uma declaração de variável global, ele procura a definição em outra unidade de tradução. As declarações de variáveis não const em escopo global são externas por padrão. só se aplicam **extern** às declarações que não fornecem a definição.

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

## <a name="extern-linkage-for-const-globals"></a>vinculação extern para globals const

Um **const** variável global tem vinculação interna, por padrão. Se você quiser que a variável para ter vinculação externa, aplicar a **extern** palavra-chave para definição, bem como para todas as outras declarações em outros arquivos:

```cpp
//fileA.cpp
extern const int i = 42; // extern const definition

//fileB.cpp
extern const int i;  // declaration only. same as i in FileA
```

## <a name="extern-constexpr-linkage"></a>vinculação de contexpr externo

No Visual Studio 2017 versão 15.3 e versões anteriores, o compilador sempre forneceu uma ligação interna variável de constexpr mesmo quando a variável foi marcado como externo. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, ([/Zc:externConstexpr](../build/reference/zc-externconstexpr.md)), habilita o comportamento correto em conformidade com os padrões. Eventualmente, isso se tornará o padrão.

```cpp
extern constexpr int x = 10; //error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contém um constexpr externo declarado variável, ele deve ser marcada **__declspec(selectany)** para suas declarações duplicadas sejam combinadas corretamente:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

## <a name="extern-c-and-extern-c-function-declarations"></a>declarações de função extern "C" e extern "C++"

No C++, quando usado com uma cadeia de caracteres **extern** Especifica que as convenções de vinculação de outra linguagem estão sendo usadas para os declaradores. As funções C e os dados podem ser acessados somente se forem declarados anteriormente como tendo vinculação C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.

Microsoft C++ suporta as cadeias de caracteres **"C"** e **"C++"** no *literal de cadeia de caracteres* campo. Todas as do padrão incluem o uso de arquivos a **extern** sintaxe "C" para permitir que as funções da biblioteca de tempo de execução a ser usado em programas C++.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar os nomes que têm vinculação C:

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

Se uma função tiver mais de uma especificação de vinculação, elas devem concordar; é errado declarar funções como tendo o vínculos de C e C++. Além disso, se duas declarações para uma função ocorrem em um programa — uma com uma especificação de vinculação e a outra sem — a declaração com a especificação de vinculação deve ser a primeira. Todas as declarações redundantes de funções que já têm a especificação de vinculação são atribuídas a uma vinculação especificada na primeira declaração. Por exemplo:

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

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Programa e ligação](program-and-linkage-cpp.md)<br/>
[Especificador de classe de armazenamento em C externa](../c-language/extern-storage-class-specifier.md)<br/>
[Comportamento de identificadores em C](../c-language/behavior-of-identifiers.md)<br/>
[Ligação em C](../c-language/linkage.md)