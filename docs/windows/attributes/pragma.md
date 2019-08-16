---
title: pragma (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.pragma
helpviewer_keywords:
- pragma attribute
ms.assetid: 3f90d023-b8b5-4007-8311-008bb72cbea1
ms.openlocfilehash: 5c3ee0d3f99bd27ca41d68b11c11522e92c8d40a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514271"
---
# <a name="pragma"></a>(pragma)

Emite a cadeia de caracteres especificada no arquivo. idl gerado sem o uso de aspas.

## <a name="syntax"></a>Sintaxe

```cpp
[ pragma(pragma_statement) ];
```

### <a name="parameters"></a>Parâmetros

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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[pack](../../preprocessor/pack.md)