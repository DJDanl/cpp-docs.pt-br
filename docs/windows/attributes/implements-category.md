---
title: implements_category (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.implements_category
helpviewer_keywords:
- implements_category attribute
ms.assetid: fb162df3-1ebe-43dc-a084-668d7ef8c03f
ms.openlocfilehash: dd55c7474a0a8a273ddfab212b3ebcaa6e3b4a65
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166856"
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

O atributo **implements_category** C++ especifica as categorias de componente implementadas pela classe de destino. Isso é feito criando um mapa de categoria e adicionando entradas separadas especificadas pelo atributo **implements_category** . Para obter mais informações, consulte [categorias de componentes e como elas funcionam](/windows/win32/com/component-categories-and-how-they-work).

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento. Se qualquer atributo único for usado, os outros dois serão aplicados automaticamente. Por exemplo, se `progid` for aplicado, `vi_progid` e `coclass` também serão aplicadas.

## <a name="example"></a>Exemplo

O código a seguir especifica que o objeto a seguir implementa a categoria de `Control`.

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
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Sim|
|**Atributos necessários**|Um dos seguintes: `coclass`, `progid`ou `vi_progid`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[IMPLEMENTED_CATEGORY](../../atl/reference/category-macros.md#implemented_category)
