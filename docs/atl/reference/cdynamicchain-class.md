---
title: Classe CdynamicChain
ms.date: 11/04/2016
f1_keywords:
- CDynamicChain
- ATLWIN/ATL::CDynamicChain
- ATLWIN/ATL::CDynamicChain::CDynamicChain
- ATLWIN/ATL::CDynamicChain::CallChain
- ATLWIN/ATL::CDynamicChain::RemoveChainEntry
- ATLWIN/ATL::CDynamicChain::SetChainEntry
helpviewer_keywords:
- message maps, chaining
- chaining message maps
- CDynamicChain class
ms.assetid: f084b2be-0e77-4836-973d-ae278a1e9da8
ms.openlocfilehash: 4a72b3b4308ed83dfdc4a2895a04d1fe9a177ce5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327029"
---
# <a name="cdynamicchain-class"></a>Classe CdynamicChain

Esta classe fornece métodos que suportam o encadeamento dinâmico de mapas de mensagens.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CDynamicChain
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDynamicChain::CDynamicChain](#cdynamicchain)|O construtor.|
|[CDynamicChain::~CDynamicChain](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDynamicChain::CallChain](#callchain)|Direciona uma mensagem do Windows para o mapa de mensagens de outro objeto.|
|[CDynamicChain::RemoveChainEntry](#removechainentry)|Remove uma entrada de mapa de mensagem da coleção.|
|[cdynamicchain::Setchainentry](#setchainentry)|Adiciona uma entrada de mapa de mensagem à coleção ou modifica uma entrada existente.|

## <a name="remarks"></a>Comentários

`CDynamicChain`gerencia uma coleção de mapas de mensagens, permitindo que uma mensagem do Windows seja direcionada, em tempo de execução, para o mapa de mensagens de outro objeto.

Para adicionar suporte para encadeamento dinâmico de mapas de mensagens, faça o seguinte:

- Obtenha sua `CDynamicChain`classe de . No mapa de mensagens, especifique a [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro para a cadeia para o mapa de mensagem padrão de outro objeto.

- Derver todas as classes que deseja acorrentar a partir do [CMessageMap](../../atl/reference/cmessagemap-class.md). `CMessageMap`permite que um objeto exponha seus mapas de mensagem a outros objetos.

- Chamada `CDynamicChain::SetChainEntry` para identificar qual objeto e qual mapa de mensagem você deseja acorrentar.

Por exemplo, suponha que sua classe seja definida da seguinte forma:

[!code-cpp[NVC_ATL_Windowing#88](../../atl/codesnippet/cpp/cdynamicchain-class_1.h)]

O cliente `CMyWindow::SetChainEntry`então chama:

[!code-cpp[NVC_ATL_Windowing#89](../../atl/codesnippet/cpp/cdynamicchain-class_2.cpp)]

onde `chainedObj` está o objeto acorrentado e `CMessageMap`é uma instância de uma classe derivada de . Agora, `myCtl` se receber uma mensagem `OnPaint` que `OnSetFocus`não seja tratada por `chainedObj`ou , o procedimento da janela direciona a mensagem para o mapa de mensagem padrão.

Para obter mais informações sobre a cadeia de mapas de mensagens, consulte [Mapas de mensagens](../../atl/message-maps-atl.md) no artigo "CLASSES DE Janela ATL".

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin.h

## <a name="cdynamicchaincallchain"></a><a name="callchain"></a>CDynamicChain::CallChain

Direciona a mensagem do Windows para o mapa de mensagens de outro objeto.

```
BOOL CallChain(
    DWORD dwChainID,
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT& lResult);
```

### <a name="parameters"></a>Parâmetros

*dwChainID*<br/>
[em] O identificador único associado ao objeto acorrentado e seu mapa de mensagens.

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

### <a name="return-value"></a>Valor retornado

VERDADE se a mensagem estiver totalmente processada; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para que o `CallChain`procedimento de janela seja invocado, você deve especificar a [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro no mapa da mensagem. Por exemplo, veja a visão geral do [CDynamicChain.](../../atl/reference/cdynamicchain-class.md)

`CallChain`requer uma chamada anterior ao [SetChainEntry](#setchainentry) para associar o valor *dwChainID* a um objeto e seu mapa de mensagens.

## <a name="cdynamicchaincdynamicchain"></a><a name="cdynamicchain"></a>CDynamicChain::CDynamicChain

O construtor.

```
CDynamicChain();
```

## <a name="cdynamicchaincdynamicchain"></a><a name="dtor"></a>CDynamicChain::~CDynamicChain

O destruidor.

```
~CDynamicChain();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="cdynamicchainremovechainentry"></a><a name="removechainentry"></a>CDynamicChain::RemoveChainEntry

Remove o mapa de mensagem especificado da coleção.

```
BOOL RemoveChainEntry(DWORD dwChainID);
```

### <a name="parameters"></a>Parâmetros

*dwChainID*<br/>
[em] O identificador único associado ao objeto acorrentado e seu mapa de mensagens. Você define originalmente esse valor através de uma chamada para [SetChainEntry](#setchainentry).

### <a name="return-value"></a>Valor retornado

TRUE se o mapa de mensagens for removido com sucesso da coleção. Caso contrário, FALSE.

## <a name="cdynamicchainsetchainentry"></a><a name="setchainentry"></a>cdynamicchain::Setchainentry

Adiciona o mapa de mensagem especificado à coleção.

```
BOOL SetChainEntry(
    DWORD dwChainID,
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0);
```

### <a name="parameters"></a>Parâmetros

*dwChainID*<br/>
[em] O identificador único associado ao objeto acorrentado e seu mapa de mensagens.

*Pobject*<br/>
[em] Um ponteiro para o objeto acorrentado declarando o mapa da mensagem. Este objeto deve derivar do [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*<br/>
[em] O identificador do mapa de mensagem no objeto acorrentado. O valor padrão é 0, que identifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para especificar um mapa de mensagem alternativo declarado com `msgMapID` [ALT_MSG_MAP(msgMapID),](message-map-macros-atl.md#alt_msg_map)passe .

### <a name="return-value"></a>Valor retornado

TRUE se o mapa de mensagens for adicionado com sucesso à coleção. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o valor *dwChainID* já existir na coleção, seu objeto associado e mapa de mensagem serão substituídos por *pObject* e *dwMsgMapID,* respectivamente. Caso contrário, uma nova entrada é adicionada.

## <a name="see-also"></a>Confira também

[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
