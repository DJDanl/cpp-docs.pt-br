---
title: v1_enum (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.v1_enum
helpviewer_keywords:
- v1_enum attribute
ms.assetid: 2fe92d92-81b9-4a1c-b6ce-437d0eb770ca
ms.openlocfilehash: 1a189f6f1c5ef9d4ae77df9f1eda3f3671ddaf52
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80166101"
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

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Tipo enumerado|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)
