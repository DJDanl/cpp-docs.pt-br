---
title: switch_type | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.switch_type
dev_langs:
- C++
helpviewer_keywords:
- switch_type attribute
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0ed603a416e7f56e4415ce36ad4b3fd8059d311f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46415740"
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

Consulte a [caso](../windows/case-cpp.md) exemplo para uso do exemplo **switch_type**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[export](../windows/export.md)  