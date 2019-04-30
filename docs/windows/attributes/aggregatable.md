---
title: (C++ COM atributo agregável)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.aggregatable
helpviewer_keywords:
- aggregatable attribute
ms.assetid: 9253a46a-cd76-41f2-b3b6-86f709bb069c
ms.openlocfilehash: 8d5ceb46a124db8c0082495d48e6ee0e21655422
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390991"
---
# <a name="aggregatable"></a>aggregatable

Indica que a classe oferece suporte à agregação.

## <a name="syntax"></a>Sintaxe

```cpp
[ aggregatable(value) ]
```

### <a name="parameters"></a>Parâmetros

*value*<br/>
(Opcional) Um parâmetro para indicar quando o objeto COM pode ser agregado:

- `never` O objeto COM não pode ser agregado.

- `allowed` O objeto COM pode ser criado diretamente ou eles podem ser agregados. Esse é o padrão.

- `always` O objeto COM não pode ser criado diretamente e só pode ser agregado. Quando você chama `CoCreateInstance` para esse objeto, você deve especificar o objeto de agregação `IUnknown` interface (o controlando `IUnknown`).

## <a name="remarks"></a>Comentários

O **agregável** atributo C++ tem a mesma funcionalidade que o [agregável](/windows/desktop/Midl/aggregatable) atributo MIDL. Isso significa que o compilador passará a **agregável** por meio do atributo para o arquivo. idl gerado.

Este atributo exige que o [coclass](coclass.md), [progid](progid.md), ou [vi_progid](vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

### <a name="atl-projects"></a>Projetos ATL

Se esse atributo for usado em um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento descrito anteriormente, o atributo também adiciona uma das macros de seguir para a classe de destino:

|Valor do parâmetro|Macro inserida|
|---------------------|--------------------|
|`Never`|[DECLARE_NOT_AGGREGATABLE](../../atl/reference/aggregation-and-class-factory-macros.md#declare_not_aggregatable)|
|`Allowed`|[DECLARE_POLY_AGGREGATABLE](../../atl/reference/aggregation-and-class-factory-macros.md#declare_poly_aggregatable)|
|`Always`|[DECLARE_ONLY_AGGREGATABLE](../../atl/reference/aggregation-and-class-factory-macros.md#declare_only_aggregatable)|

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_aggregatable.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module(name="MyModule")];

[ coclass, aggregatable(allowed),
  uuid("1a8369cc-1c91-42c4-befa-5a5d8c9d2529")]
class CMyClass {};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Um ou mais das seguintes opções: `coclass`, `progid`, ou `vi_progid`.|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Agregação](/windows/desktop/com/aggregation)