---
title: "Estrutura IResourceManager | Microsoft Docs"
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
  - "concrtrm/concurrency::IResourceManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura IResourceManager"
ms.assetid: 3dd5ec2c-fe53-4121-ae77-1bc1d1167ff4
caps.latest.revision: 20
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura IResourceManager
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Uma interface para o Gerenciador de Recursos de tempo de execução de simultaneidade.  Esta é a interface pelos agendadores que se comunicam com o Gerenciador de Recursos.  
  
## Sintaxe  
  
```  
struct IResourceManager;  
```  
  
## Membros  
  
### Enumerações públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Enumeração IResourceManager::OSVersion](../Topic/IResourceManager::OSVersion%20Enumeration.md)|Um tipo enumerado que representa a versão do sistema operacional.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método IResourceManager::CreateNodeTopology](../Topic/IResourceManager::CreateNodeTopology%20Method.md)|O presentes somente em construções de depuração de tempo de execução, esse é um gancho de teste criado para facilitar teste do Gerenciador de Recursos em topologias de variação de hardware, sem exigir que o hardware real correspondentes a configuração.  Com construções de varejo de tempo de execução, esse método retornará sem executar nenhuma ação.|  
|[Método IResourceManager::GetAvailableNodeCount](../Topic/IResourceManager::GetAvailableNodeCount%20Method.md)|Retorna o número de nós disponíveis para o Gerenciador de Recursos.|  
|[Método IResourceManager::GetFirstNode](../Topic/IResourceManager::GetFirstNode%20Method.md)|Retorna o primeiro nó na ordem de enumeração como definido pelo Gerenciador de Recursos.|  
|[Método IResourceManager::Reference](../Topic/IResourceManager::Reference%20Method.md)|Incrementa a contagem de referência na instância do Gerenciador de Recursos.|  
|[Método IResourceManager::RegisterScheduler](../Topic/IResourceManager::RegisterScheduler%20Method.md)|Registra um agendador com o Gerenciador de Recursos.  Uma vez que o agendador está registrado, deve se comunicar com o Gerenciador de Recursos usando a interface de `ISchedulerProxy` que é retornada.|  
|[Método IResourceManager::Release](../Topic/IResourceManager::Release%20Method.md)|Diminui a contagem de referência na instância do Gerenciador de Recursos.  O Gerenciador de Recursos é destruído na contagem de referência da `0`.|  
  
## Comentários  
 Use a função de [CreateResourceManager](../Topic/CreateResourceManager%20Function.md) para obter uma interface para a instância do Gerenciador de Recursos singleton.  O método incrementa a contagem de referência no Gerenciador de Recursos, e você deve chamar o método de [IResourceManager::Release](../Topic/IResourceManager::Release%20Method.md) para liberar a referência ao concluir ao Gerenciador de Recursos.  Normalmente, cada agendador que você cria invocará esse método durante a criação, e libera a referência ao Gerenciador de Recursos depois que fechou.  
  
## Hierarquia de Herança  
 `IResourceManager`  
  
## Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
## Consulte também  
 [Namespace Concurrency](../../../parallel/concrt/reference/concurrency-namespace.md)   
 [Estrutura ISchedulerProxy](../../../parallel/concrt/reference/ischedulerproxy-structure.md)   
 [Estrutura IScheduler](../../../parallel/concrt/reference/ischeduler-structure.md)