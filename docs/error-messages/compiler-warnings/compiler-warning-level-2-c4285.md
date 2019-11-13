---
title: Aviso do compilador (nível 2) C4285
ms.date: 11/04/2016
f1_keywords:
- C4285
helpviewer_keywords:
- C4285
ms.assetid: fa14de1f-fc19-4eec-8bea-81003636e12f
ms.openlocfilehash: 326b73dcf4665c442926e68995bace60300b6ebf
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052098"
---
# <a name="compiler-warning-level-2-c4285"></a>Aviso do compilador (nível 2) C4285

o tipo de retorno para ' Identifier:: operator-> ' é recursivo se aplicado usando a notação de infixo

A função **Operator-> ()** especificada não pode retornar o tipo para o qual está definida ou uma referência ao tipo para o qual está definida.

O exemplo a seguir gera C4285:

```cpp
// C4285.cpp
// compile with: /W2
class C
{
public:
    C operator->();   // C4285
   // C& operator->();  C4285, also
};

int main()
{
}
```