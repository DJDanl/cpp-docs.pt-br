---
title: Aviso do compilador (nível 3) C4823
ms.date: 11/04/2016
f1_keywords:
- C4823
helpviewer_keywords:
- C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
ms.openlocfilehash: a96877252b0b7699f5e4033f8e695f4d9016a6c9
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541263"
---
# <a name="compiler-warning-level-3-c4823"></a>Aviso do compilador (nível 3) C4823

' function ': usa ponteiros de fixação, mas semântica de liberação não está habilitada. Considere o uso de/EHa

Para Desafixar um objeto na heap gerenciada apontada por um ponteiro de fixação declarado em um escopo de bloco, o compilador simula o comportamento de destruidores de classes locais, "fingindo" o ponteiro de fixação tem um destruidor que invalidará o ponteiro. Para habilitar uma chamada para um destruidor depois de lançar uma exceção, você deve habilitar o desenrolamento de objeto, o que pode ser feito usando [/EHsc](../../build/reference/eh-exception-handling-model.md).

Você também pode desafixar manualmente o objeto e ignorar o aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4823.

```cpp
// C4823.cpp
// compile with: /clr /W3 /EHa-
using namespace System;

ref struct G {
   int m;
};

void f(G ^ pG) {
   try {
      pin_ptr<int> p = &pG->m;
      // manually unpin, ignore warning
      // p = nullptr;
      throw gcnew Exception;
   }
   catch(Exception ^) {}
}   // C4823 warning

int main() {
   f( gcnew G );
}
```
