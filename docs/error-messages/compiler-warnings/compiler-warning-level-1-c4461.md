---
title: "Compilador (nível 1) de aviso C4461 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4461
dev_langs: C++
helpviewer_keywords: C4461
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b3b3a64ac5d7bcfbc912c63abf57769fe6da2d40
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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