---
title: PTR (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.ptr
helpviewer_keywords:
- ptr attribute
ms.assetid: 95eaea57-a5be-45f6-a612-ba2c9bc4645a
ms.openlocfilehash: 2c712a2d9c85e0fe8fd8c4dbad5c7f48812ab1a2
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59030122"
---
# <a name="ptr"></a>ptr

Designa um ponteiro como um ponteiro completo.

## <a name="syntax"></a>Sintaxe

```cpp
[ptr]
```

## <a name="remarks"></a>Comentários

O **ptr** atributo C++ tem a mesma funcionalidade que o [ptr](/windows/desktop/Midl/ptr) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [defaultvalue](defaultvalue.md) para uso do exemplo **ptr**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Parâmetro de interface, o método de interface, **typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)