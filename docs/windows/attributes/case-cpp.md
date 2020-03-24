---
title: Case (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.case
helpviewer_keywords:
- case attribute
ms.assetid: 6fb883c3-0526-4932-a901-b4564dcaeb7d
ms.openlocfilehash: da72fff3bb600b5db2fba0ecdfe9c6a768836f3c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80167324"
---
# <a name="case-c"></a>case (C++)

Usado com o atributo [switch_type](switch-type.md) em uma **Union**.

## <a name="syntax"></a>Sintaxe

```cpp
[ case(value) ]
```

#### <a name="parameters"></a>parâmetros

*value*<br/>
Um valor de entrada possível para o qual você deseja fornecer processamento. O tipo de **valor** pode ser um dos seguintes tipos:

- `int`

- `char`

- `boolean`

- `enum`

ou um identificador desse tipo.

## <a name="remarks"></a>Comentários

O atributo **Case** C++ tem a mesma funcionalidade que o atributo MIDL de **caso** . Esse atributo só é usado com o atributo [switch_type](switch-type.md) .

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do atributo **Case** :

```cpp
// cpp_attr_ref_case.cpp
// compile with: /LD
#include <unknwn.h>
[export]
struct SizedValue2 {
   [switch_type(char), switch_is(kind)] union {
      [case(1), string]
          wchar_t* wval;
      [default, string]
          char* val;
   };
    char kind;
};
[module(name="ATLFIRELib")];
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Membro de uma **classe** ou **estrutura**|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)
