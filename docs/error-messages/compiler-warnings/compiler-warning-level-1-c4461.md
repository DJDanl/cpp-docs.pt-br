---
title: "Compilador aviso (nível 1) C4461 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4461
dev_langs:
- C++
helpviewer_keywords:
- C4461
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 944171004dc2781bffb9b34d8b9a0fd6178398d8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4461"></a>Compilador C4461 de aviso (nível 1)
'type': essa classe tiver um finalizador' finalizador', mas nenhum destruidor 'dtor'  
  
 A presença de um finalizador em um tipo implica recursos para excluir. A menos que um finalizador explicitamente é chamado de destruidor do tipo, o common language runtime determina quando executar o finalizador, depois que o objeto sai do escopo.  
  
 Se você definir um destruidor no tipo e chama o finalizador de destruidor explicitamente, você pode executar de forma determinista seu finalizador.  
  
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
