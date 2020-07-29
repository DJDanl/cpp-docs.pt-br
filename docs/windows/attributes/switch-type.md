---
title: switch_type (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.switch_type
helpviewer_keywords:
- switch_type attribute
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
ms.openlocfilehash: 13ea76e1153e1a42fd41fe0c087a7c7f15416760
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211925"
---
# <a name="switch_type"></a>switch_type

Identifica o tipo da variável usada como discriminante de União.

## <a name="syntax"></a>Sintaxe

```cpp
[switch_type(
type
}]
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
O tipo de comutador, pode ser um número inteiro, caractere, booliano ou tipo de enumeração.

## <a name="remarks"></a>Comentários

O atributo **switch_type** C++ tem a mesma funcionalidade que o atributo MIDL [switch_type](/windows/win32/Midl/switch-type) .

Os atributos do C++ não dão suporte a [uniões encapsuladas](/windows/win32/Midl/encapsulated-unions). [Uniões não encapsuladas](/windows/win32/Midl/nonencapsulated-unions) têm suporte apenas no seguinte formato:

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

Consulte o exemplo de [caso](case-cpp.md) para obter um exemplo de uso de **switch_type**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`typedef`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Export](export.md)
