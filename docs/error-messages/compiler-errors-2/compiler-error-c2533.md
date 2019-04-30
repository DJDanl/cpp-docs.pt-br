---
title: Erro do compilador C2533
ms.date: 11/04/2016
f1_keywords:
- C2533
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
ms.openlocfilehash: 00cb13d1999b00dfcaa5a2bc7bfb3b8eb16af5f2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386974"
---
# <a name="compiler-error-c2533"></a>Erro do compilador C2533

'identifier': construtores não permitidas um tipo de retorno

Um construtor não pode ter um tipo de retorno (nem mesmo uma `void` tipo de retorno).

Uma origem comum desse erro é um ponto e vírgula ausente entre o final de uma definição de classe e a primeira implementação do construtor. O compilador considera a classe como uma definição do tipo de retorno para a função de construtor e gera C2533.

O exemplo a seguir gera C2533 e mostra como corrigi-lo:

```
// C2533.cpp
// compile with: /c
class X {
public:
   X();
};

int X::X() {}   // C2533 - constructor return type not allowed
X::X() {}   // OK - fix by using no return type
```