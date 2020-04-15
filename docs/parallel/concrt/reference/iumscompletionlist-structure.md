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
ms.openlocfilehash: c388cc98aedbd35b2d0e00a4653a85a47abcb838
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368114"
---
# <a name="iumscompletionlist-structure"></a>Estrutura IUMSCompletionList

Representa uma lista de conclusão da UMS. Quando um thread UMS bloqueia, o contexto de agendamento designado pelo agendador é despachado para tomar uma decisão sobre o que agendar na raiz do processador virtual subjacente enquanto o segmento original é bloqueado. Quando o segmento original desbloqueia, o sistema operacional faz fila para a lista de conclusão que é acessível através desta interface. O agendador pode consultar a lista de conclusão no contexto de agendamento designado ou em qualquer outro lugar que ele procura por trabalho.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSCompletionList;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSConclusãoLista::ObterUnblockNotifications](#getunblocknotifications)|Recupera uma cadeia `IUMSUnblockNotification` de interfaces representando contextos de execução cujos proxies de segmento associados foram desbloqueados desde a última vez que este método foi invocado.|

## <a name="remarks"></a>Comentários

Um agendador deve ser extraordinariamente cuidadoso sobre quais ações são executadas depois de utilizar esta interface para desmarcar itens da lista de conclusão. Os itens devem ser colocados na lista de contextos executáveis do agendador e estar geralmente acessíveis o mais rápido possível. É inteiramente possível que um dos itens enfileirados tenha sido dado a propriedade de um bloqueio arbitrário. O agendador não pode fazer chamadas de função arbitrárias que possam bloquear entre a chamada para desfilar itens e a colocação desses itens em uma lista que geralmente pode ser acessada dentro do agendador.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSCompletionList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iumscompletionlistgetunblocknotifications-method"></a><a name="getunblocknotifications"></a>IUMSConclusãoLista::Método ''Bloquear'''''''''''''''''''''''''''

Recupera uma cadeia `IUMSUnblockNotification` de interfaces representando contextos de execução cujos proxies de segmento associados foram desbloqueados desde a última vez que este método foi invocado.

```cpp
virtual IUMSUnblockNotification *GetUnblockNotifications() = 0;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia `IUMSUnblockNotification` de interfaces.

### <a name="remarks"></a>Comentários

As notificações retornadas são inválidas quando os contextos de execução são reagendados.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)
