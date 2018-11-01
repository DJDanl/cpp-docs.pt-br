---
title: controle (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.control
helpviewer_keywords:
- Control attribute
ms.assetid: 3d046bb2-4afe-4cb8-a762-233b296e1975
ms.openlocfilehash: 9a0aec5ec2142159feb592419056da0f100914d8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482089"
---
# <a name="control"></a>Controle 

Especifica que o tipo definido pelo usuário é um controle.

## <a name="syntax"></a>Sintaxe

```cpp
[control]
```

## <a name="remarks"></a>Comentários

O **controle** atributo implica a [coclass](coclass.md) atributo. O **controle** atributo C++ tem a mesma funcionalidade que o [controle](/windows/desktop/Midl/control) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_control.cpp
// compile with: /LD
#include <windows.h>
[module(name="Test", control=true)];

[object, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb")]
__interface ICustom {
   HRESULT Custom([in] long l, [out, retval] long *pLong);
};

[coclass, control, appobject, uuid("9e66a294-4365-11d2-a997-00c04fa37ddb")]
class CTest : public ICustom {};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)