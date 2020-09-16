---
title: Erro das Ferramentas de Vinculador LNK2020
ms.date: 11/04/2016
f1_keywords:
- LNK2020
helpviewer_keywords:
- LNK2020
ms.assetid: 4dd017d0-5e83-471b-ac8a-538ac1ed6870
ms.openlocfilehash: 6fd4859e4f8cad657de57e8039bd647e5e2b99a9
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684632"
---
# <a name="linker-tools-error-lnk2020"></a>Erro das Ferramentas de Vinculador LNK2020

token ' token ' não resolvido

Semelhante a um erro externo indefinido, exceto que a referência é por meio de metadados. Em metadados, todas as funções e os dados devem ser definidos.

Para resolver esse erro:

- Definir a função ou os dados ausentes ou

- Inclua o arquivo de objeto ou a biblioteca na qual a função ou os dados ausentes já estão definidos.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera LNK2020.

```cpp
// LNK2020.cpp
// compile with: /clr /LD
ref struct A {
   A(int x);   // LNK2020
   static int f();   // LNK2020
};

// OK
ref struct B {
   B(int x) {}
   static int f() { return 0; }
};
```

LNK2020 também ocorrerá se você criar uma variável de um tipo de modelo gerenciado, mas não criar também a instância do tipo.

O exemplo a seguir gera LNK2020.

```cpp
// LNK2020_b.cpp
// compile with: /clr

template <typename T>
ref struct Base {
   virtual void f1() {};
};

template <typename T>
ref struct Base2 {
   virtual void f1() {};
};

int main() {
   Base<int>^ p;   // LNK2020
   Base2<int>^ p2 = gcnew Base2<int>();   // OK
};
```
