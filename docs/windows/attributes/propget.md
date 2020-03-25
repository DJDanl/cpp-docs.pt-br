---
title: propget (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.propget
helpviewer_keywords:
- propget attribute
ms.assetid: c9d4a97f-36dd-4b61-8eb0-b1a217598f14
ms.openlocfilehash: d2c0ebab1630634ddd4fc81e7c9c8364f7fad46f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166453"
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Método|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`propput`, `propputref`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[propput](propput.md)<br/>
[propputref](propputref.md)
