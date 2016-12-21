---
title: "Estrutura DispatchState | Microsoft Docs"
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
  - "concrtrm/concurrency::DispatchState"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura DispatchState"
ms.assetid: 8c52546e-1650-48a0-985f-7e4a0fc26a90
caps.latest.revision: 17
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura DispatchState
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `DispatchState` é usada para transferir o estado para o método de `IExecutionContext::Dispatch` .  Descreve as condições sob as quais o método de `Dispatch` é invocado em uma interface de `IExecutionContext` .  
  
## Sintaxe  
  
```  
struct DispatchState;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor DispatchState::DispatchState](../Topic/DispatchState::DispatchState%20Constructor.md)|Cria um novo objeto de `DispatchState` .|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados DispatchState::m\_dispatchStateSize](../Topic/DispatchState::m_dispatchStateSize%20Data%20Member.md)|Tamanho dessa estrutura, que é usada para o controle de versão.|  
|[Membro de dados DispatchState::m\_fIsPreviousContextAsynchronouslyBlocked](../Topic/DispatchState::m_fIsPreviousContextAsynchronouslyBlocked%20Data%20Member.md)|Informa se esse contexto inseriu o método de `Dispatch` como o contexto anterior bloqueado de forma assíncrona.  Isto só é usado em UMS que agendarem o contexto, e definido como o valor `0` para todos outros contextos de execução.|  
|[Membro de dados DispatchState::m\_reserved](../Topic/DispatchState::m_reserved%20Data%20Member.md)|Bit reservadas para transmitir futuro de informações.|  
  
## Hierarquia de Herança  
 `DispatchState`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Método IExecutionContext::Dispatch](../Topic/IExecutionContext::Dispatch%20Method.md)