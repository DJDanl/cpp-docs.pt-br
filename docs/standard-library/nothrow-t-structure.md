---
title: "Estrutura nothrow_t | Microsoft Docs"
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
  - "nothrow_t"
  - "std.nothrow_t"
  - "std::nothrow_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe nothrow_t"
ms.assetid: dc7d5d42-ed5a-4919-88fe-bbad519b7a1d
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura nothrow_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O struct é usado como um parâmetro da função ao operador novo para indicar que a função deve retornar um ponteiro nulo para informar uma falha de alocação, em vez de que gerencie uma exceção.  
  
## Sintaxe  
  
```  
struct std::nothrow_t {};  
```  
  
## Comentários  
 O struct o compilador ajuda a selecionar a versão correta do construtor.  [nothrow](../Topic/nothrow%20\(%3Cnew%3E\).md) é um sinônimo para objetos de tipo `std::nothrow_t`.  
  
## Exemplo  
 Consulte [operador novo](../Topic/operator%20new%20\(%3Cnew%3E\).md) e [operador novo &#91;&#93;](../Topic/operator%20new\(%3Cnew%3E\).md) para obter exemplos de como `std::nothrow_t` é usado como um parâmetro de função.  
  
## Requisitos  
 **Header:** \<novo\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)