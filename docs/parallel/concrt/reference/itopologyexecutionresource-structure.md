---
title: "Estrutura ITopologyExecutionResource | Microsoft Docs"
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
  - "concrtrm/concurrency::ITopologyExecutionResource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ITopologyExecutionResource"
ms.assetid: e36756f7-4cd9-4fa6-ba60-23fea58ef2bf
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ITopologyExecutionResource
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma interface para um recurso de execução conforme definido pelo Gerenciador de Recursos.  
  
## Sintaxe  
  
```  
struct ITopologyExecutionResource;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ITopologyExecutionResource::GetId](../Topic/ITopologyExecutionResource::GetId%20Method.md)|Retorna o identificador exclusivo do Gerenciador de Recursos para esse recurso de execução.|  
|[Método ITopologyExecutionResource::GetNext](../Topic/ITopologyExecutionResource::GetNext%20Method.md)|Retorna uma interface para o próximo recurso de execução em ordem da enumeração.|  
  
## Comentários  
 Esta interface é superutilizada normalmente para percorrer a topologia do sistema conforme indicado pelo Gerenciador de Recursos.  
  
## Hierarquia de Herança  
 `ITopologyExecutionResource`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)