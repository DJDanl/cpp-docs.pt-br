---
title: last_is (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.last_is
helpviewer_keywords:
- last_is attribute
ms.assetid: 9e045ac0-fa38-4249-af55-67bde5d0a58c
ms.openlocfilehash: 4745d4eb59fd2adb79937b34184081dbbd0814fb
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69514510"
---
# <a name="last_is"></a>last_is

Especifica o índice do último elemento de matriz a ser transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ last_is("expression") ]
```

### <a name="parameters"></a>Parâmetros

*expression*<br/>
Uma ou mais expressões em linguagem C. São permitidos slots de argumento vazios.

## <a name="remarks"></a>Comentários

O atributo **last_is** C++ tem a mesma funcionalidade que o atributo MIDL [last_is](/windows/win32/Midl/last-is) .

## <a name="example"></a>Exemplo

Consulte [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Campo em **struct** ou **Union**, parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte contextos de [atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[max_is](max-is.md)<br/>
[length_is](length-is.md)<br/>
[size_is](size-is.md)