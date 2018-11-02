---
title: Compilador aviso (nível 1) C4620
ms.date: 11/04/2016
f1_keywords:
- C4620
helpviewer_keywords:
- C4620
ms.assetid: fed29934-b797-47e8-bbea-c7e5f8dd6e93
ms.openlocfilehash: 8e2d11d63704c86c824fd80e1c8a933c10e062d6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532712"
---
# <a name="compiler-warning-level-1-c4620"></a>Compilador aviso (nível 1) C4620

nenhuma forma de pós-fixo de ' operador + + ' encontrada para tipo 'type', usando forma de prefixo

Não há nenhum operador de incremento pós-fixado definido para o tipo determinado. O compilador usado o operador de prefixo sobrecarregado.

Esse aviso pode ser evitado com a definição de um sufixo `++` operador. Criar uma versão de dois argumentos do `++` operador conforme mostrado aqui:

```
// C4620.cpp
// compile with: /W1
class A
{
public:
   A(int nData) : m_nData(nData)
   {
   }

   A operator++()
   {
      m_nData -= 1;
      return *this;
   }

   // A operator++(int)
   // {
   //    A tmp = *this;
   //    m_nData -= 1;
   //    return tmp;
   // }

private:
   int m_nData;
};

int main()
{
   A a(10);
   ++a;
   a++;   // C4620
}
```