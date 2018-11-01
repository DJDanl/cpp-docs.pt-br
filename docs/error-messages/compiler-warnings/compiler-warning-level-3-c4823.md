---
title: Compilador aviso (nível 3) C4823
ms.date: 11/04/2016
f1_keywords:
- C4823
helpviewer_keywords:
- C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
ms.openlocfilehash: 28d490c341c4d14c2e6c03e13007b5a8be423622
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625895"
---
# <a name="compiler-warning-level-3-c4823"></a>Compilador aviso (nível 3) C4823

'function': usa ponteiros de fixação de desenrolamento, mas semântica não está habilitada. Considere o uso de /EHa

Para Desafixar um objeto no heap gerenciado apontado por um ponteiro de fixação declarado em um escopo de bloco, o compilador simula o comportamento de destruidores de classes locais, "fingindo", que o ponteiro de fixação tem um destruidor que anula o ponteiro. Para habilitar uma chamada para um destruidor depois de gerar uma exceção, você deve habilitar liberação de objeto, que pode ser feito por meio [/EHsc](../../build/reference/eh-exception-handling-model.md).

Manualmente, você pode desafixar o objeto e ignorar o aviso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4823.

```
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
