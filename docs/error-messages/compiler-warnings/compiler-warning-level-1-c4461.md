---
title: Compilador aviso (nível 1) C4461 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4461
dev_langs:
- C++
helpviewer_keywords:
- C4461
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 86c12208c6992b97f30bc36ea821ba26148ff751
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081385"
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