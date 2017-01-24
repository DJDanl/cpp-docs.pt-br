---
title: "Classe message | Microsoft Docs"
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
  - "agents/concurrency::message"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de mensagem"
ms.assetid: 3e1f3505-6c0c-486c-8191-666d0880ec62
caps.latest.revision: 21
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe message
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

O envelope básico de mensagem que contém a carga de dados que está sendo passada entre blocos da mensagem.  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class message : public ::Concurrency::details::_Runtime_object;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de dados de carga da mensagem.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`type`|Um alias de tipo para `_Type`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor message::message](../Topic/message::message%20Constructor.md)|Sobrecarregado.  Constrói um objeto `message`.|  
|[Destruidor message::~message](../Topic/message::~message%20Destructor.md)|Destrói o objeto `message`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método message::add\_ref](../Topic/message::add_ref%20Method.md)|Adiciona à contagem de referência do objeto de `message` .  Usado para os blocos de mensagem que precisam a contagem de referência de determinar o tempo de vida da mensagem.|  
|[Método message::msg\_id](../Topic/message::msg_id%20Method.md)|Retorna a ID do objeto de `message` .|  
|[Método message::remove\_ref](../Topic/message::remove_ref%20Method.md)|Subtrai de contagem de referência do objeto de `message` .  Usado para os blocos de mensagem que precisam a contagem de referência de determinar o tempo de vida da mensagem.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados message::payload](../Topic/message::payload%20Data%20Member.md)|A carga útil do objeto de `message` .|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 `message`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)