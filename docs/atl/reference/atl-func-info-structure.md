---
title: Estrutura de _ATL_FUNC_INFO
ms.date: 11/04/2016
f1_keywords:
- _ATL_FUNC_INFO
- ATL::_ATL_FUNC_INFO
- ATL._ATL_FUNC_INFO
helpviewer_keywords:
- _ATL_FUNC_INFO structure
- ATL_FUNC_INFO structure
ms.assetid: 441ebe2c-f971-47de-9f52-a258e8d6f88e
ms.openlocfilehash: b1c740cf1a1ed344dbceb028bd1f39a87fc09363
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168586"
---
# <a name="_atl_func_info-structure"></a>Estrutura de _ATL_FUNC_INFO

Contém informações de tipo usadas para descrever um método ou uma propriedade em uma dispinterface.

## <a name="syntax"></a>Sintaxe

```cpp
struct _ATL_FUNC_INFO {
    CALLCONV cc;
    VARTYPE vtReturn;
    SHORT nParams;
    VARTYPE pVarTypes[_ATL_MAX_VARTYPES];
};
```

## <a name="members"></a>Membros

`cc`<br/>
A convenção de chamada. Ao usar essa estrutura com a classe [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) , esse membro deve ser CC_STDCALL. `CC_CDECL`é a única opção com suporte no Windows CE para `CALLCONV` o campo da `_ATL_FUNC_INFO` estrutura. Qualquer outro valor não é suportado, portanto seu comportamento é indefinido.

`vtReturn`<br/>
O tipo de variante do valor de retorno da função.

`nParams`<br/>
O número de parâmetros de função.

`pVarTypes`<br/>
Uma matriz de tipos variantes dos parâmetros de função.

## <a name="remarks"></a>Comentários

Internamente, a ATL usa essa estrutura para manter as informações obtidas de uma biblioteca de tipos. Talvez seja necessário manipular essa estrutura diretamente se você fornecer informações de tipo para um manipulador de eventos usado com a classe [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) e [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) macro.

## <a name="example"></a>Exemplo

Dado um método de dispinterface definido em IDL:

[!code-cpp[NVC_ATL_Windowing#139](../../atl/codesnippet/cpp/atl-func-info-structure_1.idl)]

você definiria uma `_ATL_FUNC_INFO` estrutura:

[!code-cpp[NVC_ATL_Windowing#140](../../atl/codesnippet/cpp/atl-func-info-structure_2.h)]

## <a name="requirements"></a>Requisitos

Cabeçalho: atlcom. h

## <a name="see-also"></a>Confira também

[Classes e structs](../../atl/reference/atl-classes.md)<br/>
[Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)
