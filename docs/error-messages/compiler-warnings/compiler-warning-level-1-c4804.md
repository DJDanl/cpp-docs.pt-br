---
title: Aviso do compilador (nível 1) C4804
ms.date: 11/04/2016
f1_keywords:
- C4804
helpviewer_keywords:
- C4804
ms.assetid: 069e8f44-3ef6-43bb-8524-4116fc6eea83
ms.openlocfilehash: 3f1b349599c77bc001911431fe0d83496ca3dfce
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199401"
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
