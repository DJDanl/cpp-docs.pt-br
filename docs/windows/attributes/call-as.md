---
title: call_as (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.call_as
helpviewer_keywords:
- call_as attribute
ms.assetid: a09d7f1f-353b-4870-9b45-f0284161695d
ms.openlocfilehash: f36cf8d1be589cc614a6def583b00af00aabdb61
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501802"
---
# <a name="call_as"></a>call_as

Permite que uma função [local](local-cpp.md) seja mapeada para uma função remota para que, quando a função remota for chamada, a função local seja invocada.

## <a name="syntax"></a>Sintaxe

```cpp
[ call_as(function) ]
```

### <a name="parameters"></a>Parâmetros

*function*<br/>
A função local que você deseja que seja chamada quando uma função remota é invocada.

## <a name="remarks"></a>Comentários

O atributo **call_as** C++ tem a mesma funcionalidade que o atributo MIDL [call_as](/windows/win32/Midl/call-as) .

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar **call_as** para mapear uma função não remotable (`f1`) para uma função remota (`Remf1`):

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[local](local-cpp.md)