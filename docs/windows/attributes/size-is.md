---
title: size_is (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.size_is
helpviewer_keywords:
- size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
ms.openlocfilehash: 36b960982d1f88cd30bab707dfe7aec73381dfab
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213834"
---
# <a name="size_is"></a>size_is

Especifique o tamanho da memória alocada para ponteiros de tamanho, ponteiros de tamanho para ponteiros de tamanho e matrizes de dimensão única ou multidimensional.

## <a name="syntax"></a>Sintaxe

```cpp
[ size_is("expression") ]
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
O tamanho da memória alocada para ponteiros de tamanho.

## <a name="remarks"></a>Comentários

O atributo **size_is** C++ tem a mesma funcionalidade que o atributo MIDL [size_is](/windows/win32/Midl/size-is) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Campo no **`struct`** ou **`union`** , parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`max_is`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[last_is](last-is.md)<br/>
[max_is](max-is.md)<br/>
[length_is](length-is.md)
