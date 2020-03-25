---
title: Aviso do compilador (nível 1) C4288
ms.date: 11/04/2016
f1_keywords:
- C4288
helpviewer_keywords:
- C4288
ms.assetid: 6aaeb139-90cd-457a-9d37-65687042736f
ms.openlocfilehash: e706a448f4264eceedbb4fa8932c0fc30e88d532
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175734"
---
# <a name="compiler-warning-level-1-c4288"></a>Aviso do compilador (nível 1) C4288

extensão não padrão usada: ' var ': a variável de controle de loop declarada no loop for é usada fora do escopo de loop for; Ele está em conflito com a declaração no escopo externo

Ao compilar com [/ze](../../build/reference/za-ze-disable-language-extensions.md) e **/Zc: forScope-** , uma variável declarada em um loop **for** é usada após o escopo [do loop for](../../cpp/for-statement-cpp.md). Uma extensão da Microsoft para C++ o idioma permite que essa variável permaneça no escopo e C4288 o lembra de que a primeira declaração da variável não é usada.

Consulte [/Zc: forScope](../../build/reference/zc-forscope-force-conformance-in-for-loop-scope.md) para obter informações sobre como especificar a extensão da Microsoft no **para** loops com/Ze.

O exemplo a seguir gera C4288:

```cpp
// C4288.cpp
// compile with: /W1 /c /Zc:forScope-
int main() {
   int i = 0;    // not used in this program
   for (int i = 0 ; ; ) ;
   i++;   // C4288 using for-loop declaration of i
}
```
