---
title: Erro do compilador C2015
ms.date: 11/04/2016
f1_keywords:
- C2015
helpviewer_keywords:
- C2015
ms.assetid: 8f40af0a-3a5a-4d6a-8ed7-125966e6bfed
ms.openlocfilehash: d761dfde26cce9c99ccd4c3e6fd86ae1d6e16ddc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62351086"
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