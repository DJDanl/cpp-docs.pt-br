---
title: helpstringdll (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstringdll
helpviewer_keywords:
- helpstringdll attribute [C++]
ms.assetid: 121271fa-f061-492b-b87f-bbfcf4b02e7b
ms.openlocfilehash: 8d6dddef666f074a57f54b8c9447847ff56d26fd
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501477"
---
# <a name="helpstringdll"></a>helpstringdll

Especifica o nome da DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento (localização).

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringdll("string") ]
```

### <a name="parameters"></a>Parâmetros

*string*<br/>
A DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento.

## <a name="remarks"></a>Comentários

O atributo **helpstringdll** C++ tem a mesma funcionalidade que o atributo MIDL [helpstringdll](/windows/win32/Midl/helpstringdll) .

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_helpstringdll.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib", helpstringdll="xx.dll")];

[object, uuid("00000000-0000-0000-0000-000000000001")]
__interface IMyI
{
   HRESULT xxx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**classe**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)