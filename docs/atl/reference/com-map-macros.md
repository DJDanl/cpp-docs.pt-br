---
title: Macros de mapa COM
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_COM_MAP
- atlcom/ATL::END_COM_MAP
helpviewer_keywords:
- COM interfaces, COM map macros
ms.assetid: 0f33656d-321f-4996-90cc-9a7f21ab73c3
ms.openlocfilehash: 100402e17ca1bee5f338c37f2315fbc4898a713e
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833576"
---
# <a name="com-map-macros"></a>Macros de mapa COM

Essas macros definem mapas de interface COM.

|Macro|Descrição|
|-|-|
|[BEGIN_COM_MAP](#begin_com_map)|Marca o início das entradas do mapa da interface COM.|
|[END_COM_MAP](#end_com_map)|Marca o final das entradas do mapa da interface COM.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="begin_com_map"></a><a name="begin_com_map"></a> BEGIN_COM_MAP

O mapa COM é o mecanismo que expõe interfaces em um objeto a um cliente por meio do `QueryInterface` .

```
BEGIN_COM_MAP(x)
```

### <a name="parameters"></a>parâmetros

*x*<br/>
no O nome do objeto de classe no qual você está expondo interfaces.

### <a name="remarks"></a>Comentários

[CComObjectRootEx:: InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) retorna ponteiros apenas para interfaces no mapa com. Inicie o mapa de interface com a macro BEGIN_COM_MAP, adicione entradas para cada uma de suas interfaces com a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes e conclua o mapa com a macro [END_COM_MAP](#end_com_map) .

### <a name="example"></a>Exemplo

Do exemplo de [bip](../../overview/visual-cpp-samples.md) do ATL:

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

## <a name="end_com_map"></a><a name="end_com_map"></a> END_COM_MAP

Finaliza a definição do seu mapa de interface COM.

```
END_COM_MAP()
```

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais do mapa COM](../../atl/reference/com-map-global-functions.md)
