---
title: Aviso do compilador (nível 4) C4212
ms.date: 11/04/2016
f1_keywords:
- C4212
helpviewer_keywords:
- C4212
ms.assetid: df781ea1-182d-4f9f-9a31-55b6ce80c711
ms.openlocfilehash: 99dd99eee3c305a53c5ea03235d23a2520768176
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541821"
---
# <a name="compiler-warning-level-4-c4212"></a>Aviso do compilador (nível 4) C4212

extensão não padrão usada: a declaração de função usou reticências

O protótipo de função tem um número variável de argumentos. A definição da função não.

O exemplo a seguir gera C4212:

```c
// C4212.c
// compile with: /W4 /Ze /c
void f(int , ...);
void f(int i, int j) {}
```