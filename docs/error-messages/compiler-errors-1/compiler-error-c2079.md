---
title: Erro do compilador C2079
ms.date: 11/04/2016
f1_keywords:
- C2079
helpviewer_keywords:
- C2079
ms.assetid: ca58d6d5-eccd-40b7-ba14-c003223c5bc7
ms.openlocfilehash: 68435610680e3b21415a1d9439a8133fd1e2557f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391953"
---
# <a name="compiler-error-c2079"></a>Erro do compilador C2079

'identifier' usa a classe/struct/union indefinida 'name'

O identificador especificado é uma classe indefinida, estrutura ou união.

Esse erro pode ser causado por inicializar uma união anônima.

O exemplo a seguir gera C2079:

```
// C2079.cpp
// compile with: /EHsc
#include <iostream>
int main() {
   std::ifstream g;   // C2079
}
```

Solução possível:

```
// C2079b.cpp
// compile with: /EHsc
#include <fstream>
int main( ) {
   std::ifstream g;
}
```

C2079 também pode ocorrer se você tentar declarar um objeto na pilha de um tipo cuja declaração de encaminhamento é somente no escopo.

```
// C2079c.cpp
class A;

class B {
   A a;   // C2079
};

class A {};
```

Solução possível:

```
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