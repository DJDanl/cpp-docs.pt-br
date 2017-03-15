---
title: Controle composto Macros | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- composite controls, macros
ms.assetid: 17f2dd5e-07e6-4aa6-b965-7a361c78c45e
caps.latest.revision: 16
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
ms.sourcegitcommit: 8cdedc5cfac9d49df812ae6fcfcc548201b1edb5
ms.openlocfilehash: 9fb8a907c8052c9816d6b87247e903a63f34a5be
ms.lasthandoff: 02/25/2017

---
# <a name="composite-control-macros"></a>Macros de controle composto
Essas macros definem entradas e mapas de coleta de eventos.  
  
|||  
|-|-|  
|[BEGIN_SINK_MAP](#begin_sink_map)|Marca o início do mapa de coletor de eventos para o controle composto.|  
|[END_SINK_MAP](#end_sink_map)|Marca o fim do mapa de coletor de eventos para o controle composto.|  
|[SINK_ENTRY](#sink_entry)|Entrada no mapa de coletor de eventos.|  
|[SINK_ENTRY_EX](#sink_entry_ex)|Entrada no mapa de coletor de eventos com um parâmetro adicional.| 
|[SINK_ENTRY_EX_P](#sink_entry_ex)| (2017 do visual Studio) Semelhante ao SINK_ENTRY_EX, exceto que assume um ponteiro para a iid.|  
|[SINK_ENTRY_INFO](#sink_entry_info)|Entrada no mapa de coletor de eventos com informações de tipo manualmente fornecido para uso com [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md).|  
|[SINK_ENTRY_INFO_P](#sink_entry_info)| (2017 do visual Studio) Semelhante ao SINK_ENTRY_INFO, exceto que assume um ponteiro para a iid.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  

##  <a name="a-namebeginsinkmapa--beginsinkmap"></a><a name="begin_sink_map"></a>BEGIN_SINK_MAP  
 Declara o início do mapa de coletor de eventos para o controle composto.  
  
```
BEGIN_SINK_MAP(_class)
```  
  
### <a name="parameters"></a>Parâmetros  
 `_class`  
 [in] Especifica o controle.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#104;](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="a-nameendsinkmapa--endsinkmap"></a><a name="end_sink_map"></a>END_SINK_MAP  
 Declara o fim do mapa de coletor de eventos para o controle composto.  
  
```
END_SINK_MAP()
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#104;](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="a-namesinkentrya--sinkentry"></a><a name="sink_entry"></a>SINK_ENTRY  
 Declara a função do manipulador ( `fn`) para o evento especificado ( `dispid`), do controle identificado por `id`.  
  
```
SINK_ENTRY( id, dispid, fn )
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Identifica o controle.  
  
 `dispid`  
 [in] Identifica o evento especificado.  
  
 `fn`  
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura dispinterface-estilo apropriado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#104;](../../atl/codesnippet/cpp/composite-control-macros_1.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="a-namesinkentryexa--sinkentryex-and-sinkentryexp"></a><a name="sink_entry_ex"></a>SINK_ENTRY_EX e SINK_ENTRY_EX_P
 Declara a função do manipulador ( `fn`) para o evento especificado ( `dispid`), a interface de expedição ( *iid)*, para o controle identificado pela `id`.  
  
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
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura dispinterface-estilo apropriado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing&#136;](../../atl/codesnippet/cpp/composite-control-macros_2.h)]  
  
### <a name="remarks"></a>Comentários  
 Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  
##  <a name="a-namesinkentryinfoa--sinkentryinfo-and-sinkentryinfop"></a><a name="sink_entry_info"></a>SINK_ENTRY_INFO e SINK_ENTRY_INFO_P  
 Use o `SINK_ENTRY_INFO` macro dentro de um mapa coletor de evento para fornecer as informações necessárias pelo [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) para rotear os eventos para a função de manipulador relevante.  
  
```
SINK_ENTRY_INFO( id, iid, dispid, fn, info )
SINK_ENTRY_INFO_P( id, piid, dispid, fn, info ) // (Visual Studio 2017)
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 [in] Inteiro sem sinal que identifica a origem do evento. Esse valor deve corresponder a `nID` parâmetro de modelo usado em relacionado [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe base.  
  
 `iid`  
 [in] IID que identifica a interface de expedição.  

 `piid`  
 [in] Ponteiro para IID que identifica a interface de expedição.
  
 `dispid`  
 [in] DISPID identifica o evento especificado.  
  
 `fn`  
 [in] Nome da função de manipulador de eventos. Essa função deve usar o **stdcall** convenção de chamada e ter a assinatura dispinterface-estilo apropriado.  
  
 `info`  
 [in] Digite informações para a função de manipulador de eventos. Essas informações de tipo são fornecidas na forma de um ponteiro para um `_ATL_FUNC_INFO` estrutura. `CC_CDECL`é a única opção com suporte no Windows CE para o `CALLCONV` campo o `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento indefinido.  
  
### <a name="remarks"></a>Comentários  
 Os parâmetros de quatro primeiros macro são as mesmas para o [SINK_ENTRY_EX](#sink_entry_ex) macro. O parâmetro final fornece informações de tipo para o evento. Implementação de CE ATL do ActiveX evento coletores somente oferece suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.  
  

## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais do controle composto](../../atl/reference/composite-control-global-functions.md)

