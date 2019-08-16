---
title: custom (C++)
ms.date: 11/04/2016
f1_keywords:
- vc-attr.custom
helpviewer_keywords:
- custom attributes, defining
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
ms.openlocfilehash: 19f28963a18abf42c6f629ac0f6491628387aa6d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491005"
---
# <a name="custom-c"></a>custom (C++)

Define os metadados de um objeto na biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```cpp
[ custom(
   uuid,
   value
) ];
```

### <a name="parameters"></a>Parâmetros

*uuid*<br/>
Uma ID exclusiva.

*value*<br/>
Um valor que pode ser colocado em uma variante.

## <a name="remarks"></a>Comentários

O atributo **personalizado** C++ fará com que as informações sejam colocadas na biblioteca de tipos. Você precisará de uma ferramenta que leia o valor personalizado da biblioteca de tipos.

O atributo **personalizado** tem a mesma funcionalidade que o atributo MIDL [personalizado](/windows/win32/Midl/custom) .

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**Interface**não com, **classe**, **enum**s, `idl_module` métodos, membros de interface, parâmetros de interface, **typedef**s, **Union**s, **struct**s|
|**Repetível**|Sim|
|**Atributos necessários**|**coclass** (quando usado na classe)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)