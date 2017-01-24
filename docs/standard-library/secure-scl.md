---
title: "_SECURE_SCL | Microsoft Docs"
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
  - "_SECURE_SCL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_SECURE_SCL"
ms.assetid: 4ffbc788-cc12-4c6a-8cd7-490081675086
caps.latest.revision: 10
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _SECURE_SCL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define se [Iteradores Verificados](../standard-library/checked-iterators.md) está habilitado.  Se definido como 1, o uso não seguro de iterador causa um erro de tempo de execução e o programa será encerrado.  Se definido como 0, os iteradores verificadas são desabilitados.  No modo de depuração, o valor padrão para **\_SECURE\_SCL** é 1, indicando que os iteradores verificados estão habilitados.  No modo de versão, o valor padrão para `_SECURE_SCL` é 0.  
  
> [!IMPORTANT]
>  Use `_ITERATOR_DEBUG_LEVEL` para controlar `_SECURE_SCL`.  Para obter mais informações, consulte [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md).  
  
## Comentários  
 Para habilitar verificou iteradores, define **\_SECURE\_SCL** a 1:  
  
```  
#define _SECURE_SCL 1  
```  
  
 Para desabilitar verificou iteradores, define **\_SECURE\_SCL** a 0:  
  
```  
#define _SECURE_SCL 0  
```  
  
 Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [\_SCL\_SECURE\_NO\_WARNINGS](../standard-library/scl-secure-no-warnings.md).  
  
## Consulte também  
 [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md)   
 [Iteradores Verificados](../standard-library/checked-iterators.md)   
 [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md)   
 [Bibliotecas seguras: Biblioteca Padrão C\+\+](../standard-library/safe-libraries-cpp-standard-library.md)