---
title: max_is (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.max_is
helpviewer_keywords:
- max_is attribute
ms.assetid: 7c851f5c-6649-4d77-a792-247c37d8f560
ms.openlocfilehash: b4931962febb1e68701aa3fe271e08f3aa8d9238
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166751"
---
# <a name="max_is"></a>max_is

Designa o valor máximo para um índice de matriz válido.

## <a name="syntax"></a>Sintaxe

```cpp
[ max_is("expression") ]
```

### <a name="parameters"></a>parâmetros

*expressão*<br/>
Uma ou mais expressões em linguagem C. São permitidos slots de argumento vazios.

## <a name="remarks"></a>Comentários

O atributo **max_is** C++ tem a mesma funcionalidade que o atributo MIDL [max_is](/windows/win32/Midl/max-is) .

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Campo em **struct** ou **Union**, parâmetro de interface, método de interface|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|**size_is**|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="example"></a>Exemplo

Consulte [first_is](first-is.md) para obter um exemplo de como especificar uma seção de uma matriz.

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Atributos de parâmetro](parameter-attributes.md)<br/>
[first_is](first-is.md)<br/>
[last_is](last-is.md)<br/>
[length_is](length-is.md)<br/>
[size_is](size-is.md)
