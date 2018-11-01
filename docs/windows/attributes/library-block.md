---
title: library_block (atributo de COM do C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.library_block
helpviewer_keywords:
- library_block attribute
ms.assetid: ae7a7ebe-5e1a-4eda-a058-11bbd058ece8
ms.openlocfilehash: 76e643cb45d8a87408015e6e0726e47d423147f1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50459911"
---
# <a name="libraryblock"></a>library_block

Coloca uma construção de dentro do bloco de biblioteca IDL.

## <a name="syntax"></a>Sintaxe

```cpp
[library_block]
```

## <a name="remarks"></a>Comentários

Quando você coloca um constructo de dentro do bloco de biblioteca, você certifique-se de que ele será passado para a biblioteca de tipos, independentemente se ele é referenciado. Por padrão, somente construções modificado pela [coclass](coclass.md), [dispinterface](dispinterface.md), e [idl_module](idl-module.md) atributos são colocados no bloco de biblioteca.

## <a name="example"></a>Exemplo

No código a seguir, uma interface personalizada é colocada dentro do bloco de biblioteca.

```cpp
// cpp_attr_ref_library_block.cpp
// compile with: /LD
#include <windows.h>
[module(name="MyLib")];
[object, library_block, uuid("9E66A290-4365-11D2-A997-00C04FA37DDB")]
__interface IMyInterface {
   HRESULT f1();
};
```

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)