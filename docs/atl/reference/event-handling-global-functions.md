---
title: Funções globais de tratamento de evento
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWaitWithMessageLoop
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
ms.openlocfilehash: 02066f2e6cd215fdb68fcdb594307b646ee69cad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50660389"
---
# <a name="event-handling-global-functions"></a>Funções globais de tratamento de evento

Essa função fornece um manipulador de eventos.

> [!IMPORTANT]
>  A função listada na tabela a seguir não pode ser usada em aplicativos executados no tempo de execução do Windows.

|||
|-|-|
|[AtlWaitWithMessageLoop](#atlwaitwithmessageloop)|Aguarda um objeto a ser sinalizado, enquanto despacha as mensagens da janela, conforme necessário.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlwaitwithmessageloop"></a>  AtlWaitWithMessageLoop

Aguarda o objeto a ser sinalizado, enquanto despacha as mensagens da janela conforme necessário.

> [!IMPORTANT]
>  Essa função não pode ser usada em aplicativos executados no tempo de execução do Windows.

```
BOOL AtlWaitWithMessageLoop(HANDLE hEvent);
```

### <a name="parameters"></a>Parâmetros

*hEvent*<br/>
[in] O identificador do objeto para aguardar.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o objeto foi sinalizado.

### <a name="remarks"></a>Comentários

Isso é útil se você quiser aguardar um evento de objeto acontecer e ser notificado de que ele acontecendo, mas permitir que as mensagens de janela ser expedida enquanto aguarda.

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
