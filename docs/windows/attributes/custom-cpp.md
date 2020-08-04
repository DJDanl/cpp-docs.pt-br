---
title: custom (C++)
ms.date: 11/04/2016
f1_keywords:
- vc-attr.custom
helpviewer_keywords:
- custom attributes, defining
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
ms.openlocfilehash: 7a1d9bd64a28fa7c08477c6011dc0e8236b7bcf6
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87521246"
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

O atributo C++ **personalizado** fará com que as informações sejam colocadas na biblioteca de tipos. Você precisará de uma ferramenta que leia o valor personalizado da biblioteca de tipos.

O atributo **personalizado** tem a mesma funcionalidade que o atributo MIDL [personalizado](/windows/win32/Midl/custom) .

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

- **Aplica-se a**: não-com `interface` , `idl_module` métodos, membros de interface, parâmetros de interface,,,, **`typedef`** **`class`** **`enum`** **`union`** e **`struct`** tipos.
- **Repetível**: Sim.
- **Atributos obrigatórios**: **coclass** (quando usado na classe).
- **Atributos inválidos**: nenhum.

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)
