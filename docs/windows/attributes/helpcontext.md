---
title: HelpContext (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpcontext
helpviewer_keywords:
- helpcontext attribute
ms.assetid: 6fbb022d-a4b7-4989-a02f-7f18a9b0ad96
ms.openlocfilehash: 22023b4087c67b62d540d021fa06fd3582c7e4e2
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59038145"
---
# <a name="helpcontext"></a>helpcontext

Especifica uma ID de contexto que permite que usuários exibir informações sobre este elemento na **ajudar** arquivo.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpcontext(id) ]
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID de contexto do tópico da Ajuda. Consulte [Ajuda em HTML: Ajuda contextual para seus programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) para obter mais informações sobre IDs de contexto.

## <a name="remarks"></a>Comentários

O **helpcontext** atributo C++ tem a mesma funcionalidade que o [helpcontext](/windows/desktop/Midl/helpcontext) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para obter um exemplo de como usar **helpcontext**.

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
[helpstring](helpstring.md)