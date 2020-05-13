---
title: Macros de mensagens do Windows
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::WM_FORWARDMSG
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
ms.openlocfilehash: a5a6d45c64d6123128ae362c1ef5643392439f41
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329406"
---
# <a name="windows-messages-macros"></a>Macros de mensagens do Windows

Esta macro encaminha mensagens de janela.

|||
|-|-|
|[WM_FORWARDMSG](#wm_forwardmsg)|Use para encaminhar uma mensagem recebida por uma janela para outra janela para processamento.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="wm_forwardmsg"></a><a name="wm_forwardmsg"></a>WM_FORWARDMSG

Esta macro encaminha uma mensagem recebida por uma janela para outra janela para processamento.

```
WM_FORWARDMSG
```

### <a name="return-value"></a>Valor retornado

Não zero se a mensagem foi processada, zero se não.

### <a name="remarks"></a>Comentários

Use WM_FORWARDMSG para encaminhar uma mensagem recebida por uma janela para outra janela para processamento. Os parâmetros LPARAM e WPARAM são usados da seguinte forma:

|Parâmetro|Uso|
|---------------|-----------|
|Wparam|Dados definidos pelo usuário|
|Lparam|Um ponteiro `MSG` para uma estrutura que contém informações sobre uma mensagem|

### <a name="example"></a>Exemplo

No exemplo a `m_hWndOther` seguir, representa a outra janela que recebe esta mensagem.

[!code-cpp[NVC_ATL_Windowing#137](../../atl/codesnippet/cpp/windows-messages-macros_1.cpp)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
