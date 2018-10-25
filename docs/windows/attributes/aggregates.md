---
title: agregações (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.aggregates
dev_langs:
- C++
helpviewer_keywords:
- aggregates attribute
- aggregation [C++]
- aggregate objects [C++], aggregates attribute
- aggregates [C++]
ms.assetid: 67a084c9-941f-474b-a029-9c93b38ebe9a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0729ad2e68929f8fabbfd2d8439e8c8840e67419
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50071187"
---
# <a name="aggregates"></a>aggregates

Indica que o objeto agrega o objeto especificado pelo CLSID.

## <a name="syntax"></a>Sintaxe

```cpp
[ aggregates(clsid, variable_name) ]
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
Especifica o CLSID do objeto agregável.

*variable_name*<br/>
O nome da variável que deve ser inserido. Essa variável contém o `IUnknown` do objeto que está sendo agregado.

## <a name="remarks"></a>Comentários

Quando aplicado a um objeto, o **agregações** atributo C++ implementa um wrapper externo para o objeto que está sendo agregado (especificado por `clsid`).

Este atributo exige que o [coclass](coclass.md), [progid](progid.md), ou [vi_progid](vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

### <a name="atl-projects"></a>Projetos ATL

Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Em primeiro lugar, a seguinte entrada é adicionada ao mapa de COM do objeto de destino:

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(_m_spAttrXXX, clsid)
```

Segundo, o [DECLARE_GET_CONTROLLING_UNKNOWN](../../atl/reference/aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) macro também é adicionada.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_aggregates.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

// requires 'aggregatable.dll'
// see aggregatable attribute to create 'aggregatable.dll'
class DECLSPEC_UUID("1a8369cc-1c91-42c4-befa-5a5d8c9d2529") CMyClass;

[module (name="MYObject")];
[object, uuid("ab006d85-e754-47c5-9ef4-2744ff32a20c")]
__interface IObject
{
};

[ coclass, aggregates(__uuidof(CMyClass)),
  uuid("91cb2c06-8931-432a-baac-206e55c4edfb")]
struct CObject : IObject
{
   int i;
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um ou mais das seguintes opções: `coclass`, `progid`, ou `vi_progid`.|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Agregação](/windows/desktop/com/aggregation)<br/>
[Agregável](/windows/desktop/Midl/aggregatable)<br/>
[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](../../atl/reference/com-interface-entry-macros.md#com_interface_entry_autoaggregate_blind)