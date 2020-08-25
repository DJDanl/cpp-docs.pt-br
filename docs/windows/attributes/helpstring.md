---
title: HelpString (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstring
helpviewer_keywords:
- helpstring attribute [C++]
ms.assetid: 0401e905-a63e-4fad-98d0-d1efea111966
ms.openlocfilehash: 57f7a5bfd5bd0e7a6509797ec34e88531304ec92
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831028"
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

O atributo **HelpString** C++ tem a mesma funcionalidade que o atributo MIDL [HelpString](/windows/win32/Midl/helpstring) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [DefaultValue](defaultvalue.md) para obter um exemplo de como usar **HelpString**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**interface**, **`typedef`** , **`class`** , método, Propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpfile](helpfile.md)<br/>
[helpcontext](helpcontext.md)
