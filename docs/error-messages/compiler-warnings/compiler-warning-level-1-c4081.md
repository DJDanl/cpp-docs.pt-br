---
title: Aviso do compilador (nível 1) C4081
ms.date: 11/04/2016
f1_keywords:
- C4081
helpviewer_keywords:
- C4081
ms.assetid: 6f656373-a080-4989-bbc9-e2f894b03293
ms.openlocfilehash: b882fe9c83f072c06a63733870f610549b209691
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200250"
---
# <a name="compiler-warning-level-1-c4081"></a>Aviso do compilador (nível 1) C4081

esperado ' token1 '; ' token2 ' encontrado

O compilador esperava um token diferente neste contexto.

## <a name="example"></a>Exemplo

```cpp
// C4081.cpp
// compile with: /W1 /LD
#pragma optimize) "l", on )   // C4081
```
