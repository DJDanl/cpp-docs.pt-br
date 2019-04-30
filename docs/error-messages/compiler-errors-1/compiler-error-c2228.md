---
title: Erro do compilador C2228
ms.date: 11/04/2016
f1_keywords:
- C2228
helpviewer_keywords:
- C2228
ms.assetid: 901cadb1-ce90-4ae0-a360-547a9ba2ca18
ms.openlocfilehash: 20e295d09e39a12ed8163ec980fa304cd4167218
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404332"
---
# <a name="compiler-error-c2228"></a>Erro do compilador C2228

esquerda de '.identifier' deve ter a classe/struct/union

O operando à esquerda do período (.) não é uma classe, estrutura ou união.

O exemplo a seguir gera C2228:

```
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

Você também verá esse erro se você usar uma sintaxe incorreta ao usar extensões gerenciadas. Ao passo que em outras linguagens do Visual Studio, você pode usar o operador ponto para acessar um membro de uma classe gerenciada, um ponteiro para o objeto em C++ significa que você precisa usar o operador para acessar o membro ->:

Wrong: `String * myString = checkedListBox1->CheckedItems->Item[0].ToString();`

Certo: `String * myString = checkedListBox1->CheckedItems->Item[0]->ToString();`