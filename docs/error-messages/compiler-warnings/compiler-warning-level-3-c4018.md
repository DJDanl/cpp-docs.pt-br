---
title: Aviso do compilador (nível 3) C4018
ms.date: 11/04/2016
f1_keywords:
- C4018
helpviewer_keywords:
- C4018
ms.assetid: 6e8cbb04-d914-4319-b431-cbc2fbe40eb1
ms.openlocfilehash: f5708a9f52b6fc8206094454c352710199437f27
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161692"
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
