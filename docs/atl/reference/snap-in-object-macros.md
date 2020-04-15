---
title: Macros do objeto Snap-In
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
ms.openlocfilehash: 6a57cdb3c9b6a4448bc954ff754ac9b18fa0b393
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325865"
---
# <a name="snap-in-object-macros"></a>Macros do objeto Snap-In

Essas macros fornecem suporte para extensões snap-in.

|||
|-|-|
|[BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map)|Marca o início do mapa da classe de dados de extensão snap-in para um objeto Snap-In.|
|[BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map)|Marca o início do mapa da barra de ferramentas para um objeto Snap-In.|
|[END_EXTENSION_SNAPIN_NODEINFO_MAP](#end_extension_snapin_nodeinfo_map)|Marca o fim do mapa de classe de dados de extensão snap-in para um objeto Snap-In.|
|[END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map)|Marca o fim do mapa da barra de ferramentas para um objeto Snap-In.|
|[EXTENSION_SNAPIN_DATACLASS](#extension_snapin_dataclass)|Cria um membro de dados para a classe de dados da extensão snap-in.|
|[EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry)|Insere uma classe de dados de extensão snap-in no mapa da classe de dados de extensão snap-in do objeto Snap-In.|
|[SNAPINMENUID](#snapinmenuid)|Declara o ID do menu de contexto usado pelo objeto Snap-In.|
|[SNAPINTOOLBARID_ENTRY](#snapintoolbarid_entry)|Insere uma barra de ferramentas no mapa da barra de ferramentas do objeto Snap-In.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsnap.h

## <a name="begin_extension_snapin_nodeinfo_map"></a><a name="begin_extension_snapin_nodeinfo_map"></a>BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o início do mapa de classe de dados de extensão snap-in.

```
BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP(classname)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
[em] O nome da classe de dados de extensão snap-in.

### <a name="remarks"></a>Comentários

Inicie seu mapa de extensão snap-in com a macro BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP, adicione entradas para cada um dos seus tipos de dados de extensão snap-in com a [macro EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e complete o mapa com a [macro END_EXTENSION_SNAPIN_NODEINFO_MAP.](#end_extension_snapin_nodeinfo_map)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

## <a name="begin_snapintoolbarid_map"></a><a name="begin_snapintoolbarid_map"></a>BEGIN_SNAPINTOOLBARID_MAP

Declara o início do mapa de ID da barra de ferramentas para o objeto Snap-In.

```
BEGIN_SNAPINTOOLBARID_MAP(_class)
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[em] Especifica a classe de objeto Snap-In.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#106](../../atl/codesnippet/cpp/snap-in-object-macros_2.h)]

## <a name="end_extension_snapin_nodeinfo_map"></a><a name="end_extension_snapin_nodeinfo_map"></a>END_EXTENSION_SNAPIN_NODEINFO_MAP

Marca o fim do mapa de classe de dados de extensão snap-in.

```
END_EXTENSION_SNAPIN_NODEINFO_MAP()
```

### <a name="remarks"></a>Comentários

Inicie seu mapa de extensão snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP,](#begin_extension_snapin_nodeinfo_map) adicione entradas para cada um dos tipos de dados de extensão com a [macro EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e complete o mapa com a macro END_EXTENSION_SNAPIN_NODEINFO_MAP.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

## <a name="end_snapintoolbarid_map"></a><a name="end_snapintoolbarid_map"></a>END_SNAPINTOOLBARID_MAP

Declara o fim do mapa de ID da barra de ferramentas para o objeto Snap-In.

```
END_SNAPINTOOLBARID_MAP( _class )
```

### <a name="parameters"></a>Parâmetros

*_class*<br/>
[em] Especifica a classe de objeto Snap-In.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

## <a name="extension_snapin_dataclass"></a><a name="extension_snapin_dataclass"></a>EXTENSION_SNAPIN_DATACLASS

Adiciona um membro de dados à classe de dados de extensão snap-in para uma classe derivada do **ISnapInItemImpl.**

```
EXTENSION_SNAPIN_DATACLASS(dataClass )
```

### <a name="parameters"></a>Parâmetros

*Dataclass*<br/>
[em] A classe de dados da extensão snap-in.

### <a name="remarks"></a>Comentários

Essa classe também deve ser inserida em um mapa de classe de dados de extensão snap-in. Inicie o mapa da classe de dados de extensão snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP,](#begin_extension_snapin_nodeinfo_map) adicione entradas para cada um dos seus tipos de dados de extensão snap-in com a [macro EXTENSION_SNAPIN_NODEINFO_ENTRY](#extension_snapin_nodeinfo_entry) e complete o mapa com a macro [END_EXTENSION_SNAPIN_NODEINFO_MAP.](#end_extension_snapin_nodeinfo_map)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#105](../../atl/codesnippet/cpp/snap-in-object-macros_1.h)]

## <a name="extension_snapin_nodeinfo_entry"></a><a name="extension_snapin_nodeinfo_entry"></a>EXTENSION_SNAPIN_NODEINFO_ENTRY

Adiciona uma classe de dados de extensão snap-in ao mapa da classe de dados de extensão snap-in.

```
EXTENSION_SNAPIN_NODEINFO_ENTRY( dataClass )
```

### <a name="parameters"></a>Parâmetros

*Dataclass*<br/>
[em] A classe de dados da extensão snap-in.

### <a name="remarks"></a>Comentários

Inicie o mapa da classe de dados de extensão snap-in com a macro [BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP,](#begin_extension_snapin_nodeinfo_map) adicione entradas para cada um dos seus tipos de dados de extensão snap-in com a macro EXTENSION_SNAPIN_NODEINFO_ENTRY e complete o mapa com a [macro END_EXTENSION_SNAPIN_NODEINFO_MAP.](#end_extension_snapin_nodeinfo_map)

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_EXTENSION_SNAPIN_NODEINFO_MAP](#begin_extension_snapin_nodeinfo_map).

## <a name="snapinmenuid"></a><a name="snapinmenuid"></a>SNAPINMENUID

Use esta macro para declarar o recurso de menu de contexto do objeto Snap-In.

```
SNAPINMENUID( id )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Identifica o menu de contexto do objeto Snap-In.

## <a name="snapintoolbarid_entry"></a><a name="snapintoolbarid_entry"></a>SNAPINTOOLBARID_ENTRY

Use esta macro para inserir um ID da barra de ferramentas no mapa id da barra de ferramentas do objeto Snap-In.

```
SNAPINTOOLBARID_ENTRY( id )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
[em] Identifica o controle da barra de ferramentas.

### <a name="remarks"></a>Comentários

A [macro BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map) marca o início do mapa de identificação da barra de ferramentas; a [macro END_SNAPINTOOLBARID_MAP](#end_snapintoolbarid_map) marca o fim.

### <a name="example"></a>Exemplo

Veja o exemplo [de BEGIN_SNAPINTOOLBARID_MAP](#begin_snapintoolbarid_map).

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
