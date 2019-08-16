---
title: async_uuid (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.async_uuid
helpviewer_keywords:
- async_uuid attribute
ms.assetid: 235cb0d7-be58-4dd9-983c-e2a21bbc42c6
ms.openlocfilehash: 70e73a6286a4b6adaba20b5a35dc16d8389b1948
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501872"
---
# <a name="async_uuid"></a>async_uuid

Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
[async_uuid (uuid)]
```

### <a name="parameters"></a>Parâmetros

*uuid*<br/>
Um UUID que identifica a versão da interface.

## <a name="remarks"></a>Comentários

O atributo **async_uuid** C++ tem a mesma funcionalidade que o atributo MIDL [async_uuid](/windows/win32/Midl/async-uuid) .

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|`interface`|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|**dual**, **dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)