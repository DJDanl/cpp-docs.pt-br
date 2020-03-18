---
title: Macros de mapa de propriedades
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
ms.openlocfilehash: 1e2e7235dd924467d9d5e0613a704fedf8340ae4
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417519"
---
# <a name="property-map-macros"></a>Macros de mapa de propriedades

Essas macros definem as entradas e mapas de propriedade.

|||
|-|-|
|[BEGIN_PROP_MAP](#begin_prop_map)|Marca o início do mapa de propriedades da ATL.|
|[PROP_DATA_ENTRY](#prop_data_entry)|Indica a extensão, ou dimensões, de um controle ActiveX.|
|[PROP_ENTRY_TYPE](#prop_entry_type)|Insere uma descrição de propriedade, uma propriedade DISPID e um CLSID de página de propriedades no mapa de propriedade.|
|[PROP_ENTRY_TYPE_EX](#prop_entry_type_ex)|Insere uma descrição de propriedade, uma propriedade DISPID, uma página de propriedades CLSID e `IDispatch` IID no mapa de propriedades.|
|[PROP_PAGE](#prop_page)|Insere um CLSID de página de propriedades no mapa de propriedades.|
|[END_PROP_MAP](#end_prop_map)|Marca o final do mapa de propriedades da ATL.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="begin_prop_map"></a>BEGIN_PROP_MAP

Marca o início do mapa de propriedades do objeto.

```
BEGIN_PROP_MAP(theClass)
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
no Especifica a classe que contém o mapa de propriedade.

### <a name="remarks"></a>Comentários

O mapa de propriedade armazena descrições de propriedade, DISPIDs de propriedade, CLSIDs de página de propriedades e `IDispatch` IIDs. As classes [IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md), [IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md), [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md)e [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md) usam o mapa de propriedades para recuperar e definir essas informações.

Quando você cria um objeto com o assistente de projeto do ATL, o assistente criará um mapa de propriedades vazio especificando BEGIN_PROP_MAP seguido por [END_PROP_MAP](#end_prop_map).

BEGIN_PROP_MAP não salva a extensão (ou seja, as dimensões) de um mapa de propriedade, porque um objeto que usa um mapa de propriedade pode não ter uma interface do usuário, portanto, ele não teria nenhuma extensão. Se o objeto for um controle ActiveX com uma interface do usuário, ele terá uma extensão. Nesse caso, você deve especificar [PROP_DATA_ENTRY](#prop_data_entry) em seu mapa de propriedades para fornecer a extensão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#103](../../atl/codesnippet/cpp/property-map-macros_1.h)]

##  <a name="prop_data_entry"></a>PROP_DATA_ENTRY

Indica a extensão, ou dimensões, de um controle ActiveX.

```
PROP_DATA_ENTRY( szDesc, member, vt)
```

### <a name="parameters"></a>parâmetros

*szDesc*<br/>
no A descrição da propriedade.

*member*<br/>
no O membro de dados que contém a extensão; por exemplo, `m_sizeExtent`.

*pt*<br/>
no Especifica o tipo de variante da propriedade.

### <a name="remarks"></a>Comentários

Essa macro faz com que o membro de dados especificado seja persistido.

Quando você cria um controle ActiveX, o assistente insere essa macro após a macro do mapa de propriedades [BEGIN_PROP_MAP](#begin_prop_map) e antes da [END_PROP_MAP](#end_prop_map)de macro do mapa de propriedades.

### <a name="example"></a>Exemplo

No exemplo a seguir, a extensão do objeto (`m_sizeExtent`) está sendo persistida.

[!code-cpp[NVC_ATL_Windowing#131](../../atl/codesnippet/cpp/property-map-macros_2.h)]

[!code-cpp[NVC_ATL_Windowing#132](../../atl/codesnippet/cpp/property-map-macros_3.h)]

##  <a name="prop_entry_type"></a>PROP_ENTRY_TYPE

Use esta macro para inserir uma descrição de propriedade, uma propriedade DISPID e um CLSID de página de propriedades no mapa de propriedades do objeto.

```
PROP_ENTRY_TYPE( szDesc, dispid, clsid, vt)
```

### <a name="parameters"></a>parâmetros

*szDesc*<br/>
no A descrição da propriedade.

*DISPID*<br/>
no O DISPID da propriedade.

*CLSID*<br/>
no O CLSID da página de propriedades associada. Use o valor especial CLSID_NULL para uma propriedade que não tenha uma página de propriedades associada.

*pt*<br/>
no O tipo da propriedade.

### <a name="remarks"></a>Comentários

A macro PROP_ENTRY estava insegura e preterida. Ele foi substituído por PROP_ENTRY_TYPE.

A macro [BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa de propriedade; a macro [END_PROP_MAP](#end_prop_map) marca o final.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_PROP_MAP](#begin_prop_map).

##  <a name="prop_entry_type_ex"></a>PROP_ENTRY_TYPE_EX

Semelhante a [PROP_ENTRY_TYPE](#prop_entry_type), mas permite que você ESPECIFIQUE um IID específico se o seu objeto der suporte a várias interfaces duplas.

```
PROP_ENTRY_TYPE_EX( szDesc, dispid, clsid, iidDispatch, vt)
```

### <a name="parameters"></a>parâmetros

*szDesc*<br/>
no A descrição da propriedade.

*DISPID*<br/>
no O DISPID da propriedade.

*CLSID*<br/>
no O CLSID da página de propriedades associada. Use o valor especial CLSID_NULL para uma propriedade que não tenha uma página de propriedades associada.

*iidDispatch*<br/>
no O IID da interface dupla que define a propriedade.

*pt*<br/>
no O tipo da propriedade.

### <a name="remarks"></a>Comentários

A macro PROP_ENTRY_EX estava insegura e preterida. Ele foi substituído por PROP_ENTRY_TYPE_EX.

A macro [BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa de propriedade; a macro [END_PROP_MAP](#end_prop_map) marca o final.

### <a name="example"></a>Exemplo

O exemplo a seguir agrupa entradas para `IMyDual1` seguido por uma entrada para `IMyDual2`. O agrupamento por interface dual melhorará o desempenho.

[!code-cpp[NVC_ATL_Windowing#133](../../atl/codesnippet/cpp/property-map-macros_4.h)]

##  <a name="prop_page"></a>PROP_PAGE

Use esta macro para inserir um CLSID de página de propriedades no mapa de propriedades do objeto.

```
PROP_PAGE(clsid)
```

### <a name="parameters"></a>parâmetros

*CLSID*<br/>
no O CLSID de uma página de propriedades.

### <a name="remarks"></a>Comentários

PROP_PAGE é semelhante a [PROP_ENTRY_TYPE](#prop_entry_type), mas não requer uma descrição de propriedade ou um DISPID.

> [!NOTE]
>  Se você já tiver inserido um CLSID com PROP_ENTRY_TYPE ou [PROP_ENTRY_TYPE_EX](#prop_entry_type_ex), não será necessário fazer uma entrada adicional com PROP_PAGE.

A macro [BEGIN_PROP_MAP](#begin_prop_map) marca o início do mapa de propriedade; a macro [END_PROP_MAP](#end_prop_map) marca o final.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#134](../../atl/codesnippet/cpp/property-map-macros_5.h)]

##  <a name="end_prop_map"></a>END_PROP_MAP

Marca o final do mapa de propriedades do objeto.

```
END_PROP_MAP()
```

### <a name="remarks"></a>Comentários

Quando você cria um objeto com o assistente de projeto do ATL, o assistente criará um mapa de propriedades vazio especificando [BEGIN_PROP_MAP](#begin_prop_map) seguido por END_PROP_MAP.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_PROP_MAP](#begin_prop_map).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
