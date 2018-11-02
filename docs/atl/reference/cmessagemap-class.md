---
title: Classe CMessageMap
ms.date: 11/04/2016
f1_keywords:
- CMessageMap
- ATLWIN/ATL::CMessageMap
- ATLWIN/ATL::CMessageMap::ProcessWindowMessage
helpviewer_keywords:
- CMessageMap class
- message maps, ATL
- ATL, message handlers
ms.assetid: 1f97bc16-a8a0-4cf0-b90f-1778813a5c8e
ms.openlocfilehash: 325851b75cef340fe5dcc762df54c40ded1ed704
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534076"
---
# <a name="cmessagemap-class"></a>Classe CMessageMap

Essa classe permite que os mapas de mensagem de um objeto para ser acessado por outro objeto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CMessageMap
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMessageMap::ProcessWindowMessage](#processwindowmessage)|Acessa um mapa de mensagem no `CMessageMap`-classe derivada.|

## <a name="remarks"></a>Comentários

`CMessageMap` é uma classe base abstrata que permite que a mensagem de um objeto é mapeado para ser acessado por outro objeto. Para um objeto exponha seus mapas de mensagem que, sua classe deve derivar de `CMessageMap`.

Usa o ATL `CMessageMap` contido de suporte ao windows e o encadeamento de mapa de mensagem dinâmica. Por exemplo, qualquer classe que contém um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) objeto deve derivar de `CMessageMap`. O código a seguir é retirado do [SUBEDIT](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit) exemplo. Por meio [CComControl](../../atl/reference/ccomcontrol-class.md), o `CAtlEdit` classe automaticamente deriva `CMessageMap`.

[!code-cpp[NVC_ATL_Windowing#90](../../atl/codesnippet/cpp/cmessagemap-class_1.h)]

Porque a janela de independente `m_EditCtrl`, usará um mapa de mensagens na classe recipiente, `CAtlEdit` deriva `CMessageMap`.

Para obter mais informações sobre mapas de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="processwindowmessage"></a>  CMessageMap::ProcessWindowMessage

Acessa o mapa de mensagem identificado por *dwMsgMapID* em um `CMessageMap`-classe derivada.

```
virtual BOOL ProcessWindowMessage(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT& lResult,
    DWORD dwMsgMapID) = 0;
```

### <a name="parameters"></a>Parâmetros

*hWnd*<br/>
[in] O identificador para a janela de recebimento da mensagem.

*uMsg*<br/>
[in] A mensagem enviada para a janela.

*wParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

*lParam*<br/>
[in] Obter informações adicionais específicas de mensagem.

*lResult*<br/>
[out] O resultado do processamento da mensagem.

*dwMsgMapID*<br/>
[in] O identificador do mapa de mensagens que processará a mensagem. O mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), é identificado por 0. Um mapa de mensagens alternativos, declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), é identificado por `msgMapID`.

### <a name="return-value"></a>Valor de retorno

TRUE se a mensagem é totalmente tratada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamada pelo procedimento de janela de um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) de objeto ou de um objeto que está encadeando dinamicamente para o mapa da mensagem.

## <a name="see-also"></a>Consulte também

[Classe CDynamicChain](../../atl/reference/cdynamicchain-class.md)<br/>
[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)<br/>
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
