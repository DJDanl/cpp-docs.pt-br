---
title: Aviso do compilador (nível 1) C4141
ms.date: 11/04/2016
f1_keywords:
- C4141
helpviewer_keywords:
- C4141
ms.assetid: 6ce8c058-7f4c-41cf-93e7-90a466744656
ms.openlocfilehash: 707df8ef4b56879da80d885ed75f352b36299fe9
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73625038"
---
# <a name="compiler-warning-level-1-c4141"></a>Aviso do compilador (nível 1) C4141

' Modifier ': usado mais de uma vez

## <a name="example"></a>Exemplo

```cpp
// C4141.cpp
// compile with: /W1 /LD
inline inline void func ();   // C4141
```