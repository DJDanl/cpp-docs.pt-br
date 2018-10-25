---
title: caso (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.case
dev_langs:
- C++
helpviewer_keywords:
- case attribute
ms.assetid: 6fb883c3-0526-4932-a901-b4564dcaeb7d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1e7a15d81c8efd5320cf142faa3e3f381f81abd7
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079669"
---
# <a name="case-c"></a>case (C++)

Usado com o [switch_type](switch-type.md) atributo em uma **união**.

## <a name="syntax"></a>Sintaxe

```cpp
[ case(value) ]
```

#### <a name="parameters"></a>Parâmetros

*value*<br/>
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

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](class-attributes.md)