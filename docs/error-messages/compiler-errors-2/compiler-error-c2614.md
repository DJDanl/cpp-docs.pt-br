---
title: Erro do compilador C2614
ms.date: 11/04/2016
f1_keywords:
- C2614
helpviewer_keywords:
- C2614
ms.assetid: a550c1d5-8718-4e17-a888-b2619e00fe11
ms.openlocfilehash: 71f0fe3211ce253bcf30347658692651e84ab608
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463590"
---
# <a name="compiler-error-c2614"></a>Erro do compilador C2614

'class1': inicialização de membro inválida: 'class2' não é uma base ou membro

Somente o membro ou classes base podem aparecer na lista de inicialização para uma classe ou estrutura.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2614.

```
// C2614.cpp
// compile with: /c
struct A {
   int i;
   A( int ia ) : B( i ) {};   // C2614 B is not a member of A
};

struct A2 {
   int B;
   int i;
   A2( int ia ) : B( i ) {};   // OK
};
```