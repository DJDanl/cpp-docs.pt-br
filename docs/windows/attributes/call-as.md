---
title: call_as (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.call_as
helpviewer_keywords:
- call_as attribute
ms.assetid: a09d7f1f-353b-4870-9b45-f0284161695d
ms.openlocfilehash: 16839f5a5040e6b0019005912782ba359178cc47
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50579878"
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

O **call_as** atributo C++ tem a mesma funcionalidade que o [call_as](/windows/desktop/Midl/call-as) atributo MIDL.

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