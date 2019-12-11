---
title: Aviso do compilador (nível 4) C4460
ms.date: 11/04/2016
f1_keywords:
- C4460
helpviewer_keywords:
- C4460
ms.assetid: c97ac1c9-598d-479e-bfff-c993690c4f3d
ms.openlocfilehash: 1b4ec02211dc346c1672b403bf8af16dc6fca461
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990801"
---
# <a name="compiler-warning-level-4-c4460"></a>Aviso do compilador (nível 4) C4460

O operador ' operator ' do WinRT ou do CLR tem um parâmetro passado por referência. O operador ' operator ' do WinRT ou do CLR tem uma C++ semântica diferente do operador ' operator ', você pretendia passar por valor?

Você passou um valor por referência a um operador de Windows Runtime ou CLR definido pelo usuário. Se o valor for alterado dentro da função, observe que o valor retornado após a chamada de função será atribuído ao valor de retorno da função. No padrão C++, o valor alterado é refletido após a chamada de função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4460 e mostra como corrigi-lo.

```cpp
// C4460.cpp
// compile with: /W4 /clr
#include <stdio.h>

public value struct V {
   static V operator ++(V& me) {   // C4460
   // try the following line instead
   // static V operator ++(V me) {

      printf_s(__FUNCSIG__ " called\n");
      V tmp = me;
      me.m_i++;
      return tmp;
   }
   int m_i;
};

int main() {
   V v;
   v.m_i = 0;

   printf_s("%d\n", v.m_i);   // Should print 0
   v++;   // Translates to "v = V::operator ++(v)"
   printf_s("%d\n", v.m_i);   // will print 0, hence the warning
}
```
