---
title: agregável (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.aggregatable
helpviewer_keywords:
- aggregatable attribute
ms.assetid: 9253a46a-cd76-41f2-b3b6-86f709bb069c
ms.openlocfilehash: d929543f699dcd20471ff9a9b45f54119f82a40a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168519"
---
# <a name="aggregatable"></a>aggregatable

Indica que a classe oferece suporte à agregação.

## <a name="syntax"></a>Sintaxe

```cpp
[ aggregatable(value) ]
```

### <a name="parameters"></a>parâmetros

*value*<br/>
Adicional Um parâmetro para indicar quando o objeto COM pode ser agregado:

- `never` o objeto COM não pode ser agregado.

- `allowed` o objeto COM pode ser criado diretamente ou pode ser agregado. Esse é o padrão.

- `always` o objeto COM não pode ser criado diretamente e só pode ser agregado. Ao chamar `CoCreateInstance` para esse objeto, você deve especificar a interface de `IUnknown` do objeto de agregação (o `IUnknown`de controle).

## <a name="remarks"></a>Comentários

O **aggregatable** C++ atributo agregável tem a mesma funcionalidade que o atributo MIDL [agregável](/windows/win32/Midl/aggregatable) . Isso significa que o compilador passará o atributo **agregável** para o arquivo. idl gerado.

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` for aplicado, `vi_progid` e `coclass` também serão aplicadas.

### <a name="atl-projects"></a>Projetos da ATL

Se esse atributo for usado em um projeto que usa ATL, o comportamento do atributo será alterado. Além do comportamento descrito anteriormente, o atributo também adiciona uma das seguintes macros à classe de destino:

|Valor de parâmetro|Macro inserida|
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos necessários**|Um ou mais dos seguintes: `coclass`, `progid`ou `vi_progid`.|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Agregação](/windows/win32/com/aggregation)
