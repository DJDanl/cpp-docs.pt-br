---
title: size_is (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.size_is
helpviewer_keywords:
- size_is attribute
ms.assetid: 70192d09-f6c5-4d52-b3fe-303f8cb10aa5
ms.openlocfilehash: 95b0e16e5f5d085e526f45e8e98898474fc5a17f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449433"
---
# <a name="sizeis"></a>size_is

Especifique o tamanho da memória alocada para ponteiros de tamanho, tamanho de ponteiros para ponteiros de tamanho e único ou matrizes multidimensionais.

## <a name="syntax"></a>Sintaxe

```cpp
[ size_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
O tamanho da memória alocada para ponteiros de tamanho.

## <a name="remarks"></a>Comentários

O **size_is** atributo C++ tem a mesma funcionalidade que o [size_is](/windows/desktop/Midl/size-is) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|`max_is`|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[last_is](last-is.md)<br/>
[max_is](max-is.md)<br/>
[length_is](length-is.md)