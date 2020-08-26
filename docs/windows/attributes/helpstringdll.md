---
title: helpstringdll (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstringdll
helpviewer_keywords:
- helpstringdll attribute [C++]
ms.assetid: 121271fa-f061-492b-b87f-bbfcf4b02e7b
ms.openlocfilehash: 0c90a6a203189eff927819a3319fac6a8e9f6a55
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842839"
---
# <a name="helpstringdll"></a>helpstringdll

Especifica o nome da DLL a ser usada para executar a pesquisa de cadeia de caracteres do documento (localização).

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringdll("string") ]
```

### <a name="parameters"></a>parâmetros

*cadeia de caracteres*<br/>
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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos do método](method-attributes.md)
