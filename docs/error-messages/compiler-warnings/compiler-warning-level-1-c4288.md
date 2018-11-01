---
title: Compilador aviso (nível 1) C4288
ms.date: 11/04/2016
f1_keywords:
- C4288
helpviewer_keywords:
- C4288
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
ms.openlocfilehash: d8769f5663ca0bde9048e52d4579012dfccab0a1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532022"
---
# <a name="compiler-warning-level-1-c4288"></a>Compilador aviso (nível 1) C4288

extensão não padrão usada: 'var': variável de controle de loop declarada no loop for é usada fora do escopo de loop for; ela está em conflito com a declaração no escopo externo

Ao compilar com [/Ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc:forscope-**, uma variável declarada em um **para** loop foi usado após o [para](../../cpp/for-statement-cpp.md)-escopo de loop. Uma extensão da Microsoft para a linguagem C++ permite que essa variável permanece no escopo e C4288 lembra você de que a primeira declaração da variável não é usada.

Ver [/ZC: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar a extensão da Microsoft no **para** loops com /ze.

O exemplo a seguir gera C4288:

```
// C4288.cpp
// compile with: /W1 /c /Zc:forScope-
int main() {
   int i = 0;    // not used in this program
   for (int i = 0 ; ; ) ;
   i++;   // C4288 using for-loop declaration of i
}
```