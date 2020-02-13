---
title: Estrutura IUMSCompletionList
ms.date: 11/04/2016
f1_keywords:
- IUMSCompletionList
- CONCRTRM/concurrency::IUMSCompletionList
- CONCRTRM/concurrency::IUMSCompletionList::IUMSCompletionList::GetUnblockNotifications
helpviewer_keywords:
- IUMSCompletionList structure
ms.assetid: 81b5250e-3065-492c-b20d-2cdabf12271a
ms.openlocfilehash: 02382ef4606a6e73804fcbd5ce7735ecf2f0dcc7
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140042"
---
# <a name="iumscompletionlist-structure"></a>Estrutura IUMSCompletionList

Representa uma lista de conclusão de UMS. Quando um thread UMS é bloqueado, o contexto de agendamento designado do Agendador é expedido para tomar uma decisão do que deve ser agendado na raiz do processador virtual subjacente enquanto o thread original é bloqueado. Quando o thread original é desbloqueado, o sistema operacional o enfileira na lista de conclusão que é acessível por essa interface. O Agendador pode consultar a lista de conclusão no contexto de agendamento designado ou em qualquer outro lugar em que ele procura trabalho.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSCompletionList;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IUMSCompletionList::GetUnblockNotifications](#getunblocknotifications)|Recupera uma cadeia de interfaces de `IUMSUnblockNotification` que representa contextos de execução cujos proxies de thread associados foram desbloqueados desde a última vez que esse método foi invocado.|

## <a name="remarks"></a>Comentários

Um Agendador deve ser um pouco cuidadoso sobre quais ações são executadas após a utilização dessa interface para remover itens da lista de conclusão. Os itens devem ser colocados na lista de contextos executáveis do Agendador e estar geralmente acessíveis assim que possível. É totalmente possível que um dos itens da fila tenha recebido a propriedade de um bloqueio arbitrário. O Agendador pode não fazer chamadas de função arbitrárias que possam ser bloqueadas entre a chamada para itens de remoção da fila e o posicionamento desses itens em uma lista que pode ser geralmente acessada de dentro do Agendador.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSCompletionList`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="getunblocknotifications"></a>Método IUMSCompletionList:: GetUnblockNotifications

Recupera uma cadeia de interfaces de `IUMSUnblockNotification` que representa contextos de execução cujos proxies de thread associados foram desbloqueados desde a última vez que esse método foi invocado.

```cpp
virtual IUMSUnblockNotification *GetUnblockNotifications() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de interfaces de `IUMSUnblockNotification`.

### <a name="remarks"></a>Comentários

As notificações retornadas são inválidas quando os contextos de execução são reagendados.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)
