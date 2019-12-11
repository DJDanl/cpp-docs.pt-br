---
title: Aviso do compilador (nível 4) C4670
ms.date: 11/04/2016
f1_keywords:
- C4670
helpviewer_keywords:
- C4670
ms.assetid: e172b134-b1fb-4dfe-8e9d-209ea08b73c7
ms.openlocfilehash: 3ea32e8693fbe310b82eeeb87b1e97f2281ddf04
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990757"
---
# <a name="compiler-warning-level-4-c4670"></a>Aviso do compilador (nível 4) C4670

' identifier ': esta classe base é inacessível

A classe base especificada de um objeto a ser gerado em um bloco **try** não está acessível. O objeto não poderá ser instanciado se for gerado. Verifique se a classe base é herdada com o especificador de acesso correto.

O exemplo a seguir gera C4670:

```cpp
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
