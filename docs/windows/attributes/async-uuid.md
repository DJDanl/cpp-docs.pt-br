---
title: async_uuid (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.async_uuid
helpviewer_keywords:
- async_uuid attribute
ms.assetid: 235cb0d7-be58-4dd9-983c-e2a21bbc42c6
ms.openlocfilehash: 537bd6d645532d9d5d20b740125c66f3953239bc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168454"
---
# <a name="async_uuid"></a>async_uuid

Especifica o UUID que direciona o compilador MIDL para definir versões síncronas e assíncronas de uma interface COM.

## <a name="syntax"></a>Sintaxe

```cpp
[async_uuid (uuid)]
```

### <a name="parameters"></a>parâmetros

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
|**Atributos inválidos**|**dupla**, **dispinterface**|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
