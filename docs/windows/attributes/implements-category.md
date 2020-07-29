---
title: implements_category (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.implements_category
helpviewer_keywords:
- implements_category attribute
ms.assetid: fb162df3-1ebe-43dc-a084-668d7ef8c03f
ms.openlocfilehash: 067a3a183820b09112217647e20d12b592540613
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224416"
---
# <a name="implements_category"></a>implements_category

Especifica as categorias de componentes implementadas pela classe de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[ implements_category(implements_category="uuid") ]
```

### <a name="parameters"></a>parâmetros

*implements_category*<br/>
A ID da categoria implementada.

## <a name="remarks"></a>Comentários

O atributo **implements_category** C++ especifica as categorias de componentes implementadas pela classe de destino. Isso é feito criando um mapa de categoria e adicionando entradas separadas especificadas pelo atributo **implements_category** . Para obter mais informações, consulte [categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work).

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` é aplicado `vi_progid` e `coclass` também é aplicado.

## <a name="example"></a>Exemplo

O código a seguir especifica que o objeto a seguir implementa a `Control` categoria.

```cpp
// cpp_attr_ref_implements_category.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module (name="MyLib")];
[ coclass, implements_category("CATID_Control"),
  uuid("20a0d0cc-5172-40f5-99ae-5e032f3205ae")]
class CMyClass {};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`class`**, **`struct`**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um dos seguintes: `coclass` , `progid` ou`vi_progid`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[IMPLEMENTED_CATEGORY](../../atl/reference/category-macros.md#implemented_category)
