---
title: HelpContext (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpcontext
helpviewer_keywords:
- helpcontext attribute
ms.assetid: 6fbb022d-a4b7-4989-a02f-7f18a9b0ad96
ms.openlocfilehash: 292db21e8092284a92b09ef3f889bb0475d0d886
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166998"
---
# <a name="helpcontext"></a>helpcontext

Especifica uma ID de contexto que permite ao usuário exibir informações sobre esse elemento no arquivo de **ajuda** .

## <a name="syntax"></a>Sintaxe

```cpp
[ helpcontext(id) ]
```

### <a name="parameters"></a>parâmetros

*id*<br/>
A ID de contexto do tópico da ajuda. Consulte [ajuda em HTML: Ajuda contextual para seus programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) para obter mais informações sobre IDs de contexto.

## <a name="remarks"></a>Comentários

O atributo **HelpContext** C++ tem a mesma funcionalidade que o atributo MIDL de [HelpContext](/windows/win32/Midl/helpcontext) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [DefaultValue](defaultvalue.md) para obter um exemplo de como usar o **HelpContext**.

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
[helpstring](helpstring.md)
