---
title: HelpString (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstring
helpviewer_keywords:
- helpstring attribute [C++]
ms.assetid: 0401e905-a63e-4fad-98d0-d1efea111966
ms.openlocfilehash: d22ecf5a7131a1368abf2b1fbd8261ec6195b51e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166959"
---
# <a name="helpstring"></a>helpstring

Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstring("string") ]
```

### <a name="parameters"></a>parâmetros

*cadeia de caracteres*<br/>
O texto da cadeia de caracteres da ajuda.

## <a name="remarks"></a>Comentários

O **helpstring** C++ atributo HelpString tem a mesma funcionalidade que o atributo MIDL [HelpString](/windows/win32/Midl/helpstring) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [DefaultValue](defaultvalue.md) para obter um exemplo de como usar **HelpString**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **Class**, Method, Property|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpfile](helpfile.md)<br/>
[helpcontext](helpcontext.md)
