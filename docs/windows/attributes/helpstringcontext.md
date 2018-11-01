---
title: helpstringcontext (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstringcontext
helpviewer_keywords:
- helpstringcontext attribute [C++]
ms.assetid: d4cd135e-d91c-4aa3-9353-8aeb096f52cf
ms.openlocfilehash: d292dd53ff3009a571dd5b0a1ba102e75b648e4d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50533595"
---
# <a name="helpstringcontext"></a>helpstringcontext

Especifica a ID do tópico da Ajuda em um arquivo. hlp ou. chm.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringcontext(contextID) ]
```

### <a name="parameters"></a>Parâmetros

*contextID*<br/>
Um identificador de contexto de ajuda de 32 bits na **ajudar** arquivo.

## <a name="remarks"></a>Comentários

O **helpstringcontext** atributo C++ tem a mesma funcionalidade que o [helpstringcontext](/windows/desktop/Midl/helpstringcontext) atributo ODL.

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_helpstringcontext.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLib")];

[   object, helpstring("help string"), helpstringcontext(1), uuid="11111111-1111-1111-1111-111111111111"
]
__interface IMyI
{
   HRESULT xx();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos de método](method-attributes.md)<br/>
[module](module-cpp.md)