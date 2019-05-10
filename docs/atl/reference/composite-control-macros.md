---
title: Macros de controle de composição
ms.date: 05/06/2019
f1_keywords:
- atlcom/ATL::BEGIN_SINK_MAP
- atlcom/ATL::END_SINK_MAP
- atlcom/ATL::SINK_ENTRY
helpviewer_keywords:
- composite controls, macros
ms.assetid: 17f2dd5e-07e6-4aa6-b965-7a361c78c45e
ms.openlocfilehash: 685bf55910d4746463de30b17b71aa6d246db199
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221109"
---
# <a name="composite-control-macros"></a>Macros de controle de composição

Essas macros definem os mapas de coleta de eventos e entradas.

|||
|-|-|
|[BEGIN_SINK_MAP](#begin_sink_map)|Marca o início do mapa do coletor de eventos para o controle composto.|
|[END_SINK_MAP](#end_sink_map)|Marca o fim do mapa do coletor de eventos para o controle composto.|
|[SINK_ENTRY](#sink_entry)|Entrada no mapa de coletor de eventos.|
|[SINK_ENTRY_EX](#sink_entry_ex)|Entrada no mapa de coletor de eventos com um parâmetro adicional.|
|[SINK_ENTRY_EX_P](#sink_entry_ex)| (Visual Studio 2017) Semelhante ao SINK_ENTRY_EX, exceto que assume um ponteiro para um iid.|
|[SINK_ENTRY_INFO](#sink_entry_info)|Entrada no mapa de coletor de eventos com informações de tipo fornecido manualmente para uso com [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md).|
|[SINK_ENTRY_INFO_P](#sink_entry_info)| (Visual Studio 2017) Semelhante ao SINK_ENTRY_INFO, exceto que assume um ponteiro para um iid.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="begin_sink_map"></a>  BEGIN_SINK_MAP

Declara o início do mapa do coletor de eventos para o controle composto.

```
BEGIN_SINK_MAP(_class)
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[in] Especifica o controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

##  <a name="end_sink_map"></a>  END_SINK_MAP

Declara o final do mapa do coletor de eventos para o controle composto.

```
END_SINK_MAP()
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

##  <a name="sink_entry"></a>  SINK_ENTRY

Declara a função do manipulador (*fn*) para o evento especificado (*dispid*), do controle identificado pela *id*.

```
SINK_ENTRY( id, dispid, fn )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] Identifica o controle.

*dispid*<br/>
[in] Identifica o evento especificado.

*fn*<br/>
[in] Nome da função de manipulador de eventos. Essa função deve usar o `_stdcall` convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

##  <a name="sink_entry_ex"></a>  SINK_ENTRY_EX e SINK_ENTRY_EX_P

Declara a função do manipulador (*fn*) para o evento especificado (*dispid*), da interface de expedição (*iid*), para o controle identificado pela *id*.

```
SINK_ENTRY_EX( id, iid, dispid, fn )
SINK_ENTRY_EX_P( id, piid, dispid, fn ) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] Identifica o controle.

*iid*<br/>
[in] Identifica a interface de expedição.

*piid*<br/>
[in] Ponteiro para a interface de expedição.

*dispid*<br/>
[in] Identifica o evento especificado.

*fn*<br/>
[in] Nome da função de manipulador de eventos. Essa função deve usar o `_stdcall` convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#136](../../atl/codesnippet/cpp/composite-control-macros_2.h)]

### <a name="remarks"></a>Comentários

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

##  <a name="sink_entry_info"></a>  SINK_ENTRY_INFO e SINK_ENTRY_INFO_P

Use a macro SINK_ENTRY_INFO dentro de um mapa de coletor de eventos para fornecer as informações necessárias pelo [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) para eventos de rota para a função de manipulador relevante.

```
SINK_ENTRY_INFO( id, iid, dispid, fn, info )
SINK_ENTRY_INFO_P( id, piid, dispid, fn, info ) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] Inteiro sem sinal de identificar a origem do evento. Esse valor deve corresponder a *nID* parâmetro de modelo usado na relacionado [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe base.

*iid*<br/>
[in] IID que identifica a interface de expedição.

*piid*<br/>
[in] Ponteiro para um IID que identifica a interface de expedição.

*dispid*<br/>
[in] DISPID identifica o evento especificado.

*fn*<br/>
[in] Nome da função de manipulador de eventos. Essa função deve usar o `_stdcall` convenção de chamada e ter a assinatura de estilo de dispinterface apropriado.

*info*<br/>
[in] Informações de tipo para a função de manipulador de eventos. Essas informações de tipo são fornecidas na forma de um ponteiro para um `_ATL_FUNC_INFO` estrutura. CC_CDECL é a única opção com suporte no Windows CE para o campo conv do `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento é indefinido.

### <a name="remarks"></a>Comentários

Os parâmetros de quatro primeiros macro são os mesmos para o [SINK_ENTRY_EX](#sink_entry_ex) macro. O parâmetro final fornece informações de tipo para o evento. Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais do controle de composição](../../atl/reference/composite-control-global-functions.md)
