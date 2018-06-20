---
title: externo (C++) | Microsoft Docs
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 00b9f94d02443163f45b83d64702fe49622597cd
ms.sourcegitcommit: d06966efce25c0e66286c8047726ffe743ea6be0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/19/2018
ms.locfileid: "36261039"
---
# <a name="extern-c"></a>externo (C++)

O **extern** palavra-chave é aplicado a uma declaração de variável, função ou modelo global para especificar que o nome do item tem *vinculação externa*. Para obter informações sobre vinculação e por que não é recomendado o uso de variáveis globais, consulte [programa e ligação](program-and-linkage-cpp.md).

O **extern** palavra-chave tem quatro significados, dependendo do contexto:

1. em uma declaração de variável global do não const, **extern** Especifica que a variável ou função está definida em outra unidade de tradução. O **extern** devem ser aplicadas em todos os arquivos exceto aquele em que a variável é definida.
1. em uma declaração de variável const, especifica que a variável tiver vinculação externa. O **extern** devem ser aplicadas a todas as declarações em todos os arquivos. (As variáveis globais constantes tem vinculação interna por padrão.)
1. **extern "C"** Especifica que a função está definida em outro lugar e usa a convenção de chamada de linguagem C. O modificador de extern "C" também pode ser aplicado a várias declarações de função em um bloco.
1. em uma declaração de modelo, especifica que o modelo já foi instanciado em outro lugar. Essa é uma otimização que informa ao compilador que ele pode usar novamente a outros instanciação em vez de criar um novo no local atual. Para obter mais informações sobre esse uso do **extern**, consulte [modelos](templates-cpp.md).

## <a name="extern-linkage-for-non-const-globals"></a>vinculação externa para globais não constante

Quando o vinculador vê **extern** antes de uma declaração de variável global, ele procura a definição em outra unidade de tradução. Declarações de variáveis não constante no escopo global são externas por padrão. se aplicam somente **extern** as declarações que não fornecem a definição.

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

## <a name="extern-linkage-for-const-globals"></a>vinculação externa para globals const

Um **const** variável global tem vinculação interna por padrão. Se você desejar que a variável com ligação externa, aplique o **extern** palavra-chave para definição, bem como para todas as outras declarações em outros arquivos:

```cpp
//fileA.cpp
extern const int i = 42; // extern const definition

//fileB.cpp
extern const int i;  // declaration only. same as i in FileA
```

## <a name="extern-constexpr-linkage"></a>Vinculação de constexpr extern

No Visual Studio 2017 versão 15,3 e anteriores, o compilador sempre forneceu uma vinculação de interna de variável constexpr mesmo quando a variável foi marcado como externo. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, ([/Zc:externConstexpr](../build/reference/zc-externconstexpr.md)), habilita o comportamento correto em conformidade com os padrões. Eventualmente, isso se tornará o padrão.

```cpp
extern constexpr int x = 10; //error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contém um constexpr variável extern declarado, ele precisa ser marcado como **__declspec(selectany)** para ter corretamente suas declarações duplicadas combinadas:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

## <a name="extern-c-and-extern-c-function-declarations"></a>extern "C" e extern "C++" declarações de função

 No C++, quando usada com uma cadeia de caracteres, **extern** Especifica que as convenções de vinculação de outro idioma estão sendo usadas para o declarator(s). As funções C e os dados podem ser acessados somente se forem declarados anteriormente como tendo vinculação C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.

 Microsoft C++ oferece suporte as cadeias de caracteres **"C"** e **"C++"** no *literal de cadeia de caracteres* campo. Todas as do padrão incluem o uso de arquivos de **extern** sintaxe "C" para permitir que as funções de biblioteca de tempo de execução a ser usado em programas C++.

## <a name="example"></a>Exemplo

O exemplo a seguir mostra como declarar nomes com vínculo a C:

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

- [Palavras-chave](../cpp/keywords-cpp.md)
- [Programa e ligação](program-and-linkage-cpp.md)
- [extern especificador de classe de armazenamento em C](../c-language/extern-storage-class-specifier.md) 
- [Comportamento de identificadores em C](../c-language/behavior-of-identifiers.md) 
- [Ligação em C](../c-language/linkage.md)