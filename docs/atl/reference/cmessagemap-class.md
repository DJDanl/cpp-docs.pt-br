---
title: Classe CMessageMap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 22
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
ms.openlocfilehash: f0b40c73101463b934e3fcf299171bea142fe838
ms.lasthandoff: 02/25/2017

---
# <a name="cmessagemap-class"></a>Classe CMessageMap
Essa classe permite que mapas de mensagem de um objeto para ser acessado por outro objeto.  
  
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
 `CMessageMap`é uma classe base abstrata que permite que a mensagem de um objeto é mapeado para ser acessado por outro objeto. Em ordem de um objeto para expor seus mapas de mensagem, sua classe deve derivar de `CMessageMap`.  
  
 ATL usa `CMessageMap` windows suporte contido e encadeamento de mapa de mensagem dinâmica. Por exemplo, qualquer classe que contém um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) objeto deve derivar de `CMessageMap`. O código a seguir é obtido a [SUBEDIT](../../visual-cpp-samples.md) exemplo. Por meio de [CComControl](../../atl/reference/ccomcontrol-class.md), o `CAtlEdit` classe automaticamente deriva de `CMessageMap`.  
  
 [!code-cpp[NVC_ATL_Windowing&#90;](../../atl/codesnippet/cpp/cmessagemap-class_1.h)]  
  
 Porque a janela independente, `m_EditCtrl`, usará um mapa de mensagem na classe recipiente, `CAtlEdit` deriva de `CMessageMap`.  
  
 Para obter mais informações sobre mapas de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="processwindowmessage"></a>CMessageMap::ProcessWindowMessage  
 Acessa o mapa da mensagem identificado por `dwMsgMapID` em um `CMessageMap`-classe derivada.  
  
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
  
 `dwMsgMapID`  
 [in] O identificador do mapa de mensagens que irá processar a mensagem. O mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554), é identificado por 0. Um mapa de mensagens alternativos, declarado com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), é identificado por `msgMapID`.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a mensagem é totalmente tratado; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo procedimento de janela de um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) de objeto ou de um objeto que é dinamicamente encadeamento ao mapa da mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicChain](../../atl/reference/cdynamicchain-class.md)   
 [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554)   
 [ALT_MSG_MAP](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

