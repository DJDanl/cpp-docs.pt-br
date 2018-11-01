---
title: Erro do compilador C3366
ms.date: 11/04/2016
f1_keywords:
- C3366
helpviewer_keywords:
- C3366
ms.assetid: efc55bcf-c16d-43c1-a36f-87a6165fa2a8
ms.openlocfilehash: 4d1cd510cda9957ced1d9dd5fd8fea267f39220d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50507764"
---
# <a name="compiler-error-c3366"></a>Erro do compilador C3366

'variable': membros de dados estáticos gerenciados ou WinRTtypes devem ser definidos dentro da definição de classe

Você tentou fazer referência a um membro estático de uma classe de WinRT ou .NET ou a interface fora da definição da classe ou interface.

O compilador precisa saber a definição completa da classe (para emitir os metadados após uma passagem) e requer que os membros de dados estáticos sejam inicializados dentro da classe.

Por exemplo, o exemplo a seguir gera C3366 e mostra como corrigi-lo:

```
// C3366.cpp
// compile with: /clr /c
ref class X {
   public:
   static int i;   // initialize i here to avoid C3366
};

int X::i = 5;      // C3366
```
