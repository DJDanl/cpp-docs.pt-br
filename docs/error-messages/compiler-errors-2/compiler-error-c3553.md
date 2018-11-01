---
title: Erro do compilador C3553
ms.date: 11/04/2016
f1_keywords:
- C3553
helpviewer_keywords:
- C3553
ms.assetid: 7f84bf37-6419-4ad3-ab30-64266100b930
ms.openlocfilehash: 219592f2403904f9923e84bfd4539a22cddd02de
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50543423"
---
# <a name="compiler-error-c3553"></a>Erro do compilador C3553

> decltype espera uma expressão não é um tipo

O `decltype()` palavra-chave requer uma expressão como um argumento, não o nome de um tipo. Por exemplo, a última instrução no fragmento de código a seguir produz o erro C3553.

```cpp
int x = 0;
decltype(x+1);
decltype(int); // C3553
```