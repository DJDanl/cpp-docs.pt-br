---
title: Macros de mensagens do Windows
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::WM_FORWARDMSG
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
ms.openlocfilehash: b4cd3c2eea24449eb17050b147d9c59560d8358f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834434"
---
# <a name="windows-messages-macros"></a>Macros de mensagens do Windows

Esta macro encaminha as mensagens da janela.

|Nome|Descrição|
|-|-|
|[WM_FORWARDMSG](#wm_forwardmsg)|Use para encaminhar uma mensagem recebida por uma janela para outra janela para processamento.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="wm_forwardmsg"></a><a name="wm_forwardmsg"></a> WM_FORWARDMSG

Essa macro encaminha uma mensagem recebida por uma janela para outra janela para processamento.

```
WM_FORWARDMSG
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a mensagem tiver sido processada, zero se não for.

### <a name="remarks"></a>Comentários

Use WM_FORWARDMSG para encaminhar uma mensagem recebida por uma janela para outra janela para processamento. Os parâmetros LPARAM e WPARAM são usados da seguinte maneira:

|Parâmetro|Uso|
|---------------|-----------|
|WPARAM|Dados definidos pelo usuário|
|LPARAM|Um ponteiro para uma `MSG` estrutura que contém informações sobre uma mensagem|

### <a name="example"></a>Exemplo

No exemplo a seguir, `m_hWndOther` representa a outra janela que recebe essa mensagem.

[!code-cpp[NVC_ATL_Windowing#137](../../atl/codesnippet/cpp/windows-messages-macros_1.cpp)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
