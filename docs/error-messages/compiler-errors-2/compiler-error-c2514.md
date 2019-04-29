---
title: Erro do compilador C2514
ms.date: 11/04/2016
f1_keywords:
- C2514
helpviewer_keywords:
- C2514
ms.assetid: 4b7085e5-6714-4261-80b7-bc72e64ab3e8
ms.openlocfilehash: aef9df0718d013378f88c1a34d08d1b1e05e214c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62243743"
---
# <a name="compiler-error-c2514"></a>Erro do compilador C2514

'class': classe não possui construtores

A classe, estrutura ou união não tem nenhum construtor com uma lista de parâmetros que corresponde aos parâmetros que estão sendo usados para instanciá-lo.

Uma classe deve ser declarada totalmente antes que possa ser instanciado.

O exemplo a seguir gera C2514:

```
// C2514.cpp
// compile with: /c
class f;

class g {
public:
    g (int x);
};

class fmaker {
   f *func1() {
      return new f(2);   // C2514
   }

   g *func2() {
      return new g(2);   // OK
   }
};
```