---
title: Aviso do compilador (nível 1) C4177
ms.date: 11/04/2016
f1_keywords:
- C4177
helpviewer_keywords:
- C4177
ms.assetid: 2b05a5b3-696e-4f21-818e-227b9335e748
ms.openlocfilehash: 82aae8e5d0be15adef7891b39a6f7e482c729e60
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73625052"
---
# <a name="compiler-warning-level-1-c4177"></a>Aviso do compilador (nível 1) C4177

pragma \#pragma deve estar no escopo global

O [pragma pragma não](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) deve ser usado em um escopo local. O **pragma** não será válido até que o escopo global seja encontrado após o escopo atual.

O exemplo a seguir gera C4177:

```cpp
// C4177.cpp
// compile with: /W1
// #pragma bss_seg("global")   // OK

int main() {
   #pragma bss_seg("local")    // C4177
}
```