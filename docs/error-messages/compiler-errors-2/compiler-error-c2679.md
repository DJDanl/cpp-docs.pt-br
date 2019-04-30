---
title: Erro do compilador C2679
ms.date: 11/04/2016
f1_keywords:
- C2679
helpviewer_keywords:
- C2679
ms.assetid: 1a5f9d00-9190-4aa6-bc72-949f68ec136f
ms.openlocfilehash: de5613c306eb12bc11d45e868f502ca04d0a62e6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386818"
---
# <a name="compiler-error-c2679"></a>Erro do compilador C2679

binário 'operator': Nenhum operador encontrado que receba um operando à direita do tipo 'type' (ou não há nenhuma conversão aceitável)

Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.

O exemplo a seguir gera C2679:

```
// C2679.cpp
class C {
public:
   C();   // no constructor with an int argument
} c;

class D {
public:
   D(int) {}
   D(){}
} d;

int main() {
   c = 10;   // C2679
   d = 10;   // OK
}
```