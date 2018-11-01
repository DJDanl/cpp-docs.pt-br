---
title: async_uuid (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.async_uuid
helpviewer_keywords:
- async_uuid attribute
ms.assetid: 235cb0d7-be58-4dd9-983c-e2a21bbc42c6
ms.openlocfilehash: 559500a1390e0d1bac8344d0ffcfc1bdd9ad55f0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50490903"
---
# <a name="asyncuuid"></a>async_uuid

Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
[async_uuid (uuid)]
```

### <a name="parameters"></a>Parâmetros

*uuid*<br/>
Um UUID que identifica a versão da interface.

## <a name="remarks"></a>Comentários

O **async_uuid** atributo C++ tem a mesma funcionalidade que o [async_uuid](/windows/desktop/Midl/async-uuid) atributo MIDL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_async_uuid.cpp
// compile with: /LD
#include <Windows.h>
[module(name="Test")];
[object, uuid("9e66a290-4365-11d2-a997-00c04fa37ddb"),
async_uuid("e8583106-38fd-487e-912e-4fc8645c677e")]
__interface ICustom {
   HRESULT Custom([in] long l, [out, retval] long *pLong);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|`interface`|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|**dupla**, **dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)