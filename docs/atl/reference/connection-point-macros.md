---
title: Macros de ponto de conexão
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_CONNECTION_POINT_MAP
- atlcom/ATL::END_CONNECTION_POINT_MAP
helpviewer_keywords:
- connection points [C++], macros
ms.assetid: cc3a6dd3-5538-45df-b027-1f34963c31e5
ms.openlocfilehash: 361cf6ab2c7af142c1d57c002681ccf6e4a87bda
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331490"
---
# <a name="connection-point-macros"></a>Macros de ponto de conexão

Essas macros definem mapas e entradas de ponto de conexão.

|||
|-|-|
|[BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map)|Marca o início das entradas do mapa de ponto de conexão.|
|[CONNECTION_POINT_ENTRY](#connection_point_entry)|Insere pontos de conexão no mapa.|
|[CONNECTION_POINT_ENTRY_P](#connection_point_entry)| (Visual Studio 2017) Semelhante ao CONNECTION_POINT_ENTRY, mas leva um ponteiro para iid.|
|[END_CONNECTION_POINT_MAP](#end_connection_point_map)|Marca o fim das entradas do mapa de ponto de conexão.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_connection_point_map"></a><a name="begin_connection_point_map"></a>BEGIN_CONNECTION_POINT_MAP

Marca o início das entradas do mapa de ponto de conexão.

```
BEGIN_CONNECTION_POINT_MAP(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome da classe que contém os pontos de conexão.

### <a name="remarks"></a>Comentários

Inicie seu mapa de ponto de conexão com a macro BEGIN_CONNECTION_POINT_MAP, adicione entradas para cada um dos seus pontos de conexão com a [macro CONNECTION_POINT_ENTRY](#connection_point_entry) e complete o mapa com a [END_CONNECTION_POINT_MAP](#end_connection_point_map) macro.

Para obter mais informações sobre pontos de conexão no ATL, consulte o artigo [Pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#101](../../atl/codesnippet/cpp/connection-point-macros_1.h)]

## <a name="connection_point_entry-and-connection_point_entry_p"></a><a name="connection_point_entry"></a>CONNECTION_POINT_ENTRY e CONNECTION_POINT_ENTRY_P

Insere um ponto de conexão para a interface especificada no mapa de ponto de conexão para que ele possa ser acessado.

```
CONNECTION_POINT_ENTRY(iid)
CONNECTION_POINT_ENTRY_P(piid) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface que está sendo adicionado ao mapa de ponto de conexão.

*Piid*<br/>
[em] Ponteiro para o GUID da interface que está sendo adé.

### <a name="remarks"></a>Comentários

As entradas de ponto de conexão no mapa são usadas pelo [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md). A classe que contém o mapa `IConnectionPointContainerImpl`de ponto de conexão deve herdar de .

Inicie seu mapa de ponto de conexão com a [macro BEGIN_CONNECTION_POINT_MAP,](#begin_connection_point_map) adicione entradas para cada um dos seus pontos de conexão com a macro CONNECTION_POINT_ENTRY e complete o mapa com a [macro END_CONNECTION_POINT_MAP.](#end_connection_point_map)

Para obter mais informações sobre pontos de conexão no ATL, consulte o artigo [Pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#120](../../atl/codesnippet/cpp/connection-point-macros_2.h)]

## <a name="end_connection_point_map"></a><a name="end_connection_point_map"></a>END_CONNECTION_POINT_MAP

Marca o fim das entradas do mapa de ponto de conexão.

```
END_CONNECTION_POINT_MAP()
```

### <a name="remarks"></a>Comentários

Inicie seu mapa de ponto de conexão com a macro [BEGIN_CONNECTION_POINT_MAP,](#begin_connection_point_map) adicione entradas para cada um dos seus pontos de conexão com a macro [CONNECTION_POINT_ENTRY](#connection_point_entry) e complete o mapa com a macro END_CONNECTION_POINT_MAP.

Para obter mais informações sobre pontos de conexão no ATL, consulte o artigo [Pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#128](../../atl/codesnippet/cpp/connection-point-macros_3.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais do ponto de conexão](../../atl/reference/connection-point-global-functions.md)
