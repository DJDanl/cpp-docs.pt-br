---
title: transmit_as (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.transmit_as
helpviewer_keywords:
- transmit_as attribute
ms.assetid: 53d0b8ab-5b06-423e-83eb-3d01a10424b2
ms.openlocfilehash: 9483bfd7ca95aa1121beb56aac8a286c25fa17cb
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840798"
---
# <a name="transmit_as"></a>transmit_as

Instrui o compilador a associar um tipo apresentado que os aplicativos cliente e servidor manipulam, com um tipo transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ transmit_as(type) ]
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
Especifica o tipo de dados que é transmitido entre o cliente e o servidor.

## <a name="remarks"></a>Comentários

O atributo **transmit_as** C++ tem a mesma funcionalidade que o atributo MIDL [transmit_as](/windows/win32/Midl/transmit-as) .

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do atributo **transmit_as** :

```cpp
// cpp_attr_ref_transmit_as.cpp
// compile with: /LD
#include "windows.h"
[module(name="MyLibrary")];

[export] typedef struct _TREE_NODE_TYPE {
unsigned short data;
struct _TREE_NODE_TYPE * left;
struct _TREE_NODE_TYPE * right;
} TREE_NODE_TYPE;

[export] struct PACKED_NODE {
   unsigned short data;   // same as normal node
   int index;   // array index of parent
};

// A left node recursive built array of
// the nodes in the tree.  Can be unpacked with
// that knowledge
[export] typedef struct _TREE_XMIT_TYPE {
   int count;
   [size_is(count)] PACKED_NODE node[];
} TREE_XMIT_TYPE;

[transmit_as(TREE_XMIT_TYPE)] typedef TREE_NODE_TYPE * TREE_TYPE;
```

## <a name="requirements"></a>Requisitos

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`typedef`**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos typedef, enum, Union e struct](typedef-enum-union-and-struct-attributes.md)<br/>
[Export](export.md)
