---
title: last_is (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.last_is
helpviewer_keywords:
- last_is attribute
ms.assetid: 9e045ac0-fa38-4249-af55-67bde5d0a58c
ms.openlocfilehash: ad82a5a9688dfbc6c5eb59883be00e8dc39e1942
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840876"
---
# <a name="last_is"></a>last_is

Especifica o índice do último elemento de matriz a ser transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ last_is("expression") ]
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
Uma ou mais expressões em linguagem C. São permitidos slots de argumento vazios.

## <a name="remarks"></a>Comentários

O atributo **last_is** C++ tem a mesma funcionalidade que o atributo MIDL [last_is](/windows/win32/Midl/last-is) .

## <a name="example"></a>Exemplo

Consulte [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
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
[length_is](length-is.md)<br/>
[size_is](size-is.md)
