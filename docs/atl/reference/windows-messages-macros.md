---
title: Macros de mensagens do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlbase/ATL::WM_FORWARDMSG
dev_langs:
- C++
ms.assetid: 63abd22c-372d-4148-bb04-c605950ae64f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3f9d312104254323e98f6b2fd031adf1064ecfac
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50078213"
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
