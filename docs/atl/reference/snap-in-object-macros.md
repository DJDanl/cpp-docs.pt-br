---
title: Macros de Snap-In do objeto
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
ms.openlocfilehash: b75dd04bed4895d722939d1bf9c0a6dfff2126e0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62276192"
---
# <a name="snap-in-object-macros"></a>Macros de Snap-In do objeto

Essas macros fornecem suporte para extensões de snap-in.

|||
|-|-|
|[BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map)|Marca o início do mapa de classe de extensão do snap-in de dados para um objeto de Snap-In.|
|[BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map)|Marca o início do mapa da barra de ferramentas para um objeto de Snap-In.|
|[END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map)|Marca o fim do mapa de classe de extensão do snap-in de dados para um objeto de Snap-In.|
|[END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map)|Marca o fim do mapa da barra de ferramentas para um objeto de Snap-In.|
|[EXTENSION_SNAPIN_DATACLASS](#extension_snapin_dataclass)|Cria um membro de dados para a classe de dados da extensão do snap-in.|
|[EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry)|Insere uma classe de snap-in de extensão de dados no mapa de classe de dados de extensão do snap-in do Snap-In do objeto.|
|[SNAPINMENUID](#snapinmenuid)|Declara a ID do menu de contexto usado pelo objeto de Snap-In.|
|[SNAPINTOOLBARID_ENTRY](#snapintoolbarid_entry)|Insere uma barra de ferramentas do mapa de barra de ferramentas do Snap-In do objeto.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap.h

##  <a name="begin_extension_snapin_nodeinfo_map"></a>  BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o início do mapa de classe de dados de extensão do snap-in.

```
BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname)
```

### <a name="parameters"></a>Parâmetros

*classname*<br/>
[in] O nome da classe de dados de extensão do snap-in.

### <a name="remarks"></a>Comentários

Inicie seu mapa de extensão do snap-in com a macro BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP, adicione entradas para cada um dos seus tipos de dados de extensão do snap-in com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) macro e concluir o mapa com o [ END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

##  <a name="begin_snapintoolbarid_map"></a>  BEGIN_SNAPINTOOLBARID_MAP

Declara o início do mapa de ID de barra de ferramentas para o objeto de Snap-In.

```
BEGIN_SNAPINTOOLBARID_MAP(_class)
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[in] Especifica a classe de objeto Snap-In.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#106](../../atl/codesnippet/cpp/snap-in-object-macros_2.h)]

##  <a name="end_extension_snapin_nodeinfo_map"></a>  END_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o fim do mapa de classe de extensão do snap-in de dados.

```
END_EXTENSION_SNAPIN_NODEINFO_MAP()
```

### <a name="remarks"></a>Comentários

Inicie seu mapa de extensão do snap-in com o [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de snap-in de extensão com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) macro, e conclua o mapa com a macro END_EXTENSION_SNAPIN_NODEINFO_MAP.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

##  <a name="end_snapintoolbarid_map"></a>  END_SNAPINTOOLBARID_MAP

Declara o final do mapa de ID de barra de ferramentas para o objeto de Snap-In.

```
END_SNAPINTOOLBARID_MAP( _class )
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[in] Especifica a classe de objeto Snap-In.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

##  <a name="extension_snapin_dataclass"></a>  EXTENSION_SNAPIN_DATACLASS

Adiciona um membro de dados para a classe de dados de extensão do snap-in para um **ISnapInItemImpl**-classe derivada.

```
EXTENSION_SNAPIN_DATACLASS(dataClass )
```

### <a name="parameters"></a>Parâmetros

*dataClass*<br/>
[in] A classe de dados da extensão do snap-in.

### <a name="remarks"></a>Comentários

Essa classe também deve ser inserida em um mapa de classe de dados de extensão do snap-in. Inicie seu mapa de classe de dados de extensão do snap-in com o [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de extensão do snap-in com o [EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry)macro e concluir o mapa com o [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

##  <a name="extension_snapin_nodeinfo_entry"></a>  EXTENSION_SNAPIN_NODEINFO_ENTRY

Adiciona uma classe de dados de extensão do snap-in para o mapa de classe de dados de extensão do snap-in.

```
EXTENSION_SNAPIN_NODEINFO_ENTRY( dataClass )
```

### <a name="parameters"></a>Parâmetros

*dataClass*<br/>
[in] A classe de dados da extensão do snap-in.

### <a name="remarks"></a>Comentários

Inicie seu mapa de classe de dados de extensão do snap-in com o [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map) macro, adicione entradas para cada um dos seus tipos de dados de extensão do snap-in com a macro EXTENSION_SNAPIN_NODEINFO_ENTRY e concluir o mapa com o [END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map) macro.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

##  <a name="snapinmenuid"></a>  SNAPINMENUID

Use esta macro para declarar o recurso de menu de contexto do objeto Snap-In.

```
SNAPINMENUID( id )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] Identifica o menu de contexto do objeto Snap-In.

##  <a name="snapintoolbarid_entry"></a>  SNAPINTOOLBARID_ENTRY

Use esta macro para inserir uma ID de barra de ferramentas no mapa de ID do objeto Snap-In da barra de ferramentas.

```
SNAPINTOOLBARID_ENTRY( id )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[in] Identifica o controle de barra de ferramentas.

### <a name="remarks"></a>Comentários

O [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map) macro marca o início do mapa de ID de barra de ferramentas; o [END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map) macro marca o fim.

### <a name="example"></a>Exemplo

Veja o exemplo de [BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
