---
title: Compilador aviso (nível 3) C4823 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4823
dev_langs:
- C++
helpviewer_keywords:
- C4823
ms.assetid: 8a77560d-dcea-4cae-aebb-8ebf1b4cef85
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c3a6f24a32267f221dbc37e242bae48c0056af5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044646"
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
