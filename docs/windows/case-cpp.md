---
title: caso (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: e6b610ce888e91ed8029c4166fa79a847d700dba
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436514"
---
# <a name="case-c"></a>case (C++)

Usado com o [switch_type](../windows/switch-type.md) atributo em uma **união**.

## <a name="syntax"></a>Sintaxe

```cpp
[ case(
   value
) ]
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

O **caso** atributo C++ tem a mesma funcionalidade que o **caso** atributo MIDL. Esse atributo é usado apenas com o [switch_type](../windows/switch-type.md) atributo.

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

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)  