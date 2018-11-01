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
ms.openlocfilehash: ec3c38ee609dfa7aec8d688269f1183d307be5b2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50438201"
---
# <a name="iumscompletionlist-structure"></a>Estrutura IUMSCompletionList

Representa uma lista de conclusão UMS. Quando um thread seja bloqueado UMS, o Agendador designado de agendamento de contexto é enviado para tomar uma decisão do que agendar na raiz do processador virtual subjacente enquanto o thread original será bloqueado. Quando o thread original será desbloqueado, o sistema operacional coloca em fila-lo à lista de preenchimento que é acessível por meio dessa interface. O Agendador pode consultar a lista de conclusão no contexto de programação designado ou qualquer outro lugar, que ele procura por trabalho.

## <a name="syntax"></a>Sintaxe

```
struct IUMSCompletionList;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSCompletionList::GetUnblockNotifications](#getunblocknotifications)|Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo thread associado proxies têm desbloqueado desde a última vez que esse método foi invocado.|

## <a name="remarks"></a>Comentários

Um agendador deve ser extraordinariamente cuidado em relação a quais ações são executadas depois de utilizar essa interface para itens da lista de preenchimento de remoção da fila. Os itens devem ser colocados na lista do Agendador de contextos de executáveis e ser geralmente acessíveis assim que possível. Ele é totalmente possível que um dos itens da fila foi dada propriedade de um bloqueio arbitrário. O Agendador não pode fazer nenhuma chamada de função arbitrária que podem ser bloqueadas entre a chamada para itens de remoção da fila e o posicionamento desses itens em uma lista que pode ser geralmente acessados de dentro do Agendador.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IUMSCompletionList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="getunblocknotifications"></a>  Método iumscompletionlist:: Getunblocknotifications

Recupera uma cadeia de `IUMSUnblockNotification` interfaces que representa os contextos de execução cujo thread associado proxies têm desbloqueado desde a última vez que esse método foi invocado.

```
virtual IUMSUnblockNotification *GetUnblockNotifications() = 0;
```

### <a name="return-value"></a>Valor de retorno

Uma cadeia de `IUMSUnblockNotification` interfaces.

### <a name="remarks"></a>Comentários

As notificações retornadas são inválidas depois que os contextos de execução sejam reagendados.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)<br/>
[Estrutura IUMSUnblockNotification](iumsunblocknotification-structure.md)
