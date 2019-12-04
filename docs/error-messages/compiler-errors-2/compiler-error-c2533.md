---
title: Erro do compilador C2533
ms.date: 11/04/2016
f1_keywords:
- C2533
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
ms.openlocfilehash: b111448e7e9d8260a5101d05996a670013936894
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74746403"
---
# <a name="compiler-error-c2533"></a>Erro do compilador C2533

' identifier ': construtores não permitidos um tipo de retorno

Um construtor não pode ter um tipo de retorno (nem mesmo um `void` tipo de retorno).

Uma fonte comum desse erro é um ponto-e-vírgula ausente entre o final de uma definição de classe e a primeira implementação do construtor. O compilador vê a classe como uma definição do tipo de retorno para a função de construtor e gera C2533.

O exemplo a seguir gera C2533 e mostra como corrigi-lo:

```cpp
// C2533.cpp
// compile with: /c
class X {
public:
   X();
};

int X::X() {}   // C2533 - constructor return type not allowed
X::X() {}   // OK - fix by using no return type
```
