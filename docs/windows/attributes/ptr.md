---
title: PTR (atributo COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.ptr
helpviewer_keywords:
- ptr attribute
ms.assetid: 95eaea57-a5be-45f6-a612-ba2c9bc4645a
ms.openlocfilehash: 9e45cd529562fe238f96f98cf7f91e15df34270a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224377"
---
# <a name="ptr"></a>ptr

Designa um ponteiro como um ponteiro completo.

## <a name="syntax"></a>Sintaxe

```cpp
[ptr]
```

## <a name="remarks"></a>Comentários

O atributo **PTR** C++ tem a mesma funcionalidade que o atributo MIDL [PTR](/windows/win32/Midl/ptr) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [DefaultValue](defaultvalue.md) para um exemplo de uso de **PTR**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, método de interface,**`typedef`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
