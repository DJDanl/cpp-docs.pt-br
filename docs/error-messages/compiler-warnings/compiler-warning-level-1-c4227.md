---
title: Aviso do compilador (nível 1) C4227
ms.date: 11/04/2016
f1_keywords:
- C4227
helpviewer_keywords:
- C4227
ms.assetid: 78f98374-c00b-4000-aefa-1b1c67b4666b
ms.openlocfilehash: d63d6b4997e7a7e8baf4c80841ffb4c7e59d03c7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175903"
---
# <a name="compiler-warning-level-1-c4227"></a>Aviso do compilador (nível 1) C4227

anacronismo usado: qualificadores na referência são ignorados

Usar qualificadores como `const` ou `volatile` com C++ referências é uma prática desatualizada.

## <a name="example"></a>Exemplo

```cpp
// C4227.cpp
// compile with: /W1 /c
int j = 0;
int &const i = j;   // C4227
```
