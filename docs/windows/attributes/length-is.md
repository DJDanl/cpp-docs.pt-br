---
title: length_is (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.length_is
helpviewer_keywords:
- length_is attribute
ms.assetid: 1d99b883-84bb-4b1e-b098-eb780fc94f40
ms.openlocfilehash: 7e6ab9ec0f6f55ab0be9624b7343b087b41f2a54
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215238"
---
# <a name="length_is"></a>length_is

Especifica o número de elementos da matriz a serem transmitidos.

## <a name="syntax"></a>Sintaxe

```cpp
[ length_is("expression") ]
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
Uma ou mais expressões em linguagem C. São permitidos slots de argumento vazios.

## <a name="remarks"></a>Comentários

O atributo **length_is** C++ tem a mesma funcionalidade que o atributo MIDL [length_is](/windows/win32/Midl/length-is) .

## <a name="example"></a>Exemplo

Consulte [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Campo no **`struct`** ou **`union`** , parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[max_is](max-is.md)<br/>
[last_is](last-is.md)<br/>
[size_is](size-is.md)
