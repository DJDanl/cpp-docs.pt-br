---
title: Aviso do compilador (nível 1) C4804
ms.date: 11/04/2016
f1_keywords:
- C4804
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
ms.openlocfilehash: 97ad076325b11329896d98367fb3ac311ec5ded9
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051565"
---
# <a name="compiler-warning-level-1-c4804"></a>Aviso do compilador (nível 1) C4804

' Operation ': uso não seguro do tipo ' bool ' na operação

Esse aviso é para quando você usou uma variável ou valor de `bool` de forma inesperada. Por exemplo, C4804 será gerado se você usar operadores como o operador unário negativo ( **-** ) ou o operador de complemento (`~`). O compilador avalia a expressão.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4804:

```cpp
// C4804.cpp
// compile with: /W1

int main()
{
   bool i = true;
   if (-i)   // C4804, remove the '-' to resolve
   {
      i = false;
   }
}
```