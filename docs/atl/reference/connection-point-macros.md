---
title: Macros de ponto de Conexão
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_CONNECTION_POINT_MAP
- atlcom/ATL::END_CONNECTION_POINT_MAP
helpviewer_keywords:
- connection points [C++], macros
ms.assetid: cc3a6dd3-5538-45df-b027-1f34963c31e5
ms.openlocfilehash: cb8d6f696980ef91d7b43c960dc50289ea8500a6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258236"
---
# <a name="connection-point-macros"></a>Macros de ponto de Conexão

Essas macros definem entradas e mapas de ponto de conexão.

|||
|-|-|
|[BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map)|Marca o início das entradas de mapa de ponto de conexão.|
|[CONNECTION_POINT_ENTRY](#connection_point_entry)|Insere os pontos de conexão no mapa.|
|[CONNECTION_POINT_ENTRY_P](#connection_point_entry)| (Visual Studio 2017) Semelhante ao CONNECTION_POINT_ENTRY, mas usa um ponteiro para o iid.|
|[END_CONNECTION_POINT_MAP](#end_connection_point_map)|Marca o fim das entradas de mapa de ponto de conexão.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="begin_connection_point_map"></a>  BEGIN_CONNECTION_POINT_MAP

Marca o início das entradas de mapa de ponto de conexão.

```
BEGIN_CONNECTION_POINT_MAP(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] O nome da classe que contém os pontos de conexão.

### <a name="remarks"></a>Comentários

Inicie seu mapa de ponto de conexão com a macro BEGIN_CONNECTION_POINT_MAP, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e concluir o mapa com o [END_CONNECTION_ POINT_MAP](#end_connection_point_map) macro.

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#101](../../atl/codesnippet/cpp/connection-point-macros_1.h)]

##  <a name="connection_point_entry"></a>  CONNECTION_POINT_ENTRY e CONNECTION_POINT_ENTRY_P

Insere um ponto de conexão para a interface especificada para o mapa de ponto de conexão para que ele possa ser acessado.

```
CONNECTION_POINT_ENTRY(iid)
CONNECTION_POINT_ENTRY_P(piid) // (Visual Studio 2017)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface que está sendo adicionado ao mapa de ponto de conexão.

*piid*<br/>
[in] Ponteiro para o GUID da interface que está sendo adde.

### <a name="remarks"></a>Comentários

Entradas de ponto de Conexão no mapa são usadas pelo [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md). A classe que contém o mapa de ponto de conexão deve herdar de `IConnectionPointContainerImpl`.

Inicie seu mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com a macro CONNECTION_POINT_ENTRY e concluir o mapa com o [END_CONNECTION_ POINT_MAP](#end_connection_point_map) macro.

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#120](../../atl/codesnippet/cpp/connection-point-macros_2.h)]

##  <a name="end_connection_point_map"></a>  END_CONNECTION_POINT_MAP

Marca o fim das entradas de mapa de ponto de conexão.

```
END_CONNECTION_POINT_MAP()
```

### <a name="remarks"></a>Comentários

Inicie seu mapa de ponto de conexão com o [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) macro, adicione entradas para cada um dos seus pontos de conexão com o [CONNECTION_POINT_ENTRY](#connection_point_entry) macro e concluir o mapa com o END_ Macro CONNECTION_POINT_MAP.

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de Conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#128](../../atl/codesnippet/cpp/connection-point-macros_3.h)]

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de ponto de conexão](../../atl/reference/connection-point-global-functions.md)
