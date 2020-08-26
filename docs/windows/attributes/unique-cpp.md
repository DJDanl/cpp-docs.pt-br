---
title: exclusivo (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.unique
helpviewer_keywords:
- unique attribute
ms.assetid: abd7ed14-5ae7-44a8-8333-0058e9c92b2f
ms.openlocfilehash: 8b0bd5be19baddaed367bb619135be5cea8e7677
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836150"
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

| Contexto de atributo | Valor |
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
