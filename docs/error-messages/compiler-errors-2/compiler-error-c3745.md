---
title: Erro do compilador C3745
ms.date: 11/04/2016
f1_keywords:
- C3745
helpviewer_keywords:
- C3745
ms.assetid: 1e64aec5-7e53-47e5-bc7d-3905230cfc66
ms.openlocfilehash: da80a10cbf7246ad0aeaecffe20992d2050abb3c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208250"
---
# <a name="compiler-error-c3745"></a>Erro do compilador C3745

'function': somente um evento pode ser 'raised'

Apenas uma função definida com o [Event](../../cpp/event.md) palavra-chave pode ser passado para o [__raise](../../cpp/raise.md) palavra-chave.

O exemplo a seguir gera C3745:

```
// C3745.cpp
struct E {
   __event void func();
   void func(int) {
   }

   void func2() {
   }

   void bar() {
      __raise func();
      __raise func(1);   // C3745
      __raise func2();   // C3745
   }
};

int main() {
   E e;
   __raise e.func();
   __raise e.func(1);   // C3745
   __raise e.func2();   // C3745
}
```