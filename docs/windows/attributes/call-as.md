---
title: call_as (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.call_as
helpviewer_keywords:
- call_as attribute
ms.assetid: a09d7f1f-353b-4870-9b45-f0284161695d
ms.openlocfilehash: a0051cdca6673800b37d5733c0b849da24010fcb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62148348"
---
# <a name="callas"></a>call_as

Permite que um [local](local-cpp.md) função a ser mapeada para uma função remota para que quando a função remota é chamada, a função local é invocada.

## <a name="syntax"></a>Sintaxe

```cpp
[ call_as(function) ]
```

### <a name="parameters"></a>Parâmetros

*function*<br/>
A função local que você deseja ser chamado quando uma função remota é invocada.

## <a name="remarks"></a>Comentários

O **call_as** C++ atributo tem a mesma funcionalidade que o [call_as](/windows/desktop/Midl/call-as) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar **call_as** para mapear uma função nonremotable (`f1`) para uma função remota (`Remf1`):

```cpp
// cpp_attr_ref_call_as.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyLib")];
[dual, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMInterface {
   [local] HRESULT f1 ( int i );
   [call_as(f1)] HRESULT Remf1 ( int i );
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[local](local-cpp.md)