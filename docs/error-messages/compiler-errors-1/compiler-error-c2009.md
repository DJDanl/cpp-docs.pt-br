---
title: Erro do compilador c2009
ms.date: 11/04/2016
f1_keywords:
- C2009
helpviewer_keywords:
- C2009
ms.assetid: fe9d94ed-20a5-4d83-b9c4-60ee69d2f30a
ms.openlocfilehash: 02780a88552231472c2e16299a6d5e5dfef1bdd2
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743107"
---
# <a name="compiler-error-c2009"></a>Erro do compilador c2009

reutilização do ' identificador ' formal de macro

A lista de parâmetros formais de uma definição de macro usa o identificador mais de uma vez. Os identificadores na lista de parâmetros da macro devem ser exclusivos.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera c2009:

```cpp
// C2009.cpp
#include <stdio.h>

#define macro1(a,a) (a*a)   // C2009

int main()
{
    printf_s("%d\n", macro1(2));
}
```

Resolução possível:

```cpp
// C2009b.cpp
#include <stdio.h>

#define macro2(a)   (a*a)
#define macro3(a,b) (a*b)

int main()
{
    printf_s("%d\n", macro2(2));
    printf_s("%d\n", macro3(2,4));
}
```
