---
title: Compilador aviso (nível 1) C4807
ms.date: 11/04/2016
f1_keywords:
- C4807
helpviewer_keywords:
- C4807
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
ms.openlocfilehash: a68596136e61aa33176365a4eff818124463b77e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390458"
---
# <a name="compiler-warning-level-1-c4807"></a>Compilador aviso (nível 1) C4807

'operation': mistura não segura de tipo 'type' e o campo de bits com sinal do tipo 'type'

Esse aviso é gerado durante a comparação de um campo de bits com sinal de um bit para um `bool` variável. Como um campo de bits com sinal, de um bit só pode conter os valores de -1 ou 0, é perigoso para compará-la para `bool`. Nenhum aviso é gerado sobre misturar `bool` e um bit, sem sinal campos de bits, pois elas são idênticas às `bool` e só podem ter 0 ou 1.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4807:

```
// C4807.cpp
// compile with: /W1
typedef struct bitfield {
   signed mybit : 1;
} mybitfield;

int main() {
   mybitfield bf;
   bool b = true;

   // try..
   // int b = true;

   bf.mybit = -1;
   if (b == bf.mybit) {   // C4807
      b = false;
   }
}
```