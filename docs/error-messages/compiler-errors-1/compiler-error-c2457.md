---
title: Erro do compilador C2457
ms.date: 11/04/2016
f1_keywords:
- C2457
helpviewer_keywords:
- C2457
ms.assetid: 347e169d-23ad-434f-8836-5b09b53980ff
ms.openlocfilehash: a08ac9f9cfbc332b90ad16c663349ee227427278
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50446625"
---
# <a name="compiler-error-c2457"></a>Erro do compilador C2457

> '*macro*': macro pré-definida não pode aparecer fora do corpo de uma função

Você tentou usar uma macro predefinida, como [ &#95; &#95;função&#95;&#95;](../../preprocessor/predefined-macros.md), em um espaço global.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2457 e também mostra o uso correto:

```cpp
// C2457.cpp
#include <stdio.h>

__FUNCTION__;   // C2457, cannot be global

int main()
{
    printf_s("\n%s", __FUNCTION__);   // OK
}
```