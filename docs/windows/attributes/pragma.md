---
title: pragma (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.pragma
helpviewer_keywords:
- pragma attribute
ms.assetid: 3f90d023-b8b5-4007-8311-008bb72cbea1
ms.openlocfilehash: e5683a6f52eccf9eae7c29010849a148e506b286
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836163"
---
# <a name="pragma"></a>pragma

Emite a cadeia de caracteres especificada no arquivo. idl gerado sem o uso de aspas.

## <a name="syntax"></a>Sintaxe

```cpp
[ pragma(pragma_statement) ];
```

### <a name="parameters"></a>parâmetros

*pragma_statement*<br/>
O pragma que você deseja ir para o arquivo. idl gerado.

## <a name="remarks"></a>Comentários

O atributo **pragma** C++ tem a mesma funcionalidade que o atributo de MIDL de [pragma](/windows/win32/Midl/pragma) .

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_pragma.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="MyLib")];
[pragma(pack(4))];

[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]
__interface A
{
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[pack](../../preprocessor/pack.md)
