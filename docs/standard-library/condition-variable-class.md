---
title: "Classe condition_variable | Microsoft Docs"
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
  - "condition_variable/std::condition_variable"
dev_langs: 
  - "C++"
ms.assetid: 80b1295c-b73d-4d46-b664-6e183f2eec1b
caps.latest.revision: 16
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe condition_variable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use a classe `condition_variable` para aguardar um evento quando você tem `mutex` do tipo `unique_lock<mutex>`.  Os objetos desse tipo podem ter um desempenho melhor do que os objetos do tipo [condition\_variable\_any\<unique\_lock\<mutex\>\>](../standard-library/condition-variable-any-class.md).  
  
## Sintaxe  
  
```  
class condition_variable;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor condition\_variable::condition\_variable](../Topic/condition_variable::condition_variable%20Constructor.md)|Constrói um objeto `condition_variable`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método condition\_variable::native\_handle](../Topic/condition_variable::native_handle%20Method.md)|Retorna o tipo específico da implementação que representa o identificador condition\_variable.|  
|[Método condition\_variable::notify\_all](../Topic/condition_variable::notify_all%20Method.md)|Desbloqueia todos os threads que estão aguardando o objeto `condition_variable`.|  
|[Método condition\_variable::notify\_one](../Topic/condition_variable::notify_one%20Method.md)|Desbloqueia um dos threads que estão aguardando o objeto `condition_variable`.|  
|[Método condition\_variable::wait](../Topic/condition_variable::wait%20Method.md)|Bloqueia um thread.|  
|[Método condition\_variable::wait\_for](../Topic/condition_variable::wait_for%20Method.md)|Bloqueia um thread e define um intervalo de tempo após o qual o thread é desbloqueado.|  
|[Método condition\_variable::wait\_until](../Topic/condition_variable::wait_until%20Method.md)|Bloqueia um thread e define um ponto no tempo máximo em que o thread é desbloqueado.|  
  
## Requisitos  
 **Cabeçalho:** condition\_variable  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< condition\_variable \>](../standard-library/condition-variable.md)