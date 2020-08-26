---
title: propget (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propget
helpviewer_keywords:
- propget attribute
ms.assetid: c9d4a97f-36dd-4b61-8eb0-b1a217598f14
ms.openlocfilehash: 2627213d1d1dc74edb33d70ac45f3b7bbd38ba6b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839966"
---
# <a name="propget"></a>propget

Especifica uma função de acessador de propriedade.

## <a name="syntax"></a>Sintaxe

```cpp
[propget]
```

## <a name="remarks"></a>Comentários

O atributo **propget** C++ tem a mesma funcionalidade que o atributo MIDL [propget](/windows/win32/Midl/propget) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [ligável](bindable.md) para obter um exemplo de uso de **propget**.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`propput`, `propputref`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[propput](propput.md)<br/>
[propputref](propputref.md)
