---
title: Estrutura IResourceManager
ms.date: 03/27/2019
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
helpviewer_keywords:
- IResourceManager structure
ms.assetid: 3dd5ec2c-fe53-4121-ae77-1bc1d1167ff4
ms.openlocfilehash: 7ce5b07f5eb4272db1b00b7f0105b790ddbb28fe
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142979"
---
# <a name="iresourcemanager-structure"></a>Estrutura IResourceManager

Uma interface para o Gerenciador de recursos do Tempo de Execução de Simultaneidade. Essa é a interface pela qual os agendadores se comunicam com o Gerenciador de recursos.

## <a name="syntax"></a>Sintaxe

```cpp
struct IResourceManager;
```

## <a name="members"></a>Membros

### <a name="public-enumerations"></a>Enumerações Públicas

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IResourceManager:: OSVersion](#osversion)|Um tipo enumerado que representa a versão do sistema operacional.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IResourceManager::CreateNodeTopology](#createnodetopology)|Presente apenas em compilações de depuração do tempo de execução, esse método é um gancho de teste projetado para facilitar o teste do Gerenciador de recursos em diferentes topologias de hardware, sem a necessidade de hardware real que corresponda à configuração. Com as compilações de varejo do tempo de execução, esse método retornará sem executar nenhuma ação.|
|[IResourceManager::GetAvailableNodeCount](#getavailablenodecount)|Retorna o número de nós disponíveis para o Gerenciador de recursos.|
|[IResourceManager::GetFirstNode](#getfirstnode)|Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.|
|[IResourceManager:: referência](#reference)|Incrementa a contagem de referência na instância do Gerenciador de recursos.|
|[IResourceManager::RegisterScheduler](#registerscheduler)|Registra um Agendador com o Gerenciador de recursos. Depois que o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando a interface `ISchedulerProxy` que é retornada.|
|[IResourceManager:: versão](#release)|Decrementa a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência vai para `0`.|

## <a name="remarks"></a>Comentários

Use a função [CreateResourceManager](concurrency-namespace-functions.md) para obter uma interface para a instância do Gerenciador de recursos singleton. O método incrementa uma contagem de referência no Gerenciador de recursos e você deve invocar o método [IResourceManager:: Release](#release) para liberar a referência quando terminar com o Resource Manager. Normalmente, cada Agendador que você criar invocará esse método durante a criação e liberará a referência ao Gerenciador de recursos depois que ele for desligado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IResourceManager`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="createnodetopology"></a>Método IResourceManager:: CreateNodeTopology

Presente apenas em compilações de depuração do tempo de execução, esse método é um gancho de teste projetado para facilitar o teste do Gerenciador de recursos em diferentes topologias de hardware, sem a necessidade de hardware real que corresponda à configuração. Com as compilações de varejo do tempo de execução, esse método retornará sem executar nenhuma ação.

```cpp
virtual void CreateNodeTopology(
    unsigned int nodeCount,
    _In_reads_(nodeCount) unsigned int* pCoreCount,
    _In_reads_opt_(nodeCount) unsigned int** pNodeDistance,
    _In_reads_(nodeCount) unsigned int* pProcessorGroups) = 0;
```

### <a name="parameters"></a>Parâmetros

*nodeCount*<br/>
O número de nós de processador sendo simulados.

*pCoreCount*<br/>
Uma matriz que especifica o número de núcleos em cada nó.

*pNodeDistance*<br/>
Uma matriz que especifica a distância do nó entre dois nós. Esse parâmetro pode ter o valor `NULL`.

*pProcessorGroups*<br/>
Uma matriz que especifica o grupo de processadores ao qual cada nó pertence.

### <a name="remarks"></a>Comentários

[invalid_argument](../../../standard-library/invalid-argument-class.md) será gerada se o parâmetro `nodeCount` tiver o valor `0` foi passado ou se o parâmetro `pCoreCount` tiver o valor `NULL`.

[invalid_operation](invalid-operation-class.md) será gerada se esse método for chamado enquanto outros agendadores existirem no processo.

## <a name="getavailablenodecount"></a>Método IResourceManager:: GetAvailableNodeCount

Retorna o número de nós disponíveis para o Gerenciador de recursos.

```cpp
virtual unsigned int GetAvailableNodeCount() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número de nós disponíveis para o Gerenciador de recursos.

## <a name="getfirstnode"></a>Método IResourceManager:: GetFirstNode

Retorna o primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.

```cpp
virtual ITopologyNode* GetFirstNode() const = 0;
```

### <a name="return-value"></a>Valor retornado

O primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de recursos.

## <a name="osversion"></a>Enumeração IResourceManager:: OSVersion

Um tipo enumerado que representa a versão do sistema operacional.

```cpp
enum OSVersion;
```

## <a name="reference"></a>Método IResourceManager:: Reference

Incrementa a contagem de referência na instância do Gerenciador de recursos.

```cpp
virtual unsigned int Reference() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência resultante.

## <a name="registerscheduler"></a>Método IResourceManager:: RegisterScheduler

Registra um Agendador com o Gerenciador de recursos. Depois que o Agendador é registrado, ele deve se comunicar com o Gerenciador de recursos usando a interface `ISchedulerProxy` que é retornada.

```cpp
virtual ISchedulerProxy *RegisterScheduler(
    _Inout_ IScheduler* pScheduler,
    unsigned int version) = 0;
```

### <a name="parameters"></a>Parâmetros

*pScheduler*<br/>
Uma interface `IScheduler` para o Agendador a ser registrado.

*version*<br/>
A versão da interface de comunicação que o Agendador está usando para se comunicar com o Gerenciador de recursos. O uso de uma versão permite que o Gerenciador de recursos evolua a interface de comunicação, permitindo que os agendadores obtenham acesso a recursos mais antigos. Os agendadores que desejam usar os recursos do Resource Manager presentes no Visual Studio 2010 devem usar a versão `CONCRT_RM_VERSION_1`.

### <a name="return-value"></a>Valor retornado

A interface de `ISchedulerProxy` que o Gerenciador de recursos associou ao seu Agendador. Seu Agendador deve usar essa interface para se comunicar com o Gerenciador de recursos deste ponto em diante.

### <a name="remarks"></a>Comentários

Use este método para iniciar a comunicação com o Gerenciador de recursos. O método associa a interface de `IScheduler` para o Agendador com uma interface de `ISchedulerProxy` e a entrega para você. Você pode usar a interface retornada para solicitar recursos de execução para uso por seu Agendador ou para assinar threads com o Gerenciador de recursos. O Gerenciador de recursos usará elementos de política da política do Agendador retornada pelo método [IScheduler:: GetPolicy](ischeduler-structure.md#getpolicy) para determinar que tipo de threads o Agendador precisará para executar o trabalho. Se sua chave de política de `SchedulerKind` tiver o valor `UmsThreadDefault` e o valor for lido de volta da política como o valor `UmsThreadDefault`, a interface `IScheduler` passada para o método deverá ser uma interface `IUMSScheduler`.

O método gera uma exceção `invalid_argument` se o parâmetro `pScheduler` tiver o valor `NULL` ou se o parâmetro `version` não for uma versão válida para a interface de comunicação.

## <a name="release"></a>Método IResourceManager:: Release

Decrementa a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de recursos é destruído quando sua contagem de referência vai para `0`.

```cpp
virtual unsigned int Release() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência resultante.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura ISchedulerProxy](ischedulerproxy-structure.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)
