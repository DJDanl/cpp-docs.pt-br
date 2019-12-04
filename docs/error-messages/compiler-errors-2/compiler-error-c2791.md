---
title: Erro do compilador C2791
ms.date: 11/04/2016
f1_keywords:
- C2791
helpviewer_keywords:
- C2791
ms.assetid: 938ad1fb-75d9-4ce2-ad92-83d6249005b5
ms.openlocfilehash: d589094f117135474d1a8788867d2d571bbb5f5d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74739539"
---
# <a name="compiler-error-c2791"></a>Erro do compilador C2791

uso ilegal de ' super ': ' class ' não tem nenhuma classe base

A palavra-chave [super](../../cpp/super.md) foi usada no contexto de uma função membro de uma classe que não tem nenhuma classe base.

O exemplo a seguir gera C2791:

```cpp
// C2791.cpp
struct D {
   void mf() {
      __super::mf();   // C2791
   }
};
```
