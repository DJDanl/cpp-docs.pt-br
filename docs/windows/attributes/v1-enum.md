---
title: v1_enum (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.v1_enum
helpviewer_keywords:
- v1_enum attribute
ms.assetid: 2fe92d92-81b9-4a1c-b6ce-437d0eb770ca
ms.openlocfilehash: 6529a32b0bfe2de09191e9cced8f6bd98e7ffdcc
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832978"
---
# <a name="v1_enum"></a>v1_enum

Direciona que o tipo enumerado especificado seja transmitido como uma entidade de 32 bits em vez do padrão de 16 bits.

## <a name="syntax"></a>Sintaxe

```cpp
[v1_enum]
```

## <a name="remarks"></a>Comentários

O atributo **v1_enum** C++ tem a mesma funcionalidade que o atributo MIDL [v1_enum](/windows/win32/Midl/v1-enum) .

## <a name="example"></a>Exemplo

O código a seguir mostra um uso de **v1_enum**:

```cpp
// cpp_attr_ref_v1_enum.cpp
// compile with: /LD
[module(name="MyLibrary")];

[export, v1_enum]
enum eList {
   e1 = 1, e2 = 2
};
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|Tipo enumerado|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)
