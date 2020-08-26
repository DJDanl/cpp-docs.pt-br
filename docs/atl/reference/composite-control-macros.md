---
title: Macros de controle composto
ms.date: 05/06/2019
f1_keywords:
- atlcom/ATL::BEGIN_SINK_MAP
- atlcom/ATL::END_SINK_MAP
- atlcom/ATL::SINK_ENTRY
helpviewer_keywords:
- composite controls, macros
ms.assetid: 17f2dd5e-07e6-4aa6-b965-7a361c78c45e
ms.openlocfilehash: 7ac13a11646faca53b38ec610dc0388bdd14d251
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833537"
---
# <a name="composite-control-macros"></a>Macros de controle composto

Essas macros definem mapas e entradas do coletor de eventos.

|Macro|Descrição|
|-|-|
|[BEGIN_SINK_MAP](#begin_sink_map)|Marca o início do mapa do coletor de eventos para o controle composto.|
|[END_SINK_MAP](#end_sink_map)|Marca o final do mapa do coletor de eventos para o controle composto.|
|[SINK_ENTRY](#sink_entry)|Entrada para o mapa do coletor de eventos.|
|[SINK_ENTRY_EX](#sink_entry_ex)|Entrada para o mapa do coletor de eventos com um parâmetro adicional.|
|[SINK_ENTRY_EX_P](#sink_entry_ex)| (Visual Studio 2017) Semelhante a SINK_ENTRY_EX, exceto pelo fato de que ele usa um ponteiro para IID.|
|[SINK_ENTRY_INFO](#sink_entry_info)|Entrada para o mapa do coletor de eventos com informações de tipo fornecidas manualmente para uso com [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md).|
|[SINK_ENTRY_INFO_P](#sink_entry_info)| (Visual Studio 2017) Semelhante a SINK_ENTRY_INFO, exceto pelo fato de que ele usa um ponteiro para IID.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="begin_sink_map"></a><a name="begin_sink_map"></a> BEGIN_SINK_MAP

Declara o início do mapa do coletor de eventos para o controle composto.

```
BEGIN_SINK_MAP(_class)
```

### <a name="parameters"></a>parâmetros

*_class*<br/>
no Especifica o controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

## <a name="end_sink_map"></a><a name="end_sink_map"></a> END_SINK_MAP

Declara o final do mapa do coletor de eventos para o controle composto.

```
END_SINK_MAP()
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

## <a name="sink_entry"></a><a name="sink_entry"></a> SINK_ENTRY

Declara a função de manipulador (*FN*) para o evento especificado (*DISPID*) do controle identificado pela *ID*.

```
SINK_ENTRY( id, dispid, fn )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no Identifica o controle.

*DISPID*<br/>
no Identifica o evento especificado.

*fn*<br/>
no Nome da função do manipulador de eventos. Essa função deve usar a `_stdcall` Convenção de chamada e ter a assinatura de estilo de dispinterface apropriada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

## <a name="sink_entry_ex-and-sink_entry_ex_p"></a><a name="sink_entry_ex"></a> SINK_ENTRY_EX e SINK_ENTRY_EX_P

Declara a função de manipulador (*FN*) para o evento especificado (*DISPID*) da interface de expedição (*IID*), para o controle identificado pela *ID*.

```
SINK_ENTRY_EX( id, iid, dispid, fn )
SINK_ENTRY_EX_P( id, piid, dispid, fn ) // (Visual Studio 2017)
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no Identifica o controle.

*IID*<br/>
no Identifica a interface de expedição.

*piid*<br/>
no Ponteiro para a interface de expedição.

*DISPID*<br/>
no Identifica o evento especificado.

*fn*<br/>
no Nome da função do manipulador de eventos. Essa função deve usar a `_stdcall` Convenção de chamada e ter a assinatura de estilo de dispinterface apropriada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#136](../../atl/codesnippet/cpp/composite-control-macros_2.h)]

### <a name="remarks"></a>Comentários

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

## <a name="sink_entry_info-and-sink_entry_info_p"></a><a name="sink_entry_info"></a> SINK_ENTRY_INFO e SINK_ENTRY_INFO_P

Use a macro SINK_ENTRY_INFO em um mapa de coletor de eventos para fornecer as informações necessárias pelo [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) para rotear eventos para a função de manipulador relevante.

```
SINK_ENTRY_INFO( id, iid, dispid, fn, info )
SINK_ENTRY_INFO_P( id, piid, dispid, fn, info ) // (Visual Studio 2017)
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no Inteiro não assinado que identifica a origem do evento. Esse valor deve corresponder ao parâmetro de modelo *NID* usado na classe base [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) relacionada.

*IID*<br/>
no IID que identifica a interface de expedição.

*piid*<br/>
no Ponteiro para IID que identifica a interface de expedição.

*DISPID*<br/>
no DISPID identificando o evento especificado.

*fn*<br/>
no Nome da função do manipulador de eventos. Essa função deve usar a `_stdcall` Convenção de chamada e ter a assinatura de estilo de dispinterface apropriada.

*detalhes*<br/>
no Informações de tipo para a função do manipulador de eventos. Essas informações de tipo são fornecidas na forma de um ponteiro para uma `_ATL_FUNC_INFO` estrutura. CC_CDECL é a única opção com suporte no Windows CE para o campo CALLCONV da `_ATL_FUNC_INFO` estrutura. Qualquer outro valor não é suportado, portanto seu comportamento é indefinido.

### <a name="remarks"></a>Comentários

Os primeiros quatro parâmetros de macro são os mesmos da macro [SINK_ENTRY_EX](#sink_entry_ex) . O parâmetro final fornece informações de tipo para o evento. A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de controle composto](../../atl/reference/composite-control-global-functions.md)
