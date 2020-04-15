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
ms.openlocfilehash: 67ad18c07a92cfecca44667908a8488e8c2da234
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331510"
---
# <a name="composite-control-macros"></a>Macros de controle composto

Essas macros definem mapas e entradas de sumidouro de eventos.

|||
|-|-|
|[BEGIN_SINK_MAP](#begin_sink_map)|Marca o início do mapa de afundamento de eventos para o controle composto.|
|[END_SINK_MAP](#end_sink_map)|Marca o fim do mapa do afundamento do evento para o controle composto.|
|[SINK_ENTRY](#sink_entry)|Entrada no mapa do dissipador de eventos.|
|[Sink_entry_ex](#sink_entry_ex)|Entrada no mapa do dissipador de eventos com um parâmetro adicional.|
|[SINK_ENTRY_EX_P](#sink_entry_ex)| (Visual Studio 2017) Semelhante ao SINK_ENTRY_EX exceto que é preciso um ponteiro para iid.|
|[Sink_entry_info](#sink_entry_info)|Entrada no mapa do dissipador de eventos com informações de tipo fornecidas manualmente para uso com [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md).|
|[SINK_ENTRY_INFO_P](#sink_entry_info)| (Visual Studio 2017) Semelhante ao SINK_ENTRY_INFO exceto que é preciso um ponteiro para iid.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_sink_map"></a><a name="begin_sink_map"></a>BEGIN_SINK_MAP

Declara o início do mapa de afundamento de eventos para o controle composto.

```
BEGIN_SINK_MAP(_class)
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[em] Especifica o controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

## <a name="end_sink_map"></a><a name="end_sink_map"></a>END_SINK_MAP

Declara o fim do mapa de afundamento de eventos para o controle composto.

```
END_SINK_MAP()
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

## <a name="sink_entry"></a><a name="sink_entry"></a>SINK_ENTRY

Declara a função do manipulador (*fn*) para o evento especificado *(dispid),* do controle identificado por *identificação*.

```
SINK_ENTRY( id, dispid, fn )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Identifica o controle.

*Dispid*<br/>
[em] Identifica o evento especificado.

*fn*<br/>
[em] Nome da função manipuladora de eventos. Esta função deve `_stdcall` usar a convenção de chamada e ter a assinatura apropriada no estilo de dispinterface.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#104](../../atl/codesnippet/cpp/composite-control-macros_1.h)]

### <a name="remarks"></a>Comentários

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

## <a name="sink_entry_ex-and-sink_entry_ex_p"></a><a name="sink_entry_ex"></a>SINK_ENTRY_EX e SINK_ENTRY_EX_P

Declara a função do manipulador (*fn*) para o evento especificado *(dispid),* da interface de despacho *(iid),* para o controle identificado por *id*.

```
SINK_ENTRY_EX( id, iid, dispid, fn )
SINK_ENTRY_EX_P( id, piid, dispid, fn ) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Identifica o controle.

*Iid*<br/>
[em] Identifica a interface de despacho.

*Piid*<br/>
[em] Ponteiro para a interface de despacho.

*Dispid*<br/>
[em] Identifica o evento especificado.

*fn*<br/>
[em] Nome da função manipuladora de eventos. Esta função deve `_stdcall` usar a convenção de chamada e ter a assinatura apropriada no estilo de dispinterface.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#136](../../atl/codesnippet/cpp/composite-control-macros_2.h)]

### <a name="remarks"></a>Comentários

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

## <a name="sink_entry_info-and-sink_entry_info_p"></a><a name="sink_entry_info"></a>SINK_ENTRY_INFO e SINK_ENTRY_INFO_P

Use a macro SINK_ENTRY_INFO dentro de um mapa de sumidouro de eventos para fornecer as informações necessárias pelo [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) para direcionar eventos para a função de manipulador relevante.

```
SINK_ENTRY_INFO( id, iid, dispid, fn, info )
SINK_ENTRY_INFO_P( id, piid, dispid, fn, info ) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Inteiro não assinado identificando a fonte do evento. Esse valor deve corresponder ao parâmetro de modelo *nID* usado na classe base [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) relacionada.

*Iid*<br/>
[em] IID que identifica a interface de despacho.

*Piid*<br/>
[em] Ponteiro para IID que identifica a interface de despacho.

*Dispid*<br/>
[em] DISPID identificando o evento especificado.

*fn*<br/>
[em] Nome da função manipuladora de eventos. Esta função deve `_stdcall` usar a convenção de chamada e ter a assinatura apropriada no estilo de dispinterface.

*Informação*<br/>
[em] Digite informações para a função de manipulador de eventos. Essas informações de tipo são fornecidas na `_ATL_FUNC_INFO` forma de um ponteiro para uma estrutura. CC_CDECL é a única opção suportada no Windows CE `_ATL_FUNC_INFO` para o campo CALLCONV da estrutura. Qualquer outro valor não é suportado, portanto, seu comportamento indefinido.

### <a name="remarks"></a>Comentários

Os quatro primeiros parâmetros macro são os mesmos da [SINK_ENTRY_EX](#sink_entry_ex) macro. O parâmetro final fornece informações de tipo para o evento. A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de controle composto](../../atl/reference/composite-control-global-functions.md)
