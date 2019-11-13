---
title: Aviso do compilador (nível 1) C4677
ms.date: 11/04/2016
f1_keywords:
- C4677
helpviewer_keywords:
- C4677
ms.assetid: a8d656a1-e2ff-4f8b-9028-201765131026
ms.openlocfilehash: 8567e7392537507a25121977448ac47ec079316b
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051377"
---
# <a name="compiler-warning-level-1-c4677"></a>Aviso do compilador (nível 1) C4677

' function ': assinatura de membro não privado contém tipo privado de assembly ' private_type '

Um tipo que tem acessibilidade pública fora do assembly usa um tipo que tem acesso privado fora do assembly. Um componente que referencia o tipo de assembly público não poderá usar o membro de tipo ou membros que referenciam o tipo privado do assembly.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4677.

```cpp
// C4677.cpp
// compile with: /clr /c /W1
delegate void TestDel();
public delegate void TestDel2();

public ref class MyClass {
public:
   static event TestDel^ MyClass_Event;   // C4677
   static event TestDel2^ MyClass_Event2;   // OK
};
```