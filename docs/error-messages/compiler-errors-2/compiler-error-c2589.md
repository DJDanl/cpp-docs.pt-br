---
title: Erro do compilador C2589
ms.date: 11/04/2016
f1_keywords:
- C2589
helpviewer_keywords:
- C2589
ms.assetid: 1d7942c7-8a81-4bb4-b272-76a0019e8513
ms.openlocfilehash: 76cc35e57c1577ed23c043740f37c602600da542
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74748496"
---
# <a name="compiler-error-c2589"></a>Erro do compilador C2589

' identifier ': token inválido no lado direito de ':: '

Se um nome de classe, estrutura ou União aparecer à esquerda do operador de resolução de escopo (dois-pontos duplos), o token à direita deverá ser um membro de classe, estrutura ou União. Caso contrário, qualquer identificador global pode aparecer à direita.

O operador de resolução de escopo não pode ser sobrecarregado.

O exemplo a seguir gera C2589:

```cpp
// C2589.cpp
void Test(){}
class A {};
void operator :: ();   // C2589

int main() {
   ::Test();
}
```
