---
title: Erro do compilador C2898
ms.date: 11/04/2016
f1_keywords:
- C2898
helpviewer_keywords:
- C2898
ms.assetid: 68466e11-2541-4f6b-b772-13a642f30dfb
ms.openlocfilehash: 14cef7e23e48f2b5caf4fae12cac511c58ba1f1a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657693"
---
# <a name="compiler-error-c2898"></a>Erro do compilador C2898

'declaração de ': modelos de função de membro não podem ser virtuais

O exemplo a seguir gera C2898:

```
// C2898.cpp
// compile with: /c
class X {
public:
   template<typename T> virtual void f(T t) {}   // C2898
};
```