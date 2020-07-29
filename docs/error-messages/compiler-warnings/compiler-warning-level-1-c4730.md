---
title: Aviso C4730 (compilador) (nível 1)
ms.date: 11/04/2016
f1_keywords:
- C4730
helpviewer_keywords:
- C4730
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
ms.openlocfilehash: a132dcc795d6055c854a5ad147940868fe4e088b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228772"
---
# <a name="compiler-warning-level-1-c4730"></a>Aviso C4730 (compilador) (nível 1)

' Main ': misturar _m64 e expressões de ponto flutuante podem resultar em código incorreto

Uma função usa [__m64](../../cpp/m64.md) e **`float`** / **`double`** tipos. Como os registros de ponto flutuante e MMX compartilham o mesmo espaço físico de registro (não podem ser usados simultaneamente), o uso de **`__m64`** **`float`** / **`double`** tipos e na mesma função pode resultar em dados corrompidos, possivelmente causando uma exceção.

Para usar **`__m64`** tipos e tipos de ponto flutuante na mesma função com segurança, cada instrução que usa um dos tipos deve ser separada pelo **_m_empty ()** (para o MMX) ou **_m_femms ()** (para 3DNow!) intrínseco.

O exemplo a seguir gera C4730:

```cpp
// C4730.cpp
// compile with: /W1
// processor: x86
#include "mmintrin.h"

void func(double)
{
}

int main(__m64 a, __m64 b)
{
   __m64 m;
   double f;
   f = 1.0;
   m = _m_paddb(a, b);
   // uncomment the next line to resolve C4730
   // _m_empty();
   func(f * 3.0);   // C4730
}
```
