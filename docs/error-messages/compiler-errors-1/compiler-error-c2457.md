---
title: Erro do compilador C2457
ms.date: 11/04/2016
f1_keywords:
- C2457
helpviewer_keywords:
- C2457
ms.assetid: 347e169d-23ad-434f-8836-5b09b53980ff
ms.openlocfilehash: 40e666b1f2b566ca6309ee7759452647f8101a38
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205238"
---
# <a name="compiler-error-c2457"></a>Erro do compilador C2457

> '*macro*': macro predefinida não pode aparecer fora de um corpo de função

Você tentou usar uma macro predefinida, [ &#95; &#95;&#95;](../../preprocessor/predefined-macros.md)como a função, em um espaço global.

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
