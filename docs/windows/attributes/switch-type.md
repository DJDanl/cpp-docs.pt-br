---
title: switch_type (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.switch_type
helpviewer_keywords:
- switch_type attribute
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
ms.openlocfilehash: e8827fe576282b86f1d3bc633ec7f9f954c015b7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448783"
---
# <a name="switchtype"></a>switch_type

Identifica o tipo da variável usada como o discriminador de união.

## <a name="syntax"></a>Sintaxe

```cpp
[switch_type(
type
}]
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
O tipo de comutador, pode ser um tipo de caractere, inteiro, booliano ou enumeração.

## <a name="remarks"></a>Comentários

O **switch_type** atributo C++ tem a mesma funcionalidade que o [switch_type](/windows/desktop/Midl/switch-type) atributo MIDL.

Atributos de C++ não oferecem suporte a [encapsulada uniões](/windows/desktop/Midl/encapsulated-unions). [Uniões nonencapsulated](/windows/desktop/Midl/nonencapsulated-unions) têm suporte apenas no seguinte formato:

```cpp
// cpp_attr_ref_switch_type.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLibrary")];
[ export ]
struct SizedValue2 {
   [switch_type("char"), switch_is(kind)] union {
      [case(1), string]
         wchar_t* wval;
      [default, string]
         char* val;
   };
   char kind;
};
```

## <a name="example"></a>Exemplo

Consulte a [caso](case-cpp.md) exemplo para uso do exemplo **switch_type**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[export](export.md)