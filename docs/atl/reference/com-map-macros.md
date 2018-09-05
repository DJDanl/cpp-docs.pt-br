---
title: Macros de mapa COM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- atlcom/ATL::BEGIN_COM_MAP
- atlcom/ATL::END_COM_MAP
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces, COM map macros
ms.assetid: 0f33656d-321f-4996-90cc-9a7f21ab73c3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 524f360f2dcc2e1eaec11723395da0be7058c21a
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43756497"
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

*x*  
[in] O nome do objeto da classe em que são expor interfaces.

### <a name="remarks"></a>Comentários

[CComObjectRootEx::InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) retorna apenas os ponteiros para as interfaces no mapa COM. Inicie seu mapa de interface com a macro BEGIN_COM_MAP, adicione entradas para cada uma das suas interfaces com o [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) macro ou uma de suas variantes e concluir o mapa com as [END_COM_MAP](#end_com_map) macro.  

### <a name="example"></a>Exemplo

Do ATL [PAGER](../../visual-cpp-samples.md) exemplo:

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

##  <a name="end_com_map"></a>  END_COM_MAP

Finaliza a definição de seu mapa de interface COM.

```
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)   
[Funções globais de mapa COM](../../atl/reference/com-map-global-functions.md)
