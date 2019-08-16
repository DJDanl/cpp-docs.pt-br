---
title: size_is (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.size_is
helpviewer_keywords:
- size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
ms.openlocfilehash: 504f1bf72b8ffa15e8df50bb00c86ef909688f1e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514030"
---
# <a name="size_is"></a>size_is

Especifique o tamanho da memória alocada para ponteiros de tamanho, ponteiros de tamanho para ponteiros de tamanho e matrizes de dimensão única ou multidimensional.

## <a name="syntax"></a>Sintaxe

```cpp
[ size_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*expression*<br/>
O tamanho da memória alocada para ponteiros de tamanho.

## <a name="remarks"></a>Comentários

O atributo **size_is** C++ tem a mesma funcionalidade que o atributo MIDL de [size_is](/windows/win32/Midl/size-is) .

## <a name="example"></a>Exemplo

Consulte o exemplo de [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Campo em **struct** ou **Union**, parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|`max_is`|

Para obter mais informações sobre os contextos de atributo, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[last_is](last-is.md)<br/>
[max_is](max-is.md)<br/>
[length_is](length-is.md)