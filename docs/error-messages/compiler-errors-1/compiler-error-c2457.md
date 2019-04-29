---
title: Erro do compilador C2457
ms.date: 11/04/2016
f1_keywords:
- C2457
helpviewer_keywords:
- C2457
ms.assetid: 347e169d-23ad-434f-8836-5b09b53980ff
ms.openlocfilehash: a08ac9f9cfbc332b90ad16c663349ee227427278
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62347097"
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