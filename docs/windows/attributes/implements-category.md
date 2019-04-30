---
title: implements_category (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.implements_category
helpviewer_keywords:
- implements_category attribute
ms.assetid: fb162df3-1ebe-43dc-a084-668d7ef8c03f
ms.openlocfilehash: beca804fae8d6e82b4664102b39d76a23e66ca59
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62409402"
---
# <a name="implementscategory"></a>implements_category

Especifica as categorias de componente implementadas pela classe de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[ implements_category(implements_category="uuid") ]
```

### <a name="parameters"></a>Parâmetros

*implements_category*<br/>
A ID da categoria de implementado.

## <a name="remarks"></a>Comentários

O **implements_category** C++ atributo especifica as categorias de componente implementadas pela classe de destino. Isso é feito criando um mapa de categoria e adicionando entradas separadas especificadas pelo **implements_category** atributo. Para obter mais informações, consulte [quais são as categorias de componente e como fazer funcionam?](https://msdn.microsoft.com/library/windows/desktop/ms694322).

Este atributo exige que o [coclass](coclass.md), [progid](progid.md), ou [vi_progid](vi-progid.md) atributo (ou outro atributo que implica uma destas opções) também ser aplicadas ao mesmo elemento. Se qualquer atributo único for usado, os outros dois são aplicados automaticamente. Por exemplo, se `progid` for aplicada, `vi_progid` e `coclass` também são aplicadas.

## <a name="example"></a>Exemplo

O código a seguir especifica que o seguinte objeto implementa a `Control` categoria.

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**class**, **struct**|
|**Repetível**|Sim|
|**Atributos obrigatórios**|Um dos seguintes: `coclass`, `progid`, ou `vi_progid`|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de COM](com-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[IMPLEMENTED_CATEGORY](../../atl/reference/category-macros.md#implemented_category)