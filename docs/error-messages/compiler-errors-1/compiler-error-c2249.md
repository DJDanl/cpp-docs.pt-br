---
title: Erro do compilador C2249
ms.date: 11/04/2016
f1_keywords:
- C2249
helpviewer_keywords:
- C2249
ms.assetid: bdd6697c-e04b-49b9-8e40-d9eb6d74f2b6
ms.openlocfilehash: f3f82549cf5d9230adfee7e83248e92f8e93e769
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62301338"
---
# <a name="compiler-error-c2249"></a>Erro do compilador C2249

'member': nenhum caminho acessível para acesso a membro declarado na base virtual 'class'

O `member` é herdada de um nonpublic `virtual` estrutura ou classe base.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2249.

```
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

## <a name="example"></a>Exemplo

C2249 também pode ocorrer se você tentar atribuir um fluxo da biblioteca padrão C++ em outro fluxo.  O exemplo a seguir gera C2249.

```
// C2249_2.cpp
#include <iostream>
using namespace std;
int main() {
   cout = cerr;   // C2249
   #define cout cerr;   // OK
}
```