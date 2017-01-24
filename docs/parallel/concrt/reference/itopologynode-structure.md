---
title: "Estrutura ITopologyNode | Microsoft Docs"
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
  - "concrtrm/concurrency::ITopologyNode"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ITopologyNode"
ms.assetid: 92e7e032-04f6-4c7c-be36-8f9a35fc4734
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ITopologyNode
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma interface para um nó da topologia conforme definido pelo Gerenciador de Recursos.  Um nó contém um ou mais recursos de execução.  
  
## Sintaxe  
  
```  
struct ITopologyNode;  
```  
  
## Membros  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método ITopologyNode::GetExecutionResourceCount](../Topic/ITopologyNode::GetExecutionResourceCount%20Method.md)|Retorna o número de recursos de execução agrupados neste nó.|  
|[Método ITopologyNode::GetFirstExecutionResource](../Topic/ITopologyNode::GetFirstExecutionResource%20Method.md)|Retorna o primeiro recurso de execução clusterizado neste nó na ordem da enumeração.|  
|[Método ITopologyNode::GetId](../Topic/ITopologyNode::GetId%20Method.md)|Retorna o identificador exclusivo do Gerenciador de Recursos para este nó.|  
|[Método ITopologyNode::GetNext](../Topic/ITopologyNode::GetNext%20Method.md)|Retorna uma interface para o próximo nó da topologia na ordem da enumeração.|  
|[Método ITopologyNode::GetNumaNode](../Topic/ITopologyNode::GetNumaNode%20Method.md)|Retorna o número do nó NUMA atribuído do Windows ao qual este nó do Gerenciador de Recursos pertence.|  
  
## Comentários  
 Esta interface é superutilizada normalmente para percorrer a topologia do sistema conforme indicado pelo Gerenciador de Recursos.  
  
## Hierarquia de Herança  
 `ITopologyNode`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)