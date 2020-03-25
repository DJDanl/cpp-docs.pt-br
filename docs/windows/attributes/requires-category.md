---
title: requires_category (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.requires_category
helpviewer_keywords:
- requires_category attribute
ms.assetid: a645fdc6-1ef5-414d-8c56-5fe2686d4687
ms.openlocfilehash: 19a454a8bfc959d7d97959d765dbf68d0f766ca1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214546"
---
# <a name="requires_category"></a>requires_category

Especifica as categorias de componente necessárias da classe de destino.

## <a name="syntax"></a>Sintaxe

```cpp
[ requires_category(
  requires_category) ]
```

### <a name="parameters"></a>parâmetros

*requires_category*<br/>
A ID da categoria necessária.

## <a name="remarks"></a>Comentários

O atributo **requires_category** C++ especifica as categorias de componente exigidas pela classe de destino. Para obter mais informações, consulte [REQUIRED_CATEGORY](../../atl/reference/category-macros.md#required_category).

Esse atributo requer que o atributo [coclass](coclass.md), [ProgID](progid.md)ou [vi_progid](vi-progid.md) (ou outro atributo que implica um deles) também seja aplicado ao mesmo elemento.

## <a name="example"></a>Exemplo

O código a seguir requer que o objeto implemente a categoria Control.

```cpp
// cpp_attr_ref_requires_category.cpp
// compile with: /LD
#define _ATL_ATTRIBUTES
#include "atlbase.h"
#include "atlcom.h"

[module (name="MyLibrary")];

[ coclass, requires_category("CATID_Control"),
  uuid("1e1a2436-f3ea-4ff3-80bf-5409370e8144")]
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

[Atributos de COM](com-attributes.md)<br/>
[implements_category](implements-category.md)
