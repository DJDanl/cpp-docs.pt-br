---
title: COM Map Global Functions
ms.date: 11/04/2016
f1_keywords:
- atlbase/ATL::AtlInternalQueryInterface
- atlbase/ATL::InlineIsEqualIUnknown
helpviewer_keywords:
- COM interfaces, COM map global functions
ms.assetid: b9612d30-eb23-46ef-8093-d56f237d3cf1
ms.openlocfilehash: c4ce7c7a68c0744ad65ef4914088fa12d3340628
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326693"
---
# <a name="com-map-global-functions"></a>COM Map Global Functions

Essas funções fornecem suporte `IUnknown` para implementações do COM Map.

|||
|-|-|
|[AtlInternalQueryInterface](#atlinternalqueryinterface)|Delegados para `IUnknown` um objeto não agregado.|
|[InlineIsEqualIUnknown](#inlineisequaliunknown)|Gera código eficiente para comparar `IUnknown`interfaces com .|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="atlinternalqueryinterface"></a><a name="atlinternalqueryinterface"></a>AtlInternalQueryInterface

Recupera um ponteiro para a interface solicitada.

```
HRESULT AtlInternalQueryInterface(
    void* pThis,
    const _ATL_INTMAP_ENTRY* pEntries,
    REFIID iid,
    void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*Pthis*<br/>
[em] Um ponteiro para o objeto que contém o `QueryInterface`mapa COM de interfaces expostas a .

*entradas pEntries*<br/>
[em] Uma matriz `_ATL_INTMAP_ENTRY` de estruturas que acessam um mapa de interfaces disponíveis.

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppvobject*<br/>
[fora] Um ponteiro para o ponteiro de interface especificado em *iid*ou NULL se a interface não for encontrada.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

`AtlInternalQueryInterface` somente lida com interfaces na tabela de mapa COM. Se o objeto estiver `AtlInternalQueryInterface` agregado, não delege ao desconhecido externo. Você pode inserir interfaces na tabela de mapas COM com o [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) de macro ou uma de suas variantes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#94](../../atl/codesnippet/cpp/com-map-global-functions_1.cpp)]

## <a name="inlineisequaliunknown"></a><a name="inlineisequaliunknown"></a>InlineIsEqualiUnknown

Chame esta função, para o caso `IUnknown`especial de teste para .

```
BOOL InlineIsEqualUnknown(REFGUID rguid1);
```

### <a name="parameters"></a>Parâmetros

*rguid1*<br/>
[em] O GUID para `IID_IUnknown`comparar com .

## <a name="see-also"></a>Confira também

[Funções](../../atl/reference/atl-functions.md)<br/>
[COM Map Macros](../../atl/reference/com-map-macros.md)
