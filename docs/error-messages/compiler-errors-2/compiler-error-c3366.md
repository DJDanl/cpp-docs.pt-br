---
title: Erro do compilador C3366
ms.date: 11/04/2016
f1_keywords:
- C3366
helpviewer_keywords:
- C3366
ms.assetid: efc55bcf-c16d-43c1-a36f-87a6165fa2a8
ms.openlocfilehash: 5173b1c0df7de6a4e8d9993e680b961a82bb10a7
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738460"
---
# <a name="compiler-error-c3366"></a>Erro do compilador C3366

' Variable ': membros de dados estáticos de Managed ou WinRTtypes devem ser definidos dentro da definição de classe

Você tentou fazer referência a um membro estático de uma interface ou classe do WinRT ou .NET fora da definição dessa classe ou interface.

O compilador precisa saber a definição completa da classe (para emitir os metadados após uma passagem) e exige que os membros de dados estáticos sejam inicializados dentro da classe.

Por exemplo, o exemplo a seguir gera C3366 e mostra como corrigi-lo:

```cpp
// C3366.cpp
// compile with: /clr /c
ref class X {
   public:
   static int i;   // initialize i here to avoid C3366
};

int X::i = 5;      // C3366
```
