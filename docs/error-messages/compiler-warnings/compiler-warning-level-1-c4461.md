---
title: Compilador aviso (nível 1) C4461
ms.date: 11/04/2016
f1_keywords:
- C4461
helpviewer_keywords:
- C4461
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
ms.openlocfilehash: 5cc9b08f0f25e9c92b4185f060ab123684c5d9e2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408258"
---
# <a name="compiler-warning-level-1-c4461"></a>Compilador aviso (nível 1) C4461

'type': esta classe tem um finalizador' finalizador', mas nenhum destruidor 'dtor'

A presença de um finalizador em um tipo implica recursos para excluir. A menos que explicitamente, um finalizador é chamado de destruidor do tipo, o common language runtime determina quando executar o finalizador, depois que seu objeto sai do escopo.

Se você definir um destruidor no tipo e chama o finalizador de destruidor explicitamente, você pode executar determinística, seu finalizador.

Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4461.

```
// C4461.cpp
// compile with: /W1 /clr /c
ref class A {
protected:
   !A() {}   // C4461
};

// OK
ref struct B {
   ~B() {
      B::!B();
   }

   !B() {}
};
```