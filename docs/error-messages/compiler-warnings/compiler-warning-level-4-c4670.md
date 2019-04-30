---
title: Compilador aviso (nível 4) C4670
ms.date: 11/04/2016
f1_keywords:
- C4670
helpviewer_keywords:
- C4670
ms.assetid: e172b134-b1fb-4dfe-8e9d-209ea08b73c7
ms.openlocfilehash: 1ce32ef4d07ea5e2c6f328578837f805eed5c897
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408128"
---
# <a name="compiler-warning-level-4-c4670"></a>Compilador aviso (nível 4) C4670

'identifier': esta classe base é inacessível

A classe base especificada de um objeto a ser gerada em um **tente** bloco não está acessível. O objeto não pode ser instanciado se ele for lançado. Verifique que a classe base é herdada com o especificador de acesso correto.

O exemplo a seguir gera C4670:

```
// C4670.cpp
// compile with: /EHsc /W4
class A
{
};

class B : /* public */ A
{
} b;   // inherits A with private access by default

int main()
{
    try
    {
       throw b;   // C4670
    }
    catch( B )
    {
    }
}
```