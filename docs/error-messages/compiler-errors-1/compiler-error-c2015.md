---
title: Erro do compilador C2015
ms.date: 11/04/2016
f1_keywords:
- C2015
helpviewer_keywords:
- C2015
ms.assetid: 8f40af0a-3a5a-4d6a-8ed7-125966e6bfed
ms.openlocfilehash: 5453009e1c2bd091ed3507f3c43bd7fcecd33abc
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743094"
---
# <a name="compiler-error-c2015"></a>Erro do compilador C2015

muitos caracteres na constante

Uma constante de caractere contém mais de dois caracteres. O limite é um caractere para constantes de caractere padrão e dois caracteres para constantes de caractere longo.

Uma sequência de escape, como \t, é convertida em um único caractere.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2015:

```cpp
// C2015.cpp
// compile with: /c

char test1 = 'error';   // C2015
char test2 = 'e';   // OK
```

C2015 também pode ocorrer ao usar uma extensão da Microsoft, constantes de caractere convertidas em inteiros.  O exemplo a seguir gera C2015:

```cpp
// C2015b.cpp
#include <stdio.h>

int main()
{
    int a = 'abcde';   // C2015

    int b = 'a';   // 'a' = ascii 0x61
    printf_s("%x\n", b);
}
```
