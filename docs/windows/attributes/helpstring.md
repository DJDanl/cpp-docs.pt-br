---
title: HelpString (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstring
helpviewer_keywords:
- helpstring attribute [C++]
ms.assetid: 0401e905-a63e-4fad-98d0-d1efea111966
ms.openlocfilehash: 12707dde61013caa1ed9feb1d0daa74cbb7b9d9a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50591367"
---
# <a name="helpstring"></a>helpstring

Especifica uma cadeia de caracteres que é usada para descrever o elemento ao qual ela se aplica.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstring("string") ]
```

### <a name="parameters"></a>Parâmetros

*string*<br/>
O texto da cadeia de caracteres de Ajuda.

## <a name="remarks"></a>Comentários

O **helpstring** atributo C++ tem a mesma funcionalidade que o [helpstring](/windows/desktop/Midl/helpstring) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para obter um exemplo de como usar **helpstring**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, propriedade|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[helpfile](helpfile.md)<br/>
[helpcontext](helpcontext.md)