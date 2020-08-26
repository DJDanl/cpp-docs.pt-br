---
title: call_as (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.call_as
helpviewer_keywords:
- call_as attribute
ms.assetid: a09d7f1f-353b-4870-9b45-f0284161695d
ms.openlocfilehash: 9ae620ed6f2b01cc52e4a9c76217f044db925f11
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88838914"
---
# <a name="call_as"></a>call_as

Permite que uma função [local](local-cpp.md) seja mapeada para uma função remota para que, quando a função remota for chamada, a função local seja invocada.

## <a name="syntax"></a>Sintaxe

```cpp
[ call_as(function) ]
```

### <a name="parameters"></a>parâmetros

*função*<br/>
A função local que você deseja que seja chamada quando uma função remota é invocada.

## <a name="remarks"></a>Comentários

O atributo **call_as** C++ tem a mesma funcionalidade que o atributo MIDL [call_as](/windows/win32/Midl/call-as) .

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode usar **call_as** para mapear uma função não remotable ( `f1` ) para uma função remota ( `Remf1` ):

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[local](local-cpp.md)
