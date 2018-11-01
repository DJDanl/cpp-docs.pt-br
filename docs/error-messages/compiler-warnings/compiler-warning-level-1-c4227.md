---
title: Compilador aviso (nível 1) C4227
ms.date: 11/04/2016
f1_keywords:
- C4227
helpviewer_keywords:
- C4227
ms.assetid: 78f98374-c00b-4000-aefa-1b1c67b4666b
ms.openlocfilehash: a93b7f225149f9b557ad6238376ffd1bafec82d3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50550300"
---
# <a name="compiler-warning-level-1-c4227"></a>Compilador aviso (nível 1) C4227

anacronismo usado: qualificadores na referência são ignorados

Usando os qualificadores como `const` ou `volatile` com referências de C++ é uma prática antiquada.

## <a name="example"></a>Exemplo

```
// C4227.cpp
// compile with: /W1 /c
int j = 0;
int &const i = j;   // C4227
```