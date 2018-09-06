---
title: Classe CDynamicChain | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CDynamicChain
- ATLWIN/ATL::CDynamicChain
- ATLWIN/ATL::CDynamicChain::CDynamicChain
- ATLWIN/ATL::CDynamicChain::CallChain
- ATLWIN/ATL::CDynamicChain::RemoveChainEntry
- ATLWIN/ATL::CDynamicChain::SetChainEntry
dev_langs:
- C++
helpviewer_keywords:
- message maps, chaining
- chaining message maps
- CDynamicChain class
ms.assetid: f084b2be-0e77-4836-973d-ae278a1e9da8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6cb05f61d3cd90177fe5e44ce432430ba8f74dd5
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43754807"
---
# <a name="cdynamicchain-class"></a>Classe CDynamicChain

Essa classe fornece métodos que dão suporte a encadeamento dinâmico de mapas de mensagem.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CDynamicChain
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDynamicChain::CDynamicChain](#cdynamicchain)|O construtor.|
|[CDynamicChain:: ~ CDynamicChain](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDynamicChain::CallChain](#callchain)|Direciona a uma mensagem do Windows ao mapa de mensagem de outro objeto.|
|[CDynamicChain::RemoveChainEntry](#removechainentry)|Remove uma entrada de mapa de mensagem da coleção.|
|[CDynamicChain::SetChainEntry](#setchainentry)|Adiciona uma entrada de mapa de mensagem à coleção ou modifica uma entrada existente.|

## <a name="remarks"></a>Comentários

`CDynamicChain` gerencia uma coleção de mapas de mensagem, permitindo que uma mensagem do Windows ser direcionado em tempo de execução ao mapa de mensagem de outro objeto.

Para adicionar suporte para o encadeamento dinâmico de mapas de mensagem, faça o seguinte:

- Derive sua classe de `CDynamicChain`. No mapa de mensagens, especificar o [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro encadear para mapa de mensagem padrão do objeto para outro.

- Derivar todas as classes que você deseja encadear a partir [CMessageMap](../../atl/reference/cmessagemap-class.md). `CMessageMap` permite que um objeto exponha seus mapas de mensagem a outros objetos.

- Chamar `CDynamicChain::SetChainEntry` para identificar qual objeto e qual mensagem do mapa que você desejam encadear para.

Por exemplo, suponha que sua classe é definida da seguinte maneira:

[!code-cpp[NVC_ATL_Windowing#88](../../atl/codesnippet/cpp/cdynamicchain-class_1.h)]

O cliente, em seguida, chama `CMyWindow::SetChainEntry`:

[!code-cpp[NVC_ATL_Windowing#89](../../atl/codesnippet/cpp/cdynamicchain-class_2.cpp)]

em que `chainedObj` é o objeto encadeado e é uma instância de uma classe derivada de `CMessageMap`. Agora, se `myCtl` recebe uma mensagem que não é tratada pelo `OnPaint` ou `OnSetFocus`, o procedimento de janela direciona a mensagem a ser `chainedObj`do mapa de mensagem padrão.

Para obter mais informações sobre o encadeamento de mapa de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="callchain"></a>  CDynamicChain::CallChain

Direciona a mensagem do Windows ao mapa de mensagem de outro objeto.

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

*dwChainID*  
[in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem.

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

### <a name="return-value"></a>Valor de retorno

TRUE se a mensagem seja totalmente processada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para obter o procedimento de janela invocar `CallChain`, você deve especificar o [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro no seu mapa de mensagem. Por exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.

`CallChain` requer uma chamada anterior a [SetChainEntry](#setchainentry) para associar a *dwChainID* valor com um objeto e seu mapa de mensagem.

##  <a name="cdynamicchain"></a>  CDynamicChain::CDynamicChain

O construtor.

```
CDynamicChain();
```

##  <a name="dtor"></a>  CDynamicChain:: ~ CDynamicChain

O destruidor.

```
~CDynamicChain();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="removechainentry"></a>  CDynamicChain::RemoveChainEntry

Remove o mapa de mensagem especificado da coleção.

```
BOOL RemoveChainEntry(DWORD dwChainID);
```

### <a name="parameters"></a>Parâmetros

*dwChainID*  
[in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem. Originalmente, você define esse valor por meio de uma chamada para [SetChainEntry](#setchainentry).

### <a name="return-value"></a>Valor de retorno

TRUE se o mapa da mensagem for removido com êxito da coleção. Caso contrário, FALSE.

##  <a name="setchainentry"></a>  CDynamicChain::SetChainEntry

Adiciona o mapa de mensagem especificado à coleção.

```
BOOL SetChainEntry(  
    DWORD dwChainID,
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0);
```

### <a name="parameters"></a>Parâmetros

*dwChainID*  
[in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem.

*pObject*  
[in] Um ponteiro para o objeto encadeado declarando o mapa da mensagem. Esse objeto deve ser derivado de [CMessageMap](../../atl/reference/cmessagemap-class.md).

*dwMsgMapID*  
[in] O identificador do mapa de mensagens no objeto encadeado. O valor padrão é 0, que identifica o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para especificar um mapa de mensagens alternativos declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), passe `msgMapID`.

### <a name="return-value"></a>Valor de retorno

TRUE se o mapa da mensagem é adicionado com êxito à coleção. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o *dwChainID* valor já existe na coleção, seu objeto associado e mapa de mensagem são substituídas por *pObject* e *dwMsgMapID*, respectivamente. Caso contrário, uma nova entrada é adicionada.

## <a name="see-also"></a>Consulte também

[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)   
[Visão geral da classe](../../atl/atl-class-overview.md)
