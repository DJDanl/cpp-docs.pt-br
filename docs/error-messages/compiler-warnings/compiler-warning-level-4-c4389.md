---
title: Aviso do compilador (nível 4) C4389
description: Aviso do compilador C/C++ da Microsoft C4389, suas causas e resolução.
ms.date: 10/16/2020
f1_keywords:
- c4389
helpviewer_keywords:
- C4389
ms.openlocfilehash: b06b013151ed12b4f66bb23a7e862992d05e6b30
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176269"
---
# <a name="compiler-warning-level-4-c4389"></a>Aviso do compilador (nível 4) C4389

> "*operador de igualdade*": incompatibilidade de assinado/não assinado

Uma **`==`** **`!=`** operação ou envolvida **`signed`** e **`unsigned`** variáveis. Isso pode resultar em perda de dados.

## <a name="remarks"></a>Comentários

Uma maneira de corrigir esse aviso é se você converter um dos dois tipos ao comparar **`signed`** e **`unsigned`** tipos.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4389:

```cpp
// C4389.cpp
// compile with: cl /EHsc /W4 C4389.cpp

int main()
{
   int a = 9;
   unsigned int b = 10;
   int result = 0;

   if (a == b)   // C4389
      result = 1;
   else
      result = 2;

   if (unsigned(a) == b) // OK
      result = 3;
   else
      result = 4;

   return result;
}
```

## <a name="see-also"></a>Confira também

[Aviso do compilador C4018](compiler-warning-level-3-c4018.md)\
[Aviso do compilador (nível 4) C4388](c4388.md)
