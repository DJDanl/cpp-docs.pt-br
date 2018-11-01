---
title: length_is (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.length_is
helpviewer_keywords:
- length_is attribute
ms.assetid: 1d99b883-84bb-4b1e-b098-eb780fc94f40
ms.openlocfilehash: 54206dd82a550924169bf7bcccd4f70f9e5a657c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50489551"
---
# <a name="lengthis"></a>length_is

Especifica o número de elementos da matriz a ser transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ length_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
Uma ou mais expressões de linguagem C. Slots de argumentos vazia são permitidos.

## <a name="remarks"></a>Comentários

O **length_is** atributo C++ tem a mesma funcionalidade que o [length_is](/windows/desktop/Midl/length-is) atributo MIDL.

## <a name="example"></a>Exemplo

Ver [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Campo do **struct** ou **união**, a interface do parâmetro, o método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[max_is](max-is.md)<br/>
[last_is](last-is.md)<br/>
[size_is](size-is.md)