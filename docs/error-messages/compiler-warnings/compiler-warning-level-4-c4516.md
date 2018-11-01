---
title: Compilador aviso (nível 4) C4516
ms.date: 11/04/2016
f1_keywords:
- C4516
helpviewer_keywords:
- C4516
ms.assetid: 6677bb1f-d26e-4ab9-8644-6b5a2a8f4ff8
ms.openlocfilehash: 8020103e8e20bf1a5e955cbfdfafc6a328b439e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50564041"
---
# <a name="compiler-warning-level-4-c4516"></a>Compilador aviso (nível 4) C4516

'class::symbol': declarações de acesso são preteridas; declarações de using membro fornecem uma alternativa melhor

O Comitê de C++ ANSI declarou declarações de acesso (alterando o acesso de um membro em uma classe derivada sem a [usando](../../cpp/using-declaration.md) palavra-chave) fiquem desatualizados. Declarações de acesso podem não ter suporte por versões futuras do C++.

O exemplo a seguir gera C4516:

```
// C4516.cpp
// compile with: /W4
class A
{
public:
   void x(char);
};

class B : protected A
{
public:
   A::x;  // C4516 on access-declaration
   // use the following line instead
   // using A::x; // using-declaration, ok
};

int main()
{
}
```