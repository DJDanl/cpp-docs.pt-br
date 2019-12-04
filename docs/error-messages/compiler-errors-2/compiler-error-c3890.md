---
title: Erro do compilador C3890
ms.date: 11/04/2016
f1_keywords:
- C3890
helpviewer_keywords:
- C3890
ms.assetid: 2f22c2fd-c14e-45e1-b936-b739ffc0b135
ms.openlocfilehash: 8d93afa2ac8e365eff2f9256235b391f561cb977
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736536"
---
# <a name="compiler-error-c3890"></a>Erro do compilador C3890

' var ': não é possível obter o endereço de um membro de dados literal

Um membro de dados literal existe no heap coletado pelo lixo.  Um objeto no heap coletado pelo lixo pode ser movido, portanto, pegar o endereço não é útil.

O exemplo a seguir gera C3890:

```cpp
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
