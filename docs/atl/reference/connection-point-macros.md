---
title: Macros de ponto de conexão
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_CONNECTION_POINT_MAP
- atlcom/ATL::END_CONNECTION_POINT_MAP
helpviewer_keywords:
- connection points [C++], macros
ms.assetid: cc3a6dd3-5538-45df-b027-1f34963c31e5
ms.openlocfilehash: cb8d6f696980ef91d7b43c960dc50289ea8500a6
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78872482"
---
# <a name="connection-point-macros"></a>Macros de ponto de conexão

Essas macros definem mapas e entradas de ponto de conexão.

|||
|-|-|
|[BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map)|Marca o início das entradas do mapa do ponto de conexão.|
|[CONNECTION_POINT_ENTRY](#connection_point_entry)|Insere pontos de conexão no mapa.|
|[CONNECTION_POINT_ENTRY_P](#connection_point_entry)| (Visual Studio 2017) Semelhante a CONNECTION_POINT_ENTRY, mas usa um ponteiro para IID.|
|[END_CONNECTION_POINT_MAP](#end_connection_point_map)|Marca o final das entradas de mapa do ponto de conexão.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

##  <a name="begin_connection_point_map"></a>BEGIN_CONNECTION_POINT_MAP

Marca o início das entradas do mapa do ponto de conexão.

```
BEGIN_CONNECTION_POINT_MAP(x)
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome da classe que contém os pontos de conexão.

### <a name="remarks"></a>Comentários

Inicie o mapa do ponto de conexão com a macro BEGIN_CONNECTION_POINT_MAP, adicione entradas para cada um dos pontos de conexão com a macro [CONNECTION_POINT_ENTRY](#connection_point_entry) e conclua o mapa com a macro [END_CONNECTION_POINT_MAP](#end_connection_point_map) .

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#101](../../atl/codesnippet/cpp/connection-point-macros_1.h)]

##  <a name="connection_point_entry"></a>CONNECTION_POINT_ENTRY e CONNECTION_POINT_ENTRY_P

Insere um ponto de conexão para a interface especificada no mapa de ponto de conexão para que possa ser acessado.

```
CONNECTION_POINT_ENTRY(iid)
CONNECTION_POINT_ENTRY_P(piid) // (Visual Studio 2017)
```

### <a name="parameters"></a>parâmetros

*IID*<br/>
no O GUID da interface que está sendo adicionada ao mapa de ponto de conexão.

*piid*<br/>
no Ponteiro para o GUID da interface que está sendo Adde.

### <a name="remarks"></a>Comentários

As entradas de ponto de conexão no mapa são usadas pelo [IConnectionPointContainerImpl](../../atl/reference/iconnectionpointcontainerimpl-class.md). A classe que contém o mapa de ponto de conexão deve herdar de `IConnectionPointContainerImpl`.

Inicie o mapa do ponto de conexão com a macro [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) , adicione entradas para cada um dos pontos de conexão com a macro CONNECTION_POINT_ENTRY e conclua o mapa com a macro [END_CONNECTION_POINT_MAP](#end_connection_point_map) .

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#120](../../atl/codesnippet/cpp/connection-point-macros_2.h)]

##  <a name="end_connection_point_map"></a>END_CONNECTION_POINT_MAP

Marca o final das entradas de mapa do ponto de conexão.

```
END_CONNECTION_POINT_MAP()
```

### <a name="remarks"></a>Comentários

Inicie o mapa do ponto de conexão com a macro [BEGIN_CONNECTION_POINT_MAP](#begin_connection_point_map) , adicione entradas para cada um dos pontos de conexão com a macro [CONNECTION_POINT_ENTRY](#connection_point_entry) e conclua o mapa com a macro END_CONNECTION_POINT_MAP.

Para obter mais informações sobre pontos de conexão na ATL, consulte o artigo [pontos de conexão](../../atl/atl-connection-points.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#128](../../atl/codesnippet/cpp/connection-point-macros_3.h)]

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de ponto de conexão](../../atl/reference/connection-point-global-functions.md)
