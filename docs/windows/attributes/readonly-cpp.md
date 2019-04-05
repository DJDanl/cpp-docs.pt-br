---
title: ReadOnly (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.readonly
helpviewer_keywords:
- readonly attribute
ms.assetid: 1246cadd-5304-43a9-beea-51153d12704d
ms.openlocfilehash: 7eea071b62130c65fbb46ebc8827fc2b428c4c0c
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59036899"
---
# <a name="readonly-c"></a>readonly (C++)

Proíbe a atribuição a um membro de dados.

## <a name="syntax"></a>Sintaxe

```cpp
[readonly]
```

## <a name="remarks"></a>Comentários

O **readonly** atributo C++ tem a mesma funcionalidade que o [readonly](/windows/desktop/Midl/readonly) atributo MIDL.

Se você quiser impedir a modificação de um parâmetro de método, em seguida, use o [em](in-cpp.md) atributo.

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do **readonly** atributo:

```cpp
// cpp_attr_ref_readonly.cpp
// compile with: /LD
[idl_quote("midl_pragma warning(disable:2461)")];
#include "unknwn.h"
[module(name="ATLFIRELib")];

[dispinterface, uuid(11111111-1111-1111-1111-111111111111)]
__interface IFireTabCtrl
{
   [readonly, id(1)] int i();
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

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de membro de dados](data-member-attributes.md)