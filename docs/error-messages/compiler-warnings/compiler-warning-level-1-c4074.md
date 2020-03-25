---
title: Aviso do compilador (nível 1) C4074
ms.date: 11/04/2016
f1_keywords:
- C4074
helpviewer_keywords:
- C4074
ms.assetid: cd510e66-c338-4a86-a4d7-bfa1df9b16c3
ms.openlocfilehash: 7a11112962872788df855bfc63b869193188fab9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164073"
---
# <a name="compiler-warning-level-1-c4074"></a>Aviso do compilador (nível 1) C4074

inicializadores colocados na área de inicialização reservada do compilador

A área de inicialização do compilador, que é especificada por [#pragma init_seg](../../preprocessor/init-seg.md), é reservada pela Microsoft. O código nessa área pode ser executado antes da inicialização da biblioteca de tempo de execução do C.

O exemplo a seguir gera C4074:

```cpp
// C4074.cpp
// compile with: /W1
#pragma init_seg( compiler )   // C4074

// try this line to resolve the warning
// #pragma init_seg(user)

int main() {
}
```
