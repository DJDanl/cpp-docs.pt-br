---
title: Classe CMessageMap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 04aff6922358048fcbd330096eb26a412cdb75ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmessagemap-class"></a>Classe CMessageMap
Essa classe permite que mapas de mensagem de um objeto para ser acessado por outro objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
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
  
 ATL usa `CMessageMap` suporte contido windows e o encadeamento de mapa de mensagem dinâmica. Por exemplo, qualquer classe que contém um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) objeto deve ser derivado de `CMessageMap`. O código a seguir é obtido a [SUBEDIT](../../visual-cpp-samples.md) exemplo. Por meio de [CComControl](../../atl/reference/ccomcontrol-class.md), o `CAtlEdit` classe automaticamente é derivada de `CMessageMap`.  
  
 [!code-cpp[NVC_ATL_Windowing#90](../../atl/codesnippet/cpp/cmessagemap-class_1.h)]  
  
 Porque a janela independente, `m_EditCtrl`, usará um mapa de mensagem na classe que contém, `CAtlEdit` deriva de `CMessageMap`.  
  
 Para obter mais informações sobre mapas de mensagem, consulte [mapas de mensagem](../../atl/message-maps-atl.md) no artigo "Classes de janela ATL".  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="processwindowmessage"></a>CMessageMap::ProcessWindowMessage  
 Acessa o mapa de mensagem identificado por `dwMsgMapID` em um `CMessageMap`-classe derivada.  
  
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
 [in] O identificador do mapa da mensagem que processará a mensagem. O mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map), é identificado por 0. Um mapa de mensagem alternativo, declarado com [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map), é identificado pelo `msgMapID`.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a mensagem é totalmente tratada; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Chamado pelo procedimento de janela de um [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) de objeto ou de um objeto que é dinamicamente encadeamento ao mapa da mensagem.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDynamicChain](../../atl/reference/cdynamicchain-class.md)   
 [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)   
 [ALT_MSG_MAP(msgMapID)](message-map-macros-atl.md#alt_msg_map)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
