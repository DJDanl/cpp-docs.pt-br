---
title: Public (atributos C++) (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.public
helpviewer_keywords:
- public attribute
ms.assetid: c42e1fd5-6cb1-48fe-8a03-95f2a2e0137c
ms.openlocfilehash: d5307b96c58492aa06f115ca7a814aa221062e01
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224364"
---
# <a name="public-c-attributes"></a>public (atributos C++)

Garante que um typedef entrará na biblioteca de tipos, mesmo que não seja referenciado de dentro do arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[public]
```

## <a name="remarks"></a>Comentários

O **`public`** atributo C++ tem a mesma funcionalidade que o atributo MIDL [público](/windows/win32/Midl/public) .

## <a name="example"></a>Exemplo

O código a seguir mostra como usar o **`public`** atributo:

```cpp
// cpp_attr_ref_public.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="ATLFIRELib")];
[export, public] typedef long MEMBERID;

[dispinterface, uuid(99999999-9999-9999-9999-000000000000)]
__interface IFireTabCtrl : IDispatch
{
   [id(2)] long procedure ([in, optional] VARIANT i);
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`typedef`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
