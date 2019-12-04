---
title: Erro do compilador C2228
ms.date: 11/04/2016
f1_keywords:
- C2228
helpviewer_keywords:
- C2228
ms.assetid: 901cadb1-ce90-4ae0-a360-547a9ba2ca18
ms.openlocfilehash: 56eed6aeff5a955253a440d5931d66118f4604e0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759276"
---
# <a name="compiler-error-c2228"></a>Erro do compilador C2228

esquerda de '. Identifier ' deve ter Class/struct/Union

O operando à esquerda do período (.) não é uma classe, estrutura ou União.

O exemplo a seguir gera C2228:

```cpp
// C2228.cpp
int i;
struct S {
public:
    int member;
} s, *ps = &s;

int main() {
   i.member = 0;   // C2228 i is not a class type
   ps.member = 0;  // C2228 ps is a pointer to a structure

   s.member = 0;   // s is a structure type
   ps->member = 0; // ps points to a structure S
}
```

Você também verá esse erro se usar a sintaxe incorreta ao usar extensões gerenciadas. Enquanto em outras linguagens do Visual Studio, você pode usar o operador ponto para acessar um membro de uma classe gerenciada, um ponteiro para C++ o objeto no significa que você precisa usar o operador-> para acessar o membro:

Errado: `String * myString = checkedListBox1->CheckedItems->Item[0].ToString();`

À direita: `String * myString = checkedListBox1->CheckedItems->Item[0]->ToString();`
