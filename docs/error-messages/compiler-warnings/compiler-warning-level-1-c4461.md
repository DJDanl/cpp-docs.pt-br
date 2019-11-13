---
title: Aviso do compilador (nível 1) C4461
ms.date: 11/04/2016
f1_keywords:
- C4461
helpviewer_keywords:
- C4461
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
ms.openlocfilehash: 195e5532b6555210077e43ad3086ee3106f3e757
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966018"
---
# <a name="compiler-warning-level-1-c4461"></a>Aviso do compilador (nível 1) C4461

' type ': essa classe tem um finalizador ' Finalizer ', mas nenhum destruidor ' dtor '

A presença de um finalizador em um tipo implica recursos a serem excluídos. A menos que um finalizador seja explicitamente chamado do destruidor do tipo, o Common Language Runtime determina quando executar o finalizador, depois que o objeto sair do escopo.

Se você definir um destruidor no tipo e chamar explicitamente o finalizador a partir do destruidor, você poderá executar de forma determinística o finalizador.

Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4461.

```cpp
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