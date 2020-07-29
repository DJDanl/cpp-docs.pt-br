---
title: exclusivo (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.unique
helpviewer_keywords:
- unique attribute
ms.assetid: abd7ed14-5ae7-44a8-8333-0058e9c92b2f
ms.openlocfilehash: a46d607ef03fcb75fea31835726d0e2d95e71df8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87201018"
---
# <a name="unique-c"></a>unique (C++)

Especifica um ponteiro exclusivo.

## <a name="syntax"></a>Sintaxe

```cpp
[unique]
```

## <a name="remarks"></a>Comentários

O atributo C++ **exclusivo** tem a mesma funcionalidade que o atributo MIDL [exclusivo](/windows/win32/Midl/unique) .

## <a name="example"></a>Exemplo

Consulte o exemplo [ref](ref-cpp.md) para um exemplo de uso de **exclusivo**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|**`typedef`**, **`struct`** , **`union`** , parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)
