---
title: Erro do compilador C3160
ms.date: 11/04/2016
f1_keywords:
- C3160
helpviewer_keywords:
- C3160
ms.assetid: a250c433-8adf-43b9-8dee-c3794e09b0a5
ms.openlocfilehash: 96fd97aa5021b7e1bc5226162f9c54ff4d6211b1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50649732"
---
# <a name="compiler-error-c3160"></a>Erro do compilador C3160

'ponteiro': uma classe de WinRT ou membro de dados de um gerenciado não pode ter esse tipo

Ponteiros de coleta de lixo interiores podem apontar para o interior de um ou a classe do WinRT. Como eles são mais lentos que os ponteiros do objeto inteiro e requerem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados internos como membros de uma classe.

O exemplo a seguir gera C3160:

```
// C3160.cpp
// compile with: /clr
ref struct A {
   // cannot create interior pointers inside a class
   interior_ptr<int> pg;   // C3160
   int g;   // OK
   int* pg2;   // OK
};

int main() {
   interior_ptr<int> pg2;   // OK
}
```
