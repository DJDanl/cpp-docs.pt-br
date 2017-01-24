---
title: "Classe lock_guard | Microsoft Docs"
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
  - "mutex/std::lock_guard"
dev_langs: 
  - "C++"
ms.assetid: 57121f0d-9c50-481c-b971-54e64df864e0
caps.latest.revision: 9
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe lock_guard
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um modelo que possa ser criado uma instância do para criar um objeto cujo destruidor desbloquee `mutex`.  
  
## Sintaxe  
  
```  
template<class Mutex>  
class lock_guard;  
```  
  
## Comentários  
 O argumento `Mutex` do modelo deve nomear *um tipo de mutex*.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`lock_guard::mutex_type`|Sinônimo para o argumento `Mutex`do modelo.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor lock\_guard::lock\_guard](../Topic/lock_guard::lock_guard%20Constructor.md)|Constrói um objeto `lock_guard`.|  
|[Destruidor lock\_guard::~lock\_guard](../Topic/lock_guard::~lock_guard%20Destructor.md)|Desbloqueia `mutex` passado ao construtor.|  
  
## Requisitos  
 **Cabeçalho:** mutex  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<mutex\>](../standard-library/mutex.md)