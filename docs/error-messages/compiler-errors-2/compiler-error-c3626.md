---
title: Erro do compilador C3626
ms.date: 11/04/2016
f1_keywords:
- C3626
helpviewer_keywords:
- C3626
ms.assetid: 43926e2b-1ba9-4a43-9343-c58449cbb336
ms.openlocfilehash: 7d86f0f650f6a13ac764497d6d5b52f001f5c35d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757661"
---
# <a name="compiler-error-c3626"></a>Erro do compilador C3626

' keyword ': a palavra-chave ' __event ' só pode ser usada em interfaces COM, funções de membro e membros de dados que são ponteiros para delegados

Uma palavra-chave foi usada incorretamente.

O exemplo a seguir gera C3626:

```cpp
// C3626.cpp
// compile with: /c
struct A {
   __event int i;   // C3626
// try the following line instead
// __event int i();
};
```
