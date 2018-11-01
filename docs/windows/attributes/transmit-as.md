---
title: transmit_as (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.transmit_as
helpviewer_keywords:
- transmit_as attribute
ms.assetid: 53d0b8ab-5b06-423e-83eb-3d01a10424b2
ms.openlocfilehash: 546b4c4b32837b46c48eafbe12e991bb6c1630ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50573245"
---
# <a name="transmitas"></a>transmit_as

Instrui o compilador para associar um tipo apresentado que manipulam a aplicativos cliente e servidor, com um tipo transmitido.

## <a name="syntax"></a>Sintaxe

```cpp
[ transmit_as(type) ]
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
Especifica o tipo de dados que é transmitido entre cliente e servidor.

## <a name="remarks"></a>Comentários

O **transmit_as** atributo C++ tem a mesma funcionalidade que o [transmit_as](/windows/desktop/Midl/transmit-as) atributo MIDL.

## <a name="example"></a>Exemplo

O código a seguir mostra um uso do **transmit_as** atributo:

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

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**typedef**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)<br/>
[export](export.md)