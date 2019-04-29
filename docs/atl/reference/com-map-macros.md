---
title: Macros de mapa COM
ms.date: 11/04/2016
f1_keywords:
- atlcom/ATL::BEGIN_COM_MAP
- atlcom/ATL::END_COM_MAP
helpviewer_keywords:
- COM interfaces, COM map macros
ms.assetid: 0f33656d-321f-4996-90cc-9a7f21ab73c3
ms.openlocfilehash: 3159a53b5a500aa61b85cf2bc5a97d321ed6ebb5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62245615"
---
# <a name="com-map-macros"></a>Macros de mapa COM

Essas macros definem os mapas de interface COM.

|||
|-|-|
|[BEGIN_COM_MAP](#begin_com_map)|Marca o início das entradas de mapa de interface COM.|
|[END_COM_MAP](#end_com_map)|Marca o fim das entradas de mapa de interface COM.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="begin_com_map"></a>  BEGIN_COM_MAP

O mapa COM é o mecanismo que expõe interfaces em um objeto para um cliente por meio de `QueryInterface`.

```
BEGIN_COM_MAP(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] O nome do objeto da classe em que são expor interfaces.

### <a name="remarks"></a>Comentários

[CComObjectRootEx::InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) retorna apenas os ponteiros para as interfaces no mapa COM. Inicie seu mapa de interface com a macro BEGIN_COM_MAP, adicione entradas para cada uma das suas interfaces com o [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) macro ou uma de suas variantes e concluir o mapa com as [END_COM_MAP](#end_com_map) macro.

### <a name="example"></a>Exemplo

Do ATL [PAGER](../../overview/visual-cpp-samples.md) exemplo:

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

##  <a name="end_com_map"></a>  END_COM_MAP

Finaliza a definição de seu mapa de interface COM.

```
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de mapa COM](../../atl/reference/com-map-global-functions.md)
