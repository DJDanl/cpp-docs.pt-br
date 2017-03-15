---
title: "Classe EventSource | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "event/Microsoft::WRL::EventSource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe EventSource"
ms.assetid: 91f1c072-6af4-44e6-b6d8-ac6d0c688dde
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe EventSource
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um evento.  As funções de membro de EventSource adicionar, remover, e invoca manipuladores de eventos.  
  
## Sintaxe  
  
```  
template<  
   typename TDelegateInterface  
>  
class EventSource;  
```  
  
#### Parâmetros  
 `TDelegateInterface`  
 A interface um representante que representa um manipulador de eventos.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor EventSource::EventSource](../windows/eventsource-eventsource-constructor.md)|Inicializa uma nova instância da classe de EventSource.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método EventSource::Add](../windows/eventsource-add-method.md)|Anexa o manipulador de eventos representado pela interface especificada de delegação ao conjunto de manipuladores de eventos para o objeto atual de EventSource.|  
|[Método EventSource::GetSize](../windows/eventsource-getsize-method.md)|Recupera o número de manipuladores de eventos associados ao objeto atual de EventSource|  
|[Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)|Chama cada manipulador de eventos associado ao objeto atual de EventSource usando os tipos e os argumentos especificados do argumento.|  
|[Método EventSource::Remove](../Topic/EventSource::Remove%20Method.md)|Exclui o manipulador de eventos representado pelo token especificado do registro de eventos do conjunto de manipuladores de eventos associados ao objeto atual de EventSource.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados EventSource::addRemoveLock\_](../windows/eventsource-addremovelock-data-member.md)|Sincronizar o acesso à matriz de [targets\_](../Topic/EventSource::targets_%20Data%20Member.md) ao adicionar, remover, ao ou ao chamar manipuladores de eventos.|  
|[Membro de dados EventSource::targets\_](../Topic/EventSource::targets_%20Data%20Member.md)|Uma matriz de um ou vários manipuladores de eventos.|  
|[Membro de dados EventSource::targetsPointerLock\_](../windows/eventsource-targetspointerlock-data-member.md)|Sincronizar o acesso a membros de dados internos mesmo quando os manipuladores de eventos para este EventSource são adicionados, removidos, ou invocados.|  
  
## Hierarquia de Herança  
 `EventSource`  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)