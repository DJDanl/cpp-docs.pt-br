---
title: Funções globais de manipulação de eventos
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWaitWithMessageLoop
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
ms.openlocfilehash: f2f8269dcf0f59a5d0794d3f16d4c4f85d8841ac
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330143"
---
# <a name="event-handling-global-functions"></a>Funções globais de manipulação de eventos

Esta função fornece um manipulador de eventos.

> [!IMPORTANT]
> A função listada na tabela a seguir não pode ser usada em aplicativos executados no Tempo de execução do Windows.

|||
|-|-|
|[AtlWaitWithMessageLoop](#atlwaitwithmessageloop)|Espera que um objeto seja sinalizado, enquanto isso, despacha mensagens de janela conforme necessário.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlwaitwithmessageloop"></a><a name="atlwaitwithmessageloop"></a>AtlWaitWithMessageLoop

Aguarda o objeto a ser sinalizado, enquanto despacha as mensagens da janela conforme necessário.

> [!IMPORTANT]
> Esta função não pode ser usada em aplicativos executados no Tempo de execução do Windows.

```
BOOL AtlWaitWithMessageLoop(HANDLE hEvent);
```

### <a name="parameters"></a>Parâmetros

*Hevent*<br/>
[em] A alça do objeto para esperar.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o objeto tiver sido sinalizado.

### <a name="remarks"></a>Comentários

Isso é útil se você quiser esperar que o evento de um objeto aconteça e ser notificado sobre o que está acontecendo, mas permita que mensagens de janela sejam enviadas enquanto espera.

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
