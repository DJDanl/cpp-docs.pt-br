---
title: "Classe allocator&lt;void&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "memory/std::allocator<void>"
  - "std::allocator<void>"
  - "std.allocator<void>"
  - "allocator<void>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe allocator<void>"
ms.assetid: abfb40f5-c600-46a6-b130-f42c6535b2bd
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe allocator&lt;void&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma especialização do alocador da classe do modelo para digitar `void`, definindo os tipos que fazem sentido neste contexto.  
  
## Sintaxe  
  
```  
template<>  
   class allocator<void> {  
   typedef void *pointer;  
   typedef const void *const_pointer;  
   typedef void value_type;  
   template<class Other>  
      struct rebind;  
   allocator( );  
   allocator(  
      const allocator<void>&  
   );  
   template<class Other>  
      allocator(  
         const allocator<Other>&  
      );  
   template<class Other>  
      allocator<void>& operator=(  
         const allocator<Other>&  
      );  
   };  
```  
  
## Comentários  
 A classe especializa explicitamente a classe de modelo [allocator](../standard-library/allocator-class.md) para o tipo *void.* Os construtores e o operador de atribuição se comportam da mesma forma que para a classe do modelo, mas define apenas os seguintes tipos:  
  
-   [const\_pointer](../Topic/allocator::const_pointer.md).  
  
-   [ponteiro](../Topic/allocator::pointer.md).  
  
-   [value\_type](../Topic/allocator::value_type.md).  
  
-   [reassociar](../Topic/allocator::rebind.md), uma classe aninhada do modelo.  
  
## Requisitos  
 Memória\<de**Header:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)