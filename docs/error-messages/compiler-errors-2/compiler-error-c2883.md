---
title: Erro do compilador C2883
ms.date: 11/04/2016
f1_keywords:
- C2883
helpviewer_keywords:
- C2883
ms.assetid: 5c6d689d-ed42-41ad-b5c0-e9c2e0b8c356
ms.openlocfilehash: 3f32307e519394433927d49aa92333fdff7b70f3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62378863"
---
# <a name="compiler-error-c2883"></a>Erro do compilador C2883

'name': declaração de função está em conflito com 'identifier' introduzido por declaração using

Você tentou definir uma função mais de uma vez. A primeira definição foi feita de um namespace com um `using` declaração. A segunda era uma definição de local.

O exemplo a seguir gera C2883:

```
// C2883.cpp
namespace A {
   void z(int);
}

int main() {
   using A::z;
   void z(int);   // C2883  z is already defined
}
```