---
title: Estrutura IResourceManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 20
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: 2d054bd632db90708d90fe8d791965b47f713493
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="iresourcemanager-structure"></a>Estrutura IResourceManager
Uma interface para o Gerenciador de recursos do tempo de execução de simultaneidade. Essa é a interface pela qual agendadores se comunicar com o Gerenciador de recursos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IResourceManager;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-enumerations"></a>Enumerações públicas  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Iresourcemanager:: osversion](#osversion)|Um tipo enumerado que representa a versão do sistema operacional.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Createnodetopology](#createnodetopology)|Presente somente no modo de depuração compilações do tempo de execução, esse método é um gancho de teste criado para facilitar os testes do Gerenciador de recursos em diferentes topologias de hardware, sem a necessidade de correspondência a configuração de hardware real. Com compilações para venda do tempo de execução, esse método retornará sem executar nenhuma ação.|  
|[Getavailablenodecount](#getavailablenodecount)|Retorna o número de nós disponíveis para o Gerenciador de recursos.|  
|[Getfirstnode](#getfirstnode)|Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.|  
|[Iresourcemanager](#reference)|Incrementa a contagem de referência na instância do Gerenciador de recursos.|  
|[Registerscheduler](#registerscheduler)|Registra um agendador com o Gerenciador de recursos. Quando o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando o `ISchedulerProxy` interface é retornado.|  
|[Iresourcemanager](#release)|Diminui a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência vai para `0`.|  
  
## <a name="remarks"></a>Comentários  
 Use o [CreateResourceManager](concurrency-namespace-functions.md) função para obter uma interface para a instância do Gerenciador de recursos de singleton. O método incrementa uma contagem de referência no Gerenciador de recursos, e você deve chamar o [Iresourcemanager](#release) método para liberar a referência quando terminar com o Gerenciador de recursos. Normalmente, cada Agendador que você criar será invocar esse método durante a criação e liberar a referência ao Gerenciador de recursos após desligar.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IResourceManager`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="createnodetopology"></a>Método Createnodetopology  
 Presente somente no modo de depuração compilações do tempo de execução, esse método é um gancho de teste criado para facilitar os testes do Gerenciador de recursos em diferentes topologias de hardware, sem a necessidade de correspondência a configuração de hardware real. Com compilações para venda do tempo de execução, esse método retornará sem executar nenhuma ação.  
  
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
 [invalid_argument](../../../standard-library/invalid-argument-class.md) será lançada se o parâmetro `nodeCount` tem o valor `0` foi passado, ou se o parâmetro `pCoreCount` tem o valor `NULL`.  
  
 [invalid_operation](invalid-operation-class.md) será lançada se esse método é chamado, enquanto outros agendadores existem no processo.  
  
##  <a name="getavailablenodecount"></a>Método Getavailablenodecount  
 Retorna o número de nós disponíveis para o Gerenciador de recursos.  
  
```
virtual unsigned int GetAvailableNodeCount() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de nós disponíveis para o Gerenciador de recursos.  
  
##  <a name="getfirstnode"></a>Método Getfirstnode  
 Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.  
  
```
virtual ITopologyNode* GetFirstNode() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.  
  
##  <a name="iresourcemanager__osversion"></a>Enumeração iresourcemanager:: osversion  
 Um tipo enumerado que representa a versão do sistema operacional.  
  
```
enum OSVersion;
```  
  
##  <a name="reference"></a>Método Iresourcemanager::  
 Incrementa a contagem de referência na instância do Gerenciador de recursos.  
  
```
virtual unsigned int Reference() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência resultante.  
  
##  <a name="registerscheduler"></a>Método Registerscheduler  
 Registra um agendador com o Gerenciador de recursos. Quando o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando o `ISchedulerProxy` interface é retornado.  
  
```
virtual ISchedulerProxy *RegisterScheduler(
    _Inout_ IScheduler* pScheduler,
    unsigned int version) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pScheduler`  
 Um `IScheduler` interface para o Agendador a ser registrado.  
  
 `version`  
 A versão da interface de comunicação que o Agendador está usando para se comunicar com o Gerenciador de recursos. Usando uma versão permite que o Gerenciador de recursos para desenvolver a interface de comunicação permitindo agendadores obter acesso a recursos mais antigos para. Agendadores que deseja usar os recursos do Gerenciador de recursos presentes no Visual Studio 2010 devem usar a versão `CONCRT_RM_VERSION_1`.  
  
### <a name="return-value"></a>Valor de retorno  
 O `ISchedulerProxy` o Gerenciador de recursos associado com o Agendador de interface. O Agendador deve usar essa interface para se comunicar com o Gerenciador de recursos a partir deste ponto em.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para iniciar a comunicação com o Gerenciador de recursos. O método associa o `IScheduler` interface para o Agendador com um `ISchedulerProxy` interface e mãos-los de volta para você. Você pode usar a interface retornada para solicitar os recursos de execução para uso pelo seu Agendador ou assinar threads com o Gerenciador de recursos. O Gerenciador de recursos será usar elementos de diretiva da política de Agendador retornado pelo [Getpolicy](ischeduler-structure.md#getpolicy) método para determinar que tipo de threads que o Agendador precisa executar o trabalho. Se seu `SchedulerKind` chave de política tem o valor `UmsThreadDefault` e o valor é lido novamente a política como o valor `UmsThreadDefault`, o `IScheduler` passado para o método de interface deve ser um `IUMSScheduler` interface.  
  
 O método lança um `invalid_argument` exceção se o parâmetro `pScheduler` tem o valor `NULL` ou se o parâmetro `version` não é uma versão válida para a interface de comunicação.  
  
##  <a name="release"></a>Método Iresourcemanager::  
 Diminui a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência vai para `0`.  
  
```
virtual unsigned int Release() = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de referência resultante.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura ISchedulerProxy](ischedulerproxy-structure.md)   
 [Estrutura IScheduler](ischeduler-structure.md)

