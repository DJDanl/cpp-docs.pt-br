---
title: Macros do mapa da propriedade
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_PROP_MAP
- atlcom/ATL::PROP_DATA_ENTRY
- atlcom/ATL::PROP_ENTRY_TYPE
- atlcom/ATL::PROP_ENTRY_TYPE_EX
- atlcom/ATL::PROP_PAGE
- atlcom/ATL::END_PROP_MAP
helpviewer_keywords:
- property maps
ms.assetid: 128bc742-2b98-4b97-a243-684dbb83db77
ms.openlocfilehash: 56fdb02939a99e396b9000705753e2475b80f6dc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326099"
---
# <a name="property-map-macros"></a>Macros do mapa da propriedade

Essas macros definem mapas de propriedades e entradas.

|||
|-|-|
|[Begin_prop_map](#begin_prop_map)|Marca o início do mapa de propriedade ATL.|
|[PROP_DATA_ENTRY](#prop_data_entry)|Indica a extensão, ou dimensões, de um controle ActiveX.|
|[Prop_entry_type](#prop_entry_type)|Insere uma descrição da propriedade, dispid de propriedade e a página de propriedade CLSID no mapa da propriedade.|
|[PROP_ENTRY_TYPE_EX](#prop_entry_type_ex)|Insere uma descrição da propriedade, DISPID `IDispatch` de propriedade, página de propriedade CLSID e IID no mapa da propriedade.|
|[Prop_page](#prop_page)|Insere uma página de propriedade CLSID no mapa da propriedade.|
|[END_PROP_MAP](#end_prop_map)|Marca o fim do mapa de propriedade ATL.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_prop_map"></a><a name="begin_prop_map"></a>Begin_prop_map

Marca o início do mapa de propriedade do objeto.

```
BEGIN_PROP_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
[em] Especifica a classe que contém o mapa da propriedade.

### <a name="remarks"></a>Comentários

O mapa da propriedade armazena descrições de propriedades, DISPIDs `IDispatch` de propriedade, CLSIDs da página de propriedade e IIDs. Classes [IPerPropertyBrowsingImpl,](../../atl/reference/iperpropertybrowsingimpl-class.md) [IPersistPropertyBagImpl,](../../atl/reference/ipersistpropertybagimpl-class.md) [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)e [ISpecifiePropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) usam o mapa da propriedade para recuperar e definir essas informações.

Quando você cria um objeto com o Assistente de Projeto ATL, o assistente criará um mapa de propriedade vazio especificando BEGIN_PROP_MAP seguido de [END_PROP_MAP](#end_prop_map).

BEGIN_PROP_MAP não salva a extensão (ou seja, as dimensões) de um mapa de propriedade, porque um objeto usando um mapa de propriedade pode não ter uma interface de usuário, então não teria extensão. Se o objeto é um controle ActiveX com uma interface de usuário, ele tem uma extensão. Neste caso, você deve especificar [PROP_DATA_ENTRY](#prop_data_entry) em seu mapa de propriedade para fornecer a extensão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#103](../../atl/codesnippet/cpp/property-map-macros_1.h)]

## <a name="prop_data_entry"></a><a name="prop_data_entry"></a>PROP_DATA_ENTRY

Indica a extensão, ou dimensões, de um controle ActiveX.

```
PROP_DATA_ENTRY( szDesc, member, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[em] A descrição da propriedade.

*Membro*<br/>
[em] O membro de dados contendo a extensão; por exemplo, `m_sizeExtent`.

*vt*<br/>
[em] Especifica o tipo VARIANT da propriedade.

### <a name="remarks"></a>Comentários

Essa macro faz com que o membro de dados especificado seja persistido.

Quando você cria um controle ActiveX, o assistente insere essa macro após a [BEGIN_PROP_MAP](#begin_prop_map) de macro mapa de propriedade e antes que a [END_PROP_MAP](#end_prop_map)de macro mapa de propriedade .

### <a name="example"></a>Exemplo

No exemplo a seguir, a`m_sizeExtent`extensão do objeto ( ) está sendo persistida.

[!code-cpp[NVC_ATL_Windowing#131](../../atl/codesnippet/cpp/property-map-macros_2.h)]

[!code-cpp[NVC_ATL_Windowing#132](../../atl/codesnippet/cpp/property-map-macros_3.h)]

## <a name="prop_entry_type"></a><a name="prop_entry_type"></a>Prop_entry_type

Use essa macro para inserir uma descrição de propriedade, dISPID de propriedade e a página de propriedade CLSID no mapa de propriedade do objeto.

```
PROP_ENTRY_TYPE( szDesc, dispid, clsid, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[em] A descrição da propriedade.

*Dispid*<br/>
[em] A propriedade é DISPID.

*clsid*<br/>
[em] O CLSID da página de propriedade associada. Use o valor especial CLSID_NULL para uma propriedade que não tenha uma página de propriedade associada.

*vt*<br/>
[em] O tipo da propriedade.

### <a name="remarks"></a>Comentários

A PROP_ENTRY macro era insegura e preterida. Foi substituído por PROP_ENTRY_TYPE.

A [macro BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa da propriedade; a [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_PROP_MAP](#begin_prop_map).

## <a name="prop_entry_type_ex"></a><a name="prop_entry_type_ex"></a>PROP_ENTRY_TYPE_EX

Semelhante ao [PROP_ENTRY_TYPE,](#prop_entry_type)mas permite especificar um IID específico se o objeto suportar várias interfaces duplas.

```
PROP_ENTRY_TYPE_EX( szDesc, dispid, clsid, iidDispatch, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[em] A descrição da propriedade.

*Dispid*<br/>
[em] A propriedade é DISPID.

*clsid*<br/>
[em] O CLSID da página de propriedade associada. Use o valor especial CLSID_NULL para uma propriedade que não tenha uma página de propriedade associada.

*IidDispatch*<br/>
[em] O IID da interface dupla definindo a propriedade.

*vt*<br/>
[em] O tipo da propriedade.

### <a name="remarks"></a>Comentários

A PROP_ENTRY_EX macro era insegura e preterida. Foi substituído por PROP_ENTRY_TYPE_EX.

A [macro BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa da propriedade; a [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

O exemplo a seguir `IMyDual1` agrupa entradas `IMyDual2`para seguir uma entrada para . O agrupamento por interface dupla melhorará o desempenho.

[!code-cpp[NVC_ATL_Windowing#133](../../atl/codesnippet/cpp/property-map-macros_4.h)]

## <a name="prop_page"></a><a name="prop_page"></a>Prop_page

Use esta macro para inserir uma página de propriedade CLSID no mapa de propriedade do objeto.

```
PROP_PAGE(clsid)
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[em] O CLSID de uma página de propriedade.

### <a name="remarks"></a>Comentários

PROP_PAGE é semelhante ao [PROP_ENTRY_TYPE,](#prop_entry_type)mas não requer uma descrição da propriedade ou DISPID.

> [!NOTE]
> Se você já inscreveu um CLSID com PROP_ENTRY_TYPE ou [PROP_ENTRY_TYPE_EX,](#prop_entry_type_ex)você não precisa fazer uma entrada adicional com PROP_PAGE.

A [macro BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa da propriedade; a [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#134](../../atl/codesnippet/cpp/property-map-macros_5.h)]

## <a name="end_prop_map"></a><a name="end_prop_map"></a>END_PROP_MAP

Marca o fim do mapa de propriedade do objeto.

```
END_PROP_MAP()
```

### <a name="remarks"></a>Comentários

Quando você cria um objeto com o Assistente de Projeto ATL, o assistente criará um mapa de propriedade vazio especificando [BEGIN_PROP_MAP](#begin_prop_map) seguido de END_PROP_MAP.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_PROP_MAP](#begin_prop_map).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
