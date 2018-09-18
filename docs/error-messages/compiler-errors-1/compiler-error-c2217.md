---
title: Erro do compilador C2217 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2217
dev_langs:
- C++
helpviewer_keywords:
- C2217
ms.assetid: 1ce1e3f5-4171-4376-804d-967f7e612935
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a4eb8b9fcaffa30f3a5ced5362a0f9d54a45f07e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050613"
---
# <a name="compiler-error-c2217"></a>Erro do compilador C2217

'attribute1' requer 'attribute2'

O primeiro atributo de função requer o segundo atributo.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Interrupção (`__interrupt`) função declarada como `near`. Interrupção funções devem ser `far`.

1. Interromper a função declarada com `__stdcall`, ou `__fastcall`. Funções de interrupção deve usar C convenções de chamada.

## <a name="example"></a>Exemplo

C2217 também pode ocorrer se você tentar associar um delegado a uma função CLR que usa um número variável de argumentos. Se a função também tem a sobrecarga de matriz e parâmetro, use-a. O exemplo a seguir gera C2217.

```
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