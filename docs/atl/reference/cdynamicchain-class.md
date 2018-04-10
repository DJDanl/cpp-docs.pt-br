---
title: Classe CDynamicChain | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
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
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f57da02b764c1cbce6a97ecbea8aa84e4ffcce9e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdynamicchain-class"></a>Classe CDynamicChain
Essa classe fornece métodos que suporte o encadeamento dinâmico de mapas de mensagem.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
|[CDynamicChain::CallChain](#callchain)|Direciona uma mensagem do Windows ao mapa de mensagem de outro objeto.|  
|[CDynamicChain::RemoveChainEntry](#removechainentry)|Remove uma entrada de mapa de mensagem da coleção.|  
|[CDynamicChain::SetChainEntry](#setchainentry)|Adiciona uma entrada de mapa de mensagem para a coleção ou modifica uma entrada existente.|  
  
## <a name="remarks"></a>Comentários  
 `CDynamicChain`gerencia uma coleção de mapas de mensagem, permitindo que uma mensagem do Windows ser direcionado em tempo de execução ao mapa de mensagem de outro objeto.  
  
 Para adicionar suporte para dinâmico encadeamento de mapas de mensagem, faça o seguinte:  
  
-   Derive a classe de `CDynamicChain`. No mapa de mensagem, especifique o [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro cadeia ao mapa de mensagem padrão do outro objeto.  
  
-   Obter todas as classes que você deseja para de cadeia de [CMessageMap](../../atl/reference/cmessagemap-class.md). `CMessageMap`permite que um objeto para expor seus mapas de mensagem a outros objetos.  
  
-   Chamar `CDynamicChain::SetChainEntry` para identificar o objeto e qual mensagem mapear você desejam cadeia.  
  
 Por exemplo, suponha que a classe é definida da seguinte maneira:  
  
 [!code-cpp[NVC_ATL_Windowing#88](../../atl/codesnippet/cpp/cdynamicchain-class_1.h)]  
  
 O cliente, em seguida, chama `CMyWindow::SetChainEntry`:  
  
 [!code-cpp[NVC_ATL_Windowing#89](../../atl/codesnippet/cpp/cdynamicchain-class_2.cpp)]  
  
 onde `chainedObj` é o objeto encadeado e é uma instância de uma classe derivada de `CMessageMap`. Agora, se `myCtl` recebe uma mensagem que não é tratada por `OnPaint` ou `OnSetFocus`, o procedimento de janela direciona a mensagem a ser `chainedObj`do mapa da mensagem padrão.  
  
 Para obter mais informações sobre encadeamento de mapa de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="callchain"></a>CDynamicChain::CallChain  
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
 `dwChainID`  
 [in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem.  
  
 `hWnd`  
 [in] O identificador para a janela de recebimento da mensagem.  
  
 `uMsg`  
 [in] A mensagem enviada para a janela.  
  
 `wParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lResult`  
 [out] O resultado do processamento da mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a mensagem for totalmente processada; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 O procedimento de janela invocar `CallChain`, você deve especificar o [CHAIN_MSG_MAP_DYNAMIC](message-map-macros-atl.md#chain_msg_map_dynamic) macro em seu mapa de mensagem. Para obter um exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.  
  
 `CallChain`requer uma chamada anterior a [SetChainEntry](#setchainentry) para associar o `dwChainID` valor com um objeto e seu mapa de mensagem.  
  
##  <a name="cdynamicchain"></a>CDynamicChain::CDynamicChain  
 O construtor.  
  
```
CDynamicChain();
```  
  
##  <a name="dtor"></a>CDynamicChain:: ~ CDynamicChain  
 O destruidor.  
  
```
~CDynamicChain();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="removechainentry"></a>CDynamicChain::RemoveChainEntry  
 Remove o mapa de mensagem especificado da coleção.  
  
```
BOOL RemoveChainEntry(DWORD dwChainID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwChainID`  
 [in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem. Originalmente, você define esse valor por meio de uma chamada para [SetChainEntry](#setchainentry).  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o mapa da mensagem for removido com êxito da coleção. Caso contrário, **FALSE**.  
  
##  <a name="setchainentry"></a>CDynamicChain::SetChainEntry  
 Adiciona o mapa de mensagem especificada à coleção.  
  
```
BOOL SetChainEntry(  
    DWORD dwChainID,
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwChainID`  
 [in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem.  
  
 `pObject`  
 [in] Um ponteiro para o objeto encadeado declarando o mapa da mensagem. Este objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).  
  
 `dwMsgMapID`  
 [in] O identificador do mapa de mensagem no objeto encadeado. O valor padrão é 0, que identifica o mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map). Para especificar um mapa de mensagem alternativo declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), passar `msgMapID`.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o mapa de mensagens foi adicionado com êxito à coleção. Caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se o `dwChainID` valor já existe na coleção, seu objeto associado e um mapa de mensagem são substituídas por `pObject` e `dwMsgMapID`, respectivamente. Caso contrário, uma nova entrada será adicionada.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
