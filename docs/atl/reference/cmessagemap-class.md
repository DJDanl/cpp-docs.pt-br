---
title: Classe CMessageMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CMessageMap
- ATLWIN/ATL::CMessageMap
- ATLWIN/ATL::CMessageMap::ProcessWindowMessage
dev_langs:
- C++
helpviewer_keywords:
- CMessageMap class
- message maps, ATL
- ATL, message handlers
ms.assetid: 1f97bc16-a8a0-4cf0-b90f-1778813a5c8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: be04510f7967b431b7e7c4a3b11aef6f51afe8d8
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763221"
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

*hWnd*  
[in] O identificador para a janela de recebimento da mensagem.

*uMsg*  
[in] A mensagem enviada para a janela.

*wParam*  
[in] Obter informações adicionais específicas de mensagem.

*lParam*  
[in] Obter informações adicionais específicas de mensagem.

*lResult*  
[out] O resultado do processamento da mensagem.

*dwMsgMapID*  
[in] O identificador do mapa de mensagens que processará a mensagem. O mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), é identificado por 0. Um mapa de mensagens alternativos, declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), é identificado por `msgMapID`.

### <a name="return-value"></a>Valor de retorno

TRUE se a mensagem é totalmente tratada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamada pelo procedimento de janela de um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) de objeto ou de um objeto que está encadeando dinamicamente para o mapa da mensagem.

## <a name="see-also"></a>Consulte também

[Classe CDynamicChain](../../atl/reference/cdynamicchain-class.md)   
[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)   
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)   
[Visão geral da classe](../../atl/atl-class-overview.md)
