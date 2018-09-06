---
title: Funções globais de tratamento de eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlWaitWithMessageLoop
dev_langs:
- C++
helpviewer_keywords:
- event handling, global functions
- global functions, event handling
ms.assetid: fd674470-3def-47c3-be1c-894fa85f13e8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fcdf854eeeceb1aa3648ff984e3a2c956d973eeb
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754645"
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

*hEvent*  
[in] O identificador do objeto para aguardar.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o objeto foi sinalizado.

### <a name="remarks"></a>Comentários

Isso é útil se você quiser aguardar um evento de objeto acontecer e ser notificado de que ele acontecendo, mas permitir que as mensagens de janela ser expedida enquanto aguarda.

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)
