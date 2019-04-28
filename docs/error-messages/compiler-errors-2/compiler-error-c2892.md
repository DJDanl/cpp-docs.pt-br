---
title: Erro do compilador C2892
ms.date: 11/04/2016
f1_keywords:
- C2892
helpviewer_keywords:
- C2892
ms.assetid: c22a5084-2f50-42c2-a56b-6dfe5442edc9
ms.openlocfilehash: 296224532b19d9ff85c8644aa653b6d842205213
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62265874"
---
# <a name="compiler-error-c2892"></a>Erro do compilador C2892

classe local não deve ter modelos de membro

Funções de membro de modelo não são válidas em uma classe que é definida em uma função.

O exemplo a seguir gera C2892:

```
// C2892.cpp
int main() {
   struct local {
      template<class T>   // C2892
      void f() {}
   };
}
```