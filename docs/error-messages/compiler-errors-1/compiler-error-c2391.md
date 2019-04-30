---
title: Erro do compilador C2391
ms.date: 11/04/2016
f1_keywords:
- C2391
helpviewer_keywords:
- C2391
ms.assetid: 63a9c6b9-03cc-4517-885c-bdcd048643b3
ms.openlocfilehash: 7683ad1580454bd7edb1fc08e5bd110a3e5c36c4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393617"
---
# <a name="compiler-error-c2391"></a>Erro do compilador C2391

'identifier': 'friend' não pode ser usado durante a definição de tipo

O `friend` declaração inclui uma declaração de classe completo. Um `friend` declaração pode especificar uma função de membro ou um especificador de tipo elaborado, mas não uma declaração de classe completo.

O exemplo a seguir gera C2326:

```
// C2391.cpp
// compile with: /c
class D {
   void func( int );
};

class A {
   friend class B { int i; };   // C2391

   // OK
   friend class C;
   friend void D::func(int);
};
```