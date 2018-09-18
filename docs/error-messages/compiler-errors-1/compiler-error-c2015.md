---
title: Erro do compilador C2015 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2015
dev_langs:
- C++
helpviewer_keywords:
- C2015
ms.assetid: 8f40af0a-3a5a-4d6a-8ed7-125966e6bfed
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5fb9c3ba86224906f749088b96e5daae364d99e2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076041"
---
# <a name="compiler-error-c2015"></a>Erro do compilador C2015

número excessivo de caracteres na constante

Uma constante de caractere contém mais de dois caracteres. O limite é um caractere para constantes de caractere padrão e dois caracteres para constantes de caracteres longa.

Uma sequência de escape, como \t, é convertida em um único caractere.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2015:

```
// C2015.cpp
// compile with: /c

char test1 = 'error';   // C2015
char test2 = 'e';   // OK
```

## <a name="example"></a>Exemplo

C2015 também podem ocorrer ao usar uma extensão da Microsoft, constantes de caractere convertidas em inteiros.  O exemplo a seguir gera C2015:

```
// C2015b.cpp
#include <stdio.h>

int main()
{
    int a = 'abcde';   // C2015

    int b = 'a';   // 'a' = ascii 0x61
    printf_s("%x\n", b);
}
```