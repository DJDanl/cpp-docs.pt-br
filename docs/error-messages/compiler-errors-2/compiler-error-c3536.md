---
title: Erro do compilador C3536
ms.date: 11/04/2016
f1_keywords:
- C3536
helpviewer_keywords:
- C3536
ms.assetid: 8d866075-866b-49eb-9979-ee27b308f7e3
ms.openlocfilehash: b58136cc03efda83071c531b25889743de3485f5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456739"
---
# <a name="compiler-error-c3536"></a>Erro do compilador C3536

'symbol': não pode ser usado antes de ser inicializado

O símbolo indicado não pode ser usado antes de ser inicializado. Na prática, isso significa que uma variável não pode ser usada para se inicializar.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não inicialize uma variável com ele próprio.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3536 porque cada variável é inicializada com ele próprio.

```
// C3536.cpp
// Compile with /Zc:auto
int main()
{
   auto a = a;     //C3536
   auto b = &b;    //C3536
   auto c = c + 1; //C3536
   auto* d = &d;   //C3536
   auto& e = e;    //C3536
   return 0;
};
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)