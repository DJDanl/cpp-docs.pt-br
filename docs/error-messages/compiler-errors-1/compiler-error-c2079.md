---
title: Erro do compilador C2079 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2079
dev_langs:
- C++
helpviewer_keywords:
- C2079
ms.assetid: ca58d6d5-eccd-40b7-ba14-c003223c5bc7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ddea9a8651a62f7cbb857e1d53962142471c2cb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032167"
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