---
title: Erro do compilador C3890
ms.date: 11/04/2016
f1_keywords:
- C3890
helpviewer_keywords:
- C3890
ms.assetid: 2f22c2fd-c14e-45e1-b936-b739ffc0b135
ms.openlocfilehash: 2354be5ac7299fc0361e1b3ad50554e9949f8c1d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385544"
---
# <a name="compiler-error-c3890"></a>Erro do compilador C3890

'var': é possível tomar o endereço de um membro de dados literais

Existe um membro de dados literais no heap coletado como lixo.  Um objeto no heap coletado como lixo pode ser movido para que colocar o endereço não seja útil.

O exemplo a seguir gera C3890:

```
// C3890.cpp
// compile with: /clr
ref struct Y1 {
   literal int staticConst = 9;
};

int main() {
   int p = &Y1::staticConst;   // C3890
   int p2 = Y1::staticConst;   // OK
}
```