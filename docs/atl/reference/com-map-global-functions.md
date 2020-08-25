---
title: Funções globais do mapa COM
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlInternalQueryInterface
- atlbase/ATL::InlineIsEqualIUnknown
helpviewer_keywords:
- COM interfaces, COM map global functions
ms.assetid: b9612d30-eb23-46ef-8093-d56f237d3cf1
ms.openlocfilehash: adf4e06eb46aed74d08071dccce1db549ca31226
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833589"
---
# <a name="com-map-global-functions"></a>Funções globais do mapa COM

Essas funções fornecem suporte para implementações de mapa COM `IUnknown` .

|Função|Descrição|
|-|-|
|[AtlInternalQueryInterface](#atlinternalqueryinterface)|Delega para o `IUnknown` de um objeto não agregado.|
|[InlineIsEqualIUnknown](#inlineisequaliunknown)|Gera um código eficiente para comparar interfaces com o `IUnknown` .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="atlinternalqueryinterface"></a><a name="atlinternalqueryinterface"></a> AtlInternalQueryInterface

Recupera um ponteiro para a interface solicitada.

```
HRESULT AtlInternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```

### <a name="parameters"></a>parâmetros

*pThis*<br/>
no Um ponteiro para o objeto que contém o mapa COM de interfaces expostas para `QueryInterface` .

*pEntries*<br/>
no Uma matriz de `_ATL_INTMAP_ENTRY` estruturas que acessa um mapa de interfaces disponíveis.

*IID*<br/>
no O GUID da interface que está sendo solicitada.

*ppvObject*<br/>
fora Um ponteiro para o ponteiro de interface especificado em *IID*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor Retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

`AtlInternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto for agregado, o não `AtlInternalQueryInterface` delegará para o desconhecido externo. Você pode inserir interfaces na tabela de mapa com com a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#94](../../atl/codesnippet/cpp/com-map-global-functions_1.cpp)]

## <a name="inlineisequaliunknown"></a><a name="inlineisequaliunknown"></a> InlineIsEqualIUnknown

Chame essa função para o caso especial de teste para `IUnknown` .

```
BOOL InlineIsEqualUnknown(REFGUID rguid1);
```

### <a name="parameters"></a>parâmetros

*rguid1*<br/>
no O GUID para comparar `IID_IUnknown` .

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[Macros de mapa COM](../../atl/reference/com-map-macros.md)
