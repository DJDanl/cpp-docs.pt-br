---
title: Aviso C4730 (compilador) (nível 1)
ms.date: 11/04/2016
f1_keywords:
- C4730
helpviewer_keywords:
- C4730
ms.assetid: 11303e3f-162b-4b19-970a-479686123a68
ms.openlocfilehash: 4da60194deaeac3c79f8c3e9be3bd87d91bc7ca2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386350"
---
# <a name="compiler-warning-level-1-c4730"></a>Aviso C4730 (compilador) (nível 1)

'principal': misturar _m64 e expressões podem resultar em um código incorreto de ponto flutuante

Uma função usa [__m64](../../cpp/m64.md) e **float**/**double** tipos. Espaço de registro como o MMX e os registros de ponto flutuante compartilham o mesmo físico (não podem ser usados simultaneamente), usando `__m64` e **float**/**double** tipos no mesmo função pode resultar em corrupção de dados, possivelmente causando uma exceção.

Para usar com segurança `__m64` tipos e tipos de ponto flutuante na mesma função, cada instrução que usa um dos tipos deve ser separada pela **_m_empty()** (para MMX) ou **_m_femms()** (para 3DNow!) intrínseco.

O exemplo a seguir gera C4730:

```
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