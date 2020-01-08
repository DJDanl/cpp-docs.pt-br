---
title: externo (C++)
ms.date: 04/12/2018
f1_keywords:
- extern
- extern_CPP
helpviewer_keywords:
- extern keyword [C++], linkage to non-C++ functions
- declarations, external
- external linkage, extern modifier
ms.assetid: 1e2f0ae3-ae98-4410-85b5-222d6abc865a
ms.openlocfilehash: d42a32202f7fa67751ea36757c13b2c6af4953b2
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301529"
---
# <a name="extern-c"></a>externo (C++)

A palavra-chave **extern** é aplicada a uma variável global, uma função ou uma declaração de modelo para especificar que o nome dessa coisa tem *vínculo externo*. Para obter informações básicas sobre vinculação e por que o uso de variáveis globais não é recomendado, consulte [unidades de tradução e vinculação](program-and-linkage-cpp.md).

A palavra-chave **extern** tem quatro significados dependendo do contexto:

1. em uma declaração de variável global não const, **extern** especifica que a variável ou função é definida em outra unidade de tradução. O **externo** deve ser aplicado em todos os arquivos, exceto aquele em que a variável é definida.
1. em uma declaração de variável const, ela especifica que a variável tem vínculo externo. O **externo** deve ser aplicado a todas as declarações em todos os arquivos. (As variáveis global const têm vínculo interno por padrão.)
1. o **"C" externo** especifica que a função é definida em outro lugar e usa a Convenção de chamada de linguagem C. O modificador "C" externo também pode ser aplicado a várias declarações de função em um bloco.
1. em uma declaração de modelo, ele especifica que o modelo já foi instanciado em outro lugar. Essa é uma otimização que informa ao compilador que ele pode reutilizar a outra instanciação em vez de criar uma nova no local atual. Para obter mais informações sobre esse uso de **externo**, consulte [modelos](templates-cpp.md).

## <a name="extern-linkage-for-non-const-globals"></a>vínculo externo para globais não const

Quando o vinculador vê **externo** antes de uma declaração de variável global, ele procura a definição em outra unidade de tradução. Declarações de variáveis não const em escopo global são externas por padrão; aplica-se somente ao **extern** às declarações que não fornecem a definição.

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

## <a name="extern-linkage-for-const-globals"></a>vínculo externo para const Globals

Uma variável global **const** tem vínculo interno por padrão. Se você quiser que a variável tenha vínculo externo, aplique a palavra-chave **extern** à definição, bem como a todas as outras declarações em outros arquivos:

```cpp
//fileA.cpp
extern const int i = 42; // extern const definition

//fileB.cpp
extern const int i;  // declaration only. same as i in FileA
```

## <a name="extern-constexpr-linkage"></a>vínculo constexpr externo

No Visual Studio 2017 versão 15,3 e anterior, o compilador sempre deu um vínculo interno de variável constexpr mesmo quando a variável foi marcada como externa. No Visual Studio 2017 versão 15.5, uma nova opção de compilador, ([/Zc:externConstexpr](../build/reference/zc-externconstexpr.md)), habilita o comportamento correto em conformidade com os padrões. Eventualmente, isso se tornará o padrão. A opção/permissive-não habilita/Zc: externConstexpr.

```cpp
extern constexpr int x = 10; //error LNK2005: "int const x" already defined
```

Se um arquivo de cabeçalho contiver uma variável declarada como constexpr externa, ele precisará ser marcado como **__declspec (selectany)** para ter corretamente suas declarações duplicadas combinadas:

```cpp
extern constexpr __declspec(selectany) int x = 10;
```

## <a name="extern-c-and-extern-c-function-declarations"></a>declarações de função "C" eC++extern "" extern

No C++, quando usado com uma cadeia de caracteres, **extern** especifica que as convenções de vinculação de outro idioma estão sendo usadas para o declarador (es). As funções C e os dados podem ser acessados somente se forem declarados anteriormente como tendo vinculação C. No entanto, devem ser definidos em uma unidade de conversão compilada separadamente.

A C++ Microsoft dá suporte às cadeias de caracteres **"C"** e **C++""** no campo *String-literal* . Todos os arquivos de inclusão padrão usam a sintaxe "C" **externa** para permitir que as funções de biblioteca de tempo de execução sejam C++ usadas em programas.

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

## <a name="see-also"></a>Veja também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Unidades de tradução e vinculação](program-and-linkage-cpp.md)<br/>
[Especificador de classe de armazenamento externo em C](../c-language/extern-storage-class-specifier.md)<br/>
[Comportamento de identificadores em C](../c-language/behavior-of-identifiers.md)<br/>
[Ligação em C](../c-language/linkage.md)