---
title: "Classe cancellation_token_source | Microsoft Docs"
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
  - "pplcancellation_token/concurrency::cancellation_token_source"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cancellation_token_source"
ms.assetid: 3548b1a0-12b0-4334-95db-4bf57141c066
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe cancellation_token_source
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `cancellation_token_source` representa a capacidade para cancelar qualquer operação anulável.  
  
## Sintaxe  
  
```  
class cancellation_token_source;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor cancellation\_token\_source::cancellation\_token\_source](../Topic/cancellation_token_source::cancellation_token_source%20Constructor.md)|Sobrecarregado.  Constrói um novo `cancellation_token_source`.  A fonte pode ser usada para sinalizar o cancelamento de qualquer operação anulável.|  
|[Destruidor cancellation\_token\_source::~cancellation\_token\_source](../Topic/cancellation_token_source::~cancellation_token_source%20Destructor.md)||  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método cancellation\_token\_source::cancel](../Topic/cancellation_token_source::cancel%20Method.md)|Cancela o token.  Qualquer `task_group`, `structured_task_group` ou `task` que usa o token será cancelado nessa chamada e será gerada uma exceção no próximo ponto de interrupção.|  
|[Método cancellation\_token\_source::create\_linked\_source](../Topic/cancellation_token_source::create_linked_source%20Method.md)|Sobrecarregado.  Cria um `cancellation_token_source` que é cancelado quando o token fornecido é cancelado.|  
|[Método cancellation\_token\_source::get\_token](../Topic/cancellation_token_source::get_token%20Method.md)|Retorna um token de cancelamento associado a esta origem.  O token retornado pode ser monitorado para o cancelamento ou fornecer um retorno de chamada, se e quando o cancelamento ocorrer.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador cancellation\_token\_source::operator\!\=](../Topic/cancellation_token_source::operator!=%20Operator.md)||  
|[Operador cancellation\_token\_source::operator\=](../Topic/cancellation_token_source::operator=%20Operator.md)||  
|[Operador cancellation\_token\_source::operator\=\=](../Topic/cancellation_token_source::operator==%20Operator.md)||  
  
## Hierarquia de Herança  
 `cancellation_token_source`  
  
## Requisitos  
 **Cabeçalho:** pplcancellation\_token.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)