---
title: Aviso do compilador (nível 3) C4390
ms.date: 11/04/2016
f1_keywords:
- C4390
helpviewer_keywords:
- C4390
ms.assetid: c95c2f1b-9bce-4b1f-a80c-565d4cde0b1e
ms.openlocfilehash: 63150f4ca801d3c377c7bc09b58a778bebf02b46
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198673"
---
# <a name="compiler-warning-level-3-c4390"></a>Aviso do compilador (nível 3) C4390

'; ': instrução controlada vazia encontrada; Essa é a intenção?

Um ponto e vírgula foi encontrado após uma instrução de controle que não contém instruções.

Se você receber C4390 devido a uma macro, deverá usar o pragma de [aviso](../../preprocessor/warning.md) para desabilitar o C4390 no módulo que contém a macro.

O exemplo a seguir gera C4390:

```cpp
// C4390.cpp
// compile with: /W3
int main() {
   int i = 0;
   if (i);   // C4390
      i++;
}
```
