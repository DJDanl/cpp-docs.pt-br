---
title: Macros de controle composto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlcom/ATL::BEGIN_SINK_MAP
- atlcom/ATL::END_SINK_MAP
- atlcom/ATL::SINK_ENTRY
dev_langs: C++
helpviewer_keywords: composite controls, macros
ms.assetid: 17f2dd5e-07e6-4aa6-b965-7a361c78c45e
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b609801a1716e47b208644be02d4746abf8c288a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="composite-control-macros"></a>Macros de controle composto
Essas macros definem mapas de coleta de eventos e entradas.  
  
|||  
|-|-|  
|[BEGIN_SINK_MAP](#begin_sink_map)|Marca o início do mapa de coletor de eventos para o controle composto.|  
|[END_SINK_MAP](#end_sink_map)|Marca o fim do mapa de coletor de eventos para o controle composto.|  
|[SINK_ENTRY](#sink_entry)|Entrada para o mapa de coletor de evento.|  
|[SINK_ENTRY_EX](#sink_entry_ex)|Entrada para o mapa de coletor de eventos com um parâmetro adicional.| 
|[SINK_ENTRY_EX_P](#sink_entry_ex)| (2017 do visual Studio) Semelhante ao SINK_ENTRY_EX, exceto que assume um ponteiro para o iid.|  
|[SINK_ENTRY_INFO](#sink_entry_info)|Entrada no mapa de coletor de eventos com informações de tipo manualmente fornecido para uso com [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md).|  
|[SINK_ENTRY_INFO_P](#sink_entry_info)| (2017 do visual Studio) Semelhante ao SINK_ENTRY_INFO, exceto que assume um ponteiro para o iid.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  

##  <a name="begin_sink_map"></a>BEGIN_SINK_MAP  
 Declara o início do mapa de coletor de eventos para o controle composto.  
  
```
BEGIN_SINK_MAP(_class)
```  
  
### <a name="parameters"></a>Parâmetros  
 `_class`  
 [in] Especifica o controle.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="end_sink_map"></a>END_SINK_MAP  
 Declara o fim do mapa de coletor de eventos para o controle composto.  
  
```
END_SINK_MAP()
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="sink_entry"></a>SINK_ENTRY  
 Declara a função de manipulador ( `fn`) para o evento especificado ( `dispid`), do controle identificado por `id`.  
  
```
SINK_ENTRY( id, dispid, fn )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Identifica o controle.  
  
 `dispid`  
 [in] Identifica o evento especificado.  
  
 `fn`  
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="sink_entry_ex"></a>SINK_ENTRY_EX e SINK_ENTRY_EX_P
 Declara a função de manipulador ( `fn`) para o evento especificado ( `dispid`), da interface de expedição ( *iid)*, para o controle identificado pela `id`.  
  
```
SINK_ENTRY_EX( id, iid, dispid, fn )
SINK_ENTRY_EX_P( id, piid, dispid, fn ) // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Identifica o controle.  
  
 `iid`  
 [in] Identifica a interface de expedição.  

 `piid`  
 [in] Ponteiro para a interface de expedição.  
  
 `dispid`  
 [in] Identifica o evento especificado.  
  
 `fn`  
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#136](../../atl/codesnippet/cpp/composite-control-macros_2.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="sink_entry_info"></a>SINK_ENTRY_INFO e SINK_ENTRY_INFO_P  
 Use o `SINK_ENTRY_INFO` macro dentro de um mapa de coletor de eventos para fornecer as informações necessárias para [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) para eventos de rota para a função de manipulador relevante.  
  
```
SINK_ENTRY_INFO( id, iid, dispid, fn, info )
SINK_ENTRY_INFO_P( id, piid, dispid, fn, info ) // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Inteiro sem sinal que identifica a origem do evento. Esse valor deve corresponder a `nID` parâmetro de modelo usado no relacionado [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe base.  
  
 `iid`  
 [in] IID que identifica a interface de expedição.  

 `piid`  
 [in] Ponteiro para o IID que identifica a interface de expedição.
  
 `dispid`  
 [in] DISPID identifica o evento especificado.  
  
 `fn`  
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.  
  
 `info`  
 [in] Digite informações para a função de manipulador de eventos. Essas informações de tipo são fornecidas na forma de um ponteiro para um `_ATL_FUNC_INFO` estrutura. `CC_CDECL`é a única opção com suporte no Windows CE para o `CALLCONV` campo o `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento indefinido.  
  
### <a name="remarks"></a>Comentários  
 Os parâmetros de quatro primeiros macro são os mesmos para o [SINK_ENTRY_EX](#sink_entry_ex) macro. O parâmetro final fornece informações de tipo para o evento. Implementação de CE ATL de ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de métodos de manipuladores de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  

## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais do controle de composição](../../atl/reference/composite-control-global-functions.md)
