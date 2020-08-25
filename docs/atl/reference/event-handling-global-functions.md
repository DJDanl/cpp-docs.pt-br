---
title: Funções globais de manipulação de eventos
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlWaitWithMessageLoop
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
ms.openlocfilehash: fde93415640ef7fa460bb363af4c3cb14b356061
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833446"
---
# <a name="event-handling-global-functions"></a>Funções globais de manipulação de eventos

Essa função fornece um manipulador de eventos.

> [!IMPORTANT]
> A função listada na tabela a seguir não pode ser usada em aplicativos que são executados no Windows Runtime.

|Nome|Descrição|
|-|-|
|[AtlWaitWithMessageLoop](#atlwaitwithmessageloop)|Aguarda até que um objeto seja sinalizado, ao mesmo tempo em que distribui mensagens de janela conforme necessário.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="atlwaitwithmessageloop"></a><a name="atlwaitwithmessageloop"></a> AtlWaitWithMessageLoop

Aguarda o objeto a ser sinalizado, enquanto despacha as mensagens da janela conforme necessário.

> [!IMPORTANT]
> Essa função não pode ser usada em aplicativos que são executados no Windows Runtime.

```
BOOL AtlWaitWithMessageLoop(HANDLE hEvent);
```

### <a name="parameters"></a>parâmetros

*hEvent*<br/>
no O identificador do objeto a ser aguardado.

### <a name="return-value"></a>Valor Retornado

Retornará TRUE se o objeto tiver sido sinalizado.

### <a name="remarks"></a>Comentários

Isso será útil se você quiser aguardar o evento de um objeto ocorrer e ser notificado sobre ele que está acontecendo, mas permitir que as mensagens de janela sejam expedidas enquanto aguardam.

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)
