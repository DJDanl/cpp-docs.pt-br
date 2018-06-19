---
title: Compilador (nível 1) de aviso C4461 | Microsoft Docs
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
ms.openlocfilehash: 2884daeb7497f6664cecf864ec705891cac62f48
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33278627"
---
# <a name="compiler-warning-level-1-c4461"></a>Compilador C4461 de aviso (nível 1)
'type': esta classe possui um finalizador' finalizador', mas nenhum destruidor 'dtor'  
  
 A presença de um finalizador em um tipo implica recursos para excluir. A menos que um finalizador explicitamente é chamado de destruidor do tipo, o common language runtime determina quando executar o finalizador, depois que o objeto sai do escopo.  
  
 Se você define um destruidor no tipo e chama explicitamente o finalizador do destruidor, você pode executar determinística o finalizador.  
  
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