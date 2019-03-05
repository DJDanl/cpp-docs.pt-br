---
title: _ATL_FUNC_INFO Structure
ms.date: 11/04/2016
f1_keywords:
- _ATL_FUNC_INFO
- ATL::_ATL_FUNC_INFO
- ATL._ATL_FUNC_INFO
helpviewer_keywords:
- _ATL_FUNC_INFO structure
- ATL_FUNC_INFO structure
ms.assetid: 441ebe2c-f971-47de-9f52-a258e8d6f88e
ms.openlocfilehash: f6cf32bab86d741f3b0750c150c7bbc647b27ddc
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57299537"
---
# <a name="atlfuncinfo-structure"></a>_ATL_FUNC_INFO Structure

Contém informações de tipo usadas para descrever um método ou propriedade em um dispinterface.

## <a name="syntax"></a>Sintaxe

```
struct _ATL_FUNC_INFO {
    CALLCONV cc;
    VARTYPE vtReturn;
    SHORT nParams;
    VARTYPE pVarTypes[_ATL_MAX_VARTYPES];
};
```

## <a name="members"></a>Membros

`cc`<br/>
A convenção de chamada. Ao usar essa estrutura com o [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe, esse membro deve ser CC_STDCALL. `CC_CDECL` é a única opção com suporte no Windows CE para o `CALLCONV` campo do `_ATL_FUNC_INFO` estrutura. Não há suporte para qualquer outro valor, portanto, seu comportamento é indefinido.

`vtReturn`<br/>
O tipo de variante da função retornar um valor.

`nParams`<br/>
O número de parâmetros de função.

`pVarTypes`<br/>
Uma matriz de tipos variantes dos parâmetros de função.

## <a name="remarks"></a>Comentários

Internamente, o ATL usa essa estrutura para manter as informações obtidas de uma biblioteca de tipos. Talvez você precise manipular essa estrutura diretamente se você fornecer informações de tipo para um manipulador de eventos usado com o [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md) classe e [SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info) macro.

## <a name="example"></a>Exemplo

Um método de dispinterface definido no IDL:

[!code-cpp[NVC_ATL_Windowing#139](../../atl/codesnippet/cpp/atl-func-info-structure_1.idl)]

você definiria um `_ATL_FUNC_INFO` estrutura:

[!code-cpp[NVC_ATL_Windowing#140](../../atl/codesnippet/cpp/atl-func-info-structure_2.h)]

## <a name="requirements"></a>Requisitos

Header: atlcom.h

## <a name="see-also"></a>Consulte também

[Classes e structs](../../atl/reference/atl-classes.md)<br/>
[Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)
