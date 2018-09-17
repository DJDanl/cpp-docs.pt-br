---
title: Valores de retorno (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 53583524-b337-4228-a9c6-c9bf516babe8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 673853417ad3dd5f08171ea2d5b55df5440705ad
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45714630"
---
# <a name="return-values-c"></a>Valores de retorno (C++)

Um valor de retorno escalar que pode caber em 64 bits é retornado com o RAX — isso inclui os tipos __m64. Tipos não escalares incluindo floats, doubles e tipos de vetor, como [__m128](../cpp/m128.md), [__m128i](../cpp/m128i.md), [__m128d](../cpp/m128d.md) são retornados em XMM0. O estado de bits não usados no valor retornado em RAX ou XMM0 é indefinido.

Tipos definidos pelo usuário podem ser retornados pelo valor de funções globais e funções de membro estático. A ser retornado pelo valor em RAX, tipos definidos pelo usuário devem ter um comprimento de 1, 2, 4, 8, 16, 32 ou 64 bits; Nenhum construtor definido pelo usuário, o destruidor ou o operador de atribuição de cópia; Nenhum membro de dados de não estático particular ou protegido; Nenhum membro de dados não estáticos do tipo de referência; Nenhuma classe base; Nenhuma função virtual; e nenhum membro de dados que também não atender a esses requisitos. (Isso é, essencialmente, a definição de um c++03 tipo POD. Como a definição foi alterada no c++11 standard, nós não recomendamos o uso `std::is_pod` para este teste.) Caso contrário, o chamador assume a responsabilidade de alocação de memória e passar um ponteiro para o valor retornado como o primeiro argumento. Os argumentos subsequentes são, em seguida, deslocado um argumento para a direita. O mesmo ponteiro deve ser retornado pelo receptor em RAX.

Estes exemplos mostram como parâmetros e valores de retorno são passadas para funções com as declarações especificadas:

## <a name="example-of-return-value-1---64-bit-result"></a>Exemplo de resultado de 1 a 64 bits do valor de retorno

```Output
__int64 func1(int a, float b, int c, int d, int e);
// Caller passes a in RCX, b in XMM1, c in R8, d in R9, e pushed on stack,
// callee returns __int64 result in RAX.
```

## <a name="example-of-return-value-2---128-bit-result"></a>Exemplo de resultado de 2 de 128 bits do valor de retorno

```Output
__m128 func2(float a, double b, int c, __m64 d);
// Caller passes a in XMM0, b in XMM1, c in R8, d in R9,
// callee returns __m128 result in XMM0.
```

## <a name="example-of-return-value-3---user-type-result-by-pointer"></a>Exemplo de valor de retorno 3 – resultado de tipo de usuário pelo ponteiro

```Output
struct Struct1 {
   int j, k, l;    // Struct1 exceeds 64 bits.
};
Struct1 func3(int a, double b, int c, float d);
// Caller allocates memory for Struct1 returned and passes pointer in RCX,
// a in RDX, b in XMM2, c in R9, d pushed on the stack;
// callee returns pointer to Struct1 result in RAX.
```

## <a name="example-of-return-value-4---user-type-result-by-value"></a>Exemplo de valor de retorno 4 – resultado de tipo de usuário por valor

```Output
struct Struct2 {
   int j, k;    // Struct2 fits in 64 bits, and meets requirements for return by value.
};
Struct2 func4(int a, double b, int c, float d);
// Caller passes a in RCX, b in XMM1, c in R8, and d in XMM3;
// callee returns Struct2 result by value in RAX.
```

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)