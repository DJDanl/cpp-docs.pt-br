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
ms.openlocfilehash: 15e27a586fc039791255c01a053f6a1109183f90
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368183"
---
# <a name="iresourcemanager-structure"></a>Estrutura IResourceManager

Uma interface para o Gerenciador de Recursos do Concurrency Runtime. Esta é a interface pela qual os agendadores se comunicam com o Gerenciador de Recursos.

## <a name="syntax"></a>Sintaxe

```cpp
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
|[Gerenciador de recursos::CreateNodeTopology](#createnodetopology)|Presente apenas em compilações de depuração do tempo de execução, este método é um gancho de teste projetado para facilitar o teste do Gerenciador de Recursos em topologias de hardware variadas, sem exigir que o hardware real corresponda à configuração. Com as compilações de varejo do tempo de execução, este método retornará sem realizar qualquer ação.|
|[Gerenciador de recursos::GetAvailableNodeCount](#getavailablenodecount)|Retorna o número de nós disponíveis para o Gerenciador de Recursos.|
|[Gerenciador de recursos::GetFirstNode](#getfirstnode)|Retorna o primeiro nó em ordem de enumeração conforme definido pelo Gerenciador de recursos.|
|[IResourceManager::Referência](#reference)|Incrementa a contagem de referência na instância do Gerenciador de recursos.|
|[Gerenciador de recursos::Agendador de registros](#registerscheduler)|Registra um agendador junto ao Gerenciador de Recursos. Uma vez que o agendador é registrado, ele `ISchedulerProxy` deve se comunicar com o Gerenciador de Recursos usando a interface que é devolvida.|
|[IResourceManager::Lançamento](#release)|Decreta a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de Recursos é destruído `0`quando sua contagem de referência vai para .|

## <a name="remarks"></a>Comentários

Use a função [CreateResourceManager](concurrency-namespace-functions.md) para obter uma interface na instância do Gerenciador de recursos singleton. O método incrementa uma contagem de referência no Gerenciador de recursos e você deve invocar o método [IResourceManager::Release](#release) para liberar a referência quando terminar com o Gerenciador de recursos. Normalmente, cada agendador criado invocará esse método durante a criação e liberará a referência ao Gerenciador de recursos após o desligamento.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IResourceManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iresourcemanagercreatenodetopology-method"></a><a name="createnodetopology"></a>Gerenciador de recursos::Criarmétodo de nodeTopologia

Presente apenas em compilações de depuração do tempo de execução, este método é um gancho de teste projetado para facilitar o teste do Gerenciador de Recursos em topologias de hardware variadas, sem exigir que o hardware real corresponda à configuração. Com as compilações de varejo do tempo de execução, este método retornará sem realizar qualquer ação.

```cpp
virtual void CreateNodeTopology(
    unsigned int nodeCount,
    _In_reads_(nodeCount) unsigned int* pCoreCount,
    _In_reads_opt_(nodeCount) unsigned int** pNodeDistance,
    _In_reads_(nodeCount) unsigned int* pProcessorGroups) = 0;
```

### <a name="parameters"></a>Parâmetros

*nodeCount*<br/>
O número de nós do processador sendo simulados.

*pCoreCount*<br/>
Uma matriz que especifica o número de núcleos em cada nó.

*pNodeDistance*<br/>
Uma matriz especificando a distância do nó entre os dois nós. Este parâmetro pode ter `NULL`o valor .

*pProcessorGroups*<br/>
Uma matriz que especifica o grupo de processadores a que cada nó pertence.

### <a name="remarks"></a>Comentários

[invalid_argument](../../../standard-library/invalid-argument-class.md) é jogado se `nodeCount` o `0` parâmetro tiver o valor foi `pCoreCount` passado, `NULL`ou se o parâmetro tiver o valor .

[invalid_operation](invalid-operation-class.md) é lançada se esse método for chamado enquanto outros agendadores existem no processo.

## <a name="iresourcemanagergetavailablenodecount-method"></a><a name="getavailablenodecount"></a>Gerenciador de recursos::GetAvailableNodeCount Method

Retorna o número de nós disponíveis para o Gerenciador de Recursos.

```cpp
virtual unsigned int GetAvailableNodeCount() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número de nós disponíveis para o Gerenciador de Recursos.

## <a name="iresourcemanagergetfirstnode-method"></a><a name="getfirstnode"></a>Gerenciador de recursos::getFirstNode Method

Retorna o primeiro nó em ordem de enumeração conforme definido pelo Gerenciador de recursos.

```cpp
virtual ITopologyNode* GetFirstNode() const = 0;
```

### <a name="return-value"></a>Valor retornado

O primeiro nó na ordem de enumeração, conforme definido pelo Gerenciador de Recursos.

## <a name="iresourcemanagerosversion-enumeration"></a><a name="osversion"></a>IResourceManager::Enumeração de versão ossitiva

Um tipo enumerado que representa a versão do sistema operacional.

```cpp
enum OSVersion;
```

## <a name="iresourcemanagerreference-method"></a><a name="reference"></a>IResourceManager::Método de referência

Incrementa a contagem de referência na instância do Gerenciador de recursos.

```cpp
virtual unsigned int Reference() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência resultante.

## <a name="iresourcemanagerregisterscheduler-method"></a><a name="registerscheduler"></a>Gerenciador de recursos::Método de agendamento de registro

Registra um agendador junto ao Gerenciador de Recursos. Uma vez que o agendador é registrado, ele `ISchedulerProxy` deve se comunicar com o Gerenciador de Recursos usando a interface que é devolvida.

```cpp
virtual ISchedulerProxy *RegisterScheduler(
    _Inout_ IScheduler* pScheduler,
    unsigned int version) = 0;
```

### <a name="parameters"></a>Parâmetros

*pScheduler*<br/>
Uma `IScheduler` interface para o agendador a ser registrado.

*versão*<br/>
A versão da interface de comunicação que o agendador está usando para se comunicar com o Gerenciador de Recursos. O uso de uma versão permite que o Gerenciador de recursos evolua a interface de comunicação, permitindo que os agendadores obtenham acesso a recursos mais antigos. Os agendadores que desejam usar recursos do Gerenciador de Recursos `CONCRT_RM_VERSION_1`presentes no Visual Studio 2010 devem usar a versão .

### <a name="return-value"></a>Valor retornado

A `ISchedulerProxy` interface que o Gerenciador de Recursos associou ao seu agendador. Seu agendador deve usar essa interface para se comunicar com o Resource Manager a partir de agora.

### <a name="remarks"></a>Comentários

Use este método para iniciar a comunicação com o Gerenciador de Recursos. O método `IScheduler` associa a interface do `ISchedulerProxy` seu agendador com uma interface e devolve-a a você. Você pode usar a interface retornada para solicitar recursos de execução para uso pelo seu agendador ou para assinar threads com o Gerenciador de recursos. O Gerenciador de recursos usará elementos de diretiva da diretiva de agendador retornado pelo método [IScheduler::GetPolicy](ischeduler-structure.md#getpolicy) para determinar que tipo de threads o agendador precisará para executar o trabalho. Se `SchedulerKind` a sua chave `UmsThreadDefault` de política tiver o valor e `UmsThreadDefault`o `IScheduler` valor for lido de `IUMSScheduler` volta fora da política como o valor, a interface passada para o método deve ser uma interface.

O método `invalid_argument` abre uma exceção se o parâmetro `pScheduler` tiver o valor `NULL` ou se o parâmetro `version` não for uma versão válida para a interface de comunicação.

## <a name="iresourcemanagerrelease-method"></a><a name="release"></a>IResourceManager::Método de lançamento

Decreta a contagem de referência na instância do Gerenciador de recursos. O Gerenciador de Recursos é destruído `0`quando sua contagem de referência vai para .

```cpp
virtual unsigned int Release() = 0;
```

### <a name="return-value"></a>Valor retornado

A contagem de referência resultante.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura ISchedulerProxy](ischedulerproxy-structure.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)
