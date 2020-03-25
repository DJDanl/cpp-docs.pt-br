---
title: Aviso do compilador (nível 1) C4939
ms.date: 11/04/2016
f1_keywords:
- C4939
helpviewer_keywords:
- C4939
ms.assetid: 07096008-ba47-436c-a84c-2b03ad90d0b3
ms.openlocfilehash: 5c87dad744281464599ee6c28b5bcf6e350b9feb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199271"
---
# <a name="compiler-warning-level-1-c4939"></a>Aviso do compilador (nível 1) C4939

\#pragma vtordisp é preterido e será removido em uma versão futura do VisualC++

O pragma [vtordisp](../../preprocessor/vtordisp.md) será removido em uma versão futura do Visual C++.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4939.

```cpp
// C4939.cpp
// compile with: /c /W1
#pragma vtordisp(off)   // C4939
```
