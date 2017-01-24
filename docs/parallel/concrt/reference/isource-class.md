---
title: "Classe ISource | Microsoft Docs"
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
  - "agents/concurrency::ISource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ISource"
ms.assetid: c7b73463-42f6-4dcc-801a-81379b12d35a
caps.latest.revision: 20
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ISource
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `ISource` é a interface para todos os blocos de origem.  Mensagens de propagação blocos de origem nos blocos de `ITarget` .  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class ISource;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de dados de carga nas mensagens geradas pelo bloco de origem.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`source_type`|Um alias de tipo para `_Type`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Destruidor ISource::~ISource](../Topic/ISource::~ISource%20Destructor.md)|Destrói o objeto `ISource`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ISource::accept](../Topic/ISource::accept%20Method.md)|Quando substituído em uma classe derivada, aceita uma mensagem que é oferecida por esse bloco de `ISource` , transferindo propriedade ao chamador.|  
|[Método ISource::acquire\_ref](../Topic/ISource::acquire_ref%20Method.md)|Quando substituído em uma classe derivada, adquire uma contagem de referência do bloco de `ISource` , para evitar a exclusão.|  
|[Método ISource::consume](../Topic/ISource::consume%20Method.md)|Quando substituído em uma classe derivada, consome uma mensagem oferecida anteriormente por esse bloco de `ISource` e reservada com êxito pelo destino, transferindo propriedade ao chamador.|  
|[Método ISource::link\_target](../Topic/ISource::link_target%20Method.md)|Quando substituído em uma classe derivada, links um bloco de destino a esse bloco de `ISource` .|  
|[Método ISource::release](../Topic/ISource::release%20Method.md)|Quando substituído em uma classe derivada, versões uma reserva com êxito anterior da mensagem.|  
|[Método ISource::release\_ref](../Topic/ISource::release_ref%20Method.md)|Quando substituído em uma classe derivada, versões uma contagem de referência do bloco de `ISource` .|  
|[Método ISource::reserve](../Topic/ISource::reserve%20Method.md)|Quando substituído em uma classe derivada, reservas que uma mensagem oferecida anteriormente por esse bloco de `ISource` .|  
|[Método ISource::unlink\_target](../Topic/ISource::unlink_target%20Method.md)|Quando substituído em uma classe derivada, unlinks um bloco de destino desse bloco de `ISource` , se localizado a ser vinculado anteriormente.|  
|[Método ISource::unlink\_targets](../Topic/ISource::unlink_targets%20Method.md)|Quando substituído em uma classe derivada, unlinks todos os blocos de destino desse bloco de `ISource` .|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 `ISource`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe ITarget](../../../parallel/concrt/reference/itarget-class.md)