---
title: Compilador aviso (nível 1) C4621
ms.date: 11/04/2016
f1_keywords:
- C4621
helpviewer_keywords:
- C4621
ms.assetid: 40931bd9-cb89-497e-86f0-cec9f016c63c
ms.openlocfilehash: d35c4143d5b90c7a6a49337931dad4ba73804f20
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62221348"
---
# <a name="compiler-warning-level-1-c4621"></a>Compilador aviso (nível 1) C4621

nenhuma forma de pós-fixo de 'operator--' encontrada para tipo 'type', usando forma de prefixo

Não havia nenhum operador de decremento de sufixo definido para o tipo determinado. O compilador usado o operador de prefixo sobrecarregado.

Esse aviso pode ser evitado com a definição de um sufixo `--` operador. Criar uma versão de dois argumentos do `--` operador conforme mostrado abaixo:

```
// C4621.cpp
// compile with: /W1
class A
{
public:
   A(int nData) : m_nData(nData)
   {
   }

   A operator--()
   {
      m_nData -= 1;
      return *this;
   }

   // A operator--(int)
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
   --a;
   a--;   // C4621
}
```