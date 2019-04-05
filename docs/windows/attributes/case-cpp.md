---
title: caso (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.case
helpviewer_keywords:
- case attribute
ms.assetid: 6fb883c3-0526-4932-a901-b4564dcaeb7d
ms.openlocfilehash: b3058f2fe6f35e1b11d4790780cb0fcdcaada706
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038194"
---
# <a name="case-c"></a>case (C++)

Usado com o [switch_type](switch-type.md) atributo em uma **união**.

## <a name="syntax"></a>Sintaxe

```cpp
[ case(value) ]
```

#### <a name="parameters"></a>Parâmetros

*Valor *<br/>
Um valor de entrada possíveis para o qual você deseja fornecer processamento. O tipo de **valor** pode ser um dos seguintes tipos:

- `int`

- `char`

- `boolean`

- `enum`

ou um identificador desse tipo.

## <a name="remarks"></a>Comentários

O **caso** atributo C++ tem a mesma funcionalidade que o **caso** atributo MIDL. Esse atributo é usado apenas com o [switch_type](switch-type.md) atributo.

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do **caso** atributo:

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Membro de um **classe** ou **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)