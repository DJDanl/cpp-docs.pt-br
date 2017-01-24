---
title: "classe da chamada | Microsoft Docs"
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
  - "agents/concurrency::call"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe da chamada"
ms.assetid: 1521970a-1e9c-4b0c-a681-d18e40976f49
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# classe da chamada
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um bloco da mensagem de `call` é uma origem, várias `target_block` ordenado que invoca uma função especificada ao receber uma mensagem.  
  
## Sintaxe  
  
```  
template<  
   class _Type,  
   class _FunctorType = std::tr1::function<void(_Type const&)>  
>  
class call : public target_block<multi_link_registry<ISource<_Type>>>;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de carga útil de mensagens propagadas a esse bloco.  
  
 `_FunctorType`  
 A assinatura das funções que esse bloco pode aceitar.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor call::call](../Topic/call::call%20Constructor.md)|Sobrecarregado.  Constrói um bloco da mensagem de `call` .|  
|[Destruidor call::~call](../Topic/call::~call%20Destructor.md)|Destrói o bloco da mensagem de `call` .|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método call::process\_input\_messages](../Topic/call::process_input_messages%20Method.md)|Executa a função de chamada em mensagens de entrada.|  
|[Método call::process\_message](../Topic/call::process_message%20Method.md)|Processa uma mensagem que é aceita por esse bloco da mensagem de `call` .|  
|[Método call::propagate\_message](../Topic/call::propagate_message%20Method.md)|Passa de forma assíncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `call` .  É invocado pelo método de `propagate` , quando chamado por um bloco de origem.|  
|[Método call::send\_message](../Topic/call::send_message%20Method.md)|Passa de forma síncrona uma mensagem de um bloco de `ISource` a esse bloco da mensagem de `call` .  É invocado pelo método de `send` , quando chamado por um bloco de origem.|  
|[Método call::supports\_anonymous\_source](../Topic/call::supports_anonymous_source%20Method.md)|Substitui o método de `supports_anonymous_source` para indicar que esse bloco pode aceitar as mensagens são oferecidas a ele por uma origem que não seja vinculada. \(Substitui [ITarget::supports\_anonymous\_source](../Topic/ITarget::supports_anonymous_source%20Method.md).\)|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 [ITarget](../../../parallel/concrt/reference/itarget-class.md)  
  
 [target\_block](../../../parallel/concrt/reference/target-block-class.md)  
  
 `call`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe transformer](../../../parallel/concrt/reference/transformer-class.md)