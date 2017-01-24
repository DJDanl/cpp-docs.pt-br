---
title: "scheduler_ptr Estrutura (Tempo de Execu&#231;&#227;o de Simultaneidade) | Microsoft Docs"
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
  - "pplinterface/concurrency::scheduler_ptr"
dev_langs: 
  - "C++"
ms.assetid: e88c84af-c306-476d-aef1-f42a0fa0a80f
caps.latest.revision: 8
caps.handback.revision: 1
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# scheduler_ptr Estrutura (Tempo de Execu&#231;&#227;o de Simultaneidade)
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Representa um ponteiro para um agendador.  Essa classe existe para permitir a especificação de um tempo de vida compartilhado usando o shared\_ptr ou apenas uma referência simples usando o ponteiro bruto.  
  
## Sintaxe  
  
```  
struct scheduler_ptr;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor scheduler\_ptr::scheduler\_ptr \(Tempo de Execução de Simultaneidade\)](../Topic/scheduler_ptr::scheduler_ptr%20Constructor%20\(Concurrency%20Runtime\).md)|Sobrecarregado.  Cria um ponteiro de agendador de shared\_ptr para o agendador|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método scheduler\_ptr::get \(Tempo de Execução de Simultaneidade\)](../Topic/scheduler_ptr::get%20Method%20\(Concurrency%20Runtime\).md)|Retorna o ponteiro bruto ao agendador|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador scheduler\_ptr::operator bool \(tempo de execução de simultaneidade\)](../Topic/scheduler_ptr::operator%20bool%20Operator%20\(Concurrency%20Runtime\).md)|Testa se o ponteiro de agendador é não\-nulo|  
|[Operador scheduler\_ptr::operator\-\> \(tempo de execução de simultaneidade\)](../Topic/scheduler_ptr::operator-%3E%20Operator%20\(Concurrency%20Runtime\).md)|Atua como um ponteiro|  
  
## Hierarquia de Herança  
 `scheduler_ptr`  
  
## Requisitos  
 **Cabeçalho:** pplinterface.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)