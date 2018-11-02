---
title: Compilador aviso (nível 4) C4510
ms.date: 11/04/2016
f1_keywords:
- C4510
helpviewer_keywords:
- C4510
ms.assetid: fd28d1d4-ad27-4dad-94c0-9dba46c93180
ms.openlocfilehash: 80183e9f7ef17cbc37592f36eb8db1df2be94827
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539055"
---
# <a name="compiler-warning-level-4-c4510"></a>Compilador aviso (nível 4) C4510

'class': não foi possível gerar um construtor padrão

O compilador não pode gerar um construtor padrão para a classe especificada e nenhum construtor definido pelo usuário foi criado. Você não poderá criar objetos desse tipo.

Há várias situações que impedem que o compilador gere um construtor padrão, incluindo:

- Um membro de dados const.

- Um membro de dados que é uma referência.

Você precisa criar um construtor padrão definido pelo usuário para a classe que inicializa esses membros.

O exemplo a seguir gera C4510:

```
// C4510.cpp
// compile with: /W4
struct A {
   const int i;
   int &j;
   A& operator=( const A& ); // C4510 expected
   // uncomment the following line to resolve this C4510
   // A(int ii, int &jj) : i(ii), j(jj) {}
};   // C4510

int main() {
}
```