---
title: "Classe cancellation_token | Microsoft Docs"
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
  - "pplcancellation_token/concurrency::cancellation_token"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe cancellation_token"
ms.assetid: 2787df2b-e9d3-440e-bfd0-841a46a9835f
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe cancellation_token
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `cancellation_token` representa a capacidade para determinar se qualquer operação teve solicitação de cancelamento.  Um token determinado pode ser associado com um `task_group`, `structured_task_group`, ou `task` para fornecer cancelamento implícito.  Também pode ser pesquisado para cancelamento ou ter um retorno de chamada registrado para se e quando o `cancellation_token_source` associado for cancelado.  
  
## Sintaxe  
  
```  
class cancellation_token;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor cancellation\_token::cancellation\_token](../Topic/cancellation_token::cancellation_token%20Constructor.md)||  
|[Destruidor cancellation\_token::~cancellation\_token](../Topic/cancellation_token::~cancellation_token%20Destructor.md)||  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método cancellation\_token::deregister\_callback](../Topic/cancellation_token::deregister_callback%20Method.md)|Remove um retorno de chamada registrado anteriormente pelo método de `register` baseado no objeto de `cancellation_token_registration` retornado no momento do registro.|  
|[Método cancellation\_token::is\_cancelable](../Topic/cancellation_token::is_cancelable%20Method.md)|Retorna uma indicação se este token pode ser cancelado ou não.|  
|[Método cancellation\_token::is\_canceled](../Topic/cancellation_token::is_canceled%20Method.md)|Retorna `true` se o símbolo foi cancelado.|  
|[Método cancellation\_token::none](../Topic/cancellation_token::none%20Method.md)|Retorna um token de cancelamento que nunca pode estar sujeito ao cancelamento.|  
|[Método cancellation\_token::register\_callback](../Topic/cancellation_token::register_callback%20Method.md)|Registra um função de retorno de chamada com o símbolo.  Se e quando o token for cancelado, o retorno de chamada será feito.  Observe que se o token já tiver sido cancelado no ponto onde esse método é chamado, o retorno de chamada será feito imediatamente e de forma síncrona.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador cancellation\_token::operator\!\=](../Topic/cancellation_token::operator!=%20Operator.md)||  
|[Operador cancellation\_token::operator\=](../Topic/cancellation_token::operator=%20Operator.md)||  
|[Operador cancellation\_token::operator\=\=](../Topic/cancellation_token::operator==%20Operator.md)||  
  
## Hierarquia de Herança  
 `cancellation_token`  
  
## Requisitos  
 **Cabeçalho:** pplcancellation\_token.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)