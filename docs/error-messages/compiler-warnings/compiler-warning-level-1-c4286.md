---
title: Compilador aviso (nível 1) C4286
ms.date: 11/04/2016
f1_keywords:
- C4286
helpviewer_keywords:
- C4286
ms.assetid: 93eadd6c-6f36-413b-ba91-c9aa2314685a
ms.openlocfilehash: be02d330678eaab7f538ed092641f957bdcb01b2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50455205"
---
# <a name="compiler-warning-level-1-c4286"></a>Compilador aviso (nível 1) C4286

'type1': é capturado pela classe base ('type2') no número de linha

O tipo de exceção especificado é tratado por um manipulador anterior. O tipo para o segundo problema é derivado do tipo do primeiro. Exceções para uma classe base capturam exceções para uma classe derivada.

## <a name="example"></a>Exemplo

```
//C4286.cpp
// compile with: /W1
#include <eh.h>
class C {};
class D : public  C {};
int main()
{
    try
    {
        throw "ooops!";
    }
    catch( C ) {}
    catch( D ) {}  // warning C4286, D is derived from C
}
```