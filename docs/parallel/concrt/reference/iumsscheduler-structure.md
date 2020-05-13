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
ms.openlocfilehash: 70954906122c048e5199a801632626d35a8e3f18
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368091"
---
# <a name="iumsscheduler-structure"></a>Estrutura IUMSScheduler

Uma interface para uma abstração de um agendador de trabalho que deseja que o Gerenciador de Recursos do Concurrency Runtime o entregue a threads de ums (ums) em modo de usuário. O Gerenciador de recursos usa essa interface para se comunicar com agendadores de thread ums. A interface `IUMSScheduler` herda da interface `IScheduler` .

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSScheduler : public IScheduler;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iUMSScheduler::SetCompletList](#setcompletionlist)|Atribui uma `IUMSCompletionList` interface a um agendador de threads UMS.|

## <a name="remarks"></a>Comentários

Se você estiver implementando um agendador personalizado que se comunica com o Gerenciador de recursos e quiser que os segmentos UMS `IUMSScheduler` sejam entregues ao seu agendador em vez de threads Win32 comuns, você deve fornecer uma implementação da interface. Além disso, você deve definir o valor `SchedulerKind` da `UmsThreadDefault`política para a chave da política do agendador ser . Se a diretiva especificar o `IScheduler` segmento UMS, a interface que é passada como parâmetro para `IUMSScheduler` o [método IResourceManager::RegisterScheduler](iresourcemanager-structure.md#registerscheduler) deve ser uma interface.

O Gerenciador de Recursos é capaz de entregar-lhe threads UMS apenas em sistemas operacionais que tenham o recurso UMS. Sistemas operacionais de 64 bits com versão Windows 7 e rosca UMS de suporte superior. Se você criar uma diretiva `SchedulerKind` de agendador `UmsThreadDefault` com a chave definida para o valor `SchedulerKind` e a plataforma subjacente não `ThreadScheduler`suportar ums, o valor da chave nessa diretiva será alterado para o valor . Você deve sempre ler de volta este valor de política antes de esperar receber threads UMS.

A `IUMSScheduler` interface é uma extremidade de um canal de comunicação bidirecional entre um agendador e o Gerenciador de Recursos. A outra extremidade é `IResourceManager` `ISchedulerProxy` representada pelas interfaces e interfaces, que são implementadas pelo Gerenciador de Recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ischeduler](ischeduler-structure.md)

`IUMSScheduler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iumsschedulersetcompletionlist-method"></a><a name="setcompletionlist"></a>iUMSScheduler::Método SetCompletList

Atribui uma `IUMSCompletionList` interface a um agendador de threads UMS.

```cpp
virtual void SetCompletionList(_Inout_ IUMSCompletionList* pCompletionList) = 0;
```

### <a name="parameters"></a>Parâmetros

*lista de preenchimento*<br/>
A interface da lista de conclusão para o agendador. Há uma única lista por agendador.

### <a name="remarks"></a>Comentários

O Gerenciador de Recursos invocará esse método em um agendador que especifica que deseja threads UMS, depois que o agendador solicitar uma alocação inicial de recursos. O agendador pode `IUMSCompletionList` usar a interface para determinar quando os proxies de segmento ums foram desbloqueados. Só é válido acessar essa interface a partir de um proxy de thread em execução em uma raiz de processador virtual atribuída ao agendador UMS.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[PolicyElementKey](concurrency-namespace-enums.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IUMSCompletionList](iumscompletionlist-structure.md)<br/>
[Estrutura IResourceManager](iresourcemanager-structure.md)
