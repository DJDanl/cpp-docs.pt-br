---
title: agregações (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.aggregates
helpviewer_keywords:
- aggregates attribute
- aggregation [C++]
- aggregate objects [C++], aggregates attribute
- aggregates [C++]
ms.assetid: 67a084c9-941f-474b-a029-9c93b38ebe9a
ms.openlocfilehash: 65a166faa9380272c87af92ebaf8294c0e0b1af3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87217279"
---
# <a name="aggregates"></a>aggregates

Indica que o objeto agrega o objeto especificado pelo CLSID.

## <a name="syntax"></a>Sintaxe

```cpp
[ aggregates(clsid, variable_name) ]
```

### <a name="parameters"></a>parâmetros

*clsid*<br/>
Especifica o CLSID do objeto agregável.

*variable_name*<br/>
O nome da variável a ser inserida. Essa variável contém o `IUnknown` do objeto que está sendo agregado.

## <a name="remarks"></a>Comentários

Quando aplicado a um objeto, o atributo de **agregações** do C++ implementa um wrapper externo para o objeto que está sendo agregado (especificado por `clsid` ).

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` é aplicado `vi_progid` e `coclass` também é aplicado.

### <a name="atl-projects"></a>Projetos da ATL

Se esse atributo for usado em um projeto que usa ATL, o comportamento do atributo será alterado. Primeiro, a seguinte entrada é adicionada ao mapa COM do objeto de destino:

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(_m_spAttrXXX, clsid)
```

Em segundo lugar, a macro [DECLARE_GET_CONTROLLING_UNKNOWN](../../atl/reference/aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) também é adicionada.

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um ou mais dos seguintes: `coclass` , `progid` ou `vi_progid` .|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Agregação](/windows/win32/com/aggregation)<br/>
[Agregável](/windows/win32/Midl/aggregatable)<br/>
[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](../../atl/reference/com-interface-entry-macros.md#com_interface_entry_autoaggregate_blind)
