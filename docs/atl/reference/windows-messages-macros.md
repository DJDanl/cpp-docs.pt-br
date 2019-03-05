---
title: Macros de mensagens do Windows
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::WM_FORWARDMSG
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
ms.openlocfilehash: 7bb5e2fa265c3a5dcabcc16d8343d5b86a4aaf42
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57273902"
---
# <a name="windows-messages-macros"></a>Macros de mensagens do Windows

Essa macro encaminha mensagens de janela.

|||
|-|-|
|[WM_FORWARDMSG](#wm_forwardmsg)|Use esta opção para encaminhar uma mensagem recebida por uma janela para outra janela para processamento.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="wm_forwardmsg"></a>  WM_FORWARDMSG

Essa macro encaminha uma mensagem recebida por uma janela para outra janela para processamento.

```
WM_FORWARDMSG
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a mensagem foi processada, zero se não.

### <a name="remarks"></a>Comentários

Use WM_FORWARDMSG para encaminhar uma mensagem recebida por uma janela para outra janela para processamento. O LPARAM e o WPARAM parâmetros são usados da seguinte maneira:

|Parâmetro|Uso|
|---------------|-----------|
|WPARAM|Dados definidos pelo usuário|
|LPARAM|Um ponteiro para um `MSG` estrutura que contém informações sobre uma mensagem|

### <a name="example"></a>Exemplo

No exemplo a seguir, `m_hWndOther` representa a outra janela que recebe essa mensagem.

[!code-cpp[NVC_ATL_Windowing#137](../../atl/codesnippet/cpp/windows-messages-macros_1.cpp)]

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
