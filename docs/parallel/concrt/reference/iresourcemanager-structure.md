---
title: Estrutura IResourceManager | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IResourceManager
- CONCRTRM/concurrency::IResourceManager
- CONCRTRM/concurrency::IResourceManager::IResourceManager::OSVersion
- CONCRTRM/concurrency::IResourceManager::IResourceManager::CreateNodeTopology
- CONCRTRM/concurrency::IResourceManager::IResourceManager::GetAvailableNodeCount
- CONCRTRM/concurrency::IResourceManager::IResourceManager::GetFirstNode
- CONCRTRM/concurrency::IResourceManager::IResourceManager::Reference
- CONCRTRM/concurrency::IResourceManager::IResourceManager::RegisterScheduler
- CONCRTRM/concurrency::IResourceManager::IResourceManager::Release
dev_langs:
- C++
helpviewer_keywords:
- IResourceManager structure
ms.assetid: 3dd5ec2c-fe53-4121-ae77-1bc1d1167ff4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d309e057a8f829b11cc97ad60f3f5d56ff7ecaff
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="iresourcemanager-structure"></a>Estrutura IResourceManager
Uma interface para o Gerenciador de recursos do tempo de execução de simultaneidade. Essa é a interface pela qual os agendadores se comunicar com o Gerenciador de recursos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IResourceManager;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-enumerations"></a>Enumerações públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IResourceManager::OSVersion](#osversion)|Um tipo enumerado que representa a versão do sistema operacional.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IResourceManager::CreateNodeTopology](#createnodetopology)|Presente somente em depuração compilações do tempo de execução, esse método é um gancho de teste desenvolvido para facilitar o teste do Gerenciador de recursos em variáveis de topologias de hardware, sem a necessidade de correspondência a configuração de hardware real. Com compilações para venda do tempo de execução, esse método retornará sem executar nenhuma ação.|  
|[IResourceManager::GetAvailableNodeCount](#getavailablenodecount)|Retorna o número de nós disponíveis para o Gerenciador de recursos.|  
|[IResourceManager::GetFirstNode](#getfirstnode)|Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.|  
|[IResourceManager::Reference](#reference)|Incrementa a contagem de referência na instância do Gerenciador de recursos.|  
|[IResourceManager::RegisterScheduler](#registerscheduler)|Registra um agendador com o Gerenciador de recursos. Quando o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando o `ISchedulerProxy` interface que é retornado.|  
|[IResourceManager::Release](#release)|Diminui a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência chegar a `0`.|  
  
## <a name="remarks"></a>Comentários  
 Use o [CreateResourceManager](concurrency-namespace-functions.md) função para obter uma interface para a instância do Gerenciador de recursos de singleton. O método incrementa a contagem de referência no Gerenciador de recursos, e você deve chamar o [Iresourcemanager](#release) método para liberar a referência ao terminar com o Gerenciador de recursos. Normalmente, cada Agendador que você criar serão invocar esse método durante a criação e liberar a referência para o Gerenciador de recursos, depois que ela é desligada.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IResourceManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="createnodetopology"></a>  Método: Createnodetopology  
 Presente somente em depuração compilações do tempo de execução, esse método é um gancho de teste desenvolvido para facilitar o teste do Gerenciador de recursos em variáveis de topologias de hardware, sem a necessidade de correspondência a configuração de hardware real. Com compilações para venda do tempo de execução, esse método retornará sem executar nenhuma ação.  
  
```
virtual void CreateNodeTopology(
    unsigned int nodeCount,
    _In_reads_(nodeCount) unsigned int* pCoreCount,
    _In_reads_opt_(nodeCount) unsigned int** pNodeDistance,
    _In_reads_(nodeCount) unsigned int* pProcessorGroups) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `nodeCount`  
 O número de nós de processador que está sendo simulada.  
  
 `pCoreCount`  
 Uma matriz que especifica o número de núcleos em cada nó.  
  
 `pNodeDistance`  
 Uma matriz que especifica a distância do nó entre quaisquer dois nós. Esse parâmetro pode ter o valor `NULL`.  
  
 `pProcessorGroups`  
 Uma matriz que especifica o grupo de processador cada nó pertence.  
  
### <a name="remarks"></a>Comentários  
 [invalid_argument](../../../standard-library/invalid-argument-class.md) é gerada se o parâmetro `nodeCount` tem o valor `0` foi passado, ou se o parâmetro `pCoreCount` tem o valor `NULL`.  
  
 [invalid_operation](invalid-operation-class.md) é gerada se esse método é chamado, enquanto outros agendadores existem no processo.  
  
##  <a name="getavailablenodecount"></a>  IResourceManager::GetAvailableNodeCount Method  
 Retorna o número de nós disponíveis para o Gerenciador de recursos.  
  
```
virtual unsigned int GetAvailableNodeCount() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de nós disponíveis para o Gerenciador de recursos.  
  
##  <a name="getfirstnode"></a>  Método: Getfirstnode  
 Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.  
  
```
virtual ITopologyNode* GetFirstNode() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.  
  
##  <a name="iresourcemanager__osversion"></a>  IResourceManager::OSVersion Enumeration  
 Um tipo enumerado que representa a versão do sistema operacional.  
  
```
enum OSVersion;
```  
  
##  <a name="reference"></a>  Método Iresourcemanager::  
 Incrementa a contagem de referência na instância do Gerenciador de recursos.  
  
```
virtual unsigned int Reference() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência resultante.  
  
##  <a name="registerscheduler"></a>  IResourceManager::RegisterScheduler Method  
 Registra um agendador com o Gerenciador de recursos. Quando o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando o `ISchedulerProxy` interface que é retornado.  
  
```
virtual ISchedulerProxy *RegisterScheduler(
    _Inout_ IScheduler* pScheduler,
    unsigned int version) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pScheduler`  
 Um `IScheduler` interface para o Agendador para ser registrado.  
  
 `version`  
 A versão da interface de comunicação que o Agendador está usando para se comunicar com o Gerenciador de recursos. Usando uma versão permite que o Gerenciador de recursos para desenvolver a interface de comunicação permitindo agendadores obter acesso a recursos para mais antigos. Agendadores que deseja usar os recursos do Gerenciador de recursos presentes no Visual Studio 2010 devem usar a versão `CONCRT_RM_VERSION_1`.  
  
### <a name="return-value"></a>Valor de retorno  
 O `ISchedulerProxy` interface o Gerenciador de recursos associado seu Agendador. O Agendador deve usar essa interface para se comunicar com o Gerenciador de recursos a partir deste ponto em.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para iniciar a comunicação com o Gerenciador de recursos. Associa o método de `IScheduler` interface para o Agendador com um `ISchedulerProxy` interface e ponteiros-lo de volta para você. Você pode usar a interface retornada para solicitar recursos de execução para uso pelo seu Agendador ou para inscrever-se com o Gerenciador de recursos de threads. O Gerenciador de recursos usará os elementos da política da política de Agendador retornado pelo [: Getpolicy](ischeduler-structure.md#getpolicy) método para determinar que tipo de threads que o Agendador precisa executar o trabalho. Se seu `SchedulerKind` chave de política tem o valor `UmsThreadDefault` e o valor é lido novamente a política como o valor `UmsThreadDefault`, o `IScheduler` passado para o método de interface deve ser um `IUMSScheduler` interface.  
  
 O método gera uma `invalid_argument` exceção se o parâmetro `pScheduler` tem o valor `NULL` ou se o parâmetro `version` não é uma versão válida para a interface de comunicação.  
  
##  <a name="release"></a>  Método Iresourcemanager:  
 Diminui a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência chegar a `0`.  
  
```
virtual unsigned int Release() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência resultante.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura ISchedulerProxy](ischedulerproxy-structure.md)   
 [Estrutura IScheduler](ischeduler-structure.md)
