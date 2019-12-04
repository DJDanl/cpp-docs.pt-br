---
title: Erro do compilador C2892
ms.date: 11/04/2016
f1_keywords:
- C2892
helpviewer_keywords:
- C2892
ms.assetid: c22a5084-2f50-42c2-a56b-6dfe5442edc9
ms.openlocfilehash: f3868a44cf04d6c87092759ea473aa78aa0ad4c4
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760883"
---
# <a name="compiler-error-c2892"></a>Erro do compilador C2892

a classe local não deve ter modelos de membro

As funções de membro de modelo não são válidas em uma classe que é definida em uma função.

O exemplo a seguir gera C2892:

```cpp
// C2892.cpp
int main() {
   struct local {
      template<class T>   // C2892
      void f() {}
   };
}
```
