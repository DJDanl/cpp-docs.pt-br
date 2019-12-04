---
title: Erro do compilador C2079
ms.date: 11/04/2016
f1_keywords:
- C2079
helpviewer_keywords:
- C2079
ms.assetid: ca58d6d5-eccd-40b7-ba14-c003223c5bc7
ms.openlocfilehash: ea158d8dada013f6b90d0fbe1e7502665c1c24da
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757716"
---
# <a name="compiler-error-c2079"></a>Erro do compilador C2079

' identifier ' usa Class/struct/Union ' name ' indefinido

O identificador especificado é uma classe, estrutura ou União indefinida.

Esse erro pode ser causado pela inicialização de uma União anônima.

O exemplo a seguir gera C2079:

```cpp
// C2079.cpp
// compile with: /EHsc
#include <iostream>
int main() {
   std::ifstream g;   // C2079
}
```

Resolução possível:

```cpp
// C2079b.cpp
// compile with: /EHsc
#include <fstream>
int main( ) {
   std::ifstream g;
}
```

C2079 também pode ocorrer se você tentar declarar um objeto na pilha de um tipo cuja declaração de encaminhamento está apenas no escopo.

```cpp
// C2079c.cpp
class A;

class B {
   A a;   // C2079
};

class A {};
```

Resolução possível:

```cpp
// C2079d.cpp
// compile with: /c
class A;
class C {};

class B {
   A * a;
   C c;
};

class A {};
```
