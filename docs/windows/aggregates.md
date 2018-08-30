---
title: agregações | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: bf6ca06ffbd3912ac3545bc3c014224412c01bc1
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221164"
---
# <a name="aggregates"></a>aggregates

Indica que o objeto agrega o objeto especificado pelo CLSID.

## <a name="syntax"></a>Sintaxe

```cpp
[ aggregates(
   clsid,
   variable_name
) ]
```

### <a name="parameters"></a>Parâmetros

*clsid*  
Especifica o CLSID do objeto agregável.

*variable_name*  
O nome da variável que deve ser inserido. Essa variável contém o `IUnknown` do objeto que está sendo agregado.

## <a name="remarks"></a>Comentários

Quando aplicado a um objeto, o **agregações** atributo C++ implementa um wrapper externo para o objeto que está sendo agregado (especificado por `clsid`).

Este atributo exige que o [coclass](../windows/coclass.md), [progid](../windows/progid.md), ou [vi_progid](../windows/vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

### <a name="atl-projects"></a>Projetos ATL

Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Em primeiro lugar, a seguinte entrada é adicionada ao mapa de COM do objeto de destino:

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(_m_spAttrXXX, clsid)  
```

Segundo, o [DECLARE_GET_CONTROLLING_UNKNOWN](../atl/reference/aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) macro também é adicionada.

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

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de COM](../windows/com-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[Agregação](/windows/desktop/com/aggregation)  
[Agregável](/windows/desktop/Midl/aggregatable)  
[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](../atl/reference/com-interface-entry-macros.md#com_interface_entry_autoaggregate_blind)  