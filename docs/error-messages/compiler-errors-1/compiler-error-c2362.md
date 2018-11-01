---
title: Erro do compilador C2362
ms.date: 11/04/2016
f1_keywords:
- C2362
helpviewer_keywords:
- C2362
ms.assetid: 7aafecbc-b3cf-45a6-9ec3-a17e3f222511
ms.openlocfilehash: 17656b2a48a3680a9269d3ca300fd4188eda6b84
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661104"
---
# <a name="compiler-error-c2362"></a>Erro do compilador C2362

inicialização de 'identifier' é ignorada por 'goto rótulo'

Ao compilar com [/Za](../../build/reference/za-ze-disable-language-extensions.md), saltar para o rótulo impede que o identificador que está sendo inicializado.

Não é possível saltar após uma declaração com um inicializador, a menos que a declaração é incluída em um bloco que não é inserido, ou a variável já foi inicializada.

O exemplo a seguir gera C2326:

```
// C2362.cpp
// compile with: /Za
int main() {
   goto label1;
   int i = 1;      // C2362, initialization skipped
label1:;
}
```

Solução possível:

```
// C2362b.cpp
// compile with: /Za
int main() {
   goto label1;
   {
      int j = 1;   // OK, this block is never entered
   }
label1:;
}
```