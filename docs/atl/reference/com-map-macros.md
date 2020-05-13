---
title: COM Map Macros
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_COM_MAP
- atlcom/ATL::END_COM_MAP
helpviewer_keywords:
- COM interfaces, COM map macros
ms.assetid: 0f33656d-321f-4996-90cc-9a7f21ab73c3
ms.openlocfilehash: 191a0ba0aeda6ad18cdac7ba14f7ab5f3b2282f7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326598"
---
# <a name="com-map-macros"></a>COM Map Macros

Essas macros definem mapas de interface COM.

|||
|-|-|
|[Begin_com_map](#begin_com_map)|Marca o início das entradas do mapa de interface COM.|
|[END_COM_MAP](#end_com_map)|Marca o fim das entradas do mapa de interface COM.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="begin_com_map"></a><a name="begin_com_map"></a>Begin_com_map

O mapa COM é o mecanismo que expõe interfaces `QueryInterface`em um objeto a um cliente através de .

```
BEGIN_COM_MAP(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome do objeto de classe em que você está expondo interfaces.

### <a name="remarks"></a>Comentários

[CComObjectRootEx::InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) só retorna ponteiros para interfaces no mapa COM. Inicie seu mapa de interface com a macro BEGIN_COM_MAP, adicione entradas para cada uma de suas interfaces com a [macro COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes e complete o mapa com a [END_COM_MAP](#end_com_map) macro.

### <a name="example"></a>Exemplo

A partir da amostra ATL [BEEPER:](../../overview/visual-cpp-samples.md)

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

## <a name="end_com_map"></a><a name="end_com_map"></a>END_COM_MAP

Termina a definição do seu mapa de interface COM.

```
END_COM_MAP()
```

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)<br/>
[COM Map Global Functions](../../atl/reference/com-map-global-functions.md)
