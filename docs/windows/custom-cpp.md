---
title: personalizado (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.custom
dev_langs:
- C++
helpviewer_keywords:
- custom attributes, defining
ms.assetid: 3abac928-4d55-4ea6-8cf6-8427a4ad79f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ec3ba8280ab481211d98c9dc5256c94e76e193e2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396435"
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

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)<br/>
[Atributos independentes](../windows/stand-alone-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](../windows/parameter-attributes.md)<br/>
[Atributos de método](../windows/method-attributes.md)<br/>
[Atributos de classe](../windows/class-attributes.md)<br/>
[Atributos de interface](../windows/interface-attributes.md)  