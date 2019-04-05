---
title: Erro do compilador C3797
ms.date: 11/04/2016
f1_keywords:
- C3797
helpviewer_keywords:
- C3797
ms.assetid: ab27ff34-8c1d-4297-b004-9e39bd3a4f25
ms.openlocfilehash: 76206cdffce3f551ff472cbd83df486eb41ae80b
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58774822"
---
# <a name="compiler-error-c3797"></a>Erro do compilador C3797

'override': declaração de evento não pode possuir especificador de substituição (deve ser colocado nos métodos de adicionar/remover/raise do evento em vez disso)

Você não pode substituir um evento trivial (um evento sem métodos de acessador definido explicitamente) com outro evento trivial. O evento de substituição deve definir seu comportamento com funções do acessador.

Para obter mais informações, consulte [evento](../../extensions/event-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3797.

```
// C3797.cpp
// compile with: /clr /c
delegate void MyDel();

ref class Class1 {
public:
   virtual event MyDel ^ E;
};

ref class Class2 : public Class1 {
public:
   virtual event MyDel ^ E override;   // C3797
};

// OK
ref class Class3 : public Class1 {
public:
   virtual event MyDel ^ E {
      void add(MyDel ^ d) override {}
      void remove(MyDel ^ d) override {}
   }
};
```