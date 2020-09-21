---
title: Erro do compilador C2249
ms.date: 11/04/2016
f1_keywords:
- C2249
helpviewer_keywords:
- C2249
ms.assetid: bdd6697c-e04b-49b9-8e40-d9eb6d74f2b6
ms.openlocfilehash: ac396fe5fa3505311f5a45ebb49dae283e35248c
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90741403"
---
# <a name="compiler-error-c2249"></a>Erro do compilador C2249

' member ': nenhum caminho acessível para o membro de acesso declarado na base virtual ' class '

O `member` é herdado de uma **`virtual`** classe base ou estrutura não pública.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2249.

```cpp
// C2249.cpp
class A {
private:
   void privFunc( void ) {};
public:
   void pubFunc( void ) {};
};

class B : virtual public A {} b;

int main() {
   b.privFunc();    // C2249, private member of A
   b.pubFunc();    // OK
}
```

C2249 também pode ocorrer se você tentar atribuir um fluxo da biblioteca padrão C++ para outro fluxo.  O exemplo a seguir gera C2249.

```cpp
// C2249_2.cpp
#include <iostream>
using namespace std;
int main() {
   cout = cerr;   // C2249
   #define cout cerr;   // OK
}
```
