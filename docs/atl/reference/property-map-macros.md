---
title: Macros de mapa de propriedade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::BEGIN_PROP_MAP
- atlcom/ATL::PROP_DATA_ENTRY
- atlcom/ATL::PROP_ENTRY_TYPE
- atlcom/ATL::PROP_ENTRY_TYPE_EX
- atlcom/ATL::PROP_PAGE
- atlcom/ATL::END_PROP_MAP
dev_langs:
- C++
helpviewer_keywords:
- property maps
ms.assetid: 128bc742-2b98-4b97-a243-684dbb83db77
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: caa298ebbb96b04145bf2beb52f93838708ae50b
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50088896"
---
# <a name="property-map-macros"></a>Macros de mapa de propriedade

Essas macros definem entradas e mapas de propriedade.

|||
|-|-|
|[BEGIN_PROP_MAP](#begin_prop_map)|Marca o início do mapa de propriedade do ATL.|
|[PROP_DATA_ENTRY](#prop_data_entry)|Indica a extensão ou dimensões de um controle ActiveX.|
|[PROP_ENTRY_TYPE](#prop_entry_type)|Insere uma propriedade DISPID, descrição e propriedade página de propriedades CLSID o mapa de propriedade.|
|[PROP_ENTRY_TYPE_EX](#prop_entry_type_ex)|Insere uma descrição de propriedade, a propriedade DISPID, CLSID, página de propriedades e `IDispatch` IID do mapa de propriedade.|
|[PROP_PAGE](#prop_page)|Insere uma página de propriedades CLSID o mapa de propriedade.|
|[END_PROP_MAP](#end_prop_map)|Marca o fim do mapa de propriedade do ATL.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="begin_prop_map"></a>  BEGIN_PROP_MAP

Marca o início do mapa de propriedade do objeto.

```
BEGIN_PROP_MAP(theClass)
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
[in] Especifica a classe que contém o mapa de propriedade.

### <a name="remarks"></a>Comentários

O mapa de propriedade armazena as descrições de propriedade, DISPIDs de propriedade, a página de propriedades CLSIDs, e `IDispatch` IIDs. As classes [IPerPropertyBrowsingImpl](../../atl/reference/iperpropertybrowsingimpl-class.md), [IPersistPropertyBagImpl](../../atl/reference/ipersistpropertybagimpl-class.md), [IPersistStreamInitImpl](../../atl/reference/ipersiststreaminitimpl-class.md), e [ISpecifyPropertyPagesImpl](../../atl/reference/ispecifypropertypagesimpl-class.md)usar o mapa de propriedade para recuperar e definir essas informações.

Quando você cria um objeto com o Assistente de projeto da ATL, o assistente criará um mapa de propriedade vazia especificando BEGIN_PROP_MAP seguido [END_PROP_MAP](#end_prop_map).

BEGIN_PROP_MAP não salvar a extensão (ou seja, as dimensões) de um mapa de propriedade, porque um objeto usando um mapa de propriedade pode não ter uma interface do usuário, então ele teria nenhuma extensão. Se o objeto for um controle ActiveX com uma interface do usuário, ele tem uma extensão. Nesse caso, você deve especificar [PROP_DATA_ENTRY](#prop_data_entry) no seu mapa de propriedade para fornecer a extensão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#103](../../atl/codesnippet/cpp/property-map-macros_1.h)]

##  <a name="prop_data_entry"></a>  PROP_DATA_ENTRY

Indica a extensão ou dimensões de um controle ActiveX.

```
PROP_DATA_ENTRY( szDesc, member, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[in] A descrição da propriedade.

*member*<br/>
[in] O membro de dados que contém a extensão; Por exemplo, `m_sizeExtent`.

*vt*<br/>
[in] Especifica o tipo de VARIANTE da propriedade.

### <a name="remarks"></a>Comentários

Essa macro faz com que o membro de dados especificados a serem persistidos.

Quando você cria um controle ActiveX, o assistente insere essa macro após a macro de mapa de propriedade [BEGIN_PROP_MAP](#begin_prop_map) e antes da macro de mapa de propriedade [END_PROP_MAP](#end_prop_map).

### <a name="example"></a>Exemplo

No exemplo a seguir, a extensão do objeto (`m_sizeExtent`) está sendo persistente.

[!code-cpp[NVC_ATL_Windowing#131](../../atl/codesnippet/cpp/property-map-macros_2.h)]

[!code-cpp[NVC_ATL_Windowing#132](../../atl/codesnippet/cpp/property-map-macros_3.h)]

##  <a name="prop_entry_type"></a>  PROP_ENTRY_TYPE

Use esta macro para inserir uma descrição, a propriedade DISPID e a propriedade página de propriedades CLSID no mapa de propriedade do objeto.

```
PROP_ENTRY_TYPE( szDesc, dispid, clsid, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[in] A descrição da propriedade.

*DISPID*<br/>
[in] DISPID da propriedade.

*clsid*<br/>
[in] O CLSID da página de propriedades associadas. Use o valor especial CLSID_NULL para uma propriedade que não tem uma página de propriedade associada.

*vt*<br/>
[in] O tipo da propriedade.

### <a name="remarks"></a>Comentários

A macro PROP_ENTRY foi preterido e não segura. Ele foi substituído com PROP_ENTRY_TYPE.

O [BEGIN_PROP_MAP](#begin_prop_map) macro marca o início do mapa de propriedade; o [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_PROP_MAP](#begin_prop_map).

##  <a name="prop_entry_type_ex"></a>  PROP_ENTRY_TYPE_EX

Semelhante ao [PROP_ENTRY_TYPE](#prop_entry_type), mas permite que você especifique um IID específico se seu objeto oferecer suporte a múltiplas interfaces duplas.

```
PROP_ENTRY_TYPE_EX( szDesc, dispid, clsid, iidDispatch, vt)
```

### <a name="parameters"></a>Parâmetros

*szDesc*<br/>
[in] A descrição da propriedade.

*DISPID*<br/>
[in] DISPID da propriedade.

*clsid*<br/>
[in] O CLSID da página de propriedades associadas. Use o valor especial CLSID_NULL para uma propriedade que não tem uma página de propriedade associada.

*iidDispatch*<br/>
[in] O IID da interface dupla definindo a propriedade.

*vt*<br/>
[in] O tipo da propriedade.

### <a name="remarks"></a>Comentários

A macro PROP_ENTRY_EX foi preterido e não segura. Ele foi substituído com PROP_ENTRY_TYPE_EX.

O [BEGIN_PROP_MAP](#begin_prop_map) macro marca o início do mapa de propriedade; o [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

O exemplo a seguir agrupa as entradas para `IMyDual1` seguido por uma entrada para `IMyDual2`. O agrupamento por interface dupla irá melhorar o desempenho.

[!code-cpp[NVC_ATL_Windowing#133](../../atl/codesnippet/cpp/property-map-macros_4.h)]

##  <a name="prop_page"></a>  PROP_PAGE

Use esta macro para inserir uma página de propriedades CLSID no mapa de propriedade do objeto.

```
PROP_PAGE(clsid)
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
[in] O CLSID de uma página de propriedades.

### <a name="remarks"></a>Comentários

PROP_PAGE é semelhante à [PROP_ENTRY_TYPE](#prop_entry_type), mas não requer uma descrição de propriedade ou o DISPID.

> [!NOTE]
>  Se você tiver inserido um CLSID com PROP_ENTRY_TYPE ou [PROP_ENTRY_TYPE_EX](#prop_entry_type_ex), você não precisa criar uma entrada adicional com PROP_PAGE.

O [BEGIN_PROP_MAP](#begin_prop_map) macro marca o início do mapa de propriedade; o [END_PROP_MAP](#end_prop_map) macro marca o fim.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#134](../../atl/codesnippet/cpp/property-map-macros_5.h)]

##  <a name="end_prop_map"></a>  END_PROP_MAP

Marca o fim do mapa de propriedade do objeto.

```
END_PROP_MAP()
```

### <a name="remarks"></a>Comentários

Quando você cria um objeto com o Assistente de projeto da ATL, o assistente criará um mapa de propriedade vazia, especificando [BEGIN_PROP_MAP](#begin_prop_map) seguido por END_PROP_MAP.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_PROP_MAP](#begin_prop_map).

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
