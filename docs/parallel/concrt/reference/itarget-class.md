---
title: "Classe ITarget | Microsoft Docs"
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
  - "agents/concurrency::ITarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe ITarget"
ms.assetid: 5678db25-112a-4f72-be13-42e16b67c48b
caps.latest.revision: 22
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe ITarget
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A classe de `ITarget` é a interface para todos os blocos de destino.  Os blocos de destino consomem as mensagens são oferecidas a elas por blocos de `ISource` .  
  
## Sintaxe  
  
```  
template<  
   class _Type  
>  
class ITarget;  
```  
  
#### Parâmetros  
 `_Type`  
 O tipo de dados de carga nas mensagens aceitas pelo bloco de destino.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`filter_method`|A assinatura de qualquer método usado pelo bloco que retorna um valor de `bool` para determinar se uma mensagem oferecida deve ser aceita.|  
|`type`|Um alias de tipo para `_Type`.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Destruidor ITarget::~ITarget](../Topic/ITarget::~ITarget%20Destructor.md)|Destrói o objeto `ITarget`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ITarget::propagate](../Topic/ITarget::propagate%20Method.md)|Quando substituído em uma classe derivada, passa de forma assíncrona uma mensagem de um bloco de origem para este bloco de destino.|  
|[Método ITarget::send](../Topic/ITarget::send%20Method.md)|Quando substituído em uma classe derivada, de forma síncrona transmite uma mensagem para o bloco de destino.|  
|[Método ITarget::supports\_anonymous\_source](../Topic/ITarget::supports_anonymous_source%20Method.md)|Quando substituído em uma classe derivada, retorna retificam ou false se o bloco de mensagem aceita as mensagens são oferecidas por uma fonte que não está vinculada a ele.  Se o método substituído retorna `true`, o destino não pode adiar uma mensagem oferecida, porque o consumo de uma mensagem adiada requer mais tarde origem a ser identificado no Registro do link de sourse.|  
  
### Métodos Protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ITarget::link\_source](../Topic/ITarget::link_source%20Method.md)|Quando substituído em uma classe derivada, links um bloco de origem especificado para esse bloco de `ITarget` .|  
|[Método ITarget::unlink\_source](../Topic/ITarget::unlink_source%20Method.md)|Quando substituído em uma classe derivada, unlinks um bloco de origem especificado deste bloco de `ITarget` .|  
|[Método ITarget::unlink\_sources](../Topic/ITarget::unlink_sources%20Method.md)|Quando substituído em uma classe derivada, unlinks todos os blocos de origem deste bloco de `ITarget` .|  
  
## Comentários  
 Para obter mais informações, consulte [Blocos de mensagens assíncronos](../../../parallel/concrt/asynchronous-message-blocks.md).  
  
## Hierarquia de Herança  
 `ITarget`  
  
## Requisitos  
 **Cabeçalho:** agents.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Classe ISource](../../../parallel/concrt/reference/isource-class.md)