---
title: Compilador aviso (nível 1) C4488
ms.date: 11/04/2016
f1_keywords:
- C4488
helpviewer_keywords:
- C4488
ms.assetid: 55625e46-ddb5-4c7c-99c7-cd4aa9f879bd
ms.openlocfilehash: c816c1b3f5481ccff19fd2a2377c5fc98f950fee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50577821"
---
# <a name="compiler-warning-level-1-c4488"></a>Compilador aviso (nível 1) C4488

'function': requer 'palavra-chave' palavra-chave para implementar o método de interface 'interface_method'

Uma classe deve implementar todos os membros de uma interface da qual ela herda diretamente. Um membro implementado deve ter acessibilidade pública e deve ser marcado como virtual.

## <a name="example"></a>Exemplo

C4488 pode ocorrer se um membro implementado não é público. O exemplo a seguir gera C4488.

```
// C4488.cpp
// compile with: /clr /c /W1 /WX
interface struct MyI {
   void f1();
};

// implemented member not public
ref class B : MyI { virtual void f1() {} };  // C4488

// OK
ref class C : MyI {
public:
   virtual void f1() {}
};
```

## <a name="example"></a>Exemplo

C4488 pode ocorrer se um membro implementado não está marcado como virtual. O exemplo a seguir gera C4488.

```
// C4488_b.cpp
// compile with: /clr /c /W1 /WX
interface struct MyI {
   void f1();
};

ref struct B : MyI { void f1() {} };   // C4488
ref struct C : MyI { virtual void f1() {} };   // OK
```