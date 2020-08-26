---
title: Cadeia de caracteres (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.string
helpviewer_keywords:
- string attribute
ms.assetid: ddde900a-2e99-4fcd-86e8-57e1bdba7c93
ms.openlocfilehash: 119e0aa60d123324c60825a9418e0b8c93696c5f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845374"
---
# <a name="string-c"></a>string (C++)

Indica que a matriz unidimensional **`char`** , **`wchar_t`** , `byte` (ou equivalente) ou o ponteiro para tal matriz deve ser tratado como uma cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
[string]
```

## <a name="remarks"></a>Comentários

O atributo de **cadeia de caracteres** C++ tem a mesma funcionalidade que o atributo MIDL de [cadeia de caracteres](/windows/win32/Midl/string) .

## <a name="example"></a>Exemplo

O código a seguir mostra como usar a **cadeia de caracteres** em uma interface e em um typedef:

```cpp
// cpp_attr_ref_string.cpp
// compile with: /LD
#include "unknwn.h"
[module(name="ATLFIRELib")];
[export, string] typedef char a[21];
[dispinterface, restricted, uuid("00000000-0000-0000-0000-000000000001")]
__interface IFireTabCtrl
{
   [id(1)] HRESULT Method3([in, string] char *pC);
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Matriz ou ponteiro para uma matriz, parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de matriz](array-attributes.md)<br/>
[Export](export.md)
