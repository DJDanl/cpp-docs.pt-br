---
title: helpstringcontext (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.helpstringcontext
helpviewer_keywords:
- helpstringcontext attribute [C++]
ms.assetid: d4cd135e-d91c-4aa3-9353-8aeb096f52cf
ms.openlocfilehash: 9e089c210ad52d8ee07291c174a151f5077ae074
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830976"
---
# <a name="helpstringcontext"></a>helpstringcontext

Especifica a ID de um tópico da ajuda em um arquivo. hlp ou. chm.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpstringcontext(contextID) ]
```

### <a name="parameters"></a>parâmetros

*contextID*<br/>
Um identificador de contexto de ajuda de 32 bits no arquivo de **ajuda** .

## <a name="remarks"></a>Comentários

O atributo **helpstringcontext** C++ tem a mesma funcionalidade que o atributo [helpstringcontext](/windows/win32/Midl/helpstringcontext) ODL.

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

| Contexto de atributo | Valor |
|-|-|
|**Aplica-se a**|**`class`**, **interface**, método de interface|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos IDL](idl-attributes.md)<br/>
[Atributos de interface](interface-attributes.md)<br/>
[Atributos de classe](class-attributes.md)<br/>
[Atributos do método](method-attributes.md)<br/>
[modulo](module-cpp.md)
