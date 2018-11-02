---
title: Erro do compilador C2552
ms.date: 11/04/2016
f1_keywords:
- C2552
helpviewer_keywords:
- C2552
ms.assetid: 0e0ab759-788a-4faf-9337-80d4b9e2e8c9
ms.openlocfilehash: ddd3755a4fcabf8c097c359f31c9cc189b36f79a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50521102"
---
# <a name="compiler-error-c2552"></a>Erro do compilador C2552

"identificador": não agregados não podem ser inicializados com a lista de inicializadores

O identificador agregado foi inicializado incorretamente.

[Agregações](../../c-language/initializing-aggregate-types.md) são definidos como:

- Matrizes

- Classes, estruturas e uniões sem:

   - Construtores

   - Membros particulares ou protegidos

   - Classes base

   - Funções virtuais

Além disso, o Visual C++ não permite tipos de dados em uma agregação que contenha construtores.

A seguir encontram-se os motivos que podem fazer com que o C2552 seja acionado quando houver uma tentativa de fazer uma inicialização de agregação em um tipo:

- O tipo tem um ou vários construtores definidos pelo usuário.

- O tipo tem um ou mais membros de dados particulares, não estáticos.

- O tipo tem uma ou mais funções virtuais.

- O tipo tem uma classe base.

- O tipo é uma classe ref ou interface CLR.

- O tipo tem uma matriz de dimensão não fixa (matriz zero) cujos elementos têm destruidores.

O seguinte exemplo gera C2552:

```
// C2552.cpp
// compile with: /clr
#include <string>
using namespace std;

struct Pair_Incorrect {
private:
   string m_name;
   double m_val;
};

struct Pair_Correct1 {
public:
   Pair_Correct1(string name, double val)
      : m_name(name), m_val(val) {}

private:
   string m_name;
   double m_val;
};

struct Pair_Correct2 {
public:
   string m_name;
   double m_val;
};

int main() {
   // To fix, add a constructor to this class and use it for
   // initializing the data members, see Pair_Correct1 (below)
   // or
   // Do not have any private or protected non-static data members,
   // see Pair_Correct2 (below).  Pair_Correct2 is not recommended in
   // case your object model requires some non-static data members to
   // be private or protected

   string name("John");
   Pair_Incorrect pair1 = { name, 0.0 };   // C2552

   // initialize a CLR immutable value type that has a constructor
   System::DateTime dt = {2001, 4, 12, 22, 16, 49, 844};   // C2552

   Pair_Correct1 pair2( name, 0.0 );
   Pair_Correct1 pair3 = Pair_Correct1( name, 0.0 );
   Pair_Correct2 pair4 = { name, 0.0 };
   System::DateTime dt2(2001, 4, 12, 22, 16, 49, 844);
}
```