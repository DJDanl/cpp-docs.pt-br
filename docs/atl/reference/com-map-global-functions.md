---
title: Funções globais de mapa COM
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlInternalQueryInterface
- atlbase/ATL::InlineIsEqualIUnknown
helpviewer_keywords:
- COM interfaces, COM map global functions
ms.assetid: b9612d30-eb23-46ef-8093-d56f237d3cf1
ms.openlocfilehash: 75d081674fa4b63e66f1296834d3de305665ab9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62258410"
---
# <a name="com-map-global-functions"></a>Funções globais de mapa COM

Essas funções fornecem suporte para o mapa COM `IUnknown` implementações.

|||
|-|-|
|[AtlInternalQueryInterface](#atlinternalqueryinterface)|Delega para o `IUnknown` de um objeto não agregado.|
|[InlineIsEqualIUnknown](#inlineisequaliunknown)|Gera um código eficiente para comparar as interfaces com `IUnknown`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="atlinternalqueryinterface"></a>  AtlInternalQueryInterface

Recupera um ponteiro para a interface solicitada.

```
HRESULT AtlInternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*pThis*<br/>
[in] Um ponteiro para o objeto que contém o mapa COM interfaces expostas a `QueryInterface`.

*pEntries*<br/>
[in] Uma matriz de `_ATL_INTMAP_ENTRY` estruturas que acessam um mapa das interfaces disponíveis.

*iid*<br/>
[in] O GUID da interface que está sendo solicitado.

*ppvObject*<br/>
[out] Um ponteiro para o ponteiro de interface especificado na *iid*, ou nulo se a interface não foi encontrada.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlInternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto for agregado, `AtlInternalQueryInterface` não delegar para o externo desconhecido. Você pode inserir interfaces na tabela de mapa COM a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#94](../../atl/codesnippet/cpp/com-map-global-functions_1.cpp)]

##  <a name="inlineisequaliunknown"></a>  InlineIsEqualIUnknown

Chame essa função, para o caso especial de teste para `IUnknown`.

```
BOOL InlineIsEqualUnknown(REFGUID rguid1);
```

### <a name="parameters"></a>Parâmetros

*rguid1*<br/>
[in] O GUID a ser comparado com `IID_IUnknown`.

## <a name="see-also"></a>Consulte também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de mapa COM](../../atl/reference/com-map-macros.md)
