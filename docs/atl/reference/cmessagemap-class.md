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
ms.openlocfilehash: a822f36d6b6fd49301d8240324e27f0ad9ce52e7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326716"
---
# <a name="cmessagemap-class"></a>Classe CMessageMap

Esta classe permite que os mapas de mensagem de um objeto sejam acessados por outro objeto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class ATL_NO_VTABLE CMessageMap
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMessageMap::ProcessWindowMessage](#processwindowmessage)|Acessa um mapa `CMessageMap`de mensagens na classe derivada.|

## <a name="remarks"></a>Comentários

`CMessageMap`é uma classe base abstrata que permite que os mapas de mensagem de um objeto sejam acessados por outro objeto. Para que um objeto exponha seus mapas de `CMessageMap`mensagem, sua classe deve derivar de .

O ATL usa `CMessageMap` para suportar janelas contidas e acadeia de mapa de mensagens dinâmicas. Por exemplo, qualquer classe que contenha um `CMessageMap`objeto [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) deve derivar de . O código a seguir é retirado da amostra [SUBEDIT.](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit) Através do [CComControl,](../../atl/reference/ccomcontrol-class.md)a `CAtlEdit` classe `CMessageMap`deriva automaticamente de .

[!code-cpp[NVC_ATL_Windowing#90](../../atl/codesnippet/cpp/cmessagemap-class_1.h)]

Como a janela `m_EditCtrl`contida, usará um mapa de `CAtlEdit` mensagem `CMessageMap`na classe contendo, deriva de .

Para obter mais informações sobre mapas de mensagens, consulte [Mapas de mensagens](../../atl/message-maps-atl.md) no artigo "CLASSES DE JANELA ATL".

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cmessagemapprocesswindowmessage"></a><a name="processwindowmessage"></a>CMessageMap::ProcessWindowMessage

Acessa o mapa de mensagens identificado por `CMessageMap` *dwMsgMapID* em uma classe derivada.

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
[em] A alça da janela recebendo a mensagem.

*Umsg*<br/>
[em] A mensagem enviada para a janela.

*wParam*<br/>
[em] Informações específicas de mensagem adicionais.

*lParam*<br/>
[em] Informações específicas de mensagem adicionais.

*Lresult*<br/>
[fora] O resultado do processamento de mensagens.

*dwMsgMapID*<br/>
[em] O identificador do mapa de mensagem que processará a mensagem. O mapa de mensagem padrão, declarado com [BEGIN_MSG_MAP,](message-map-macros-atl.md#begin_msg_map)é identificado por 0. Um mapa de mensagem alternativo, declarado com [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)é identificado por `msgMapID`.

### <a name="return-value"></a>Valor retornado

VERDADE se a mensagem for totalmente manuseada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chamado pelo procedimento de janela de um objeto [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) ou de um objeto que está acorrentado dinamicamente ao mapa da mensagem.

## <a name="see-also"></a>Confira também

[Classe CdynamicChain](../../atl/reference/cdynamicchain-class.md)<br/>
[Begin_msg_map](message-map-macros-atl.md#begin_msg_map)<br/>
[ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
