---
title: custom (C++)
ms.date: 11/04/2016
f1_keywords:
- vc-attr.custom
helpviewer_keywords:
- custom attributes, defining
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
ms.openlocfilehash: 7aca125879591f71fe2ba60f34b712918350940f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50565692"
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

O **personalizado** atributo C++ fará com que informações sejam colocados em biblioteca de tipos. Você precisará de uma ferramenta que lê o valor personalizado da biblioteca de tipos.

O **personalizado** atributo tem a mesma funcionalidade que o [personalizado](/windows/desktop/Midl/custom) atributo MIDL.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Não-COM **interface**, **classe**, **enum**s, `idl_module` métodos, os membros da interface, parâmetros de interface **typedef**s, **união**s, **struct**s|
|**Repetível**|Sim|
|**Atributos obrigatórios**|**coclass** (quando usado na classe)|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)