---
title: Classe CDynamicChain | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CDynamicChain
- ATL.CDynamicChain
- CDynamicChain
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 4da97d0b3d72400d7e285fde187e6860759900af
ms.lasthandoff: 02/25/2017

---
# <a name="cdynamicchain-class"></a>Classe CDynamicChain
Essa classe fornece métodos que suporte o encadeamento dinâmico de mapas de mensagem.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CDynamicChain
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDynamicChain::CDynamicChain](#cdynamicchain)|O construtor.|  
|[CDynamicChain:: ~ CDynamicChain](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDynamicChain::CallChain](#callchain)|Direciona uma mensagem do Windows ao mapa de mensagem de outro objeto.|  
|[CDynamicChain::RemoveChainEntry](#removechainentry)|Remove uma entrada de mapa de mensagem da coleção.|  
|[CDynamicChain::SetChainEntry](#setchainentry)|Adiciona uma entrada de mapa da mensagem à coleção ou modifica uma entrada existente.|  
  
## <a name="remarks"></a>Comentários  
 `CDynamicChain`gerencia uma coleção de mapas de mensagem, permitindo que uma mensagem do Windows ser direcionado, em tempo de execução ao mapa de mensagem de outro objeto.  
  
 Para adicionar suporte a encadeamento dinâmico de mapas de mensagem, faça o seguinte:  
  
-   Derive a classe de `CDynamicChain`. No mapa de mensagem, especifique o [CHAIN_MSG_MAP_DYNAMIC](http://msdn.microsoft.com/library/7e5c72b7-cb31-4f3b-8a1b-6293804af220) macro cadeia ao mapa de mensagem padrão do outro objeto.  
  
-   Derivar todas as classes que você deseja encadear a partir de [CMessageMap](../../atl/reference/cmessagemap-class.md). `CMessageMap`permite que um objeto expor seus mapas de mensagem a outros objetos.  
  
-   Chamar `CDynamicChain::SetChainEntry` para identificar qual objeto e qual mensagem do mapa que você deseja vincular a.  
  
 Por exemplo, suponha que sua classe é definida da seguinte maneira:  
  
 [!code-cpp[88 NVC_ATL_Windowing](../../atl/codesnippet/cpp/cdynamicchain-class_1.h)]  
  
 O cliente então chama `CMyWindow::SetChainEntry`:  
  
 [!code-cpp[NVC_ATL_Windowing&#89;](../../atl/codesnippet/cpp/cdynamicchain-class_2.cpp)]  
  
 onde `chainedObj` é o objeto encadeado e é uma instância de uma classe derivada de `CMessageMap`. Agora, se `myCtl` recebe uma mensagem que não é tratada por `OnPaint` ou `OnSetFocus`, o procedimento de janela direciona a mensagem `chainedObj`do mapa da mensagem padrão.  
  
 Para obter mais informações sobre o encadeamento de mapa de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="a-namecallchaina--cdynamicchaincallchain"></a><a name="callchain"></a>CDynamicChain::CallChain  
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
 O procedimento de janela invocar `CallChain`, você deve especificar o [CHAIN_MSG_MAP_DYNAMIC](http://msdn.microsoft.com/library/7e5c72b7-cb31-4f3b-8a1b-6293804af220) macro em seu mapa de mensagem. Para obter um exemplo, consulte o [CDynamicChain](../../atl/reference/cdynamicchain-class.md) visão geral.  
  
 `CallChain`requer uma chamada anterior a [SetChainEntry](#setchainentry) para associar o `dwChainID` valor com um objeto e seu mapa de mensagem.  
  
##  <a name="a-namecdynamicchaina--cdynamicchaincdynamicchain"></a><a name="cdynamicchain"></a>CDynamicChain::CDynamicChain  
 O construtor.  
  
```
CDynamicChain();
```  
  
##  <a name="a-namedtora--cdynamicchaincdynamicchain"></a><a name="dtor"></a>CDynamicChain:: ~ CDynamicChain  
 O destruidor.  
  
```
~CDynamicChain();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="a-nameremovechainentrya--cdynamicchainremovechainentry"></a><a name="removechainentry"></a>CDynamicChain::RemoveChainEntry  
 Remove o mapa da mensagem especificado da coleção.  
  
```
BOOL RemoveChainEntry(DWORD dwChainID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwChainID`  
 [in] O identificador exclusivo associado com o objeto encadeado e seu mapa de mensagem. Originalmente, você define esse valor por meio de uma chamada para [SetChainEntry](#setchainentry).  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o mapa da mensagem for removido com êxito da coleção. Caso contrário, **FALSE**.  
  
##  <a name="a-namesetchainentrya--cdynamicchainsetchainentry"></a><a name="setchainentry"></a>CDynamicChain::SetChainEntry  
 Adiciona o mapa da mensagem especificado à coleção.  
  
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
 [in] O identificador do mapa de mensagens no objeto encadeado. O valor padrão é 0, que identifica o mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554). Para especificar um mapa de mensagens alternativos declarados com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), passar `msgMapID`.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o mapa da mensagem é adicionado com êxito à coleção. Caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se o `dwChainID` valor já existe na coleção, o objeto associado e o mapa da mensagem são substituídos por `pObject` e `dwMsgMapID`, respectivamente. Caso contrário, uma nova entrada é adicionada.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

