---
title: "Classe condition_variable_any | Microsoft Docs"
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
  - "condition_variable/std::condition_variable_any"
dev_langs: 
  - "C++"
ms.assetid: d8afe5db-1561-4ec2-8e85-21ea03ee4321
caps.latest.revision: 15
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe condition_variable_any
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use a classe `condition_variable_any` para aguardar um evento que tenha qualquer tipo `mutex`.  
  
## Sintaxe  
  
```  
class condition_variable_any;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor condition\_variable\_any::condition\_variable\_any](../Topic/condition_variable_any::condition_variable_any%20Constructor.md)|Constrói um objeto `condition_variable_any`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método condition\_variable\_any::notify\_all](../Topic/condition_variable_any::notify_all%20Method.md)|Desbloqueia todos os threads que estão aguardando o objeto `condition_variable_any`.|  
|[Método condition\_variable\_any::notify\_one](../Topic/condition_variable_any::notify_one%20Method.md)|Desbloqueia um dos threads que estão aguardando o objeto `condition_variable_any`.|  
|[Método condition\_variable\_any::wait](../Topic/condition_variable_any::wait%20Method.md)|Bloqueia um thread.|  
|[Método condition\_variable\_any::wait\_for](../Topic/condition_variable_any::wait_for%20Method.md)|Bloqueia um thread e define um intervalo de tempo após o qual o thread é desbloqueado.|  
|[Método condition\_variable\_any::wait\_until](../Topic/condition_variable_any::wait_until%20Method.md)|Bloqueia um thread e define um ponto no tempo máximo em que o thread é desbloqueado.|  
  
## Requisitos  
 **Cabeçalho:** condition\_variable  
  
 std de **Namespace:**  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< condition\_variable \>](../standard-library/condition-variable.md)