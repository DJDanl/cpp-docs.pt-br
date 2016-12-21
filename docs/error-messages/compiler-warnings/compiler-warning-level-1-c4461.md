---
title: "Compilador C4461 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4461"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4461"
ms.assetid: 104ffecc-3dd4-4cb1-89a8-81154fbe46d9
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4461 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: esta classe não tem um finalizador “finalizador” mas nenhum destruidor “dtor”  
  
 A presença de um finalizador em um tipo implica recursos para excluir.  A menos que um finalizador é chamado explicitamente de destruidor do tipo, Common Language Runtime determina quando executar o finalizador, depois que seu objeto sai do escopo.  
  
 Se você definir um destruidor no tipo e chamar explicitamente o finalizador de destruidor, você pode executar de forma determinista seu finalizer.  
  
 Para obter mais informações, consulte [Destruidores e finalizers](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
## Exemplo  
 O exemplo a seguir produz C4461.  
  
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