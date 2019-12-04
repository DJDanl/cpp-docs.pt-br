---
title: Erro do compilador C3160
ms.date: 11/04/2016
f1_keywords:
- C3160
helpviewer_keywords:
- C3160
ms.assetid: a250c433-8adf-43b9-8dee-c3794e09b0a5
ms.openlocfilehash: 4d6f415c8b3c8275ac45ef4d4313021100d9a833
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755142"
---
# <a name="compiler-error-c3160"></a>Erro do compilador C3160

' pointer ': um membro de dados de uma classe gerenciada ou WinRT não pode ter esse tipo

Os ponteiros de coleta de lixo interiores podem apontar para o interior de uma classe gerenciada ou WinRT. Como eles são mais lentos do que os ponteiros de objeto inteiro e exigem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados interiores como membros de uma classe.

O exemplo a seguir gera C3160:

```cpp
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
