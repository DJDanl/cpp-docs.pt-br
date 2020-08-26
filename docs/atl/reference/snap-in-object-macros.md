---
title: Macros do objeto de snap-in
ms.date: 11/04/2016
f1_keywords:
- atlsnap/ATL::BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP
- atlsnap/ATL::BEGIN_SNAPINTOOLBARID_MAP
- atlsnap/ATL::END_EXTENSION_SNAPIN_NODEINFO_MAP
- atlsnap/ATL::END_SNAPINTOOLBARID_MAP
- atlsnap/ATL::EXTENSION_SNAPIN_DATACLASS
- atlsnap/ATL::EXTENSION_SNAPIN_NODEINFO_ENTRY
- atlsnap/ATL::SNAPINMENUID
- atlsnap/ATL::SNAPINTOOLBARID_ENTRY
ms.assetid: 4e9850c0-e395-4929-86c9-584a81828053
ms.openlocfilehash: 7e006a17ad480ea79f6aeec224278815c8c3f164
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835188"
---
# <a name="snap-in-object-macros"></a>Macros do objeto de snap-in

Essas macros oferecem suporte para extensões de snap-in.

|Nome|Descrição|
|-|-|
|[BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map)|Marca o início do mapa de classes de dados de extensão do snap-in para um objeto de snap-in.|
|[BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map)|Marca o início do mapa da barra de ferramentas para um objeto de snap-in.|
|[END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map)|Marca o final do mapa de classes de dados de extensão do snap-in para um objeto de snap-in.|
|[END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map)|Marca o final do mapa da barra de ferramentas para um objeto de snap-in.|
|[EXTENSION_SNAPIN_DATACLASS](#extension_snapin_dataclass)|Cria um membro de dados para a classe de dados da extensão do snap-in.|
|[EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry)|Insere uma classe de dados de extensão do snap-in no mapa da classe de dados de extensão do snap-in do objeto do snap-in.|
|[SNAPINMENUID](#snapinmenuid)|Declara a ID do menu de contexto usado pelo objeto de snap-in.|
|[SNAPINTOOLBARID_ENTRY](#snapintoolbarid_entry)|Insere uma barra de ferramentas no mapa da barra de ferramentas do objeto do snap-in.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap. h

## <a name="begin_extension_snapin_nodeinfo_map"></a><a name="begin_extension_snapin_nodeinfo_map"></a> BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o início do mapa de classes de dados de extensão do snap-in.

```
BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname)
```

### <a name="parameters"></a>parâmetros

*ClassName*<br/>
no O nome da classe de dados de extensão do snap-in.

### <a name="remarks"></a>Comentários

Inicie o mapa de extensão do snap-in com a macro BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP, adicione entradas para cada um dos tipos de dados de extensão do snap-in com a macro [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e conclua o mapa com a macro [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

## <a name="begin_snapintoolbarid_map"></a><a name="begin_snapintoolbarid_map"></a> BEGIN_SNAPINTOOLBARID_MAP

Declara o início do mapa de ID da barra de ferramentas para o objeto de snap-in.

```
BEGIN_SNAPINTOOLBARID_MAP(_class)
```

### <a name="parameters"></a>parâmetros

*_class*<br/>
no Especifica a classe de objeto do snap-in.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#106](../../atl/codesnippet/cpp/snap-in-object-macros_2.h)]

## <a name="end_extension_snapin_nodeinfo_map"></a><a name="end_extension_snapin_nodeinfo_map"></a> END_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o final do mapa de classes de dados de extensão do snap-in.

```
END_EXTENSION_SNAPIN_NODEINFO_MAP()
```

### <a name="remarks"></a>Comentários

Inicie o mapa de extensão do snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) , adicione entradas para cada um dos tipos de dados de snap-in de extensão com a macro [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e conclua o mapa com a macro END_EXTENSION_SNAPIN_NODEINFO_MAP.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

## <a name="end_snapintoolbarid_map"></a><a name="end_snapintoolbarid_map"></a> END_SNAPINTOOLBARID_MAP

Declara o final do mapa da ID da barra de ferramentas para o objeto do snap-in.

```
END_SNAPINTOOLBARID_MAP( _class )
```

### <a name="parameters"></a>parâmetros

*_class*<br/>
no Especifica a classe de objeto do snap-in.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

## <a name="extension_snapin_dataclass"></a><a name="extension_snapin_dataclass"></a> EXTENSION_SNAPIN_DATACLASS

Adiciona um membro de dados à classe de dados de extensão do snap-in para uma classe derivada de **ISnapInItemImpl**.

```
EXTENSION_SNAPIN_DATACLASS(dataClass )
```

### <a name="parameters"></a>parâmetros

*dataClass*<br/>
no A classe de dados da extensão do snap-in.

### <a name="remarks"></a>Comentários

Essa classe também deve ser inserida em um mapa de classe de dados de extensão de snap-in. Inicie o mapa de classes de dados de extensão do snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) , adicione entradas para cada um dos tipos de dados de extensão do snap-in com a macro [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e conclua o mapa com a macro [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

## <a name="extension_snapin_nodeinfo_entry"></a><a name="extension_snapin_nodeinfo_entry"></a> EXTENSION_SNAPIN_NODEINFO_ENTRY

Adiciona uma classe de dados de extensão do snap-in ao mapa da classe de dados de extensão do snap-in.

```
EXTENSION_SNAPIN_NODEINFO_ENTRY( dataClass )
```

### <a name="parameters"></a>parâmetros

*dataClass*<br/>
no A classe de dados da extensão do snap-in.

### <a name="remarks"></a>Comentários

Inicie o mapa de classes de dados de extensão do snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) , adicione entradas para cada um dos tipos de dados de extensão do snap-in com a macro EXTENSION_SNAPIN_NODEINFO_ENTRY e conclua o mapa com a macro [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) .

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

## <a name="snapinmenuid"></a><a name="snapinmenuid"></a> SNAPINMENUID

Use esta macro para declarar o recurso de menu de contexto do objeto de snap-in.

```
SNAPINMENUID( id )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no Identifica o menu de contexto do objeto de snap-in.

## <a name="snapintoolbarid_entry"></a><a name="snapintoolbarid_entry"></a> SNAPINTOOLBARID_ENTRY

Use esta macro para inserir uma ID da barra de ferramentas no mapa da ID da barra de ferramentas do objeto do snap-in.

```
SNAPINTOOLBARID_ENTRY( id )
```

### <a name="parameters"></a>parâmetros

*id*<br/>
no Identifica o controle ToolBar.

### <a name="remarks"></a>Comentários

A macro [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map) marca o início do mapa de ID da barra de ferramentas; a macro [END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map) marca o final.

### <a name="example"></a>Exemplo

Consulte o exemplo para [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
