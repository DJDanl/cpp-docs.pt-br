---
title: Erro do compilador C2217
ms.date: 11/04/2016
f1_keywords:
- C2217
helpviewer_keywords:
- C2217
ms.assetid: 1ce1e3f5-4171-4376-804d-967f7e612935
ms.openlocfilehash: 7417c651fde6bef781bb6eb2e081cd3ad8ecc3a0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74741294"
---
# <a name="compiler-error-c2217"></a>Erro do compilador C2217

' attribute1 ' requer ' attribute2 '

O primeiro atributo de função requer o segundo atributo.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Função Interrupt (`__interrupt`) declarada como `near`. As funções de interrupção devem ser `far`.

1. Função de interrupção declarada com `__stdcall`ou `__fastcall`. As funções de interrupção devem usar as convenções de chamada C.

## <a name="example"></a>Exemplo

C2217 também pode ocorrer se você tentar associar um delegado a uma função CLR que usa um número variável de argumentos. Se a função também tiver sobrecarga de matriz de parâmetro e, use-a em vez disso. O exemplo a seguir gera C2217.

```cpp
// C2217.cpp
// compile with: /clr
using namespace System;
delegate void MyDel(String^, Object^, Object^, ...);   // C2217
delegate void MyDel2(String ^, array<Object ^> ^);   // OK

int main() {
   MyDel2^ wl = gcnew MyDel2(Console::WriteLine);
   array<Object ^ > ^ x = gcnew array<Object ^>(2);
   x[0] = safe_cast<Object^>(0);
   x[1] = safe_cast<Object^>(1);

   // wl("{0}, {1}", 0, 1);
   wl("{0}, {1}", x);
}
```
