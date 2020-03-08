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
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864925"
---
# <a name="com-map-macros"></a>Macros de mapa COM

Essas macros definem mapas de interface COM.

|||
|-|-|
|[BEGIN_COM_MAP](#begin_com_map)|Marca o início das entradas do mapa da interface COM.|
|[END_COM_MAP](#end_com_map)|Marca o final das entradas do mapa da interface COM.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlcom. h

##  <a name="begin_com_map"></a>BEGIN_COM_MAP

O mapa COM é o mecanismo que expõe interfaces em um objeto a um cliente por meio de `QueryInterface`.

```
BEGIN_COM_MAP(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no O nome do objeto de classe no qual você está expondo interfaces.

### <a name="remarks"></a>Comentários

[CComObjectRootEx:: InternalQueryInterface](ccomobjectrootex-class.md#internalqueryinterface) retorna ponteiros apenas para interfaces no mapa com. Inicie o mapa de interface com a macro BEGIN_COM_MAP, adicione entradas para cada uma de suas interfaces com a macro [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) ou uma de suas variantes e conclua o mapa com a macro [END_COM_MAP](#end_com_map) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Do exemplo de [bip](../../overview/visual-cpp-samples.md) do ATL:

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

##  <a name="end_com_map"></a>END_COM_MAP

Finaliza a definição do seu mapa de interface COM.

```
END_COM_MAP()
```

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)<br/>
[Funções globais de mapa COM](../../atl/reference/com-map-global-functions.md)
