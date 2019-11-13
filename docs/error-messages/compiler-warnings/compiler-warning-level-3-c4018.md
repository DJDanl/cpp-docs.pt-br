---
title: Aviso do compilador (nível 3) C4018
ms.date: 11/04/2016
f1_keywords:
- C4018
helpviewer_keywords:
- C4018
ms.assetid: 6e8cbb04-d914-4319-b431-cbc2fbe40eb1
ms.openlocfilehash: e136a82f8a0ecb3f5375d3a486dd017df7edb6e0
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051978"
---
# <a name="compiler-warning-level-3-c4018"></a>Aviso do compilador (nível 3) C4018

' Expression ': incompatibilidade de assinado/não assinado

A comparação de um número assinado e não assinado exigia que o compilador converta o valor assinado para não assinado.

Esse aviso pode ser corrigido se você converter um dos dois tipos durante o teste de tipos assinados e não assinados.

O exemplo a seguir gera C4018:

```cpp
// C4018.cpp
// compile with: /W3
int main() {
   unsigned int uc = 0;
   int c = 0;
   unsigned int c2 = 0;

   if (uc < c) uc = 0;   // C4018

   // OK
   if (uc == c2) uc = 0;
}
```