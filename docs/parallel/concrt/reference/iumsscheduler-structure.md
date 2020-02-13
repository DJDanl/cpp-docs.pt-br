---
title: Estrutura IUMSScheduler
ms.date: 11/04/2016
f1_keywords:
- IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler
- CONCRTRM/concurrency::IUMSScheduler::IUMSScheduler::SetCompletionList
helpviewer_keywords:
- IUMSScheduler structure
ms.assetid: 3a500225-4e02-4849-bb56-d744865f5870
ms.openlocfilehash: 45df744a9850510006e4bf887c8ed61b000a8e5c
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139989"
---
# <a name="iumsscheduler-structure"></a>Estrutura IUMSScheduler

Uma interface para uma abstração de um Agendador de trabalho que deseja que o Gerenciador de recursos do Tempo de Execução de Simultaneidade acesse os threads de agendáveis (UMS) do modo de usuário. O Gerenciador de recursos usa essa interface para se comunicar com agendadores de threads UMS. A interface `IUMSScheduler` herda da interface `IScheduler` .

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSScheduler : public IScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IUMSScheduler:: setcompletlist](#setcompletionlist)|Atribui uma interface de `IUMSCompletionList` a um Agendador de threads UMS.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um Agendador personalizado que se comunica com o Gerenciador de recursos e deseja que os threads UMS sejam enviados para o Agendador em vez de threads Win32 comuns, você deve fornecer uma implementação da interface `IUMSScheduler`. Além disso, você deve definir o valor da política para a chave de política do Agendador `SchedulerKind` ser `UmsThreadDefault`. Se a política especificar o thread UMS, a interface de `IScheduler` que é passada como um parâmetro para o método [IResourceManager:: RegisterScheduler](iresourcemanager-structure.md#registerscheduler) deve ser uma interface `IUMSScheduler`.

O Gerenciador de recursos é capaz de enviar UMS threads somente em sistemas operacionais que têm o recurso UMS. os sistemas operacionais de 64 bits com versão Windows 7 e superior dão suporte a threads UMS. Se você criar uma política de Agendador com o `SchedulerKind` chave definida como o valor `UmsThreadDefault` e a plataforma subjacente não oferecer suporte a UMS, o valor da chave de `SchedulerKind` nessa política será alterado para o valor `ThreadScheduler`. Você deve sempre ler novamente esse valor de política antes de esperar para receber threads UMS.

A interface `IUMSScheduler` é uma extremidade de um canal bidirecional de comunicação entre um Agendador e o Gerenciador de recursos. A outra extremidade é representada pelas interfaces `IResourceManager` e `ISchedulerProxy`, que são implementadas pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[IScheduler](ischeduler-structure.md)

`IUMSScheduler`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="setcompletionlist"></a>Método IUMSScheduler:: setcompletlist

Atribui uma interface de `IUMSCompletionList` a um Agendador de threads UMS.

```cpp
virtual void SetCompletionList(_Inout_ IUMSCompletionList* pCompletionList) = 0;
```

### <a name="parameters"></a>Parâmetros

*pCompletionList*<br/>
A interface da lista de conclusão para o Agendador. Há uma única lista por Agendador.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos invocará esse método em um Agendador que especifique que ele deseja threads UMS, depois que o Agendador tiver solicitado uma alocação inicial de recursos. O Agendador pode usar a interface `IUMSCompletionList` para determinar quando os proxies de thread UMS foram desbloqueados. Ele só é válido para acessar essa interface de um proxy de thread em execução em uma raiz de processador virtual atribuída ao agendador UMS.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
